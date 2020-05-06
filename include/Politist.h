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
        Politist(double, string); // pt metoda afiseaza situatie amenzi
        double GetValAmenda(){return _valAmenda;}
        string GetNumePolitist() {return _numePolitist;}
        unsigned int GetCodPolitist() {return _codPolitist;}
        bool operator < (Politist& politist);
        void ExportPolitist(std::ostream&);
        virtual ~Politist();

    protected:

    private:
        double _valAmenda; // pt metoda afiseaza situatie amenzi
        string _numePolitist;
        unsigned int _codPolitist;
};

#endif // POLITIST_H
