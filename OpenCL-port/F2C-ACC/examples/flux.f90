subroutine loop_ij(its,nvl,npp,nd,nx,ny,nprox_ij,sidevec_e_ij,ue_ij,ve_ij,vnorm_ij)

implicit none
integer,intent (IN)    :: its
integer,intent (IN)    :: nvl
integer,intent (IN)    :: npp
integer,intent (IN)    :: nd
integer,intent (IN)    :: nx,ny
integer,intent (IN)    :: nprox_ij(nx,ny)
real,   intent (IN)    :: sidevec_e_ij(nx,ny,nd,npp)
real,   intent (IN)    :: ue_ij(nx,ny,npp,nvl)
real,   intent (IN)    :: ve_ij(nx,ny,npp,nvl)
real,  intent (OUT)    :: vnorm_ij(nx,ny,npp,nvl)

integer :: ivl
integer :: isn
integer :: i, j

!ACC$REGION (<nx>,<ny>) BEGIN
do ivl=1,nvl
!ACC$DO VECTOR
  do j=1,nx
!ACC$DO PARALLEL
    do i=1,ny
      do isn=1,nprox_ij(i,j)
        vnorm_ij(i,j,isn,ivl) = sidevec_e_ij(i,j,2,isn)*ue_ij(i,j,isn,ivl) &
                              - sidevec_e_ij(i,j,1,isn)*ve_ij(i,j,isn,ivl)  
      end do
    end do
  end do
end do
!ACC$REGION END

return
end subroutine loop_ij
