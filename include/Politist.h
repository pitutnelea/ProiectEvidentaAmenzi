#ifndef POLITIST_H
#define POLITIST_H
#include <string>
#include <iostream>
using namespace std;

class Politist
{
    public:
        Politist();
        Politist(string, unsigned int);
        void SetNumePolitist(string numePolitist){_numePolitist = numePolitist;}
        string GetNumePolitist() {return _numePolitist;}
        void SetCodPolitist(unsigned int codPolitist){_codPolitist = codPolitist;}
        unsigned int GetCodPolitist() {return _codPolitist;}
        void Export(std::ostream&);
        virtual ~Politist();

    protected:

    private:
        string _numePolitist;
        unsigned int _codPolitist;
};

#endif // POLITIST_H
