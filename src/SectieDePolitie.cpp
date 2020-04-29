#include "SectieDePolitie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>
#include <stdlib.h>
using namespace std;

SectieDePolitie::SectieDePolitie()
{
    //ctor
}

SectieDePolitie::~SectieDePolitie()
{
    //dtor
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
    cout << "Introduceti numele agentului: ";
    cin >> nume;
    cout << "Introduceti codul agentului: ";
    while(!codPolitist)
    {
        try
        {
            codPolitist = getValidatedInput<int>();
        }
        catch (exception e)
        {
            e.what();
            cout << "Reintroduceti un numar: ";
            continue;
        }
        for (unsigned int i=0; i < vctPolitist.size(); i++)
        {
            if(vctPolitist[i].GetCodPolitist() == codPolitist)
            {
                cout << "Atentie! Acest cod deja exista, va rugam sa alegeti un alt cod: ";
                cin.clear();
                codPolitist = 0;
            }
        }
    }
    vctPolitist.push_back(Politist{nume, codPolitist});
    return Politist{nume, codPolitist};
}

void SectieDePolitie::StergePolitist()
{
    unsigned int codulAgentului = 0;
    bool gasit = false;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        if((elem.GetCodPolitist()) != 0)
        {
            cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
        }
    }
    cout << "Selectati numarul agentului de sters: ";
    while(codulAgentului <= 0) // bucla va continua pana ii voi da un input mai mare decat 0
    {
        try
        {
            codulAgentului = getValidatedInput<int>();
            if (codulAgentului <= 0)
            {
                cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
                cin.clear();
                continue; // ca sa nu imi accepte 0 sau valori negative, "continue" ma duce sus la while
            }
        }
        catch (exception e)
        {
            e.what();
            cout << "Reintroduceti un numar: ";
            continue;
        }
        //verific daca codul agentului este in vector
        for(auto it = vctPolitist.begin(); it != vctPolitist.end(); ++it)
        {
            if ((it->GetCodPolitist())== codulAgentului)
            {
                gasit = true; // exista politist cu acest cod
                break; // ies din bucla for
            }
        }
        if(gasit)
        {
            break; // inseamna ca e cod valid, ies din while
        }
        //daca nu il gaseste, printez mesajul si continui sa cer cod de la tastatura
        cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
        cin.clear();
        codulAgentului = 0; //resetez valoarea ca sa nu iasa din while
    }
    for(auto it = vctPolitist.begin(); it != vctPolitist.end(); ++it)
    {
        if(codulAgentului !=0)
        {
            if ((it->GetCodPolitist())== codulAgentului)
            {
                vctPolitist.erase(it);
                break;
            }
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
}

double valAmenda;
Contravenient SectieDePolitie::AdaugaAmenda()
{
    system ("cls");
    string nume;
    unsigned int codContravenient = 0;
    unsigned int codPolitist = 0;
    unsigned int varEnum;
    unsigned int i;
    Categorii valCateg;
    bool gasit = false;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        if((elem.GetCodPolitist()) != 0)
        {
            cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
        }
    }
    cout<< "Selectati codul agentului constatator: ";
    while(codPolitist <= 0)
    {
        try
        {
            codPolitist = getValidatedInput<int>();
            if (codPolitist <= 0)
            {
                cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
                cin.clear();
                continue;
            }
        }
        catch (exception e)
        {
            e.what();
            cout << "Reintroduceti un numar: ";
            continue;
        }
        for(auto it = vctPolitist.begin(); it != vctPolitist.end(); ++it)
        {
            if ((it->GetCodPolitist())== codPolitist)
            {
                gasit = true;
                break;
            }
        }
        if(gasit)
        {
            break;
        }
        cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
        cin.clear();
        codPolitist = 0;
    }
    if(codPolitist !=0)
    {
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
        while (!valAmenda)
        {
            try
            {
                valAmenda = getValidatedInput<int>();
            }
            catch (exception e)
            {
                e.what();
                cout << "Reintroduceti un numar: ";
                continue;
            }
            break;
        }
        //IF - daca numele nu a existat | daca numele a existat
        if (i == (vctContravenient.size()))
        {
            //cout << "NU A EXISTAT" << endl;
            cout << "Introduceti codul soferului: ";
            while (!codContravenient)
            {
                try
                {
                    codContravenient = getValidatedInput<int>();
                }
                catch (exception e)
                {
                    e.what();
                    cout << "Reintroduceti un numar: ";
                    continue;
                }
                break;
            }
            vctContravenient.push_back(Contravenient{nume, codContravenient});
        }
        system ("cls");
        cout << "1. bicicleta" <<endl;
        cout << "2. motoreta-motocicleta "<<endl;
        cout << "3. autoturism" << endl;
        cout << "4. camion" << endl;
        cout << "5. tractor "<< endl;
        cout << "0. revenire ecran anterior" << endl;
        cout << "Selectati categoria: ";
        cin >> varEnum;
        while (!varEnum)
        {
            try
            {
                varEnum = getValidatedInput<int>();
            }
            catch (exception e)
            {
                e.what();
                cout << "Reintroduceti un numar: ";
                continue;
            }
            break;
        }
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
                while (!varEnum)
                {
                    try
                    {
                        varEnum = getValidatedInput<int>();
                    }
                    catch (exception e)
                    {
                        e.what();
                        cout << "Reintroduceti un numar: ";
                        continue;
                    }
                    break;
                }
                while ((varEnum <0) || (varEnum > 5))
                {
                    cout << "Input invalid! Reintroduceti o cifra intre 0 si 5: ";
                    cin >>varEnum;
                    while (!varEnum)
                    {
                        try
                        {
                            varEnum = getValidatedInput<int>();
                        }
                        catch (exception e)
                        {
                            e.what();
                            cout << "Reintroduceti un numar: ";
                            continue;
                        }
                        break;
                    }
                }
                break;
                system ("pause");
            }
        }
    }
    system("cls");
    Amenzi{codPolitist, vctContravenient[i].GetCodContravenient(), valAmenda , valCateg};
    vctAmenzi.push_back(Amenzi{codPolitist, vctContravenient[i].GetCodContravenient(), valAmenda , valCateg});
    return Contravenient{nume, vctContravenient[i].GetCodContravenient()};
}

