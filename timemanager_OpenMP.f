      subroutine timemanager()                                  
      use includepar
      use includecom

! *******************************************************************************
!                                                                               *
!  Handles the computation of trajectories, i.e. determines which               *
!  trajectories have to be computed at what time.                               *
!  Manages dry+wet deposition routines, radioactive decay and the computation   *
!  of concentrations.                                                           *
!                                                                               *
!      Author: A. Stohl                                                         *
!                                                                               *
!      20 May 1996                                                              *
!                                                                               *
!      Dec 2005, J. Fast - Only call conccalc & concoutput when (iout.ge.1)     *
!                                                                               *
! *******************************************************************************
!   Changes, Bernd C. Krueger, Feb. 2001:                                       *
!         Call of convmix when new windfield is read                            *
! ------------------------------------                                          *
!   Changes Petra Seibert, Sept 2002                                            *
!      fix wet scavenging problem                                               *
!      Code may not be correct for decay of deposition!                         *
!   Changes Petra Seibert, Nov 2002                                             *
!      call convection BEFORE new fields are read in BWD mode                   *
!   Changes Caroline Forster, Feb 2005
!      new interface between flexpart and convection scheme
!      Emanuel's latest subroutine convect43c.f is used
! *******************************************************************************
!                                                                               *
!  Variables:                                                                   *
!  DEP                .true. if either wet or dry deposition is switched on     *
!  decay(maxspec) [1/s] decay constant for radioactive decay                    *
!  DRYDEP             .true. if dry deposition is switched on                   *
!  ideltas [s]        modelling period                                          *
!  itime [s]          actual temporal position of calculation                   *
!  ldeltat [s]        time since computation of radioact. decay of depositions  *
!  loutaver [s]       averaging period for concentration calculations           *
!  loutend [s]        end of averaging for concentration calculations           *
!  loutnext [s]       next time at which output fields shall be centered        *
!  loutsample [s]     sampling interval for averaging of concentrations         *
!  loutstart [s]      start of averaging for concentration calculations         *
!  loutstep [s]       time interval for which concentrations shall be calculated*
!  npoint(maxpart)    index, which starting point the trajectory has            *
!                     starting positions of trajectories                        *
!  nstop              serves as indicator for fate of particles                 *
!                     in the particle loop                                      *
!  nstop1             serves as indicator for wind fields (see getfields)       *
!  outnum             number of samples for each concentration calculation      *
!  outnum             number of samples for each concentration calculation      *
!  prob               probability of absorption at ground due to dry deposition *
!  WETDEP             .true. if wet deposition is switched on                   *
!  weight             weight for each concentration sample (1/2 or 1)           *
!  uap(maxpart),ucp(maxpart),uzp(maxpart) = random velocities due to turbulence *
!  us(maxpart),vs(maxpart),ws(maxpart) = random velocities due to interpolation *
!  xtra1(maxpart), ytra1(maxpart), ztra1(maxpart) =                             *
!                     spatial positions of trajectories                         *
!                                                                               *
!  Constants:                                                                   *
!  maxpart            maximum number of trajectories                            *
!                                                                               *
! *******************************************************************************

      use includehanna
      use includeinterpol

!! Original line !!       integer j,k,l,n,itime,nstop,nstop1
      integer :: l, n, k, itime, nstop1, nstop, j
      integer :: loutend, loutstart, loutnext
      integer :: ldeltat, itage, nage, jy_LOCAL_timemanager, ix_LOCAL_timemanager
      real  :: outnum
      real , dimension(maxspec)  :: prob
      real  :: weight
      real , dimension(maxpart)  :: uap
      real , dimension(maxpart)  :: uzp
      real , dimension(maxpart)  :: ucp
      real  :: decfact
      real , dimension(maxpart)  :: cbt
      real , dimension(maxpart)  :: vs
      real , dimension(maxpart)  :: us
      real , dimension(maxpart)  :: ws
      real  :: gridtotalunc
      real  :: wetgridtotalunc
      real , dimension(maxspec)  :: drydeposit
      real :: yold, drygridtotalunc, xold, zold
!      real xm,xm1

!  First output for time 0
! ************************

      loutnext = loutstep/2
      outnum = 0.
      loutstart = loutnext-loutaver/2
      loutend = loutnext+loutaver/2

! **********************************************************************
!  Loop over the whole modelling period in time steps of mintime seconds
! **********************************************************************

      do itime=0,ideltas,lsynctime

