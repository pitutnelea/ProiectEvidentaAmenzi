#include "Amenzi.h"

Amenzi::Amenzi(unsigned int codPolitist, unsigned int codContravenient, double amenda, Categorii categorie): _codPolitist{codPolitist}, _codContravenient{codContravenient},_amenda{amenda}, _categorie{categorie}
{
}

Amenzi::~Amenzi()
{
    //dtor
}

