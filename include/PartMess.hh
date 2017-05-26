//
// Created by idalov on 26.05.17.
//

#ifndef M_FW_V1_PATMESS_HH
#define M_FW_V1_PATMESS_HH

#include <G4UImessenger.hh>

class PrimaryPart;
class PartMess : public G4UImessenger{
public:
    PartMess(PrimaryPart* primaryPart);
    ~PartMess();
    void SetNewValue(G4UIcommand *command, G4String newValue);
private:
    PrimaryPart* part_act;
    G4UIdirectory* part_dir;
};

#endif //M_FW_V1_PATMESS_HH
