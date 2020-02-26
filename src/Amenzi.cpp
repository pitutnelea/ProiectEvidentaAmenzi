#include "Amenzi.h"

Amenzi::Amenzi(unsigned int codPolitist, unsigned int codContravenient, double amenda, Categorii categorie, double totalAmenziAgent):
     _codPolitist{codPolitist}, _codContravenient{codContravenient},_amenda{amenda}, _categorie{categorie}, _totalAmenziAgent{totalAmenziAgent}
{
}

Amenzi::~Amenzi()
{
    //dtor
}

