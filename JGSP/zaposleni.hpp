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

    friend ostream& operator<<(ostream& output, const Zaposleni &z);
};

ostream& operator<<(ostream& output, const Zaposleni &z){
    output << "Zaposleni - ispis" << endl << "Ime i prezime: " << z.imePrezime<<endl << "Datum rodjenja: ";
    output << z.datumRodjenja;
    output << "JMBG: " << z.JMBG << endl << "Godine staza: " << z.godineStaza << endl << "Pol: " << z.pol << endl;
    output << "Adresa stanovanja: " << z.adresa << endl << "Mesto stanovanja: " << z.mestoStanovanja << endl << "Plata: " << z.plata << endl << endl;
    return output;
}

#endif // ZAPOSLENI_HPP_INCLUDED
