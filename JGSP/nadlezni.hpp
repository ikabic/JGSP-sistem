#ifndef NADLEZNI_HPP_INCLUDED
#define NADLEZNI_HPP_INCLUDED

class Nadlezni:public Zaposleni{
protected:
    bool ovlascenja;
public:
    Nadlezni(bool ovlas, string imePrez, int jmbg, int godStaz, Polovi p, string adres, string mestoStan, double plat, int d, int m, int g)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        ovlascenja = ovlas;
    }
};

#endif // NADLEZNI_HPP_INCLUDED
