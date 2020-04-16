// -----------------------------------------------------------------------------
//  G4Basic | PrimaryGeneration.cpp
//
//
// -----------------------------------------------------------------------------

#include "PrimaryGeneration.h"

#include <G4GenericMessenger.hh>
#include <G4Electron.hh>
#include <G4ParticleDefinition.hh>
#include <G4SystemOfUnits.hh>
#include <G4PrimaryParticle.hh>
#include <G4PrimaryVertex.hh>
#include <G4Event.hh>
#include <G4RandomDirection.hh>


PrimaryGeneration::PrimaryGeneration():
  G4VUserPrimaryGeneratorAction(),
  msg_(nullptr),
  particle_def_(G4Electron::Definition()),
  kinetic_energy_(0.)
{
  msg_ = new G4GenericMessenger(this, "/G4Basic/", "");

  auto& kinetic_energy_cmd =
    msg_->DeclarePropertyWithUnit("kinetic_energy", "keV", kinetic_energy_,
                                  "Kinetic energy of primary electron.");
  kinetic_energy_cmd.SetParameterName("kinetic_energy", false);
  kinetic_energy_cmd.SetRange("kinetic_energy>0.");
}


PrimaryGeneration::~PrimaryGeneration()
{
  delete msg_;
}


void PrimaryGeneration::GeneratePrimaries(G4Event* event)
{
  G4PrimaryParticle* particle = new G4PrimaryParticle(particle_def_);
  particle->SetMomentumDirection(G4RandomDirection());
  particle->SetKineticEnergy(kinetic_energy_);

  G4double initial_time = 0.;
  G4ThreeVector initial_position(0.,0.,0.);
  G4PrimaryVertex* vertex = new G4PrimaryVertex(initial_position, initial_time);
  vertex->SetPrimary(particle);

  event->AddPrimaryVertex(vertex);
}
