#ifndef AMENZI_H
#define AMENZI_H

enum Categorii{bicicleta, motoretaMotocicleta, autoturism, camion, tractor};
class Amenzi
{
    public:
        Amenzi(unsigned int, unsigned int, double);
        void SetAmenda(double amenda){_amenda = amenda;}
        double GetAmenda(){return _amenda;}
        virtual ~Amenzi();
    protected:

    private:
        Categorii _categorie;
        unsigned int _codPolitist;
        unsigned int _codContravenient;
        double _amenda;
};

#endif // AMENZI_H
