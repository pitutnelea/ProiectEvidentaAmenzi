#ifndef AMENZI_H
#define AMENZI_H
#include "Politist.h"
#include "Contravenient.h"

enum Categorii{bicicleta, motoretaMotocicleta,autoturism,camion,tractor};
class Amenzi
{
    public:
        Amenzi();
        Amenzi(unsigned int, unsigned int);
        void AfiseazaAmenziAgent(); //toate amenzile date de un anumit agent
        void AfiseazaAmenziContravenient(); //toate amenzile luate de un anumit contravenient
        void AfisezaSituatieAmenzi // afisez fiecare agent cu totalul amenzilor date
        virtual ~Amenzi();

    protected:

    private:
        Politist _codPolitist;
        Contravenient _codContraveninent;
        double _amenda;
};

#endif // AMENZI_H
