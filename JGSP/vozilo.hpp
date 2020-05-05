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
    Vozilo(string mark = "", string registr = "", int godine = 0, TipGoriva gorivo = dizel, int k = 0, int d = 1, int m = 1, int g = 2000):datumRegistracije(d,m,g), gorivoVozila(gorivo, k){
        marka = mark;
        registracija = registr;
        starost = godine;
    }
};

#endif // VOZILO_HPP_INCLUDED
