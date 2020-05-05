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
    double cena;
public:
    Usluge(Trajanje tip = jednokratno, SveUsluge usluga = reklama, double c = 0, int k = 0, int d = 1, int m = 1, int g = 2000):datumProdaje(d,m,g){
        tipPoTrajanju = tip;
        tipUsluge = usluga;
        kolicina = k;
        cena = c;
    }
};

#endif // USLUGE_HPP_INCLUDED
