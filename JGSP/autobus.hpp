#ifndef AUTOBUS_HPP_INCLUDED
#define AUTOBUS_HPP_INCLUDED

#include "vozilo.hpp"

enum TipPrevozaAutobusa{javni, deca, privatni};

class Autobus:public Vozilo{
protected:
    int brojMesta;
    TipPrevozaAutobusa tip;
public:
    Autobus(int brMesta, TipPrevozaAutobusa t, string mark, string registr, int godine, TipGoriva gorivo, int k, int d, int m, int g):Vozilo(mark, registr, godine, gorivo, k, d, m, g){
        brojMesta = brMesta;
        tip = t;
    }
};

#endif // AUTOBUS_HPP_INCLUDED
