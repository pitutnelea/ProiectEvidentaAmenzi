#include "SectieDePolitie.h"
#include <string>
#include <iostream>
using namespace std;

SectieDePolitie::SectieDePolitie()
{
    //ctor
}

SectieDePolitie::~SectieDePolitie()
{
    //dtor
}

Politist SectieDePolitie::AdaugaPolitist()
{
    string nume;
    unsigned int codPolitist;
    if (vctPolitist.size()==0)
    {
        Politist{"AgentVirtual", 0};
        vctPolitist.push_back(Politist{"AgentVirtual", 0});
    }
    system ("cls");
    cout << "Introduceti numele politistului: "<< endl;
    cin >> nume;
    cout << "Introduceti codul politistului: "<< endl;
    cin >> codPolitist;
    vctPolitist.push_back(Politist{nume, codPolitist});

    return Politist{nume, codPolitist};
}

void SectieDePolitie::StergePolitist()
{
    cout << "Selectati numarul agentului de sters" <<endl;
}

Contravenient SectieDePolitie::AdaugaAmenda()
{
    system ("cls");
    string nume;
    cout << "Introduceti numele soferului: "<< endl;
    cin >> nume;
    unsigned int categorie;
    system ("cls");
    cout << "Selectati categoria: "<< endl;
    cout << "1. bicicleta" <<endl;
    cout << "2. motoreta-motocicleta "<<endl;
    cout << "3. autoturism" << endl;
    cout << "4. camion" << endl;
    cout << "5. tractor "<< endl;
    cout << "0. revenire ecran anterior" << endl;
    cin >> categorie;
    while ((categorie < 0)||(categorie >5))
    {
        cout << "Input invalid! Reintroduceti o cifra intr 0 si 5!"<<endl;break;
    }
    //return Contravenient{nume, codContravenient};//
}

/*void SectieDePolitie::StergeAmenda()
{
    cout << "Stergeti numele contravenientului:" <<endl;
}

void SectieDePolitie::AfiseazaAmenziPolitist()
{
    cout<<"Selectati codul politistului pentru a vedea toate toate amenzile date de acesta: "<<endl;
}

void SectieDePolitie::AfiseazaAmenziContravenient()
{
    cout<<"Selectati codul contravenientului pentru a vedea toate amenzile luate de acesta"<< endl;
}

void SectieDePolitie::AfisezaSituatieAmenzi()
{
    cout<< "Se afiseaza fiecare agent cu totalul amenzilor date: "<<endl;
}*/
