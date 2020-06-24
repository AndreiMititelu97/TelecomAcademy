#include "Magazin.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
#include<iostream>
#include<string>
#include "Exceptions.h"
using namespace std;
Magazin::Magazin(const int& nrProduse) : dimensiune(nrProduse){
    produse = new Produs*[dimensiune];
    for(int i = 0;i < dimensiune;i++){
      produse[i]=NULL;
    }
}
Magazin::~Magazin(){
    for(int i = 0;i < dimensiune;i++){
        if(produse[i] != NULL){
            delete produse[i];
        }
    }
    delete[] produse;
}
Produs* Magazin::detaliiProdus(int idProdus){
    //Verificare id introdus corect
    if(idProdus < 0){
        throw IdInvalidException();
    }
    //Verificare daca capacitatea maxima a fost atinsa
    int locLiber = 0;
    for(int j=0;j<dimensiune;j++){
        if(produse[j] == NULL){
            locLiber++;
        }
    }
    if(locLiber == 0){
        throw MagazinPlinException();
    }

    char tip;
    string nume;
    double pret;

    int volum;
    char intreaba_congelator;
    bool areCongelator;

    int rotatiiPeMinut;
    string clasaEnergetica;

    cout<<"Tipul de produs (F - Frigider / M - Masina de spalat): ";
    cin>>tip;
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Pret: ";
    cin>>pret;


    if(tip == 'F'){
        cout<<"Volum frigider: ";
        cin>>volum;
        cout<<"Are congelator? Y/N ";
        cin>>intreaba_congelator;
        if(intreaba_congelator == 'Y'){
            areCongelator = true;
        }
        else
        {
            areCongelator = false;
        }
        cout<<endl;
        return new Frigider(idProdus,nume,pret,volum,areCongelator);
    }else if (tip == 'M'){
        cout<<"Rotatii pe minut: ";
        cin>>rotatiiPeMinut;
        cout<<"Clasa energetica: ";
        cin>>clasaEnergetica;
        cout<<endl;
        return new MasinaDeSpalat(idProdus,nume,pret,rotatiiPeMinut,clasaEnergetica);

    }
    return NULL;

}
void Magazin::adaugaProdus(Produs* produsDeAdaugat){
    //Verificare daca capacitatea maxima a fost atinsa
    int locLiber = 0;
    for(int j=0;j<dimensiune;j++){
        if(produse[j] == NULL){
            locLiber++;
        }
    }
    if(locLiber == 0){
        throw MagazinPlinException();
    }
    for(int i = 0 ;i<dimensiune;i++){
        if(produse[i] == NULL){
            produse[i] = produsDeAdaugat;
            cout<<"Produsul a fost adaugat"<<endl;
            return;
        }
    }
}
void Magazin::scrieProduse(){
    Frigider *fr;
    MasinaDeSpalat *ms;
    for(int i = 0;i<dimensiune;i++){
        if(produse[i] != NULL){
                cout<<"ID= "<<produse[i]->getId()<<endl;
                cout<<"Nume = "<<produse[i]->getNume()<<endl;
                cout<<"Pret = "<<produse[i]->getPret()<<endl;
            if((fr = dynamic_cast<Frigider*>(produse[i]))){
                cout<<"Volum = "<<fr->getVolum()<<endl;
                if(fr->getAreCongelator() == 1){
                    cout<<"Are congelator: DA"<<endl;
                }
                else{
                    cout<<"Are congelator: NU"<<endl;
                }
                cout<<endl;
            }
            else if((ms = dynamic_cast<MasinaDeSpalat*>(produse[i]))){
                cout<<"Rotatii pe minut = "<<ms->getRotatiiPeMinut()<<endl;
                cout<<"Clasa energetica = "<<ms->getClasaEnergetica()<<endl;
                cout<<endl;
            }
        }
    }
}
int Magazin::numaraMasiniDeSpalat(){
    int numarDeMasiniDeSpalat = 0;
    for(int i =0;i< dimensiune;i++){
        if(produse[i] !=NULL){
            if(dynamic_cast<MasinaDeSpalat*>(produse[i])){
                numarDeMasiniDeSpalat++;
            }
        }
    }
    return numarDeMasiniDeSpalat;
}
void Magazin::eliminaProdus(int idProdus){
    //Verificare id introdus corect
    if(idProdus < 0){
        throw IdInvalidException();
    }

    for(int i =0;i<dimensiune;i++){
        if(produse[i] != NULL && produse[i]->getId() == idProdus){
            cout<<"Produsul "<<produse[i]->getNume()<<" a fost eliminat"<<endl;
            delete produse[i];
            produse[i] = NULL;
            cout<<endl;
            return;
        }
    }
    throw ProdusInexistentException();
}
Produs* Magazin::cautaProdus(int idProdus){
    //Verificare id introdus corect
    if(idProdus < 0){
        throw IdInvalidException();
    }

    Frigider *fr;
    MasinaDeSpalat *ms;
    for(int i=0;i< dimensiune;i++){
        if(produse[i] !=NULL && produse[i]->getId() == idProdus){
            if((fr = dynamic_cast<Frigider*>(produse[i]))){
                return fr;
            }
            else if((ms = dynamic_cast<MasinaDeSpalat*>(produse[i]))){
                return ms;
            }
        }
    }
    throw ProdusInexistentException();
}
void Magazin::afisareDetaliiProdus(Produs* produs){
    Frigider *fr;
    MasinaDeSpalat *ms;
    cout<<"ID= "<<produs->getId()<<endl;
    cout<<"Nume = "<<produs->getNume()<<endl;
    cout<<"Pret = "<<produs->getPret()<<endl;
    if((fr = dynamic_cast<Frigider*>(produs))){
        cout<<"Volum = "<<fr->getVolum()<<endl;
        if(fr->getAreCongelator() == 1){
        cout<<"Are congelator: DA"<<endl;
        }
        else{
            cout<<"Are congelator: NU"<<endl;
        }
        cout<<endl;
    }else if((ms = dynamic_cast<MasinaDeSpalat*>(produs))){
        cout<<"Rotatii pe minut = "<<ms->getRotatiiPeMinut()<<endl;
        cout<<"Clasa energetica = "<<ms->getClasaEnergetica()<<endl;
        cout<<endl;
    }
}
void Magazin::operator<<(int idProdus){
    afisareDetaliiProdus(cautaProdus(idProdus));
}
