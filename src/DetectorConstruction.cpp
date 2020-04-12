// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.cpp
//
//
// -----------------------------------------------------------------------------

#include "DetectorConstruction.h"

#include <G4Sphere.hh>
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4SystemOfUnits.hh>
#include <G4PhysicalConstants.hh>
#include <G4NistManager.hh>
#include <G4UserLimits.hh>
#include <G4GenericMessenger.hh>
#include <G4VPhysicalVolume.hh>


DetectorConstruction::DetectorConstruction():
  G4VUserDetectorConstruction(),
  msg_(nullptr),
  world_phys_vol_(nullptr)
{
  msg_ = new G4GenericMessenger(this, "/geometry/", "");

  auto& max_step_length_cmd =
    msg_->DeclareMethodWithUnit("max_step_length", "mm",
                                &DetectorConstruction::SetMaxStepLength,
                                "Set maximum allowed step length.");
  max_step_length_cmd.SetParameterName("max_step_length", false);
  max_step_length_cmd.SetRange("max_step_length>0.");
}


DetectorConstruction::~DetectorConstruction()
{
  delete msg_;
}


G4VPhysicalVolume* DetectorConstruction::Construct()
{
  G4String world_name = "WORLD";
  G4double world_size = 25.*m;

  G4Sphere* world_solid_vol =
    new G4Sphere(world_name, 0., world_size/2., 0., 360.*deg, 0., 180.*deg);

  G4LogicalVolume* world_logic_vol =
    new G4LogicalVolume(world_solid_vol, EnrichedXenon(), world_name);

  world_phys_vol_ = new G4PVPlacement(nullptr, G4ThreeVector(0.,0.,0.),
                                      world_logic_vol, world_name, nullptr,
                                      false, 0, true);

  return world_phys_vol_;
}


void DetectorConstruction::SetMaxStepLength(double msl)
{
  world_phys_vol_->GetLogicalVolume()->SetUserLimits(new G4UserLimits(msl));
}


G4Material* DetectorConstruction::EnrichedXenon() const
{
  G4String name = "ENRICHED_XENON";
  G4double pressure    = 15.0 * bar;
  G4double temperature = STP_Temperature; // 273.15 K
  G4double density     = 97.49 * kg/m3;

  G4Material* material =
    new G4Material(name, density, 1, kStateGas, temperature, pressure);

  G4Element* Xe = new G4Element("ENRICHED_XENON", "Xe", 2);

  G4Isotope* Xe134 = new G4Isotope("Xe134", 54, 134, 133.905395*g/mole);
  G4Isotope* Xe136 = new G4Isotope("Xe136", 54, 136, 135.907219*g/mole);
  Xe->AddIsotope(Xe134,  9.*perCent);
  Xe->AddIsotope(Xe136, 91.*perCent);

  material->AddElement(Xe,1);

  return material;
}
