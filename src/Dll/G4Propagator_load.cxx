/** 
* @file G4Propagator_load.cpp
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/G4Propagator/src/Dll/G4Propagator_load.cxx,v 1.1.1.1 2003/01/23 21:24:32 usher Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES(G4Propagator) {
    DECLARE_TOOL( G4PropagatorTool );
    DECLARE_TOOL( G4PropagationTool );
} 
