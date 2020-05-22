#ifndef ZAPOSLENI_HPP_INCLUDED
#define ZAPOSLENI_HPP_INCLUDED

#include "datum.hpp"
#include "bazaPodatakaZaposlenih.hpp"

enum Polovi{muski, zenski};

class Zaposleni{
protected:
    string imePrezime;
    Datum datumRodjenja;
    string JMBG;
    int godineStaza;
    Polovi pol;
    string adresa;
    string mestoStanovanja;
    double plata;
public:
    Zaposleni(string imePrez = "", string jmbg = "", int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000):datumRodjenja(d,m,g){
        imePrezime = imePrez;
        JMBG = jmbg;
        godineStaza = godStaz;
        pol = p;
        adresa = adres;
        mestoStanovanja = mestoStan;
        plata = plat;
    }

    Zaposleni(const Zaposleni &z){
        imePrezime = z.imePrezime;
        datumRodjenja = z.datumRodjenja;
        JMBG = z.JMBG;
        godineStaza = z.godineStaza;
        pol = z.pol;
        adresa = z.adresa;
        mestoStanovanja = z.mestoStanovanja;
        plata = z.plata;
    }

    string getIme() const{return imePrezime;}
    int getDan() const{return datumRodjenja.getDan();}
    int getMesec() const{return datumRodjenja.getMesec();}
    int getGodina() const{return datumRodjenja.getGodina();}
    double getPlata() const{return plata;}
    string getJMBG() const{return JMBG;}
    int getGodineStaza() const{return godineStaza;}
    Polovi getPol() const{return pol;}
    string getMestoStanovanja() const{return mestoStanovanja;}
    string getAdresa() const{return adresa;}

    virtual void printRezime() const{
        cout << "Rezime - " << imePrezime << endl;
        if(pol == muski) cout << "Rodjen " << datumRodjenja;
        else cout << "Rodjena " << datumRodjenja;
        cout << "Trenutno mesto prebivalista je " << mestoStanovanja << ", u ulici " << adresa << "." << endl << "Ima " << godineStaza;
        cout << " godina staza i zaradjuje " << plata << " mesecno." << endl << "Dodatne informacije:" << endl;
        cout << "JMBG: " << JMBG << endl;
    }

    virtual void ucitajPreset(string imeFajla, unsigned int l){
        unsigned int i = 0;
        string line, line2;
        ifstream myFile(imeFajla);
        if (myFile.is_open()){
            while(i <= l){getline(myFile,line); i++;}
                i = 0;
                imePrezime = "";
                while(line[i] != '|'){imePrezime += line[i]; i++;} /// ime i prezime
                i++;
                line2 = "";
                while(line[i] != '|'){line2 += line[i]; i++;} /// dan rodjenja
                i++;
                datumRodjenja.setDan(atoi(line2.c_str()));
                line2 = "";
                while(line[i] != '|'){line2 += line[i]; i++;} /// mesec rodjenja
                i++;
                datumRodjenja.setMesec(atoi(line2.c_str()));
                line2 = "";
                while(line[i] != '|'){line2 += line[i]; i++;} /// godina rodjenja
                i++;
                datumRodjenja.setGodina(atoi(line2.c_str()));
                line2 = "";
                JMBG = "";
                while(line[i] != '|'){JMBG += line[i]; i++;} /// jmbg
                i++;
                line2 = "";
                while(line[i] != '|'){line2 += line[i]; i++;} /// godine staza
                i++;
                godineStaza = atoi(line2.c_str());
                line2 = "";
                while(line[i] != '|'){line2 += line[i]; i++;} /// pol
                if(line2 == "muski") pol = muski;
                else pol = zenski;
                i++;
                line2 = "";
                adresa = "";
                while(line[i] != '|'){adresa += line[i]; i++;} /// adresa
                i++;
                line2 = "";
                mestoStanovanja = "";
                while(line[i] != '|'){mestoStanovanja += line[i]; i++;} /// mesto stanovanja
                i++;
                line2 = "";
                while(i < strlen(line.c_str()) && line[i] != '|'){
                        line2 += line[i]; i++;} /// plata
                plata = atoi(line2.c_str());
                line2 = "";
        }
        myFile.close();
}

    friend ostream& operator<<(ostream& output, const Zaposleni &z);
};

ostream& operator<<(ostream& output, const Zaposleni &z){
    output << "Ime i prezime: " << z.imePrezime<<endl << "Datum rodjenja: ";
    output << z.datumRodjenja;
    output << "JMBG: " << z.JMBG << endl << "Godine staza: " << z.godineStaza << endl << "Pol: ";
    if(z.pol == muski) output << "muski" << endl;
    else output << "zenski" << endl;
    output << "Adresa stanovanja: " << z.adresa << endl << "Mesto stanovanja: " << z.mestoStanovanja << endl << "Plata: " << z.plata << endl << endl;
    return output;
}

#endif // ZAPOSLENI_HPP_INCLUDED
