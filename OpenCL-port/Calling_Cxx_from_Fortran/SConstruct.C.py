# Proof of concept SConstruct for integrating C++ into FORTRAN

cxxsources=['testCxx.cc']
fsources=['test_Cxx_in_C.c']

envCxx=Environment(CXX='g++');
envCxx.Library('testCxx',cxxsources)

envF=Environment(CC='gcc',CFLAGS=['-Wall','-O3'])
envF.Program('testCxx_in_C',fsources,LIBS=['testCxx','stdc++'],LIBPATH='.')
