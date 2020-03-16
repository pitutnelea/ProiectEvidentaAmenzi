#include "SectieDePolitie.h"
#include <iostream>
using namespace std;
#include <fstream>


#include <string>
//#include <strstream>
#include <sstream>


//#include <algorithm>
//#include <cmath>
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
    cout << "Introduceti numele politistului: ";
    cin >> nume;
    //https://stackoverflow.com/questions/13440831/how-do-i-check-if-input-is-an-integer-string
    /*if (any_of(nume.begin(), nume.end(),isdigit))
    {
        cout << "No digits allowed in name\n";
    }*/

    cout << "Introduceti codul politistului: ";
    //validez inputul sa nu fie alfabetic sau cu caractere speciale
    while (!(cin >> codPolitist))
    {
        cout << "Atentie! Trebuie sa reintroduceti un numar: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    //validez inputul sa nu mai existe un politist cu acest cod
    for(Politist elem : vctPolitist)
    {
        while ((elem.GetCodPolitist()) == codPolitist)
        {
            cout << "Atentie! Acest cod deja exista, va rugam sa alegeti un alt cod: ";
            while (!(cin >> codPolitist))
            {
                cout << "Atentie! Trebuie sa reintroduceti un numar: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }
    }

    vctPolitist.push_back(Politist{nume, codPolitist});
    return Politist{nume, codPolitist};
}

void SectieDePolitie::StergePolitist()
{
    unsigned int codulAgentului;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
    }
    cout << "Selectati numarul agentului de sters: ";
    cin >> codulAgentului;
    for(auto it = vctPolitist.begin(); it != vctPolitist.end(); ++it)
    {
        if ((it->GetCodPolitist())== codulAgentului)
        {
            vctPolitist.erase(it);
            break;
        }
    }
    //prin referinta se modifica originalul
    for(Amenzi &elemPol : vctAmenzi)
    {
        if ((elemPol.GetCodPolitist()) == codulAgentului)
        {
            elemPol.SetCodPolitist(0);
        }
    }

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
    system("cls");
    double varTotal;
    for(Amenzi elemPol : vctAmenzi)
    {
        if ((elemPol.GetCodPolitist()) == codulAgentului)
        {
            for(Contravenient elemContr : vctContravenient)
            {
                if((elemContr.GetCodContravenient())== elemPol.GetCodContrav())
                {
                    cout << elemContr.GetCodContravenient()<<". "<< elemContr.GetNumeContravenient() << " ";
                }
            }
            cout << elemPol.GetAmenda()<<endl;
            varTotal += (elemPol.GetAmenda());
        }
    }
    cout << "Totalul amenzilor date de agentul selectat: " << varTotal<< endl;
    system ("pause");
}

void SectieDePolitie::AfiseazaAmenziContravenient()
{
    for(Contravenient elem : vctContravenient)
    {
        cout << elem.GetCodContravenient() <<". "<< elem.GetNumeContravenient() <<endl;
    }
    cout<<"Selectati codul contravenientului: ";
    unsigned int codulContravenientului;
    cin >> codulContravenientului;
    double varTotal;
    system("cls");
    for (Contravenient elem : vctContravenient)
    {
        if ((elem.GetCodContravenient()) == codulContravenientului)
        {
            cout << elem.GetCodContravenient()<<". "<< elem.GetNumeContravenient() << " "<<endl;
            for (Amenzi elemContr : vctAmenzi)
            {
                cout << elemContr.GetAmenda() << " (" ;
                switch (elemContr.GetCategorie())
                {
                    case 1: {cout << "bicicleta";  break;}
                    case 2: {cout << "motoretaMotocicleta"; break;}
                    case 3: {cout << "autoturism"; break;}
                    case 4: {cout << "camion"; break;}
                    case 5: {cout << "tractor"; break;}
                }
                cout<< ") "<<endl;
                varTotal += (elemContr.GetAmenda());
            }
        }
    cout << "Totalul amenzilor luate de contravenientul selectat: " << varTotal<< endl;
    system ("pause");
    }
}


void SectieDePolitie::AfiseazaSituatieAmenzi()
{
    double varTotal;
    for(Politist elem : vctPolitist)
    {
        double varPartial = 0;
        for(Amenzi elemPol : vctAmenzi)
        {
            if ((elemPol.GetCodPolitist())== (elem.GetCodPolitist()))
            {
                varPartial += (elemPol.GetAmenda());
                Amenzi{elemPol.GetAmenda()};
                vctSituatieAmenzi.push_back(Amenzi{elemPol.GetAmenda()});
            }
        }
        cout << elem.GetCodPolitist() <<". " << elem.GetNumePolitist()<< " "<<varPartial<<endl;
        varTotal += varPartial;
    }
    cout << "Totalul amenzilor date de toti agentii: " << varTotal<< endl;


    /*for(Amenzi elem : vctSituatieAmenzi)
    {
        cout << elem.GetAmenda() <<endl;
    }*/

    system ("pause");


//Înțeleg de ce ai pus elemente de tip Amenzi în vector
//Că așa ai și codul polițistului nu doar totalul amenzilor?
/*
    for(const auto &i: vctSituatieAmenzi)
        cout << i <<endl;
        sort(vctSituatieAmenzi.begin(), vctSituatieAmenzi.end());
    for (const auto &i: vctSituatieAmenzi)
        cout << i << ' '<<endl;
    // Sort the vector in descending order
    sort(vctSituatieAmenzi.begin(), vctSituatieAmenzi.end(), wayToSort);
    for (int i = 0; i < vctSituatieAmenzi.size(); i++)
    {
*/
}

void SectieDePolitie::ScriereInFisier()
{
    ofstream outFisAgenti("Agenti.txt");
    for (unsigned int i= 0; i < vctPolitist.size(); i++)
    {
        vctPolitist[i].ExportPolitist(outFisAgenti);
        if(!vctPolitist.size())
        {
            outFisAgenti << endl;
        }
    }

    outFisAgenti.close();

    ofstream outFisContravenienti("Contravenienti.txt");
    for(Contravenient elemCtr: vctContravenient)
    {
        elemCtr.ExportContravenient(outFisContravenienti);
        outFisContravenienti << endl;
    }
    outFisContravenienti.close();

    ofstream outFisAmenzi("Amenzi.txt");
    for(Amenzi elemAm: vctAmenzi)
    {
        elemAm.ExportAmenzi(outFisAmenzi);
        outFisAmenzi << endl;
    }
    outFisAmenzi.close();
    system("pause");
}

void SectieDePolitie::CitireDinFisier()
{
    ImportAgenti();
    ImportContravenienti();
    ImportAmenzi();
}

void SectieDePolitie::ImportAgenti()
{
    //leg ifstreamul de fisier
    ifstream inFisAgenti;
    inFisAgenti.open("Agenti.txt");

    //parcurg fiecare linie din fisier. O linie inseamna un obiect. Alta linie alt obiect, trebuie sa recuperez linie cu linie
    unsigned short nrLinii = 0;
    while(!inFisAgenti.eof())
    {
        char buff[20];
        inFisAgenti.getline(buff,20); // citesc ca sa treaca cursorul la ultimul rand, buff e ultima linie citita
        stringstream ss;
        ss << buff; // inserez bufferul in stringstreamul ss
        unsigned int codPolitist;
        string numePolitist;
        ss >> codPolitist >> numePolitist;
        Politist obTemp{numePolitist, codPolitist};
        vctPolitist.push_back(obTemp);
        ++nrLinii;
    }
    cout<<"Numarul total de linii este agenti: " << nrLinii<<endl;

    for (Politist elem: vctPolitist)
    {
        elem.ExportPolitist(cout);//ii dau obiect de tip ostream unde sa-si faca exportul
        cout << endl;
    }
    inFisAgenti.close();
    system("pause");
}

void SectieDePolitie::ImportContravenienti()
{
    ifstream inFisContravenienti;
    inFisContravenienti.open("Contravenienti.txt");

    unsigned short nrLinii = 0;
    while(!inFisContravenienti.eof())
    {
        char buff[20];
        inFisContravenienti.getline(buff,20);
        stringstream ss;
        ss << buff;
        unsigned int codContravenient;
        string numeContravenient;
        ss >> codContravenient >> numeContravenient;
        Contravenient obTemp{numeContravenient, codContravenient};
        vctContravenient.push_back(obTemp);
        ++nrLinii;
    }
    cout<<"Numarul total de linii contravenienti este: " << nrLinii<<endl;

    for (Contravenient elem: vctContravenient)
    {
        elem.ExportContravenient(cout);
        cout << endl;
    }
    inFisContravenienti.close();
    system("pause");
}

void SectieDePolitie::ImportAmenzi()
{
    /*ifstream inFisAmenzi;
    inFisAmenzi.open("Amenzi.txt");
    unsigned short nrLinii = 0;
    while(!inFisAmenzi.eof())
    {
        char buff[20];
        inFisAmenzi.getline(buff,20);
        stringstream ss;
        ss << buff;
        unsigned int codPolitist, codContravenient;
        double amenda;
        Categorii categorie;
        ss >> codPolitist >> codContravenient >> amenda >> categorie;
        Amenzi obTemp{codPolitist, codContravenient, amenda, categorie};
        vctAmenzi.push_back(obTemp);
        ++nrLinii;
    }
    cout<<"Numarul total de linii amenzi este: " << nrLinii<<endl;
    for (Amenzi elem: vctAmenzi)
    {
        elem.ExportAmenzi(cout);
        cout << endl;
    }
    inFisAmenzi.close();
    system("pause"); */
}
