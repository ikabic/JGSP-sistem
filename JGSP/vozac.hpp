#ifndef VOZAC_HPP_INCLUDED
#define VOZAC_HPP_INCLUDED

enum VozackaDozvola{B = 0,C,D};

class Vozac:public Zaposleni{
protected:
    VozackaDozvola kategorijaVozacke;
public:
    Vozac(VozackaDozvola doz = B, string imePrez = "", string jmbg = "", int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        kategorijaVozacke = doz;
    }

    Vozac(const Vozac &v){
        imePrezime = v.imePrezime;
        datumRodjenja = v.datumRodjenja;
        JMBG = v.JMBG;
        godineStaza = v.godineStaza;
        pol = v.pol;
        adresa = v.adresa;
        mestoStanovanja = v.mestoStanovanja;
        plata = v.plata;
        kategorijaVozacke = v.kategorijaVozacke;
    }

    VozackaDozvola getVozackaDozvola() const{return kategorijaVozacke;}

    void printRezime() const{
        Zaposleni::printRezime();
        if (kategorijaVozacke == 0){cout << "Vozac s vozackom dozvolom kategorije B."; return;}
        else if (kategorijaVozacke == 1){cout << "Vozac s vozackom dozvolom kategorije C."; return;}
        else cout << "Vozac s vozackom dozvolom kategorije D.";
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
            if(line2 == "B") kategorijaVozacke = B;
            else if(line2 == "C") kategorijaVozacke = C;
            else kategorijaVozacke = D;
        }
        myFile.close();
    }

    friend ostream& operator<<(ostream& output, const Vozac &v);
};

ostream& operator<<(ostream& output, const Vozac &v){
    output << "Ime i prezime: " << v.imePrezime<<endl << "Datum rodjenja: ";
    output << v.datumRodjenja;
    output << "JMBG: " << v.JMBG << endl << "Godine staza: " << v.godineStaza << endl << "Pol: ";
    if(v.pol == muski) output << "muski" << endl;
    else output << "zenski" << endl;
    output << "Adresa stanovanja: " << v.adresa << endl << "Mesto stanovanja: " << v.mestoStanovanja << endl << "Plata: " << v.plata << endl<< "Kategorija vozacke dozvole: ";
    if(v.kategorijaVozacke == B){
            output << "B" << endl << endl;
            return output;
    }
    if(v.kategorijaVozacke == C){
            output << "C" << endl << endl;
            return output;
    }
    output << "D" << endl << endl;
    return output;
}

#endif // VOZAC_HPP_INCLUDED
