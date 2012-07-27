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

!WV! This is the parallel loop		
!$OMP PARALLEL
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
            if (iflux == 1) call calcfluxes(nage,j,xold,yold,zold,xtra1,ytra1,dx,xoutshift,dxout,dy, &
      youtshift,dyout,numzgrid,outheight,ztra1,numxgrid,numygrid,outheighthalf,nspec,fluxu,xmass1, &
      fluxd,nx,fluxw,fluxe,nxmin1,fluxs,fluxn)
!  Determine, when next time step is due
!  If trajectory is terminated, mark it
! **************************************
            if (nstop > 1) then
              itra1(j) = -999999999
            else
              itra1(j) = itime+lsynctime !  Dry deposition and radioactive decay for each species
! ******************************************************
              do k=1,nspec
                if (decay(k) > 0.) then             
                  decfact = exp(-float(abs(lsynctime))*decay(k))
                else
                  decfact = 1.
                endif
                if (drydepspec(k)) then        
                  drydeposit(k) = xmass1(j,k)*prob(k)*decfact
                  xmass1(j,k) = xmass1(j,k)*(1.-prob(k))*decfact
                  if (decay(k) > 0.) then   
                    drydeposit(k) = drydeposit(k)* exp(float(abs(ldeltat))*decay(k))
                  endif
                else                           
                  xmass1(j,k) = xmass1(j,k)*decfact
                endif
              end do
              if (drydep) then
                call drydepokernel(nclass(j),drydeposit,sngl(xtra1(j)),sngl(ytra1(j)),nage,dx, &
      xoutshift,dxout,dy,youtshift,dyout,numxgrid,numygrid,nspec,drydepspec,drygridunc)
                if (nested_output == 1) call drydepokernel_nest(nclass(j),drydeposit,sngl(xtra1(j)), &
      sngl(ytra1(j)),nage,dx,xoutshiftn,dxoutn,dy,youtshiftn,dyoutn,numxgridn,numygridn,nspec, &
      drydepspec,drygriduncn)
              endif
!  Terminate trajectories that are older than maximum allowed age
! ***************************************************************
              if (abs(itra1(j)-itramem(j)) >= lage(nageclass)) itra1(j)=-999999999
            endif
          endif
      end do
!$OMP END DO
!$OMP END PARALLEL

      end