!  Computation of wet deposition every lsynctime seconds
!  maybe wet depo frequency can be relaxed later but better be on safe side
!  wetdepo must be called BEFORE new fields are read in but should not
!  be called in the very beginning before any fields are loaded, or
!  before particles are in the system
!  Code may not be correct for decay of deposition
!  changed by Petra Seibert 9/02
! ********************************************************************

        if (wetdep .and. itime  /=  0 .and. numpart  >  0) call wetdepo(itime,lsynctime,loutnext)
          if ((ldirect == -1).and.(lconvection == 1).and.(itime < 0)) call convmix(itime)
        call getfields(itime,nstop1)

!  compute convection for backward runs
! *************************************

!  Get necessary wind fields if not available
! *******************************************

        if (nstop1 > 1) stop 'NO METEO FIELDS AVAILABLE'

!  Release particles
! ******************

        if (mdomainfill >= 1) then
          if (itime == 0) then
            call init_domainfill()
          else
            call boundcond_domainfill(itime,loutend)
          endif
        else
          call releaseparticles(itime)
        endif

!  Compute convective mixing for forward runs
!  for backward runs it is done before next windfield is read in
! **************************************************************

          if ((ldirect == 1).and.(lconvection == 1)) call convmix(itime)
        if (dep.and.(itime == loutnext)) then 

!  If middle of averaging period of output fields is reached, accumulated
!  deposited mass radioactively decays 
! ***********************************************************************

          do k=1,nspec
            if (decay(k) > 0.) then
              do nage=1,nageclass
                do l=1,nclassunc
!  Mother output grid
                  do jy=0,numygrid-1
                    do ix=0,numxgrid-1
                      wetgridunc(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage) = wetgridunc(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage)* exp(-1.*outstep*decay(k))
    drygridunc(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage) = drygridunc(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage)* exp(-1.*outstep*decay(k))
      end do
      end do
!  Nested output grid
                  if (nested_output == 1) then
                    do jy=0,numygridn-1
                      do ix=0,numxgridn-1
                        wetgriduncn(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage) = wetgriduncn(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage)* exp(-1.*outstep*decay(k))
    drygriduncn(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage) = drygriduncn(ix_LOCAL_timemanager,jy_LOCAL_timemanager,k,l, &
      nage)* exp(-1.*outstep*decay(k))
      end do
      end do
                  endif
      end do
      end do
            endif
      end do
        endif

! !! CHANGE: These lines may be switched on to check the conservation
! !! of mass within FLEXPART

!        if (mod(itime,loutsample).eq.0) then 
!           xm=0.
!           xm1=0.
!           do 247 j=1,numpart
! 47          if (itra1(j).eq.itime) xm1=xm1+xmass1(j,1)
!           xm=xm1
!           do 248 nage=1,nageclass
!             do 248 ix=0,numxgrid-1
!               do 248 jy=0,numygrid-1
!                 do 248 l=1,nclassunc
! 48        xm=xm+wetgridunc(ix,jy,1,l,nage)+drygridunc(ix,jy,1,l,nage)
!           write(*,'(i6,4f10.3)') itime,xm,xm1
!        endif
! !! CHANGE

!  Check whether concentrations are to be calculated
! **************************************************

        if ((ldirect*itime >= ldirect*loutstart).and. (ldirect*itime <= ldirect*loutend)) then 
          if (mod(itime-loutstart,loutsample) == 0) then

!  If we are exactly at the start or end of the concentration averaging interval,
!  give only half the weight to this sample
! *******************************************************************************

            if ((itime == loutstart).or.(itime == loutend)) then
              weight = 0.5
            else
              weight = 1.0
            endif
            outnum = outnum+weight
            if(iout >= 1) call conccalc(itime,weight)
          endif

          if ((mquasilag == 1).and.(itime == (loutstart+loutend)/2)) call partoutput_short(itime)    

          if ((itime == loutend).and.(outnum > 0.)) then

!  Output and reinitialization of grid
!  If necessary, first sample of new grid is also taken
! *****************************************************

            if ((iout <= 3.).or.(iout == 5)) then 
              if(iout >= 1) call concoutput(itime,outnum,gridtotalunc, wetgridtotalunc, &
      drygridtotalunc)
              if (nested_output == 1.and.iout >= 1) call concoutput_nest(itime,outnum)
              outnum = 0.
            endif
            if ((iout == 4).or.(iout == 5)) call plumetraj(itime)
            if (iflux == 1) call fluxoutput(itime)
            write(*,45) itime,numpart,gridtotalunc,wetgridtotalunc, drygridtotalunc