void SectieDePolitie::AfiseazaAmenziPolitist()
{
    unsigned int codulAgentului = 0;
    bool gasit = false;
    cout << "Codul si numele aferent fiecarui agent: " << endl;
    for(Politist elem : vctPolitist)
    {
        if((elem.GetCodPolitist()) != 0)
        {
        cout << elem.GetCodPolitist() <<". "<< elem.GetNumePolitist() <<endl;
        }
    }
    cout<<"Selectati codul agentului: ";
    while (codulAgentului <= 0)
    {
        try
        {
            codulAgentului = getValidatedInput<int>();
            if (codulAgentului <= 0)
            {
                cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
                cin.clear();
                continue;
            }
        }
        catch (exception e)
        {
            e.what();
            cout << "Reintroduceti un numar: ";
            continue;
        }
        for(auto it = vctPolitist.begin(); it != vctPolitist.end(); ++it)
        {
            if ((it->GetCodPolitist())== codulAgentului)
            {
                gasit = true;
                break;
            }
        }
        if(gasit)
        {
            break;
        }
        cout << "Atentie! A-ti ales alt cod. Va rugam sa alegeti un cod din lista afisata: ";
        cin.clear();
        codulAgentului = 0;
    }
    system("cls");
    double varTotal;
    if (codulAgentului !=0 )
    {
        system("cls");
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
}


void SectieDePolitie::AfiseazaAmenziContravenient()
{
    for(Contravenient elem : vctContravenient)
    {
        cout << elem.GetCodContravenient() <<". "<< elem.GetNumeContravenient() <<endl;
    }
    cout<<"Selectati contravenientul: ";
    unsigned int codulContravenientului;
    while (!codulContravenientului)
    {
        try
        {
            codulContravenientului = getValidatedInput<int>();
        }
        catch (exception e)
        {
            e.what();
            cout << "Reintroduceti un numar: ";
            continue;
        }
        for(unsigned int i = 0; i < vctContravenient.size(); i++)
        {
            if(vctContravenient[i].GetCodContravenient() != codulContravenientului)
            {
                cout << "Atentie! Va rugam sa reintroduceti un cod din lista afisata:";
                cin.clear();
                codulContravenientului = 0;
            }
        }
    }
    double varTotal;
    system("cls");
    for(Amenzi elemContr : vctAmenzi)
    {
        if ((elemContr.GetCodContrav()) == codulContravenientului)
        {
            for (Contravenient elem : vctContravenient)
            {
                if((elem.GetCodContravenient())==elemContr.GetCodContrav())
                {
                    cout << elem.GetCodContravenient() << ". " <<elem.GetNumeContravenient()<< " ";
                }
            }
            varTotal += (elemContr.GetAmenda());
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
        }
    }
    cout << "Totalul amenzilor luate de contravenientul selectat: " << varTotal<< endl;
    system ("pause");
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

    system ("pause");
}

void SectieDePolitie::ScriereInFisier()
{
    // i < vctPolitist.size()
    // Daca am de ex 10 elemente, indexul va porni de la 0 - 9.
    // In schimb size-ul este de 10.
    // Pentru a nu mai insera inca un rand dupa ultimul element voi pune conditia din if if(i != (vctPolitist.size()-1))
    // Asta inseamna ca i- ul ramane tot 9, iar size-ul din 10, va deveni tot 9.
    ofstream outFisAgenti("Agenti.txt");
    for (unsigned int i = 0; i < vctPolitist.size(); i++)
    {
        vctPolitist[i].ExportPolitist(outFisAgenti);
        if(i != (vctPolitist.size()-1))
        {
            outFisAgenti << endl;
        }
    }
    outFisAgenti.close();

    ofstream outFisContravenienti("Contravenienti.txt");
    for(unsigned int i = 0; i < vctContravenient.size();i++)
    {
        vctContravenient[i].ExportContravenient(outFisContravenienti);
        if(i != (vctContravenient.size()-1))
        {
            outFisContravenienti << endl;
        }
    }
    outFisContravenienti.close();

    ofstream outFisAmenzi("Amenzi.txt");
    for(unsigned int i = 0; i < vctAmenzi.size(); i++)
    {
        vctAmenzi[i].ExportAmenzi(outFisAmenzi);
        if(i != (vctAmenzi.size()-1))
        {
            outFisAmenzi << endl;
        }
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
    /*cout<<"Numarul total de linii este agenti: " << nrLinii<<endl;
    for (Politist elem: vctPolitist)
    {
        elem.ExportPolitist(cout);//ii dau obiect de tip ostream unde sa-si faca exportul
        cout << endl;
    }*/
    inFisAgenti.close();
    //system("pause");
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
    inFisContravenienti.close();
}

void SectieDePolitie::ImportAmenzi()
{
    ifstream inFisAmenzi;
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
        unsigned int categ;
        ss >> codPolitist >> codContravenient >> amenda >> categ;
        //varianta 1
        /*Categorii categorie;
        switch(categ)
        {
            case 1: {categorie = bicicleta; break;}
            case 2: {categorie = motoretaMotocicleta; break;}
            case 3: {categorie = autoturism; break;}
            case 4: {categorie = camion; break;}
            case 5: {categorie = tractor; break;}
        }*/
        //varianta 2
        Categorii categorie = static_cast<Categorii>(categ);

        Amenzi obTemp{codPolitist, codContravenient, amenda, categorie};
        vctAmenzi.push_back(obTemp);
        ++nrLinii;
    }
    inFisAmenzi.close();
}
