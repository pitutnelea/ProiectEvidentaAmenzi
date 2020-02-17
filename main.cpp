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
        }

    }

    return 0;
}

/*
void MeniuSecundar()
{
    cout<<"Alegeti optiunea dorita:"<<endl;
    cout<< "1. Adauga politist" <<endl;
    cout<< "2. Sterge politist"<<endl;
    cout<< "3. Adauga contravenient" <<endl;
    cout<< "4. Afiseaza amenzi politist"<<endl;
    cout<< "5. Afiseaza amenzi contravenient" <<endl;
    cout<< "6. Afiseaza situatie amenzi" <<endl;
    cout<< "7. Revenire la ecranul anterior"<<endl;
    cout<< "0. Iesire" <<endl;
}

Politist AdaugaPolitist()
{
    system ("cls");
    cout << "Introduceti numele politistului: "<< endl;
    string nume;
    cin >> nume;
    cout << "Introduceti codul politistului: "<< endl;
    unsigned int codPolitist;
    cin >> codPolitist;
    Politist{nume, codPolitist};
    //Politist *pntPolitist = new Politist{nume, codPolitist};

    return Politist{nume, codPolitist};
}

Contravenient AdaugaContravenient()
{
    system ("cls");
    cout<<"Introduceti numele contravenientului: "<< endl;
    string nume;
    cin >> nume;
    cout << "Introduceti codul contravenientului:" << endl;
    unsigned int codContravenient;
    cin >> codContravenient;

    return Contravenient{nume, codContravenient};;
}*/



/*vector <Politist> pntPolitist;
    Meniu();
    unsigned int nrintrodus = 1;
    while (nrintrodus !=0)
    {
        cin >>nrintrodus;
        if (nrintrodus == 1)
        {
            system ("cls");
            pntPolitist.push_back(AdaugaPolitist());
            system ("cls");
            MeniuSecundar();
            unsigned int j;
            cin >> j;
            if (j == 7) {Meniu();}
        }
        if (nrintrodus == 2)
        {
            system ("cls");
            for (Politist *elem : pntPolitist)
            {
                cout<< elem << endl;
            }
            cout << "Selectati numarul agentului de sters"<<endl;
            unsigned int j;
            cin >> j;
        }
        if (nrintrodus == 3)
        {

        }

        while (nrintrodus > 6)
        {
            cout<< "Numarul introdus trebuie sa fie intre 0 si 6! Reintroduceti numarul: "<<endl;break;
        }
    }



    //1 vector Politist (are din oficiu un agent virtual, agentul virtual nu il afisez)
    //1 vector Contravenient (e din start pe "0".)
    */
