//
// Created by idalov on 23.05.17.
//
#include "SteppingAction.hh"
#include <EventAct.hh>
#include <G4Track.hh>
#include <Logger.hh>
#include "G4SystemOfUnits.hh"
SteppingAction::SteppingAction(EventAct * event)
        :EvAct(event)
{}


void SteppingAction::UserSteppingAction(const G4Step * aStep) {
    G4String pname = aStep->GetTrack()->GetDefinition()->GetParticleName();
    G4String volmatname = aStep->GetTrack()->GetVolume()->GetLogicalVolume()->GetMaterial()->GetName();
}
