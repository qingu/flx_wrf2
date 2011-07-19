C WV: This is the loop over all particles, encapsulated in a subroutine
C WV: The first step towards an OpenCL version
C WV: The idea is to use as few implicit parameters as possible

********************************************************************************
*                                                                              *
* Handles the computation of trajectories, i.e. determines which               *
* trajectories have to be computed at what time.                               *
* Manages dry+wet deposition routines, radioactive decay and the computation   *
* of concentrations.                                                           *
*                                                                              *
*     Author: A. Stohl                                                         *
*                                                                              *
*     20 May 1996                                                              *
*                                                                              *
*     Dec 2005, J. Fast - Only call conccalc & concoutput when (iout.ge.1)     *
*                                                                              *
********************************************************************************
*  Changes, Bernd C. Krueger, Feb. 2001:                                       *
*        Call of convmix when new windfield is read                            *
*------------------------------------                                          *
*  Changes Petra Seibert, Sept 2002                                            *
*     fix wet scavenging problem                                               *
*     Code may not be correct for decay of deposition!                         *
*  Changes Petra Seibert, Nov 2002                                             *
*     call convection BEFORE new fields are read in BWD mode                   *
*  Changes Caroline Forster, Feb 2005
*     new interface between flexpart and convection scheme
*     Emanuel's latest subroutine convect43c.f is used
********************************************************************************
*                                                                              *
* Variables:                                                                   *
* DEP                .true. if either wet or dry deposition is switched on     *
* decay(maxspec) [1/s] decay constant for radioactive decay                    *
* DRYDEP             .true. if dry deposition is switched on                   *
* itime [s]          actual temporal position of calculation                   *
* ldeltat [s]        time since computation of radioact. decay of depositions  *
* nstop              serves as indicator for fate of particles                 *
*                    in the particle loop                                      *
* prob               probability of absorption at ground due to dry deposition *
* uap(maxpart),ucp(maxpart),uzp(maxpart) = random velocities due to turbulence *
* us(maxpart),vs(maxpart),ws(maxpart) = random velocities due to interpolation *
* xtra1(maxpart), ytra1(maxpart), ztra1(maxpart) =                             *
*                    spatial positions of trajectories                         *
*                                                                              *
* Constants:                                                                   *
* maxpart            maximum number of trajectories                            *
*                                                                              *
********************************************************************************

C Loop over all particles
*************************
C itra1,itramem,
	subroutine timemanager_particles_loop(itime,
     &	ldeltat,prob,uap,ucp,uzp,us,vs,ws,cbt,
     &	gridtotalunc,wetgridtotalunc,drygridtotalunc)

C WV: the parameters in includepar will have to become either
C WV: constants or macros
       include 'includepar'
C       include 'includecom'

      integer j,k,l,n,itime,nstop
      integer ldeltat,itage,nage
      real prob(maxspec)
      real uap(maxpart),ucp(maxpart),uzp(maxpart),decfact
      real us(maxpart),vs(maxpart),ws(maxpart),cbt(maxpart)
      real drydeposit(maxspec),gridtotalunc,wetgridtotalunc
      real drygridtotalunc,xold,yold,zold

        do 20 j=1,numpart


C If integration step is due, do it
***********************************

          if (itra1(j).eq.itime) then

C Determine age class of the particle
            itage=abs(itra1(j)-itramem(j))
            do 36 nage=1,nageclass
              if (itage.lt.lage(nage)) goto 37
36            continue
37          continue

C Initialize newly released particle
************************************

            if ((itramem(j).eq.itime).or.(itime.eq.0))
     +      call initialize(itime,idt(j),uap(j),ucp(j),uzp(j),
     +      us(j),vs(j),ws(j),xtra1(j),ytra1(j),ztra1(j),cbt(j))

C Memorize particle positions
*****************************

            xold=xtra1(j)
            yold=ytra1(j)
            zold=ztra1(j)

C Integrate Lagevin equation for lsynctime seconds
**************************************************

            call advance(itime,idt(j),uap(j),ucp(j),uzp(j),us(j),
     +      vs(j),ws(j),nstop,xtra1(j),ytra1(j),ztra1(j),prob,cbt(j))


C Calculate the gross fluxes across layer interfaces
****************************************************

            if (iflux.eq.1) call calcfluxes(nage,j,xold,yold,zold)


C Determine, when next time step is due
C If trajectory is terminated, mark it
***************************************

            if (nstop.gt.1) then
              itra1(j)=-999999999
            else
              itra1(j)=itime+lsynctime


C Dry deposition and radioactive decay for each species
*******************************************************

              do 23 k=1,nspec
                if (decay(k).gt.0.) then             ! radioactive decay
                  decfact=exp(-float(abs(lsynctime))*decay(k))
                else
                  decfact=1.
                endif

                if (DRYDEPSPEC(k)) then        ! dry deposition
                  drydeposit(k)=xmass1(j,k)*prob(k)*decfact
                  xmass1(j,k)=xmass1(j,k)*(1.-prob(k))*decfact
                  if (decay(k).gt.0.) then   ! correct for decay (see wetdepo)
                    drydeposit(k)=drydeposit(k)*
     +              exp(float(abs(ldeltat))*decay(k))
                  endif
                else                           ! no dry deposition
                  xmass1(j,k)=xmass1(j,k)*decfact
                endif
23              continue

              if (DRYDEP) then
                call drydepokernel(nclass(j),drydeposit,sngl(xtra1(j)),
     +          sngl(ytra1(j)),nage)
                if (nested_output.eq.1) call drydepokernel_nest(
     +          nclass(j),drydeposit,sngl(xtra1(j)),sngl(ytra1(j)),nage)
              endif

C Terminate trajectories that are older than maximum allowed age
****************************************************************

              if (abs(itra1(j)-itramem(j)).ge.lage(nageclass))
     +        itra1(j)=-999999999
            endif

          endif

20        continue                         ! end of loop over particles
          
      end

