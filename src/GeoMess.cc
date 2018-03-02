//
// Created by idalov on 26.05.17.
//


#include <GeoMess.hh>

GeoMess::GeoMess(Geometry *geometry) {

    geom_dir = new G4UIdirectory("/det/");
    geom_dir->SetGuidance("Detector construction control");
    fDetCmd = new G4UIcmdWithAString("/det/setDetector1",this);
    fDetCmd->SetGuidance("Set Detector1");
    fDetCmd->SetParameterName("choice",false);
    fDetCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

GeoMess::~GeoMess(){
    delete fDetCmd;
    delete geom_dir;
}

void GeoMess::SetNewValue(G4UIcommand *command, G4String newValue){
    if( command == fDetCmd )
    { det->SetDetector(newValue);}

}