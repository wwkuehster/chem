#include "chemApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<chemApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

chemApp::chemApp(InputParameters parameters) : MooseApp(parameters)
{
  chemApp::registerAll(_factory, _action_factory, _syntax);
}

chemApp::~chemApp() {}

void
chemApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"chemApp"});
  Registry::registerActionsTo(af, {"chemApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
chemApp::registerApps()
{
  registerApp(chemApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
chemApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  chemApp::registerAll(f, af, s);
}
extern "C" void
chemApp__registerApps()
{
  chemApp::registerApps();
}
