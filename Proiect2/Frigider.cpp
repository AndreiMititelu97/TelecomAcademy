#include "Frigider.h"

Frigider::Frigider(const int& id,const string& nume,const double& pret,const int& volum,const bool& areCongelator):
    Produs(id,nume,pret),
    volum(volum),
    areCongelator(areCongelator)
    {}
int Frigider::getVolum(){
return volum;
}
bool Frigider::getAreCongelator(){
return areCongelator;
}
Frigider::~Frigider(){}
