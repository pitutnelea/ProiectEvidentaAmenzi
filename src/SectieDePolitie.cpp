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

/*void SectieDePolitie::StergePolitist()
{
    cout << "Introduceti numele politistului pe care doriti sa il stergeti:" <<endl;
}

void SectieDePolitie::AdaugaAmenda()
{
    cout <<"Introduceti numele contravenientului: "<<endl;
}

void SectieDePolitie::StergeAmenda()
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
