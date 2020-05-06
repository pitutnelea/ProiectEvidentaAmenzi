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

Politist::Politist(double valamenda, string nume): _valAmenda{valamenda}, _numePolitist{nume}
{

}

Politist::~Politist()
{
    //dtor
}

bool Politist::operator <(Politist& politist)
{
    return (this->_valAmenda > politist.GetValAmenda());
}

void Politist::ExportPolitist(ostream& out)
{
    out << _codPolitist << " " << _numePolitist;
}
