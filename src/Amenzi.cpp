#include "Amenzi.h"

Amenzi::Amenzi(unsigned int codPolitist, unsigned int codContravenient, double amenda, Categorii categorie): _codPolitist{codPolitist}, _codContravenient{codContravenient},_amenda{amenda}, _categorie{categorie}
{
}

Amenzi::Amenzi(unsigned int codContravenient, string numeContravenient, double amenda): _codContravenient{codContravenient},_numeContravenient{numeContravenient},_amenda{amenda}
{

}

Amenzi::~Amenzi()
{
    //dtor
}

