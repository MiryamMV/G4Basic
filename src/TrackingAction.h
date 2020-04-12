// -----------------------------------------------------------------------------
//  G4Basic | TrackingAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#ifndef TRACKING_ACTION_H
#define TRACKING_ACTION_H

#include <G4UserTrackingAction.hh>
#include <fstream>

class G4Track;


class TrackingAction: public G4UserTrackingAction
{
public:
  TrackingAction(std::ofstream&);
  ~TrackingAction() override;
  void PreUserTrackingAction(const G4Track*) override;
  void PostUserTrackingAction(const G4Track*) override;
private:
  std::ofstream& ofile_;
};

#endif
