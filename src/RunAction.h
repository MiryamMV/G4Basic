// -----------------------------------------------------------------------------
//  G4Basic | RunAction.h
//
//  User run action class.
// -----------------------------------------------------------------------------

#ifndef RUN_ACTION_H
#define RUN_ACTION_H

#include <G4UserRunAction.hh>
#include <fstream>

class G4Run;


class RunAction: public G4UserRunAction
{
public:
  RunAction(std::ofstream&);
  ~RunAction() override;
  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;
private:
  std::ofstream& ofile_;
};

#endif
