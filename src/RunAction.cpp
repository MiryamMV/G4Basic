// -----------------------------------------------------------------------------
//  G4Basic | RunAction.cpp
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "RunAction.h"

#include <G4Run.hh>


RunAction::RunAction(std::ofstream& ofile):
  G4UserRunAction(),
  ofile_(ofile)
{
}


RunAction::~RunAction()
{
}


void RunAction::BeginOfRunAction(const G4Run* run)
{
  G4cout << "------------------------------------------------------------\n"
         << "Run ID " << run->GetRunID() << G4endl;

  // Write CSV file header
  ofile_ << "event_number,"
         << "track_id,"
         << "step_number,"
         << "x,"  << "y,"  << "z,"
         << "ux," << "uy," << "uz,"
         << "angle,"
         << "step_length,"
         << "track_length,"
         << "E_kin,"
         << "E_dep"
         << std::endl;
}

void RunAction::EndOfRunAction(const G4Run*)
{
  G4cout << "------------------------------------------------------------\n"
         << G4endl;
}
