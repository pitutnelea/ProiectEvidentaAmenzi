#include "Politist.h"
#include <iostream>
using namespace std;
#include <fstream>  // iclude i si o

Politist::Politist()
{

}

Politist::Politist(string numePolitist, unsigned int codPolitist):_numePolitist{numePolitist}, _codPolitist{codPolitist}
{

}

Politist::~Politist()
{
    //dtor
}

void Politist::Export(ostream& out)
{
     out << _codPolitist << " " << _numePolitist;
}
