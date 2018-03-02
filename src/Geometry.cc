//
// Created by idalov on 25.05.17.
//

#include <Geometry.hh>
#include <G4VisAttributes.hh>
#include <G4PVPlacement.hh>
#include <G4SolidStore.hh>
#include <G4GeometryManager.hh>
#include <G4RunManager.hh>

Geometry::Geometry() {
    nist = G4NistManager::Instance();
    world_mat = nist->FindOrBuildMaterial("G4_AIR");
    water_mat = nist->FindOrBuildMaterial("G4_WATER");
    poly_mat = nist->FindOrBuildMaterial("G4_POLYETHYLENE");
    det_mat = nist->FindOrBuildMaterial("G4_Galactic");
    det_pos = G4ThreeVector(60*cm,0,0);
    geoMess = new GeoMess(this);
}

Geometry::~Geometry() {
    delete geoMess;
}

G4VPhysicalVolume* Geometry::Construct() {
    G4GeometryManager::GetInstance()->OpenGeometry();
    G4PhysicalVolumeStore::GetInstance()->Clean();
    G4LogicalVolumeStore::GetInstance()->Clean();
    G4SolidStore::GetInstance()->Clean();
    G4double size = 3 * m;
    G4Box *world = new G4Box("world", size / 2., size / 2., size / 2.);
    G4LogicalVolume *world_log = new G4LogicalVolume(world, world_mat, "world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);


    G4Tubs* water = new G4Tubs("tube",3*cm,10*cm,40/2*cm,0,360*deg);
    G4LogicalVolume * water_log = new G4LogicalVolume(water,water_mat,"water_log");
    water_log->SetVisAttributes(G4Colour::Blue());
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),water_log,"water_PVP",world_log,false,0);

    G4Tubs* poly_1 = new G4Tubs("poly_1",15*cm,45*cm,40/2*cm,-30*deg,60*deg);
    G4LogicalVolume * poly_1_log = new G4LogicalVolume(poly_1,poly_mat,"poly_1_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_1_log,"poly_1_PVP",world_log,false,0);

    G4Tubs* poly_2 = new G4Tubs("poly_2",16*cm,25*cm,40/2*cm,90*deg,60*deg);
    G4LogicalVolume * poly_2_log = new G4LogicalVolume(poly_2,poly_mat,"poly_2_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_2_log,"poly_2_PVP",world_log,false,0);

    G4Tubs* poly_3 = new G4Tubs("poly_3",13*cm,15*cm,40/2*cm,210*deg,60*deg);
    G4LogicalVolume * poly_3_log = new G4LogicalVolume(poly_3,poly_mat,"poly_3_log");
    new G4PVPlacement(new G4RotationMatrix(0,90*deg,0),G4ThreeVector(),poly_3_log,"poly_3_PVP",world_log,false,0);

    G4Box* det = new G4Box("det", 76/2,40/2*cm,250/2);
    G4LogicalVolume * det_log = new G4LogicalVolume(det,det_mat,"det_log");
    det_log->SetVisAttributes(G4Colour::Red());

    new G4PVPlacement(new G4RotationMatrix(0,0,0),det_pos,det_log,"det_PVP",world_log,false,0);

    return new G4PVPlacement(0, G4ThreeVector(), world_log, "world_PVP", 0, false, 0);
}

void Geometry::SetDetector(G4String g4String) {
    det_pos = G4ThreeVector(120*cm,0,0);
    G4RunManager::GetRunManager()->DefineWorldVolume(Construct());
    G4RunManager::GetRunManager()->ReinitializeGeometry();
}
