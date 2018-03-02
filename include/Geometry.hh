//
// Created by idalov on 25.05.17.
//

#ifndef BGO_AND_GAMMA_GEOMETRY_HH
#define BGO_AND_GAMMA_GEOMETRY_HH
#include <G4VUserDetectorConstruction.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include <G4SystemOfUnits.hh>
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "GeoMess.hh"
#include <G4Tubs.hh>

class GeoMess;

class Geometry: public G4VUserDetectorConstruction {
public:
    Geometry();
    ~Geometry();
    virtual G4VPhysicalVolume *Construct();

    void SetDetector(G4String g4String);

private:
    G4NistManager* nist;
    G4Material* world_mat;

    G4Material* water_mat;

    G4Material* poly_mat;

    G4Material* det_mat;

    G4ThreeVector det_pos;
    GeoMess* geoMess;
    G4Box *world;
    G4LogicalVolume *world_log;
};

#endif //BGO_AND_GAMMA_GEOMETRY_HH
