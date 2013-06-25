# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/G4Propagator/SConscript,v 1.16 2013/04/06 17:57:00 usher Exp $
# Authors: Tracy Usher <usher@slac.stanford.edu>
# Version: G4Propagator-03-02-00

Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='G4Propagator', toBuild='component')
G4Propagator =libEnv.ComponentLibrary('G4Propagator',listFiles(['src/*.cxx']))

progEnv.Tool('G4PropagatorLib')
progEnv.Tool('FluxSvcLib')
progEnv.Tool('GlastSvcLib')
progEnv.Tool('fluxLib')

test_G4Propagator = progEnv.GaudiProgram('test_G4Propagator',
                                         listFiles(['src/test/*.cxx']),
                                         test=1, package='G4Propagator')
progEnv.Tool('registerTargets', package = 'G4Propagator',
             libraryCxts = [[G4Propagator, libEnv]],
             testAppCxts = [[test_G4Propagator, progEnv]],
             jo = ['src/test/jobOptions.txt'])
