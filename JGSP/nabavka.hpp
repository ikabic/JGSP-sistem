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
    Nabavka(SveNabavke n = kartaBus, double c = 0, int k = 0, int d1 = 1, int m1 = 1, int g1 = 2000, int d2 = 1, int m2 = 1, int g2 = 2000):datumNabavke(d1,m1,g1),rokTrajanja(d2,m2,g2){
        tip = n;
        kolicina = k;
        cena = c;
    }

    int getKolicina(){return kolicina;}
    friend ostream& operator<<(ostream& output, const Nabavka &n);
};

/// napravi switch za tip
ostream& operator<<(ostream& output, const Nabavka &n){
    output << "Nabavka - ispis" << endl << "Tip resursa: " << n.tip << endl << "Kolicina: " << n.kolicina << endl << "Datum nabavke: " << n.datumNabavke;
    output << "Rok trajanja: " << n.rokTrajanja << "Cena: " << n.cena << endl;
    return output;
}

#endif // NABAVKA_HPP_INCLUDED
