// -----------------------------------------------------------------------------
//  G4Basic | EventAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#ifndef EVENT_ACTION_H
#define EVENT_ACTION_H

#include <G4UserEventAction.hh>
#include <fstream>

class G4Event;


class EventAction: public G4UserEventAction
{
public:
  EventAction(std::ofstream&);
  ~EventAction() override;
  void BeginOfEventAction(const G4Event*) override;
  void EndOfEventAction(const G4Event*) override;
private:
  std::ofstream& ofile_;
};

#endif
