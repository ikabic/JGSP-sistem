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
    Saobracaj(int brLinije = 1, int brStajalista = 0, int potrosGoriva = 0, int km = 0, TipSmera tS = kruzni, int brMesta = 0, TipPrevozaAutobusa t = javni, string mark = "", string registr = "", int godine = 0, TipGoriva gorivo = dizel, int k = 0, int d = 1, int m = 1, int g = 2000)
    :bus(brMesta, t, mark, registr, godine, gorivo, k, d, m, g){
        brojLinije = brLinije;
        brojStajalista = brStajalista;
        potrosnjaGoriva = potrosGoriva;
        kilometraza = km;
        smer = tS;
    }
};

#endif // SAOBRACAJ_HPP_INCLUDED
