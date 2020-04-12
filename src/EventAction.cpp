// -----------------------------------------------------------------------------
//  G4Basic | EventAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "EventAction.h"

#include <G4Run.hh>


EventAction::EventAction(std::ofstream& ofile):
  G4UserEventAction(),
  ofile_(ofile)
{
}


EventAction::~EventAction()
{
}


void EventAction::BeginOfEventAction(const G4Event*)
{
}

void EventAction::EndOfEventAction(const G4Event*)
{
}
