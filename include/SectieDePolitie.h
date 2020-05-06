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
        void StergePolitist();
        Contravenient AdaugaAmenda();
        void AfiseazaAmenziPolitist();
        void AfiseazaAmenziContravenient();
        void AfiseazaSituatieAmenzi();
        void ScriereInFisier();
        void CitireDinFisier(); //IMPORT
        virtual ~SectieDePolitie();

    protected:

    private:
        vector <Politist> vctPolitist;
        vector <Contravenient> vctContravenient;
        vector <Amenzi> vctAmenzi;
        vector <Politist> vctSituatieAmenziTotal; // pt metoda afiseaza situatie amenzi
        void ImportAgenti();
        void ImportContravenienti();
        void ImportAmenzi();
};

#endif // SECTIEDEPOLITIE_H
