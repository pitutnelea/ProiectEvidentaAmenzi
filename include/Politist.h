#ifndef POLITIST_H
#define POLITIST_H
#include <string>
#include <iostream>

class Politist
{
    public:
        Politist();
        Politist(string, unsigned int); //nume, codPolitist
        void AdaugaAgent();
        void StergeAgent();
        virtual ~Politist();

    protected:

    private:
        string _nume;
        unsigned int _codPolitist;
};

#endif // POLITIST_H
