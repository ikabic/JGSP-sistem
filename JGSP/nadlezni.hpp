#ifndef NADLEZNI_HPP_INCLUDED
#define NADLEZNI_HPP_INCLUDED

class Nadlezni:public Zaposleni{
protected:
    bool ovlascenja;
public:
    Nadlezni(bool ovlas = true, string imePrez = "", string jmbg = "", int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
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

    string getIme() const{return imePrezime;}
    double getPlata() const{return plata;}
    int getGodineStaza() const{return godineStaza;}
    Polovi getPol() const{return pol;}
    string getMestoStanovanja() const{return mestoStanovanja;}
    bool getOvlascenje() const{return ovlascenja;}

    void printRezime() const{
        Zaposleni::printRezime();
        if (ovlascenja == true){cout << "Nadlezni koji ima ovlascenja za rukovodstvo bazom podataka."; return;}
        cout << "Nadlezni koji nema ovlascenja za rukovodstvo bazom podataka.";
    }

    void ucitajPreset(string imeFajla, int l){
        Zaposleni::ucitajPreset(imeFajla, l);
        int i = 0, u = 0;
        string line, line2;
        ifstream myFile(imeFajla);
        if (myFile.is_open()){
            while(i <= l){getline(myFile,line); i++;}
            i = 0;
            while(i != 10){
                if(line[u] == '|') i++;
                u++;
            }
            line2 = line[u];
            ovlascenja = atoi(line2.c_str());
        }
        myFile.close();
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
