#ifndef AUTOBUS_HPP_INCLUDED
#define AUTOBUS_HPP_INCLUDED

#include "vozilo.hpp"

enum TipPrevozaAutobusa {javni, deca, privatni};

class Autobus:public Vozilo{
protected:
    int brojMesta;
    TipPrevozaAutobusa tip;
public:
    Autobus(int brMesta = 50, TipPrevozaAutobusa t = javni, string mark = "", string registr = "", int godine = 0, TipGoriva gorivo = dizel, int k = 0, int d = 1, int m = 1, int g = 2000)
    :Vozilo(mark, registr, godine, gorivo, k, d, m, g){
        brojMesta = brMesta;
        tip = t;
    }
};

#endif // AUTOBUS_HPP_INCLUDED
