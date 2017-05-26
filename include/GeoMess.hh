//
// Created by idalov on 26.05.17.
//

#ifndef M_FW_V1_DETMESS_HH
#define M_FW_V1_DETMESS_HH

#include <Geometry.hh>
#include <G4UImessenger.hh>
class Geometry;
class GeoMess : public G4UImessenger{
public:
    GeoMess(Geometry* geometry);
    ~GeoMess();
    void SetNewValue(G4UIcommand *command, G4String newValue);
private:
    Geometry* det;
    G4UIdirectory* geom_dir;
};
#endif //M_FW_V1_DETMESS_HH
