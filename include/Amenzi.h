#ifndef AMENZI_H
#define AMENZI_H

enum Categorii{bicicleta = 1, motoretaMotocicleta, autoturism, camion, tractor};
class Amenzi
{
    public:
        Amenzi(unsigned int, unsigned int, double, Categorii);
        void SetAmenda(double amenda){_amenda = amenda;}
        double GetAmenda(){return _amenda;}
        void SetCategorii(Categorii categorie){_categorie = categorie;}
        Categorii GetCategorii(){return _categorie;}
        virtual ~Amenzi();
    protected:

    private:
        Categorii _categorie;
        unsigned int _codPolitist;
        unsigned int _codContravenient;
        double _amenda;
};

#endif // AMENZI_H
