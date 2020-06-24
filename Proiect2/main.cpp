#include <iostream>
#include "Produs.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
#include "Magazin.h"
#include "Exceptions.h"
using namespace std;
int main()
{
    int * dimensiune;
    dimensiune = new int;
    cout<<"Dimensiune magazin: ";
    cin>> (*dimensiune);
    try{
        if(*dimensiune <= 0){
            throw DimensiuneInvalidaException();
        }
    }catch(DimensiuneInvalidaException& ex){
        cout<<"Dimensiunea introdusa este invalida"<<endl;
        return 0;
    }
    cout<<endl;
    char op;
    Magazin* shop;
    shop = new Magazin(*dimensiune);
    int id ;
    do{
        cout<<"----------------------------------"<<endl;
        cout<<"A - Adauga produs"<<endl;
        cout<<"E - Elimina produs"<<endl;
        cout<<"C - Cauta produs"<<endl;
        cout<<"N - Numara masini de spalat"<<endl;
        cout<<"L - Scrie toate produsele"<<endl;
        cout<<"Q - Inchide aplicatia"<<endl;
        cout<<"Introduceti codul operatiei: ";
        cin>>op;
        cout<<"----------------------------------"<<endl;
        switch(op){
            case 'a':
            case 'A':
                try{
                    cout<<"Introduceti un id: ";
                    cin>>id;
                    shop->adaugaProdus(shop->detaliiProdus(id));
                }catch(MagazinPlinException& ex){
                    cout<<"Capacitatea maxima a fost atinsa"<<endl;
                }catch(IdInvalidException&ex){
                    cout<<"ID-ul nu poate fi negativ"<<endl;
                }
                break;
            case 'e':
            case 'E':
                try{
                    cout<<"Introduceti un id: ";
                    cin>>id;
                    shop->eliminaProdus(id);
                }
                catch(ProdusInexistentException& ex){
                    cout<<"Produsul nu exista"<<endl;
                }
                catch(IdInvalidException& ex){
                    cout<<"ID-ul nu poate fi negativ"<<endl;
                    }
                break;
            case 'c':
            case 'C':
                try{
                    cout<<"Introduceti un id: ";
                    cin>>id;
                    shop->afisareDetaliiProdus(shop->cautaProdus(id));
                }
                catch(ProdusInexistentException&ex){
                    cout<<"Produsul nu exista"<<endl;
                }
                catch(IdInvalidException& ex){
                    cout<<"ID-ul nu poate fi negativ"<<endl;
                    }
                break;
            case 'n':
            case 'N':
                cout<<"Numar masini de spalat = "<<shop->numaraMasiniDeSpalat()<<endl;
                break;
            case 'l':
            case 'L':
                shop->scrieProduse();
                break;
            case 'q':
                op = 'Q';
            case 'Q':
                cout<<"Aplicatia se inchide"<<endl;
                break;
            default:
                cout<<"Optiune invalida"<<endl;
                break;
        }
    }while(op != 'Q');
    delete shop;
    delete dimensiune;
    return 0;
}
