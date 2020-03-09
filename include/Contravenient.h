#ifndef CONTRAVENIENT_H
#define CONTRAVENIENT_H
#include <string>
#include <iostream>
using namespace std;

class Contravenient
{
    public:
        Contravenient();
        Contravenient(string, unsigned int);
        void SetNumeContravenient(string numeContravenient){_numeContravenient = numeContravenient;}
        string GetNumeContravenient() {return _numeContravenient;}
        void SetCodContravenient(unsigned int codContravenient){_codContravenient = codContravenient;}
        unsigned int GetCodContravenient() {return _codContravenient;}
        virtual ~Contravenient();

    protected:

    private:
        string _numeContravenient;
        unsigned int _codContravenient;
};

#endif // CONTRAVENIENT_H
