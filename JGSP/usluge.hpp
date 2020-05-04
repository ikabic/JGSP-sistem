#ifndef USLUGE_HPP_INCLUDED
#define USLUGE_HPP_INCLUDED

#include "datum.hpp"

enum SveUsluge{reklama, parking, izradaKarte, izradaPropusnica};

class Usluge{
protected:
    Trajanje tipPoTrajanju;
    Datum datumProdaje;
    SveUsluge tipUsluge;
    int kolicina;
public:
    Usluge(Trajanje tip, SveUsluge usluga, int k, int d, int m, int g):datumProdaje(d,m,g){
        tipPoTrajanju = tip;
        tipUsluge = usluga;
        kolicina = k;
    }
};

#endif // USLUGE_HPP_INCLUDED
