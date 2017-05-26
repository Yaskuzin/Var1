//
// Created by idalov on 23.05.17.
//

#include <RunAction.hh>
#include <Run.hh>
#include <Logger.hh>
#include <G4RunManager.hh>

RunAction::RunAction() {

}

G4Run* RunAction::GenerateRun() {
    return new Run;
}


void RunAction::EndOfRunAction(const G4Run* aRun){
    const Run* run = static_cast<const Run*>(aRun);
    Logger::Info("End of Run");
}