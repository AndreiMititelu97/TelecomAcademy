#include "MasinaDeSpalat.h"

MasinaDeSpalat::MasinaDeSpalat(const int& id,const string& nume,const double& pret,const int& rotatiiPeMinut,const string& clasaEnergetica) :
    Produs(id,nume,pret),
    rotatiiPeMinut(rotatiiPeMinut),
    clasaEnergetica(clasaEnergetica)
    {}
int MasinaDeSpalat::getRotatiiPeMinut(){
return rotatiiPeMinut;
}
string MasinaDeSpalat::getClasaEnergetica(){
return clasaEnergetica;
}
MasinaDeSpalat::~MasinaDeSpalat(){}
