#include "ClasaHelp.h"
#include <iostream>
using namespace std;

ClasaHelp::ClasaHelp()
{
    //ctor
}

ClasaHelp::~ClasaHelp()
{
    //dtor
}

/*void ClasaHelp::AdaugaPolitist()
{
    cout << "Introduceti numele politistului: "<<endl;
}*/

void ClasaHelp::StergePolitist()
{
    cout << "Introduceti numele politistului pe care doriti sa il stergeti:" <<endl;
}

void ClasaHelp::AdaugaContravenient()
{
    cout <<"Introduceti numele contravenientului: "<<endl;
}

void ClasaHelp::StergeContravenient()
{
    cout << "Stergeti numele contravenientului:" <<endl;
}

void ClasaHelp::AfiseazaAmenziPolitist()
{
    cout<<"Selectati codul politistului pentru a vedea toate toate amenzile date de acesta: "<<endl;
}

void ClasaHelp::AfiseazaAmenziContravenient()
{
    cout<<"Selectati codul contravenientului pentru a vedea toate amenzile luate de acesta"<< endl;
}

void ClasaHelp::AfisezaSituatieAmenzi()
{
    cout<< "Se afiseaza fiecare agent cu totalul amenzilor date: "<<endl;
}
