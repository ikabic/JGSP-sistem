#ifndef NADLEZNI_HPP_INCLUDED
#define NADLEZNI_HPP_INCLUDED

class Nadlezni:public Zaposleni{
protected:
    bool ovlascenja;
public:
    Nadlezni(bool ovlas = false, string imePrez = "", string jmbg = "", int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        ovlascenja = ovlas;
    }

    Nadlezni(const Nadlezni &n){
        imePrezime = n.imePrezime;
        datumRodjenja = n.datumRodjenja;
        JMBG = n.JMBG;
        godineStaza = n.godineStaza;
        pol = n.pol;
        adresa = n.adresa;
        mestoStanovanja = n.mestoStanovanja;
        plata = n.plata;
        ovlascenja = n.ovlascenja;
    }

    Nadlezni(bool ovlas, const Zaposleni &z): Zaposleni(z){ovlascenja = ovlas;}

    bool getOvlascenje() const{return ovlascenja;}
    void setOvlascenje(bool o){ovlascenja = o;}

    void printRezime() const{
        Zaposleni::printRezime();
        if (ovlascenja == true){cout << "Nadlezni koji ima ovlascenja za rukovodstvo bazom podataka." << endl << endl; return;}
        cout << "Nadlezni koji nema ovlascenja za rukovodstvo bazom podataka." << endl;
    }

    friend ostream& operator<<(ostream& output, const Nadlezni &n);
};

ostream& operator<<(ostream& output, const Nadlezni &n){
    output << "Ime i prezime: " << n.imePrezime<<endl << "Datum rodjenja: ";
    output << n.datumRodjenja;
    output << "JMBG: " << n.JMBG << endl << "Godine staza: " << n.godineStaza << endl << "Pol: ";
    if(n.pol == muski) output << "muski" << endl;
    else output << "zenski" << endl;
    output << "Adresa stanovanja: " << n.adresa << endl << "Mesto stanovanja: " << n.mestoStanovanja << endl << "Plata: " << n.plata << endl<< "Ovlascenja: ";
    if(n.ovlascenja == 1) output << "true" << endl << endl;
    else output << "false" << endl << endl;
    return output;
}

#endif // NADLEZNI_HPP_INCLUDED
