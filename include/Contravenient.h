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
        string GetNumeContravenient() {return _numeContravenient;}
        unsigned int GetCodContravenient() {return _codContravenient;}
        void ExportContravenient(std::ostream&);
        virtual ~Contravenient();

    protected:

    private:
        string _numeContravenient;
        unsigned int _codContravenient;
};

#endif // CONTRAVENIENT_H
