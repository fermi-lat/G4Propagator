// File and Version Information:
// $Header: /nfs/slac/g/glast/ground/cvs/G4Propagator/src/G4PropagatorTool.cxx,v 1.3 2003/02/20 23:12:58 burnett Exp $
//
// Description: Service for particle transport management
//
// Author(s):
//      T.Usher

#include "G4PropagatorTool.h"

static ToolFactory<G4PropagatorTool> g4prop_factory;
const IToolFactory& G4PropagatorToolFactory = g4prop_factory;

IG4GeometrySvc*              G4PropagatorTool::geometrySvc           = 0;

G4PropagatorTool::G4PropagatorTool(const std::string& type, const std::string& name, const IInterface* parent) :
  AlgTool(type, name, parent)
{
  // Purpose and Method:  Gaudi initialization routine. 
  // Inputs:  None
  // Outputs:  Gaudi StatusCode
  // Dependencies: None
  // Restrictions None 

  //Declare additional interface
  declareInterface<IPropagatorTool>(this);
}

  StatusCode G4PropagatorTool::initialize()
  {
  MsgStream log(msgSvc(), name());

  log << MSG::INFO << "G4 Propagator Tool initializing now" << endreq;

  IService* iService = 0;
  if( serviceLocator()->getService( "G4GeometrySvc", iService, true).isFailure() ) 
  {
    log << MSG::ERROR << "Could not find the G4 Geometry Service!" << endreq;
    return StatusCode::FAILURE;
  }

  IG4GeometrySvc* gsv = dynamic_cast<IG4GeometrySvc*>(iService);

  geometrySvc = gsv;

  log << MSG::INFO << "G4 Propagator Tool ready" << endreq;

  return StatusCode::SUCCESS;
}

G4PropagatorTool::~G4PropagatorTool()
{
}
