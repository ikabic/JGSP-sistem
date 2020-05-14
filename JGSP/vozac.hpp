#ifndef VOZAC_HPP_INCLUDED
#define VOZAC_HPP_INCLUDED

enum VozackaDozvola{B,C,D};

class Vozac:public Zaposleni{
protected:
    VozackaDozvola kategorijaVozacke;
public:
    Vozac(VozackaDozvola doz = B, string imePrez = "", string jmbg = "", int godStaz = 0, Polovi p = muski, string adres = "", string mestoStan = "", double plat = 0, int d = 1, int m = 1, int g = 2000)
    :Zaposleni(imePrez, jmbg, godStaz, p, adres, mestoStan, plat, d, m, g){
        kategorijaVozacke = doz;
    }

    string getIme(){return imePrezime;}
    double getPlata(){return plata;}
    int getGodineStaza(){return godineStaza;}

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
            if(line2 == "C") kategorijaVozacke = C;
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
    if(v.kategorijaVozacke == B) output << "B" << endl << endl;
    if(v.kategorijaVozacke == C) output << "C" << endl << endl;
    else output << "D" << endl << endl;
    return output;
}

#endif // VOZAC_HPP_INCLUDED
