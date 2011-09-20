
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cutil.h>
#include "ftocmacros.h"
#define TRUE 1
#define FALSE 0


//!ACC$REGION (<nx>,<ny>) BEGIN
__global__ void loop_ij_Kernel1(int its,int nvl,int npp,int nd,int nx,int ny,int *nprox_ij,float *sidevec_e_ij,float *ue_ij,float *ve_ij,float *vnorm_ij) {

 int ivl;
 int j;
 int i;
 int isn;
  for (ivl=1;ivl<=nvl;ivl++) {
//!ACC$DO VECTOR
    j = threadIdx.x+1;
//    for (j=1;j<=nx;j++) {
//!ACC$DO PARALLEL
      i = blockIdx.x+1;
//      for (i=1;i<=ny;i++) {
        for (isn=1;isn<=nprox_ij[FTNREF2D(i,j,nx,1,1)];isn++) {
          vnorm_ij[FTNREF4D(i,j,isn,ivl,nx,ny,npp,1,1,1,1)] = sidevec_e_ij[FTNREF4D(i,j,2,isn,nx,ny,nd,1,1,1,1)] * ue_ij[FTNREF4D(i,j,isn,ivl,nx,ny,npp,1,1,1,1)] - sidevec_e_ij[FTNREF4D(i,j,1,isn,nx,ny,nd,1,1,1,1)] * ve_ij[FTNREF4D(i,j,isn,ivl,nx,ny,npp,1,1,1,1)];
        }
//      }
//    }
  }
  return;
}
//!ACC$REGION END


extern "C" void loop_ij_ (int *its__G,int *nvl__G,int *npp__G,int *nd__G,int *nx__G,int *ny__G,int *nprox_ij,float *sidevec_e_ij,float *ue_ij,float *ve_ij,float *vnorm_ij) {

  int argc=2;
  char *argv[]= {"","-device=0"};
  CUT_DEVICE_INIT(argc, argv);

  int its=*its__G;
  int nvl=*nvl__G;
  int npp=*npp__G;
  int nd=*nd__G;
  int nx=*nx__G;
  int ny=*ny__G;




  dim3 cuda_threads1(nx);
  dim3 cuda_grids1(ny);

// create and start timer
  unsigned int timer = 0;
  int *d_nprox_ij;
  cudaMalloc((void **) &d_nprox_ij,((nx)*(ny))*sizeof(int));
  cudaMemcpy(d_nprox_ij,nprox_ij,((nx)*(ny))*sizeof(int),cudaMemcpyHostToDevice);
  float *d_sidevec_e_ij;
  cudaMalloc((void **) &d_sidevec_e_ij,((nx)*(ny)*(nd)*(npp))*sizeof(float));
  cudaMemcpy(d_sidevec_e_ij,sidevec_e_ij,((nx)*(ny)*(nd)*(npp))*sizeof(float),cudaMemcpyHostToDevice);
  float *d_ue_ij;
  cudaMalloc((void **) &d_ue_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float));
  cudaMemcpy(d_ue_ij,ue_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float),cudaMemcpyHostToDevice);
  float *d_ve_ij;
  cudaMalloc((void **) &d_ve_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float));
  cudaMemcpy(d_ve_ij,ve_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float),cudaMemcpyHostToDevice);
  float *d_vnorm_ij;
  cudaMalloc((void **) &d_vnorm_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float));
  cudaMemcpy(d_vnorm_ij,vnorm_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float),cudaMemcpyHostToDevice);

  cutCreateTimer(&timer);
  cutStartTimer(timer);
  // setup execution parameters 
  // execute the kernel 
  loop_ij_Kernel1<<< cuda_grids1, cuda_threads1 >>>(its,nvl,npp,nd,nx,ny,d_nprox_ij,d_sidevec_e_ij,d_ue_ij,d_ve_ij,d_vnorm_ij);
  cudaThreadSynchronize();
  // check if kernel execution generated an error
  CUT_CHECK_ERROR("Kernel execution failed");

  cutStopTimer(timer);
  float timer__G = cutGetTimerValue(timer);
  cutDeleteTimer(timer);
  printf("loop_ij_Kernel1 execution time: %f \n",timer__G);
  cudaFree(d_nprox_ij);
  cudaFree(d_sidevec_e_ij);
  cudaFree(d_ue_ij);
  cudaFree(d_ve_ij);
  cudaMemcpy(vnorm_ij,d_vnorm_ij,((nx)*(ny)*(npp)*(nvl))*sizeof(float),cudaMemcpyDeviceToHost);
  cudaFree(d_vnorm_ij);


  *its__G=its;
  *nvl__G=nvl;
  *npp__G=npp;
  *nd__G=nd;
  *nx__G=nx;
  *ny__G=ny;

  return;
}
