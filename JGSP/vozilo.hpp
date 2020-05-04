#ifndef VOZILO_HPP_INCLUDED
#define VOZILO_HPP_INCLUDED

#include "gorivo.hpp"
#include "datum.hpp"

class Vozilo{
protected:
    string marka;
    Datum datumRegistracije;
    string registracija;
    int starost;
    Gorivo gorivoVozila;
public:
    Vozilo(string mark, string registr, int godine, TipGoriva gorivo, int k, int d, int m, int g):datumRegistracije(d,m,g), gorivoVozila(gorivo, k){
        marka = mark;
        registracija = registr;
        starost = godine;
    }
};

#endif // VOZILO_HPP_INCLUDED
