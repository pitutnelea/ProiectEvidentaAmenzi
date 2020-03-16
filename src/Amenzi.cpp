#include "Amenzi.h"

Amenzi::Amenzi()
{

}

Amenzi::Amenzi(unsigned int codPolitist, unsigned int codContravenient, double amenda, Categorii categorie):_codPolitist{codPolitist}, _codContravenient{codContravenient},_amenda{amenda}, _categorie{categorie}
{
    //ctor
}

Amenzi::Amenzi(double amenda) : _amenda{amenda}
{

}

Amenzi::~Amenzi()
{
    //dtor
}

void Amenzi::ExportAmenzi(ostream& out)
{
    out << _codPolitist << " " << _codContravenient << " " << _amenda << " " << _categorie;
}

/*istream& operator>>(istream& in, Categorii& f)
{
    in >>f.bicicleta;
    in >> f.motoretaMotocicleta;
    in >> f.autoturism;
    in >> f.camion;
    in >> f.tractor;
}*/
