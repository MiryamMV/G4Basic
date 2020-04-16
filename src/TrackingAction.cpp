// -----------------------------------------------------------------------------
//  G4Basic | TrackingAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#include "TrackingAction.h"

#include <G4SystemOfUnits.hh>
#include <G4RunManager.hh>
#include <G4Track.hh>


TrackingAction::TrackingAction(std::ofstream& ofile):
  G4UserTrackingAction(),
  ofile_(ofile)
{
}


TrackingAction::~TrackingAction()
{
}


void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
  if (track->GetParentID() != 0) return;

  // Event number
  ofile_ << G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID() << ",";

  // Step number
  ofile_ << track->GetCurrentStepNumber() << ",";

  // Position
  ofile_ << std::setprecision(3) << std::fixed
         << track->GetVertexPosition().x() / mm << ","
         << track->GetVertexPosition().y() / mm << ","
         << track->GetVertexPosition().z() / mm << ",";

  // Cosine theta
  ofile_ << std::setprecision(3) << std::fixed << "0.000,";

  // // Momentum direction
  // ofile_ << std::setprecision(3) << std::fixed
  //        << track->GetMomentumDirection().x() << ","
  //        << track->GetMomentumDirection().y() << ","
  //        << track->GetMomentumDirection().z() << ",";

  // Step length
  ofile_ << std::setprecision(3) << std::fixed << "0.000,";

  // Track length
  ofile_ << std::setprecision(3) << std::fixed << "0.000,";

  // Kinetic energy and deposited energy
  ofile_ << std::setprecision(3) << std::fixed
         << track->GetKineticEnergy() / keV << ","
         << "0.000"
         << std::endl;

}


void TrackingAction::PostUserTrackingAction(const G4Track*)
{
}
