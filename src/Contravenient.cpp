#include "Contravenient.h"
#include <iostream>
using namespace std;

Contravenient::Contravenient(unsigned int codContravenient)
{
    _codContravenient = codContravenient;
}

Contravenient::Contravenient(string numeContravenient, unsigned int codContravenient):_numeContravenient{numeContravenient}, _codContravenient{codContravenient}
{
}

Contravenient::~Contravenient()
{
    //dtor
}
