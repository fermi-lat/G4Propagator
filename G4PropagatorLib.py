# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/G4Propagator/G4PropagatorLib.py,v 1.1 2008/08/15 21:42:35 ecephas Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['G4Propagator'])
    env.Tool('G4GeneratorLib')
def exists(env):
    return 1;
