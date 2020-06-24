#ifndef PRODUS_H
#define PRODUS_H
#include<string>
using namespace std;
class Produs{
public:
    Produs(const int& id,const string& nume,const double& pret);
    string getNume();
    int getId();
    double getPret();
    virtual ~Produs();

protected:
    int id;
    string nume;
    double pret;


};
#endif // PRODUS_H
