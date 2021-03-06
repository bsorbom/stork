#include "ArcApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<ArcApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ArcApp::ArcApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ArcApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ArcApp::associateSyntax(_syntax, _action_factory);
}

ArcApp::~ArcApp()
{
}

void
ArcApp::registerApps()
{
  registerApp(ArcApp);
}

void
ArcApp::registerObjects(Factory & factory)
{
}

void
ArcApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
