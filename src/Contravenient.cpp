#include "Contravenient.h"
#include <iostream>
using namespace std;

Contravenient::Contravenient()
{

}

Contravenient::Contravenient(string numeContravenient, unsigned int codContravenient):_numeContravenient{numeContravenient}, _codContravenient{codContravenient}
{

}

Contravenient::~Contravenient()
{
    //dtor
}

void Contravenient::ExportContravenient(ostream& out)
{
    out << _codContravenient << " " << _numeContravenient;
}
