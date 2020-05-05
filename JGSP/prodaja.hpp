#ifndef PRODAJA_HPP_INCLUDED
#define PRODAJA_HPP_INCLUDED

#include "karte.hpp"
#include "usluge.hpp"

class Prodaja{
protected:
    vector <Karte> prodateKarte;
    vector <Usluge> prodateUsluge;
    int ukupnaProdaja;
public:
    Prodaja(int ukupno){
        ukupnaProdaja = ukupno;
    }

    void setKarte(Karte &k){prodateKarte.push_back(k);}
};

#endif // PRODAJA_HPP_INCLUDED
