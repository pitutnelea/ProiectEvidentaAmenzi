#include "Amenzi.h"
#include "SectieDePolitie.h"
#include <stdlib.h>
#include <iostream>
#include <ios>  // Provides ios_base::failure
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

template <typename T>
T getValidatedInput()
{
    T result;
    cin >> result;
    if (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        throw ios_base::failure("Invalid input.");
    }
    return result;
}

int main()
{
    SectieDePolitie sectie;
    unsigned int nrintrodus = 1;

    sectie.CitireDinFisier();
    while (nrintrodus !=0)
    {
        Meniu();
        while (true)
        {
            try
            {
                nrintrodus = getValidatedInput<int>();
            }
            catch (exception e)
            {
                e.what();
                cout << "Reintroduceti un numar: ";
                continue;
            }
            break;
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
    //https://www.youtube.com/watch?v=ANS0WYCsIo8
    //MAXIMUL DINTRUN VECTOR
    //https://profs.info.uaic.ro/~infogim/2015/lectii/5/59.pdf
    //SORTED VECTOR
    //https://stackoverflow.com/questions/46712581/prevent-duplicate-entry-into-vector-c
    //https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
