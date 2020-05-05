#ifndef NABAVKA_HPP_INCLUDED
#define NABAVKA_HPP_INCLUDED

#include "datum.hpp"

enum SveNabavke{gorivo, delovi, kartaBus};

class Nabavka{
protected:
    SveNabavke tip;
    int kolicina;
    Datum datumNabavke;
    Datum rokTrajanja;
    double cena;
public:
    Nabavka(SveNabavke n, double c, int k, int d1, int m1, int g1, int d2, int m2, int g2):datumNabavke(d1,m1,g1),rokTrajanja(d2,m2,g2){
        tip = n;
        kolicina = k;
        cena = c;
    }

    int getKolicina(){return kolicina;}
};

#endif // NABAVKA_HPP_INCLUDED
