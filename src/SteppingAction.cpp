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

  // Cosine theta
  G4ThreeVector u0 = step->GetTrack()->GetVertexMomentumDirection();
  G4ThreeVector u  = step->GetTrack()->GetMomentumDirection();
  G4double angle = u.angle(u0);

  ofile_ << std::setprecision(3) << std::fixed << angle / deg << ",";

  // // Momentum direction
  // ofile_ << std::setprecision(3) << std::fixed
  //        << step->GetPostStepPoint()->GetMomentumDirection().x() / mm << ","
  //        << step->GetPostStepPoint()->GetMomentumDirection().y() / mm << ","
  //        << step->GetPostStepPoint()->GetMomentumDirection().z() / mm << ",";

  // Step length
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetStepLength() / mm << ",";

  // Track length
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetTrack()->GetTrackLength() / mm << ",";

  // Kinetic energy and energy deposit
  ofile_ << std::setprecision(3) << std::fixed
         << step->GetTrack()->GetKineticEnergy() / keV << ","
         << step->GetTotalEnergyDeposit() / keV
         << std::endl;
}
