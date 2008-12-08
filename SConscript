# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/G4Propagator/SConscript,v 1.1 2008/08/15 21:22:41 ecephas Exp $
# Authors: Tracy Usher <usher@slac.stanford.edu>
# Version: G4Propagator-02-05-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('G4PropagatorLib', depsOnly = 1)
libEnv.AppendUnique(CPPPATH=['#G4Generator/']) # This is because G4Propagator/src/G4PropagatorExceptionHandler.cxx
                                              # is looking for src/RunManager.h and it is only in G4Generator/src
G4Propagator = libEnv.SharedLibrary('G4Propagator', listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.Tool('G4PropagatorLib')
test_G4Propagator = progEnv.GaudiProgram('test_G4Propagator', listFiles(['src/test/*.cxx']), test=1)
progEnv.Tool('registerObjects', package = 'G4Propagator', libraries = [G4Propagator], testApps = [test_G4Propagator])



