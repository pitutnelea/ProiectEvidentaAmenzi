#include "SectieDePolitie.h"
#include <string>
#include <iostream>
using namespace std;
#include <vector>
//#include <sstream>
//#include <algorithm>
//#include <cctype>

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
    //https://stackoverflow.com/questions/13440831/how-do-i-check-if-input-is-an-integer-string
    /*if (any_of(nume.begin(), nume.end(),isdigit))
    {
        cout << "No digits allowed in name\n";
    }*/

    cout << "Introduceti codul politistului: "<< endl;
    cin >> codPolitist;
    while (!codPolitist)
    {
        cout << "Cod invalid! Reintroduceti un cod in afara de: ";
        for (Politist elem : vctPolitist)
        {
            cout << elem.GetCodPolitist();
            cout << ", ";
        }
        cout << " " <<endl;
        cout << "Reintroduceti codul: ";
        cin >> codPolitist;
    }
    vctPolitist.push_back(Politist{nume, codPolitist});
    return Politist{nume, codPolitist};
}

Politist SectieDePolitie::StergePolitist()
{
    unsigned int codulAgentului;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }
    cout << "Selectati numarul agentului de sters: ";
    cin >> codulAgentului;
    vctPolitist.erase(vctPolitist.begin() + codulAgentului);


    /*for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }*/

    system("pause");
}
double valAmenda;
Contravenient SectieDePolitie::AdaugaAmenda()
{
    system ("cls");
    string nume;
    unsigned int codContravenient = 0;
    unsigned int codPolitist;

    unsigned int varEnum;
    unsigned int i;
    Categorii valCateg;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }
    cout<< "Selectati codul agentului constatator:";
    cin >> codPolitist;
    cout << "Introduceti numele soferului: ";
    cin >> nume;

    //for-ul ma ajuta sa verific ca nu am 2 contravenienti cu aleasi nume
    for (i = 0; i < vctContravenient.size(); i++)
    {
        if (nume.compare(vctContravenient[i].GetNumeContravenient()) == 0)
        {
            break;
        }
    }

    cout << "Precizati valoarea amenzii: ";
    cin >>valAmenda;

    //IF - daca numele nu a existat | daca numele a existat
    if (i == (vctContravenient.size()))
    {
        cout << "NU A EXISTAT" << endl;
        cout << "Introduceti codul soferului: ";
        cin >> codContravenient;
        vctContravenient.push_back(Contravenient{nume, codContravenient});
    }
    /*while (codContravenient)
    {
        cout << "Cod invalid! Reintroduceti un cod in afara de: 0, ";
        for (Contravenient elem : vctContravenient)
        {
            cout << elem.GetCodContravenient();
            cout << ", ";
        }
        cout << " " <<endl;
        cout << "Reintroduceti codul: ";
        cin >> codContravenient;
    }*/
    system ("cls");
    cout << "1. bicicleta" <<endl;
    cout << "2. motoreta-motocicleta "<<endl;
    cout << "3. autoturism" << endl;
    cout << "4. camion" << endl;
    cout << "5. tractor "<< endl;
    cout << "0. revenire ecran anterior" << endl;
    cout << "Selectati categoria: ";
    cin >> varEnum;
    switch (varEnum)
    {
        //sa determin ce categorie este si dupa switch sa creez amenda.
        //declar var enum inainte de switch ca si tipul de enum
        case 0: {break;}
        case 1: {valCateg = bicicleta;  break;}
        case 2: {valCateg = motoretaMotocicleta; break;}
        case 3: {valCateg = autoturism; break;}
        case 4: {valCateg = camion; break;}
        case 5: {valCateg = tractor; break;}
        default:
        {
            cout << "Input invalid! Reintroduceti o cifra intre 0 si 5: ";
            cin >> varEnum;
            while ((varEnum <0) || (varEnum > 5))
            {
                cout << "Input invalid! Reintroduceti o cifra intre 0 si 5: ";
                cin >>varEnum;
            }
            break;
            system ("pause");
        }
    }
    system("cls");
    Amenzi{codPolitist, vctContravenient[i].GetCodContravenient(), valAmenda , valCateg};
    vctAmenzi.push_back(Amenzi{codPolitist, vctContravenient[i].GetCodContravenient(), valAmenda , valCateg});
    return Contravenient{nume, vctContravenient[i].GetCodContravenient()};
}

void SectieDePolitie::AfiseazaAmenziPolitist()
{
    unsigned int codulAgentului;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }
    cout<<"Selectati codul politistului pentru a vedea toate toate amenzile date de acesta: "<<endl;
    cin >> codulAgentului;
    for (Contravenient elem : vctContravenient)
    {
        cout << elem.GetCodContravenient() << " "<<elem.GetNumeContravenient()<< " ";
        for(Amenzi elem : vctAmenzi)
        {
            if ((elem.GetCodPolitist()) == codulAgentului)
            {
                cout << elem.GetAmenda()<<endl;break;
            }

        }
    }
    system ("pause");
}

void SectieDePolitie::AfiseazaAmenziContravenient()
{
    cout<<"Selectati codul contravenientului pentru a vedea toate amenzile luate de acesta"<< endl;
}

void SectieDePolitie::AfisezaSituatieAmenzi()
{
    cout<< "Se afiseaza fiecare agent cu totalul amenzilor date: "<<endl;
}
