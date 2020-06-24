#ifndef FRIGIDER_H
#define FRIGIDER_H

#include "Produs.h"


class Frigider : public Produs
{
    public:
        Frigider(const int& id,const string& nume,const double& pret,const int& volum,const bool& areCongelator);
        int getVolum();
        bool getAreCongelator();
        virtual ~Frigider();
    private:
        int volum;
        bool areCongelator;
};

#endif // FRIGIDER_H
