#ifndef SAOBRACAJ_HPP_INCLUDED
#define SAOBRACAJ_HPP_INCLUDED

#include "autobus.hpp"

enum TipSmera{linijski, kruzni};
enum TipSaobracaja{gradski, prigradski, medjumesni};

class Saobracaj{
protected:
    int brojLinije;
    int brojStajalista;
    int potrosnjaGoriva;
    int kilometraza;
    TipSmera smer;
    TipSaobracaja tip;
    Autobus bus;
public:
    Saobracaj(int brLinije, int brStajalista, int potrosGoriva, int km, TipSmera tS, int brMesta, TipPrevozaAutobusa t, string mark, string registr, int godine, TipGoriva gorivo, int k, int d, int m, int g)
    :bus(brMesta, t, mark, registr, godine, gorivo, k, d, m, g){
        brojLinije = brLinije;
        brojStajalista = brStajalista;
        potrosnjaGoriva = potrosGoriva;
        kilometraza = km;
        smer = tS;
    }
};

#endif // SAOBRACAJ_HPP_INCLUDED
