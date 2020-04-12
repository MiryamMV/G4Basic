// -----------------------------------------------------------------------------
//  G4Basic | DetectorConstruction.h
//
//
// -----------------------------------------------------------------------------

#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H

#include <G4VUserDetectorConstruction.hh>

class G4Material;
class G4GenericMessenger;
class G4VPhysicalVolume;


class DetectorConstruction: public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  ~DetectorConstruction() override;
  G4VPhysicalVolume* Construct() override;
  void SetMaxStepLength(double);
private:
  G4Material* EnrichedXenon() const;
private:
  G4GenericMessenger* msg_;
  G4VPhysicalVolume* world_phys_vol_;
};

#endif
