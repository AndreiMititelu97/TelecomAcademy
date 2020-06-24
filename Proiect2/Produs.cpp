#include "Produs.h"

Produs::Produs(const int& id,const string& nume,const double& pret):
        id(id),
        nume(nume),
        pret(pret) {}

string Produs::getNume(){
    return nume;
}
int Produs::getId(){
    return id;
}
double Produs::getPret(){
    return pret;
    }
Produs::~Produs(){}

