#include "fennecApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

/// Adding in base modules
#include "DGAdvection.h"
#include "DGFluxBC.h"
#include "GAdvection.h"
#include "DGAnisotropicDiffusion.h"
#include "GAnisotropicDiffusion.h"
#include "DGFluxLimitedBC.h"
#include "CoupledCoeffTimeDerivative.h"

#include "ConstantEllipsoidIC.h"
#include "AccumulatedMaterial.h"

#include "StressTensor.h"
#include "DGMomentumDiffusion.h"
#include "GMomentumDiffusion.h"
#include "DGMomentumAdvection.h"
#include "GMomentumAdvection.h"
#include "MomentumAccumulation.h"

#include "DGMomentumFluxBC.h"
#include "DGContinuumBC.h"

#include "MomentumAcceleration.h"
#include "MomentumPressureGrad.h"
#include "DGConcentrationAdvection.h"
#include "GConcentrationAdvection.h"
#include "DGConcentrationFluxBC.h"

#include "CraneObject.h"

template <>
InputParameters
validParams<fennecApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

fennecApp::fennecApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  fennecApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  fennecApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  fennecApp::registerExecFlags(_factory);
}

fennecApp::~fennecApp() {}

void
fennecApp::registerApps()
{
  registerApp(fennecApp);
}

void
fennecApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"fennecApp"});
	
	registerDGKernel(DGAdvection);
	registerBoundaryCondition(DGFluxBC);
	registerKernel(GAdvection);
	registerDGKernel(DGAnisotropicDiffusion);
	registerKernel(GAnisotropicDiffusion);
	registerBoundaryCondition(DGFluxLimitedBC);
	registerKernel(CoupledCoeffTimeDerivative);
	
	registerInitialCondition(ConstantEllipsoidIC);
	registerAux(AccumulatedMaterial);
	
	registerKernel(StressTensor);
	registerDGKernel(DGMomentumDiffusion);
	registerKernel(GMomentumDiffusion);
	registerDGKernel(DGMomentumAdvection);
	registerKernel(GMomentumAdvection);
	
	registerKernel(MomentumAccumulation);
	
	registerBoundaryCondition(DGMomentumFluxBC);
	registerBoundaryCondition(DGContinuumBC);
	
	registerKernel(MomentumAcceleration);
	registerKernel(MomentumPressureGrad);
	registerDGKernel(DGConcentrationAdvection);
	registerKernel(GConcentrationAdvection);
	registerBoundaryCondition(DGConcentrationFluxBC);
	
	registerUserObject(CraneObject);
}

void
fennecApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"fennecApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
fennecApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
fennecApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
fennecApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fennecApp__registerApps()
{
  fennecApp::registerApps();
}

extern "C" void
fennecApp__registerObjects(Factory & factory)
{
  fennecApp::registerObjects(factory);
}

extern "C" void
fennecApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  fennecApp::associateSyntax(syntax, action_factory);
}

extern "C" void
fennecApp__registerExecFlags(Factory & factory)
{
  fennecApp::registerExecFlags(factory);
}