45    format(i9,' SECONDS SIMULATED: ',i8, ' PARTICLES:    Uncertainty: ',3f7.3)
            if (ipout >= 1) call partoutput(itime)    
            loutnext = loutnext+loutstep
            loutstart = loutnext-loutaver/2
            loutend = loutnext+loutaver/2
            if (itime == loutstart) then
              weight = 0.5
              outnum = outnum+weight
              if(iout >= 1) call conccalc(itime,weight)
            endif

!  Check, whether particles are to be split:
!  If so, create new particles and attribute all information from the old
!  particles also to the new ones; old and new particles both get half the
!  mass of the old ones
! ************************************************************************
    
            if (ldirect*itime >= ldirect*itsplit) then
              n = numpart
              do j=1,numpart
                if (ldirect*itime >= ldirect*itrasplit(j)) then
                  if (n < maxpart) then
                    n = n+1
                    itrasplit(j) = 2*(itrasplit(j)-itramem(j))+itramem(j)
                    itrasplit(n) = itrasplit(j)
                    itramem(n) = itramem(j)
                    itra1(n) = itra1(j)
                    idt(n) = idt(j)
                    npoint(n) = npoint(j)
                    nclass(n) = nclass(j)
                    xtra1(n) = xtra1(j)
                    ytra1(n) = ytra1(j)
                    ztra1(n) = ztra1(j)
                    uap(n) = uap(j)
                    ucp(n) = ucp(j)
                    uzp(n) = uzp(j)
                    us(n) = us(j)
                    vs(n) = vs(j)
                    ws(n) = ws(j)
                    cbt(n) = cbt(j)
                    do k=1,nspec
                      xmass1(j,k) = xmass1(j,k)/2.
    xmass1(n,k) = xmass1(j,k)
      end do
                  endif
                endif
      end do
              numpart = n
            endif
          endif
        endif

        if (itime == ideltas) goto 99  !Break

!  Compute interval since radioactive decay of deposited mass was computed
! ************************************************************************

        if (itime < loutnext) then
          ldeltat = itime-(loutnext-loutstep)
        else                                  
          ldeltat = itime-loutnext
        endif
    print *, 'Loop over all particles'

!  Loop over all particles
! ************************
! $ACC NOTRANSLATE C
      call particles_main_loop(cbt,decfact,drydeposit,itage,itime,j,k,ldeltat,nage,nstop,prob,uap, &
      ucp,us,uzp,vs,ws,xold,yold,zold,h,zeta,tlu,sigu,tlv,sigv,tlw,dsigwdz,sigw,dsigw2dz,ol,ust, &
      wst,numpart,itra1,itramem,nageclass,lage,idt,xtra1,ytra1,ztra1,iflux,lsynctime,nspec,decay, &
      drydepspec,xmass1,drydep,nclass,nested_output,nmixz,nglobal,switchnorthg,sglobal, &
      switchsouthg,numbnests,xln,xrn,yln,yrn,memtime,xresoln,yresoln,hmix,hmixn,method,ldirect,nz, &
      height,turbswitch,rannumb,ifine,fine,turb_option,ctl,mintime,vsetaver,lwindinterv,dxconst, &
      dyconst,xglobal,nxmin1,nymin1,memind,uun,vvn,wwn,rhon,drhodzn,ustar,wstar,oli,uupol,vvpol, &
      uu,vv,ww,drhodz,rho,vdepn,vdep,pvn,pv,ustarn,wstarn,olin,dx,xoutshiftn,dxoutn,dy,youtshiftn, &
      dyoutn,numxgridn,numygridn,drygriduncn,xoutshift,dxout,youtshift,dyout,numzgrid,outheight, &
      numxgrid,numygrid,outheighthalf,fluxu,fluxd,nx,fluxw,fluxe,fluxs,fluxn,drygridunc, &
      indzindicator,depoindicator,ngrid,ix,jy,ixp,jyp,indz,indzp,u,uprof,v,vprof,w,wprof,rhoprof, &
      rhogradprof,usig,usigprof,vsig,vsigprof,wsig,wsigprof,pvi,p1,p2,p3,p4,dt2,dt1,dtt,ddx,ddy, &
      rddx,rddy)

      end do

99    continue

      if (ipout == 2) call partoutput(itime)     

      end


