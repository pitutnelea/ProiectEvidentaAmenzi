#include "Amenzi.h"
#include "SectieDePolitie.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


void Meniu()
{
    system ("cls");
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<< "1. Adauga politist" <<endl;
    cout<< "2. Sterge politist"<<endl;
    cout<< "3. Adauga amenda" <<endl;
    cout<< "4. Afiseaza amenzi politist"<<endl;
    cout<< "5. Afiseaza amenzi contravenient" <<endl;
    cout<< "6. Afiseaza situatie amenzi" <<endl;
    cout<< "0. Iesire" <<endl;
    cout << "Trebuie sa introduceti un numar intre 0 si 6: ";
}

int main()
{
    SectieDePolitie sectie;
    unsigned int nrintrodus = 1;

    sectie.CitireDinFisier();
    while (nrintrodus !=0)
    {
        Meniu();
        //validez inputul sa nu fie alfabetic sau cu caractere speciale
        while (!(cin >> nrintrodus))
        {
            cout << "Atentie! Trebuie sa reintroduceti un numar intre 0 si 6: ";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            //validez inputul sa nu fie mai mare decat 6
            while(nrintrodus > 6)
            {
                cout << "Atentie! Trebuie sa reintroduceti un numar intre 0 si 6: ";
                cin >> nrintrodus;
            }
        }
        switch (nrintrodus)
        {
            case 0:
            {
                system ("cls");
                sectie.ScriereInFisier();
                break;
            }
            case 1:
            {
                system ("cls");
                sectie.AdaugaPolitist();
                break;
            }
            case 2:
            {
                system ("cls");
                sectie.StergePolitist();
                break;
            }
            case 3:
            {
                system ("cls");
                sectie.AdaugaAmenda();
                break;
            }
            case 4:
            {
                system("cls");
                sectie.AfiseazaAmenziPolitist();
                break;
            }
            case 5:
            {
                system("cls");
                sectie.AfiseazaAmenziContravenient();
                break;
            }
            case 6:
            {
                system("cls");
                sectie.AfiseazaSituatieAmenzi();
                break;
            }
        }
    }
    return 0;
}
