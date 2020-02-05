#ifndef CONTRAVENIENT_H
#define CONTRAVENIENT_H
#include <string>
#include <iostream>

class Contravenient
{
    public:
        Contravenient();
        Contravenient(string, unsigned int);
        void AdaugaContravenient();
        virtual ~Contravenient();

    protected:

    private:
        string _nume;
        unsigned int _codContravenient;
};

#endif // CONTRAVENIENT_H
