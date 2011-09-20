# Makefile to build GPU executables
# Written by: Mark Govett
# Date:  April 2010
#
# 
# path to F2C-ACC distribution
GPU_HOME=$(HOME)/F2C-ACC
#
# path to M4, include files
M4=/usr/bin/m4 -I $(GPU_HOME)/include/logical.m4 $(GPU_HOME)/include/ARCH.m4
#
# define path to cuda compiler and libraries
CUDA=/opt/cuda/2.2/cuda
NVCC=$(CUDA)/bin/nvcc
#
# path to user support libraries, these are used by the F2C-ACC generated code
mCUDA=$(HOME)/cuda
CUDALIBS=-L$(CUDA)/lib -lcudart -L$(mCUDA)/lib -lcutil
CUDA_INC=$(mCUDA)/common/inc
#
# optional GPU build options: profiler (-pg), emulator (-deviceemu)
GPU_OPTIONS=-pg
#
# path to F2C-ACC compiler
F2C-ACC=$(GPU_HOME)/bin/F2C-ACC
#
.SUFFIXES: .f90 .F90 .c .cu .o .m4

.f90.cu:
	$(F2C-ACC) --Generate=CUDA $<
	$(M4) $*.m4 >$*_GPU.cu
	$(NVCC) -c $(FLAGS) -I $(GPU_HOME)/include -I$(CUDA_INC) $*_GPU.cu

.f90.o:
	$(F2C-ACC) --Generate=C $<
	$(M4) $*.m4 > $*_CPU.c
	cc -c $(FLAGS) -I $(GPU_HOME)/include $*_CPU.c

# link GPU libraries to the object files:  $(CUDALIBS)
all:

clean:
	rm -f *.o *.c *.cu *.m4 *.*~
