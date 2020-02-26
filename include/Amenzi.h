#ifndef AMENZI_H
#define AMENZI_H
#include <iostream>
using namespace std;

enum Categorii{bicicleta = 1, motoretaMotocicleta, autoturism, camion, tractor};
class Amenzi
{
    public:
        Amenzi(unsigned int, unsigned int, double, Categorii);
        Amenzi(unsigned int, string, double);
        void SetAmenda(double amenda){_amenda = amenda;}
        double GetAmenda(){return _amenda;}
        void SetCodPolitist(unsigned int codPolitist){_codPolitist = codPolitist;}
        unsigned int GetCodPolitist() {return _codPolitist;}
        virtual ~Amenzi();
    protected:

    private:
        Categorii _categorie;
        unsigned int _codPolitist;
        unsigned int _codContravenient;
        string _numeContravenient;
        double _amenda;
};

#endif // AMENZI_H