! *** SUBROUTINE particles_main_loop ***
      subroutine particles_main_loop(cbt,decfact,drydeposit,itage,itime,j,k,ldeltat,nage,nstop,prob, &
      uap,ucp,us,uzp,vs,ws,xold,yold,zold,h,zeta,tlu,sigu,tlv,sigv,tlw,dsigwdz,sigw,dsigw2dz,ol, &
      ust,wst,numpart,itra1,itramem,nageclass,lage,idt,xtra1,ytra1,ztra1,iflux,lsynctime,nspec, &
      decay,drydepspec,xmass1,drydep,nclass,nested_output,nmixz,nglobal,switchnorthg,sglobal, &
      switchsouthg,numbnests,xln,xrn,yln,yrn,memtime,xresoln,yresoln,hmix,hmixn,method,ldirect,nz, &
      height,turbswitch,rannumb,ifine,fine,turb_option,ctl,mintime,vsetaver,lwindinterv,dxconst, &
      dyconst,xglobal,nxmin1,nymin1,memind,uun,vvn,wwn,rhon,drhodzn,ustar,wstar,oli,uupol,vvpol, &
      uu,vv,ww,drhodz,rho,vdepn,vdep,pvn,pv,ustarn,wstarn,olin,dx,xoutshiftn,dxoutn,dy,youtshiftn, &
      dyoutn,numxgridn,numygridn,drygriduncn,xoutshift,dxout,youtshift,dyout,numzgrid,outheight, &
      numxgrid,numygrid,outheighthalf,fluxu,fluxd,nx,fluxw,fluxe,fluxs,fluxn,drygridunc, &
      indzindicator,depoindicator,ngrid,ix,jy,ixp,jyp,indz,indzp,u,uprof,v,vprof,w,wprof,rhoprof, &
      rhogradprof,usig,usigprof,vsig,vsigprof,wsig,wsigprof,pvi,p1,p2,p3,p4,dt2,dt1,dtt,ddx,ddy, &
      rddx,rddy)
      use includepar
