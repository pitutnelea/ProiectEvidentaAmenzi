#include "Amenzi.h"
#include "SectieDePolitie.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

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
}

int main()
{
    SectieDePolitie sectie;
    unsigned int nrintrodus = 1;

    while (nrintrodus !=0)
    {
        Meniu();
        cin >> nrintrodus;

        switch (nrintrodus)
        {
            case 0:
            {
                system ("cls");
                ofstream myfile; //myfile is an object wich allows me to create or to display files from my computer
                myfile.open("agenti.txt"); // to open the file from my computer, or to create it and open
                myfile << "The content of the file.\n"; // add some words to the file
                myfile.close(); // i close the file, to avoid memory leaks.
                system ("pause");
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
            default:
            {
                system ("cls");
                cout<< "Numarul introdus trebuie sa fie intre 0 si 6! Reintroduceti numarul"<<endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
