//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fennecTestApp.h"
#include "fennecApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<fennecTestApp>()
{
  InputParameters params = validParams<fennecApp>();
  return params;
}

registerKnownLabel("fennecTestApp");

fennecTestApp::fennecTestApp(InputParameters parameters) : MooseApp(parameters)
{
    fennecTestApp::registerAll(_factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
    /**
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  fennecApp::registerObjectDepends(_factory);
  fennecApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  fennecApp::associateSyntaxDepends(_syntax, _action_factory);
  fennecApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  fennecApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    fennecTestApp::registerObjects(_factory);
    fennecTestApp::associateSyntax(_syntax, _action_factory);
    fennecTestApp::registerExecFlags(_factory);
  }
     */
}

fennecTestApp::~fennecTestApp() {}

void
fennecTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
    fennecApp::registerAll(f, af, s);
    if (use_test_objs)
    {
        Registry::registerObjectsTo(f, {"fennecTestApp"});
        Registry::registerActionsTo(af, {"fennecTestApp"});
    }
}

void
fennecTestApp::registerApps()
{
  registerApp(fennecApp);
  registerApp(fennecTestApp);
}

void
fennecTestApp::registerObjects(Factory & factory)
{
  Registry::registerObjectsTo(factory, {"fennecTestApp"});
}

void
fennecTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"fennecTestApp"});
}

void
fennecTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fennecTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
    fennecTestApp::registerAll(f, af, s);
}

// External entry point for dynamic application loading
extern "C" void
fennecTestApp__registerApps()
{
  fennecTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
fennecTestApp__registerObjects(Factory & factory)
{
  fennecTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
fennecTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  fennecTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
fennecTestApp__registerExecFlags(Factory & factory)
{
  fennecTestApp::registerExecFlags(factory);
}