! *** Original code from timemanager starts here ***
!! Original line !!             real zold
        real :: h
        real :: zeta
        real :: tlu
        real :: sigu
        real :: tlv
        real :: sigv
        real :: tlw
        real :: dsigwdz
        real :: sigw
        real :: dsigw2dz
        real :: ol
        real :: ust
        real :: wst
        integer :: numpart
        integer, dimension(maxpart)  :: itra1
        integer, dimension(maxpart)  :: itramem
        integer :: nageclass
        integer, dimension(maxageclass)  :: lage
        integer, dimension(maxpart)  :: idt
        double precision, dimension(maxpart)  :: xtra1
        double precision, dimension(maxpart)  :: ytra1
        real, dimension(maxpart)  :: ztra1
        integer :: iflux
        integer :: lsynctime
        integer :: nspec
        real, dimension(maxspec)  :: decay
        logical, dimension(maxspec)  :: drydepspec
        real, dimension(maxpart,maxspec)  :: xmass1
        logical :: drydep
        integer, dimension(maxpart)  :: nclass
        integer :: nested_output
        integer :: nmixz
        logical :: nglobal
        real :: switchnorthg
        logical :: sglobal
        real :: switchsouthg
        integer :: numbnests
        real, dimension(maxnests)  :: xln
        real, dimension(maxnests)  :: xrn
        real, dimension(maxnests)  :: yln
        real, dimension(maxnests)  :: yrn
        integer, dimension(2)  :: memtime
        real, dimension(0:maxnests)  :: xresoln
        real, dimension(0:maxnests)  :: yresoln
        real, dimension(0:nxmax-1,0:nymax-1,1,2)  :: hmix
        real, dimension(0:nxmaxn-1,0:nymaxn-1,1,2,maxnests)  :: hmixn
        integer :: method
        integer :: ldirect
        integer :: nz
        real, dimension(nzmax)  :: height
        logical :: turbswitch
        real, dimension(maxrand)  :: rannumb
        integer :: ifine
        real :: fine
        integer :: turb_option
        real :: ctl
        integer :: mintime
        real, dimension(maxspec)  :: vsetaver
        integer :: lwindinterv
        real :: dxconst
        real :: dyconst
        logical :: xglobal
        integer :: nxmin1
        integer :: nymin1
        integer, dimension(2)  :: memind
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: uun
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: vvn
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: wwn
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: rhon
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: drhodzn
        real, dimension(0:nxmax-1,0:nymax-1,1,2)  :: ustar
        real, dimension(0:nxmax-1,0:nymax-1,1,2)  :: wstar
        real, dimension(0:nxmax-1,0:nymax-1,1,2)  :: oli
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: uupol
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: vvpol
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: uu
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: vv
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: ww
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: drhodz
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: rho
        real, dimension(0:nxmaxn-1,0:nymaxn-1,maxspec,2,maxnests)  :: vdepn
        real, dimension(0:nxmax-1,0:nymax-1,maxspec,2)  :: vdep
        real, dimension(0:nxmaxn-1,0:nymaxn-1,nzmax,2,maxnests)  :: pvn
        real, dimension(0:nxmax-1,0:nymax-1,nzmax,2)  :: pv
        real, dimension(0:nxmaxn-1,0:nymaxn-1,1,2,maxnests)  :: ustarn
        real, dimension(0:nxmaxn-1,0:nymaxn-1,1,2,maxnests)  :: wstarn
        real, dimension(0:nxmaxn-1,0:nymaxn-1,1,2,maxnests)  :: olin
        real :: dx
        real :: xoutshiftn
        real :: dxoutn
        real :: dy
        real :: youtshiftn
        real :: dyoutn
        integer :: numxgridn
        integer :: numygridn
        real, dimension(0:maxxgridn-1,0:maxygridn-1,maxpointspec,nclassunc, &
      maxageclass)  :: drygriduncn
        real :: xoutshift
        real :: dxout
        real :: youtshift
        real :: dyout
        integer :: numzgrid
        real, dimension(maxzgrid)  :: outheight
        integer :: numxgrid
        integer :: numygrid
        real, dimension(maxzgrid)  :: outheighthalf
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxu
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxd
        integer :: nx
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxw
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxe
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxs
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxzgrid,maxspec,maxageclass)  :: fluxn
        real, dimension(0:maxxgrid-1,0:maxygrid-1,maxpointspec,nclassunc,maxageclass)  :: drygridunc
        logical, dimension(nzmax)  :: indzindicator
        logical, dimension(maxspec)  :: depoindicator
        integer :: ngrid
        integer :: ix
        integer :: jy
        integer :: ixp
        integer :: jyp
        integer :: indz
        integer :: indzp
        real :: u
        real, dimension(nzmax)  :: uprof
        real :: v
        real, dimension(nzmax)  :: vprof
        real :: w
        real, dimension(nzmax)  :: wprof
        real, dimension(nzmax)  :: rhoprof
        real, dimension(nzmax)  :: rhogradprof
        real :: usig
        real, dimension(nzmax)  :: usigprof
        real :: vsig
        real, dimension(nzmax)  :: vsigprof
        real :: wsig
        real, dimension(nzmax)  :: wsigprof
        real :: pvi
        real :: p1
        real :: p2
        real :: p3
        real :: p4
        real :: dt2
        real :: dt1
        real :: dtt
        real :: ddx
        real :: ddy
        real :: rddx
        real :: rddy
            real :: zold
        real :: yold
        real :: xold
        real, dimension(maxpart)  :: ws
        real, dimension(maxpart)  :: vs
        real, dimension(maxpart)  :: uzp
        real, dimension(maxpart)  :: us
        real, dimension(maxpart)  :: ucp
        real, dimension(maxpart)  :: uap
        real, dimension(maxspec)  :: prob
        integer :: nstop
        integer :: nage
        integer :: ldeltat
        integer :: k
        integer :: j
        integer :: itime
        integer :: itage
        real, dimension(maxspec)  :: drydeposit
        real :: decfact
        real, dimension(maxpart)  :: cbt


!$OMP PARALLEL
print *, 'OpenMP loop'
!$OMP DO PRIVATE(itage,xold,yold,zold,decfact,nage,k,drydeposit)
        do j=1,numpart
!  If integration step is due, do it
! **********************************
          if (itra1(j) == itime) then
!  Determine age class of the particle
            itage = abs(itra1(j)-itramem(j))
            do nage=1,nageclass
              if (itage < lage(nage)) goto 37  !Break
            end do
37    continue
!  Initialize newly released particle
! ***********************************
            if ((itramem(j) == itime).or.(itime == 0)) call initialize(itime,idt(j),uap(j),ucp(j), &
      uzp(j),us(j),vs(j),ws(j),xtra1(j),ytra1(j),ztra1(j),cbt(j),h,zeta,sigu,sigv,sigw,tlw, &
      dsigwdz,ol,ust,dsigw2dz,tlu,tlv,wst,hmix,memind,height,turbswitch,rannumb,ctl,mintime, &
      lsynctime,memtime,nz,uupol,vvpol,uu,vv,ww,pv,ustar,wstar,oli,drhodz,rho,ix,jy,ixp,jyp,indz, &
      indzp,u,uprof,v,vprof,w,wprof,usig,usigprof,vsig,vsigprof,wsig,wsigprof,ddx,ddy,rddx,rddy, &
      p1,p2,p3,p4,dt1,dt2,dtt,ngrid,pvi,rhoprof,rhogradprof,indzindicator)
