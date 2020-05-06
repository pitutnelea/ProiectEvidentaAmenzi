#include "Amenzi.h"
#include "SectieDePolitie.h"
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

int main()
{
    SectieDePolitie sectie;
    unsigned int nrintrodus = 1;

    sectie.CitireDinFisier();
    while (nrintrodus !=0)
    {
        Meniu();
        while(true)
        {
            try
            {
                nrintrodus = getValidatedInput<int>();
                if((nrintrodus < 0) || (nrintrodus > 6))
                {
                    cout << "Atentie! Trebuie sa introduceti un numar din lista afisata: ";
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
            break;
        }

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

/*
CERINTA
Scrieți un program care să permită ținerea evidenței amenzilor de circulație într-o secție de
poliție. În acest scop programul va trebui să ofere următoarele funcționalități:
1. sa afișeze în consolă un meniu de pornire, unde să enumere, opțiunile de utilizare pe care le are
utilizatorul
    • opțiunile sunt: „Adaugă agent”, „Șterge agent”, „Adaugă contravenient”, „Afișează amenzi
agent”, „Afișează amenzi contravenient”, „Afișează situație amenzi” și „Ieșire”
2. să permită utilizatorului să introducă opțiunea dorită, să valideze inputul și să îl ceară din nou
dacă inputul nu e valid (adică să corespundă uneia dintre opțiuni)
3. dacă inputul e valid să șteargă ecranul și să lanseze în execuție codul corespunzător acelei
opțiuni, afisând un nou text, cu detalii despre opțiunea selectată.
4. indiferent de opțiunea selectată, noul meniu care se afișează să aibă și opțiunea „Revenire la
ecranul anterior”. Dacă utilizatorul o selectează programul să reafișeze meniul principal.
5. la selectarea opțiunii „Adaugă agent”
    • să afișeze textul: „Introduceți numele agentului”
    • să permită utilizatorului să introducă numele.
    • să îi atribuie un cod unic.
6. la selectarea opțiunii „Șterge agent”
    • să afișeze agenții deja definiți și codurile lor, după care să afișeze textul: „Selectați numărul
agentului de șters”. Să permită utilizatorului să introducă codul agentului
    • să valideze inputul și să îl ceară din nou dacă inputul nu corespunde codului din dreptul unui
agent
    • dacă inputul e valid să șteargă din evidență agentul selectat. Să păstreze însă amenzile
acordate de acesta, mutându-le în contul unui agent virtual, care păstrează evidența
amenzilor date de agenții ce au părăsit slujba.
7. la selectarea opțiunii „Adaugă contravenient”
    • să afișeze textul: „Introduceți numele șoferului”
    • să permită utilizatorului să introducă numele.
    • în continuare să afișeze „Selectați categoria:
        1.bicicletă
        2.motoreta-motocicletă
        3.autoturism
        4.camion
        5.tractor
        0.revenire ecran anterior
    • să permită utilizatorului să introducă o opțiune, să valideze inputul și să îl ceară din nou
dacă nu e numeric și cuprins între 0 și 5
    • dacă inputul e valid să afișeze în continuare „Precizati valoarea amenzii”
    • să permită utilizatorului să o introducă, să valideze inputul și să îl ceară din nou dacă nu e
numeric și pozitiv
    • dacă inputul e valid să șteargă ecranul și să afișeze „Selectați agentul constatator” urmat de
lista agenților existenți și a codurilor lor.
    • să permită utilizatorului să introducă codul corespunzător agentului, să valideze inputul și
să îl ceară din nou dacă inputul nu corespunde codului unui agent.
    • să verifice dacă contravenientul a mai fost amendat în trecut
    ◦ dacă da, să adauge noua amendă la total amenzi contravenient
    ◦ dacă nu, să adauge contravenientul în lista contravenienților
8. la selectarea opțiunii „Afișează amenzi agent”
    ◦ să afișeze agenții existenți, după care să afișeze textul: „Selectați codul agentului”
    ◦ să permită utilizatorului să introducă codul agentului, să valideze inputul și să îl ceară din
nou dacă inputul nu corespunde codului unui agent.
    ◦ dacă inputul e valid să afișeze toți contravenienții amendați de el, cu sumele încasate de la ei
ca și totalul amenzilor date de acel agent
9. la selectarea opțiunii „Afișează amenzi contravenient”
    ◦ să afișeze contravenienții existenți, după care să afișeze textul: „Selectați contravenientul”
    ◦ să permită utilizatorului să introducă contravenientul, să valideze inputul și să îl ceară din
nou dacă inputul nu corespunde unui contravenient.
    ◦ dacă inputul e valid să afișeze toate amenzile luate de contravenient, precizând la fiecare
categoria din care face parte, ca și totalul amenzilor primite de acel contravenient.
10. la selectarea opțiunii „Afișează situație amenzi”
    ◦ să afișeze fiecare agent și totalul amenzilor sale, ordonați de la cel cu ce mai mare sumă în
jos.
    ◦ să afișeze și totalul amenzilor date de toți agenții.
11. la selectarea opțiunii „Ieșire” programul să se închidă.
    ◦ programul să salveze datele despre agenți și contravenienți în fișiere dedicate și să le încarce
la pornire.
*/
