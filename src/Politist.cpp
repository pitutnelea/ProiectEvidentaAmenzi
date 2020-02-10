#include "Politist.h"
#include <iostream>
using namespace std;

Politist::Politist(unsigned int codPolitist)
{
    _codPolitist = codPolitist;
}

Politist::Politist(string numePolitist, unsigned int codPolitist):_numePolitist{numePolitist}, _codPolitist{codPolitist}
{
}

Politist::~Politist()
{
    //dtor
}
