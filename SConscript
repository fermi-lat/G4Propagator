# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/G4Propagator/SConscript,v 1.5 2009/11/10 23:33:31 jrb Exp $
# Authors: Tracy Usher <usher@slac.stanford.edu>
# Version: G4Propagator-02-05-03
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
progEnv.Tool('FluxSvcLib')
progEnv.Tool('GlastSvcLib')
progEnv.Tool('fluxLib')
test_G4Propagator = progEnv.GaudiProgram('test_G4Propagator',
                                         listFiles(['src/test/*.cxx']), test=1)
progEnv.Tool('registerTargets', package = 'G4Propagator',
             libraryCxts = [[G4Propagator, libEnv]],
             testAppCxts = [[test_G4Propagator, progEnv]])