!  Memorize particle positions
! ****************************
            xold = xtra1(j)
            yold = ytra1(j)
            zold = ztra1(j)
!  Integrate Langevin equation for lsynctime seconds
! *************************************************
            call advance(itime,idt(j),uap(j),ucp(j),uzp(j),us(j),vs(j),ws(j),nstop,xtra1(j), &
      ytra1(j),ztra1(j),prob,cbt(j),h,zeta,tlu,sigu,tlv,sigv,tlw,dsigwdz,sigw,dsigw2dz,ol,ust,wst, &
      nmixz,drydep,nspec,nglobal,switchnorthg,sglobal,switchsouthg,numbnests,xln,xrn,yln,yrn, &
      memtime,xresoln,yresoln,hmix,hmixn,method,lsynctime,ldirect,nz,height,turbswitch,rannumb, &
      ifine,fine,turb_option,ctl,mintime,vsetaver,drydepspec,lwindinterv,dxconst,dyconst,xglobal, &
      nxmin1,nymin1,memind,uun,vvn,wwn,rhon,drhodzn,ustar,wstar,oli,uupol,vvpol,uu,vv,ww,drhodz, &
      rho,vdepn,vdep,pvn,pv,ustarn,wstarn,olin,indzindicator,depoindicator,ngrid,ix,jy,ixp,jyp, &
      indz,indzp,u,uprof,v,vprof,w,wprof,rhoprof,rhogradprof,usig,usigprof,vsig,vsigprof,wsig, &
      wsigprof,pvi,p1,p2,p3,p4,dt2,dt1,dtt,ddx,ddy,rddx,rddy)
!  Calculate the gross fluxes across layer interfaces
! ***************************************************
!WV            if (iflux == 1) call calcfluxes(nage,j,xold,yold,zold,xtra1,ytra1,dx,xoutshift,dxout,dy, &
!WV      youtshift,dyout,numzgrid,outheight,ztra1,numxgrid,numygrid,outheighthalf,nspec,fluxu,xmass1, &
!WV      fluxd,nx,fluxw,fluxe,nxmin1,fluxs,fluxn)
!WV!  Determine, when next time step is due
!WV!  If trajectory is terminated, mark it
!WV! **************************************
!WV            if (nstop > 1) then
!WV              itra1(j) = -999999999
!WV            else
!WV              itra1(j) = itime+lsynctime
!  Dry deposition and radioactive decay for each species
! ******************************************************
!WV              do k=1,nspec
!WV                if (decay(k) > 0.) then             
!WV                  decfact = exp(-float(abs(lsynctime))*decay(k))
!WV                else
!WV                  decfact = 1.
!WV                endif
!WV                if (drydepspec(k)) then        
!WV                  drydeposit(k) = xmass1(j,k)*prob(k)*decfact
!WV                  xmass1(j,k) = xmass1(j,k)*(1.-prob(k))*decfact
!WV                  if (decay(k) > 0.) then   
!WV                    drydeposit(k) = drydeposit(k)* exp(float(abs(ldeltat))*decay(k))
!WV                  endif
!WV                else                           
!WV                  xmass1(j,k) = xmass1(j,k)*decfact
!WV                endif
!WV      end do
!WV              if (drydep) then
!WV                call drydepokernel(nclass(j),drydeposit,sngl(xtra1(j)),sngl(ytra1(j)),nage,dx, &
!WV      xoutshift,dxout,dy,youtshift,dyout,numxgrid,numygrid,nspec,drydepspec,drygridunc)
!WV                if (nested_output == 1) call drydepokernel_nest(nclass(j),drydeposit,sngl(xtra1(j)), &
!WV      sngl(ytra1(j)),nage,dx,xoutshiftn,dxoutn,dy,youtshiftn,dyoutn,numxgridn,numygridn,nspec, &
!WV      drydepspec,drygriduncn)
!WV              endif
!  Terminate trajectories that are older than maximum allowed age
! ***************************************************************
!WV              if (abs(itra1(j)-itramem(j)) >= lage(nageclass)) itra1(j)=-999999999
!WV            endif
          endif
      end do
!$OMP END DO
!$OMP END PARALLEL
       print *, 'End of OpenMP region' 
      end
