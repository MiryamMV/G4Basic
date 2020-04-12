// -----------------------------------------------------------------------------
//  G4Basic | SteppingAction.h
//
//  User stepping action class.
// -----------------------------------------------------------------------------

#ifndef STEPPING_ACTION_H
#define STEPPING_ACTION_H

#include <G4UserSteppingAction.hh>
#include <fstream>

class G4Step;


class SteppingAction: public G4UserSteppingAction
{
public:
  SteppingAction(std::ofstream&);
  ~SteppingAction() override;
  void UserSteppingAction(const G4Step*) override;
private:
  std::ofstream& ofile_;
};

#endif
