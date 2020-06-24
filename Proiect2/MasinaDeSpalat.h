#ifndef MASINADESPALAT_H
#define MASINADESPALAT_H

#include "Produs.h"


class MasinaDeSpalat : public Produs
{
    public:
        MasinaDeSpalat(const int& id,const string& nume,const double& pret,const int& rotatiiPeMinut,const string& clasaEnergetica);
        int getRotatiiPeMinut();
        string getClasaEnergetica();
        virtual ~MasinaDeSpalat();
    private:
        int rotatiiPeMinut;
        string clasaEnergetica;
};

#endif // MASINADESPALAT_H
