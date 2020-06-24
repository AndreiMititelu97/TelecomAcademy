#include <iostream>
#include <string>
using namespace std;
struct Carte {
    int codIdentificare;
    string autor;
    string nume;
    int anPublicatie;
    bool imprumut;
};
struct Persoana {
    string numeClient;
    string autor;
    string nume;
    int anPublicatie;
};
void adaugaCarte(Carte* biblioteca[], int* dimensiune)
{	//Verificare daca capacitatea maxima a fost atinsa
    int locLiber = 0;
    for (int j = 0; j < *dimensiune; j++) {
        if (biblioteca[j] == NULL) {
            locLiber++;
        }
    }
    if (locLiber == 0) {
        cout << "Capacitatea maxima a fost atinsa" << endl;
        return;
    }
    //citire detalii carte
    int codIdentificare;
    string autor;
    string nume;
    int anPublicatie;

    cout << "Cod identificare: ";
    cin >> codIdentificare;
    cin.get();

    //verificare id deja utilizat
    for (int l = 0; l < *dimensiune; l++) {
        if (biblioteca[l] != NULL && biblioteca[l]->codIdentificare == codIdentificare) {
            cout << "ID deja utilizat" << endl;
            return;
        }
    }

    cout << "Autor: ";
    getline(cin, autor);

    cout << "Nume: ";
    getline(cin, nume);

    cout << "An publicatie: ";
    cin >> anPublicatie;

    //alocare memorie carte
    Carte* carteNoua = new Carte;
    carteNoua->codIdentificare = codIdentificare;
    carteNoua->autor = autor;
    carteNoua->nume = nume;
    carteNoua->anPublicatie = anPublicatie;
    //adaugare carte in biblioteca
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] == NULL) {
            biblioteca[i] = carteNoua;
            cout << "Cartea a fost adaugata\n";
            return; //incheie fuctia dupa primul loc liber gasit
        }
    }
}
void listareCarti(Carte* biblioteca[], int* dimensiune)
{	//parcurgerea intregului array
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] != NULL) {
            cout << biblioteca[i]->autor << " \"" << biblioteca[i]->nume << "\" " << biblioteca[i]->anPublicatie << " ID:" << biblioteca[i]->codIdentificare;
            cout << endl;
        }
    }
}
void eliminareCarte(Carte* biblioteca[], int* dimensiune, Persoana* clienti[])
{
    //citire id carte de eliminat
    int codIdentificare;
    cout << "Introduceti id-ul cartii: ";
    cin >> codIdentificare;
    //cautare carte cu id citit si eliminare carte
	//Cartea nu mai este vizibila in functia P
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] != NULL && biblioteca[i]->codIdentificare == codIdentificare) {
            delete biblioteca[i];
            delete clienti[i];
            clienti[i] = NULL;
            biblioteca[i] = NULL;
            cout << "Cartea a fost eliminata" << endl;
        }
    }
}
void imprumutCarte(Carte* biblioteca[], int* dimensiune, Persoana* clienti[])
{
	//citire id carte si nume client
    int codIdentificare;
    string numeClient;
    cout << "Cod identificare: ";
    cin >> codIdentificare;
    cin.get();
    cout << "Nume client: ";
    getline(cin, numeClient);
    Persoana* clientNou = new Persoana;
    clientNou->numeClient = numeClient;
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] != NULL && biblioteca[i]->codIdentificare == codIdentificare) {
            biblioteca[i]->imprumut = true;
            clientNou->autor = biblioteca[i]->autor;
            clientNou->nume = biblioteca[i]->nume;
            clientNou->anPublicatie = biblioteca[i]->anPublicatie;
            clienti[i] = clientNou;
            cout << "Cartea " << biblioteca[i]->autor << " \"" << biblioteca[i]->nume << "\" " << biblioteca[i]->anPublicatie << " a fost imprumutata de " << clientNou->numeClient;
            cout << endl;
            break;
        }
    }
}
void listareCarte(Carte* biblioteca[], int* dimensiune)
{
	//cititre id carte
    int codIdentificare;
    cout << "Cod identificare: ";
    cin >> codIdentificare;
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] != NULL && biblioteca[i]->codIdentificare == codIdentificare) {
            switch (biblioteca[i]->imprumut) {//verificare daca cartea a fost imprumutata  1-True  0-False
            case 1:
                cout << biblioteca[i]->autor << " \"" << biblioteca[i]->nume << "\" " << biblioteca[i]->anPublicatie << " -Este imprumutata";
                cout << endl;
                break;
            case 0:
                cout << biblioteca[i]->autor << " \"" << biblioteca[i]->nume << "\" " << biblioteca[i]->anPublicatie << " -Nu este imprumutata";
                cout << endl;
                break;
            }
        }
    }
}
void infoPersoana(int* dimensiune, Persoana* clienti[])
{	
	//citire nume persoana
    string numeClient;
    cout << "Nume client: ";
    cin >> numeClient;
    //afisare carti imprumutate
    for (int i = 0; i < *dimensiune; i++) {
        if (clienti[i] != NULL && clienti[i]->numeClient == numeClient) {
            cout << clienti[i]->autor << " \"" << clienti[i]->nume << "\" " << clienti[i]->anPublicatie << endl;
        }
    }
}
int main(void)
{
    int* dimensiune;
    dimensiune = new int;
    cout << "Dimensiune biblioteca: ";
    cin >> (*dimensiune);
    cout << endl;

    char op;
    Carte** biblioteca;
    biblioteca = new Carte*[(*dimensiune)];
    for (int i = 0; i < *dimensiune; i++) {
        biblioteca[i] = NULL;
    }

    Persoana** clienti;
    clienti = new Persoana*[(*dimensiune)];
    for (int j = 0; j < *dimensiune; j++) {
        clienti[j] = NULL;
    }
    do {
        cout << "----------------------------------------------" << endl;
        cout << "A-Adaugarea unei carti in biblioteca" << endl;
        cout << "L-Listarea tuturor cartilor din biblioteca" << endl;
        cout << "E-Eliminarea unei carti din biblioteca" << endl;
        cout << "I-Imprumutul unei carti catre o persoana" << endl;
        cout << "C-Listarea informatiilor despre o carte" << endl;
        cout << "P-Listarea informatiilor despre o persoana" << endl;
        cout << "X-Inchide Aplicatia" << endl;
        cout << "Introduceti codul operatiei: ";
        cin >> op;
        cout << endl;
        switch (op) {
        case 'a':
        case 'A':
            adaugaCarte(biblioteca, dimensiune);
            break;
        case 'l':
        case 'L':
            listareCarti(biblioteca, dimensiune);
            break;
        case 'e':
        case 'E':
            eliminareCarte(biblioteca, dimensiune,clienti);
            break;
        case 'i':
        case 'I':
            imprumutCarte(biblioteca, dimensiune, clienti);
            break;
        case 'c':
        case 'C':
            listareCarte(biblioteca, dimensiune);
            break;
        case 'p':
        case 'P':
            infoPersoana(dimensiune, clienti);
            break;
        case 'x':
            op = 'X';
        case 'X':
            cout << "Aplicatia se inchide" << endl;
            break;
        default:
            cout << "Optiune invalida" << endl;
            break;
        }
    } while (op != 'X');
    for (int i = 0; i < *dimensiune; i++) {
        if (biblioteca[i] != NULL) {
            delete biblioteca[i];
        }
    }
    for (int k = 0; k < *dimensiune; k++) {
        if (clienti[k] != NULL) {
            delete clienti[k];
        }
    }
    delete dimensiune;
    delete[] biblioteca;
    delete[] clienti;
    return 0;
}

