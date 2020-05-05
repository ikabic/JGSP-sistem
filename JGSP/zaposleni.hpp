#ifndef ZAPOSLENI_HPP_INCLUDED
#define ZAPOSLENI_HPP_INCLUDED

#include "datum.hpp"

enum Polovi{muski, zenski};

class Zaposleni{
protected:
    string imePrezime;
    Datum datumRodjenja;
    int JMBG;
    int godineStaza;
    Polovi pol;
    string adresa;
    string mestoStanovanja;
    double plata;
public:
    Zaposleni(string imePrez = "", int jmbg = 0, int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000):datumRodjenja(d,m,g){
        imePrezime = imePrez;
        JMBG = jmbg;
        godineStaza = godStaz;
        pol = p;
        adresa = adres;
        mestoStanovanja = mestoStan;
        plata = plat;
    }
};

#endif // ZAPOSLENI_HPP_INCLUDED
