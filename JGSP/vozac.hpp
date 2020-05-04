#ifndef VOZAC_HPP_INCLUDED
#define VOZAC_HPP_INCLUDED

enum VozackaDozvola{B,C,D};

class Vozac:public Zaposleni{
protected:
    VozackaDozvola kategorijaVozacke;
public:
    Vozac(VozackaDozvola doz, string imePrez, int jmbg, int godStaz, Polovi p, string adres, string mestoStan, double plat, int d, int m, int g)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        kategorijaVozacke = doz;
    }
};

#endif // VOZAC_HPP_INCLUDED
