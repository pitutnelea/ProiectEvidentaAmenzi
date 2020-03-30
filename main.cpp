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

#include <ios>  // Provides ios_base::failure
#include <iostream>  // Provides cin

template <typename T>
T getValidatedInput()
{
    // Get input of type T
    T result;
    cin >> result;

    // Check if the failbit has been set, meaning the beginning of the input
    // was not type T. Also make sure the result is the only thing in the input
    // stream, otherwise things like 2b would be a valid int.
    if (cin.fail() || cin.get() != '\n')
    {
        // Set the error state flag back to goodbit. If you need to get the input
        // again (e.g. this is in a while loop), this is essential. Otherwise, the
        // failbit will stay set.
        cin.clear();

        // Clear the input stream using and empty while loop.
        while (cin.get() != '\n');

        // Throw an exception. Allows the caller to handle it any way you see fit
        // (exit, ask for input again, etc.)
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
        //https://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
        while (true)
        {
            cout << "Introduceti un numar: ";
            try
            {
                nrintrodus = getValidatedInput<int>();
            }
            catch (exception e)
            {
                cerr << e.what() << endl;
                continue;
            }
        break;
        }
        //cout << "You entered: " << nrintrodus << endl;
        //return EXIT_SUCCESS;

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
    //MAXIMUL DINTRUN VECTOR
    //https://profs.info.uaic.ro/~infogim/2015/lectii/5/59.pdf


/*    Meniu();
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
        }*/


/*
        Meniu();
        //validez inputul sa nu fie alfabetic sau cu caractere speciale
        bool retFct = false;
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
            while(!retFct)
            {
                try
                {
                    retFct = Validare();
                    if (!retFct)
                    {
                        cout << "Nu a-ti introdus un numar! Mai introduceti o data:" << endl;
                        cin >> nrintrodus;
                    }
                }
                catch(const char* ex)
                {
                    cout << ex << endl;
                    cin.clear();
                    cin.ignore(10, '\n');
                }
            }
        }
*/
