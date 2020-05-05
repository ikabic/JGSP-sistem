#ifndef VOZAC_HPP_INCLUDED
#define VOZAC_HPP_INCLUDED

enum VozackaDozvola{B,C,D};

class Vozac:public Zaposleni{
protected:
    VozackaDozvola kategorijaVozacke;
public:
    Vozac(VozackaDozvola doz = B, string imePrez = "", int jmbg = 0, int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        kategorijaVozacke = doz;
    }
};

#endif // VOZAC_HPP_INCLUDED
