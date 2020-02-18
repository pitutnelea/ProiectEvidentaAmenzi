#include "SectieDePolitie.h"
#include "Amenzi.h"
#include <string>
#include <iostream>
using namespace std;
//#include <vector>
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

Contravenient SectieDePolitie::AdaugaAmenda()
{
    system ("cls");
    string nume;
    unsigned int codContravenient = 0;
    unsigned int codPolitist;
    unsigned int valAmenda;
    unsigned int categorie;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }
    cout<< "Selectati codul agentului constatator:";
    cin >> codPolitist;
    cout << "Introduceti numele soferului: "<< endl;
    cin >> nume;
    cout << "Introduceti cod contravenient: ";
    cin >> codContravenient;
    unsigned int i;

    //for-ul ma ajuta sa verific ca nu am 2 contravenienti cu aleasi nume
    for (i = 0; i < vctContravenient.size(); i++)
    {
        if (nume.compare(vctContravenient[i].GetNumeContravenient()) == 0)
        {
            break;
        }
    }

    if (i = vctContravenient.size())
    {
        vctContravenient.push_back(Contravenient{nume, codPolitist});
    }
    else if (i < vctContravenient.size())
    {
        vctContravenient.push_back(Contravenient{vctContravenient[i].GetNumeContravenient(), vctContravenient[i].GetCodContravenient()});
    }




    {
        cout << "Introduceti cod contravenient: ";
        cin << codContravenient;
    }


    //DUPA IF - obiectul deja exista. Fie l-a gasit, fie l-a creat. El exista si are un cod.
    //Am nevoie de codContravenient. Cum accesez acel obiect. Imi trebuie doar codul
    //Vreau sa recupereze codul acelui codContravenient.getCod.
    //vctParticipant [i]. GetCodContravenient()


    //citirea amenzii e dupa for
     if (i = dimensiunea vectorului vtc contr. size)//nu lam gasit > il adaug ///verfiica daca in urma parcurgeii un for
     //concluzia am de creat obiect nou?????daca a parcurs tot forul crwat obiect nou
    //si adaugat in lista de contravenienti ...cu sontr creez si dupa aia fac push back in vector.

    cout << "Introduceti codul soferului: "<< endl;
    cin >> codContravenient;
    while (!codContravenient)
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
    }
    vctContravenient.push_back(Contravenient{nume, codContravenient});
    Contravenient{nume, codContravenient};
    system ("cls");
    cout << "1. bicicleta" <<endl;
    cout << "2. motoreta-motocicleta "<<endl;
    cout << "3. autoturism" << endl;
    cout << "4. camion" << endl;
    cout << "5. tractor "<< endl;
    cout << "0. revenire ecran anterior" << endl;
    cout << "Selectati categoria: ";
    cin >> categorie;
    switch (categorie)
    {
        case 0: {break;}
        case 1: {}
        case 2: {}
        case 3: {}
        case 4: {}
        case 5: {}
        {
            cout << "Precizati valoarea amenzii: ";
            cin >>valAmenda;
            while (valAmenda < 0) {cin >>valAmenda;}
            system("cls");
            Amenzi(codPolitist, codContravenient, valAmenda);
            break;
        }
        default:
        {
            cout << "Input invalid! Reintroduceti o cifra intre 0 si 5: ";
            cin >> categorie;
            while ((categorie <0) || (categorie > 5))
            {
                cout << "Input invalid! Reintroduceti o cifra intre 0 si 5: ";
                cin >>categorie;
            }
            break;
            system ("pause");
        }
    }
return Contravenient{nume, codContravenient};
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
}
