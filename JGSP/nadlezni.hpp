#ifndef NADLEZNI_HPP_INCLUDED
#define NADLEZNI_HPP_INCLUDED

class Nadlezni:public Zaposleni{
protected:
    bool ovlascenja;
public:
    Nadlezni(bool ovlas = true, string imePrez = "", int jmbg = 0, int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        ovlascenja = ovlas;
    }
};

#endif // NADLEZNI_HPP_INCLUDED
