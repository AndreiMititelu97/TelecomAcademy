#ifndef MAGAZIN_H
#define MAGAZIN_H
#include "Produs.h"
class Magazin
{
    public:
        Magazin(const int& nrProduse);
        void adaugaProdus(Produs* produs);
        void eliminaProdus(int idProdus);
        Produs* detaliiProdus(int idProdus);
        Produs* cautaProdus(int idProdus);
        void afisareDetaliiProdus(Produs* produs);
        int numaraMasiniDeSpalat();
        void scrieProduse();
        void operator<<(int idProdus);
        virtual ~Magazin();
    private:
       const int dimensiune;
       Produs** produse;
};
#endif // MAGAZIN_H
