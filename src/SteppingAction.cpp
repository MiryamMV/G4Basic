// -----------------------------------------------------------------------------
//  G4Basic | SteppingAction.cpp
//
//  User stepping action class.
// -----------------------------------------------------------------------------

#include "SteppingAction.h"

#include <G4Step.hh>
#include <G4SystemOfUnits.hh>
#include <G4RunManager.hh>


SteppingAction::SteppingAction(std::ofstream& ofile):
  G4UserSteppingAction(),
  ofile_(ofile)
{
}


SteppingAction::~SteppingAction()
{
}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
  if ((step->GetTrack()->GetParentID() != 0) ||
      (step->GetTotalEnergyDeposit() <= 0)) return;

  // Event and step numbers
  ofile_ << G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID() << ","
         << step->GetTrack()->GetCurrentStepNumber() << ",";

  // Position
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetPostStepPoint()->GetPosition().x() / mm << ","
         << step->GetPostStepPoint()->GetPosition().y() / mm << ","
         << step->GetPostStepPoint()->GetPosition().z() / mm << ",";

  // Momentum direction
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetPostStepPoint()->GetMomentumDirection().x() / mm << ","
         << step->GetPostStepPoint()->GetMomentumDirection().y() / mm << ","
         << step->GetPostStepPoint()->GetMomentumDirection().z() / mm << ",";

  // Step length
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetStepLength() / mm << ",";

  // Kinetic energy and energy deposit
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetTrack()->GetKineticEnergy() / keV << ","
         << step->GetTotalEnergyDeposit() / keV << std::endl;
}
