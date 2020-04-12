// -----------------------------------------------------------------------------
//  G4Basic | PrimaryGeneration.cpp
//
//
// -----------------------------------------------------------------------------

#ifndef PRIMARY_GENERATION_H
#define PRIMARY_GENERATION_H

#include <G4VUserPrimaryGeneratorAction.hh>
#include <globals.hh>

class G4ParticleDefinition;


class PrimaryGeneration: public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneration();
  ~PrimaryGeneration() override;
  void GeneratePrimaries(G4Event*) override;

private:
  G4ParticleDefinition* particle_def_;
  G4double kinetic_energy_;
};

#endif
