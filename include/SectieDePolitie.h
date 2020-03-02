#ifndef SECTIEDEPOLITIE_H
#define SECTIEDEPOLITIE_H
#include "Politist.h"
#include "Contravenient.h"
#include "Amenzi.h"
#include <vector>
#include <iostream>
using namespace std;

class SectieDePolitie
{
    public:
        SectieDePolitie();
        Politist AdaugaPolitist();
        void StergePolitist(); ////intro noua clasa sau mainul o lista de vecetori cu o lista
        Contravenient AdaugaAmenda();
        void AfiseazaAmenziPolitist(); //toate amenzile date de un anumit agent
        void AfiseazaAmenziContravenient(); //toate amenzile luate de un anumit contravenient
        void AfiseazaSituatieAmenzi(); // afisez fiecare agent cu totalul amenzilor date
        virtual ~SectieDePolitie();

    protected:

    private:
        vector <Politist> vctPolitist;
        vector <Contravenient> vctContravenient;
        vector <Amenzi> vctAmenzi;
};

#endif // SECTIEDEPOLITIE_H
