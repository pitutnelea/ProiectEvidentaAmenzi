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



/*void SectieDePolitie::AfiseazaSituatieAmenzi()
{
    for (Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist();
        for(Amenzi elemPol : vctAmenzi)
        {
            cout<<" "<<(elemPol.GetAmenda())<< " ;";
        }
        cout << " " <<endl;
    }
    double varTotal;
    for(Amenzi elemPol : vctAmenzi)
    {
        varTotal += (elemPol.GetAmenda());
    }
    cout << "Totalul amenzilor date de toti agentii: " << varTotal<< endl;
    system ("pause");


}*/
