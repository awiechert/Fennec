#include "fennecApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

/// Adding in base modules (depreciated)
//#include "DGAdvection.h"
//#include "DGFluxBC.h"
//#include "GAdvection.h"
//#include "DGAnisotropicDiffusion.h"
//#include "GAnisotropicDiffusion.h"
//#include "DGFluxLimitedBC.h"
//#include "CoupledCoeffTimeDerivative.h"

//#include "ConstantEllipsoidIC.h"
//#include "AccumulatedMaterial.h"

//#include "StressTensor.h"
//#include "DGMomentumDiffusion.h"
//#include "GMomentumDiffusion.h"
//#include "DGMomentumAdvection.h"
//#include "GMomentumAdvection.h"
//#include "MomentumAccumulation.h"

//#include "DGMomentumFluxBC.h"
//#include "DGContinuumBC.h"

//#include "MomentumAcceleration.h"
//#include "MomentumPressureGrad.h"
//#include "DGConcentrationAdvection.h"
//#include "GConcentrationAdvection.h"
//#include "DGConcentrationFluxBC.h"

//#include "CARDINAL_Object.h"

//#include "Trajectory1stOrder.h"
//#include "AverageMaterial.h"
//#include "ParabolicWindIC.h"
//#include "ParabolicWind.h"

InputParameters fennecApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  return params;
}

registerKnownLabel("fennecApp");

fennecApp::fennecApp(InputParameters parameters) : MooseApp(parameters)
{
    srand(processor_id());
    fennecApp::registerAll(_factory, _action_factory, _syntax);
    
    //Lines below are depreciated
    /**
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  fennecApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  fennecApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  fennecApp::registerExecFlags(_factory);
     */
}

fennecApp::~fennecApp() {}

void
fennecApp::registerAll(Factory & f, ActionFactory & af, Syntax & /*s*/)
{
    Registry::registerObjectsTo(f, {"fennecApp"});
    Registry::registerActionsTo(af, {"fennecApp"});
}

void
fennecApp::registerApps()
{
  registerApp(fennecApp);
}

void
fennecApp::registerObjects(Factory & factory)
{
    mooseDeprecated("use registerAll instead of registerObjects");
    Registry::registerObjectsTo(factory, {"fennecApp"});
	
    //Lines below are depreciated 
	//registerDGKernel(DGAdvection);
	//registerBoundaryCondition(DGFluxBC);
	//registerKernel(GAdvection);
	//registerDGKernel(DGAnisotropicDiffusion);
	//registerKernel(GAnisotropicDiffusion);
	//registerBoundaryCondition(DGFluxLimitedBC);
	//registerKernel(CoupledCoeffTimeDerivative);
	
	//registerInitialCondition(ConstantEllipsoidIC);
	//registerAux(AccumulatedMaterial);
	//registerAux(AverageMaterial);
	
	//registerKernel(StressTensor);
	//registerDGKernel(DGMomentumDiffusion);
	//registerKernel(GMomentumDiffusion);
	//registerDGKernel(DGMomentumAdvection);
	//registerKernel(GMomentumAdvection);
	
	//registerKernel(MomentumAccumulation);
	
	//registerBoundaryCondition(DGMomentumFluxBC);
	//registerBoundaryCondition(DGContinuumBC);
	
	//registerKernel(MomentumAcceleration);
	//registerKernel(MomentumPressureGrad);
	//registerDGKernel(DGConcentrationAdvection);
	//registerKernel(GConcentrationAdvection);
	//registerBoundaryCondition(DGConcentrationFluxBC);
	
	//registerUserObject(CARDINAL_Object);
	
	//registerAux(Trajectory1stOrder);
	
	//registerInitialCondition(ParabolicWindIC);
	//registerAux(ParabolicWind);
}

void
fennecApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  mooseDeprecated("use registerAll instead of associateSyntax");
  Registry::registerActionsTo(action_factory, {"fennecApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
fennecApp::registerObjectDepends(Factory & /*factory*/)
{
    mooseDeprecated("use registerAll instead of registerObjectsDepends");
    /* Uncomment factory parameter and register your new production objects here! */
}

void
fennecApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
    mooseDeprecated("use registerAll instead of associateSyntaxDepends");
    /* Uncomment syntax and factory parameter and register your new production objects here! */
}

void
fennecApp::registerExecFlags(Factory & /*factory*/)
{
    mooseDeprecated("use registerAll instead of registerExecFlags");
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
fennecApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
    fennecApp::registerAll(f, af, s);
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
