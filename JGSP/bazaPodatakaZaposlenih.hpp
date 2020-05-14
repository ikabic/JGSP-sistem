#ifndef BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED
#define BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED

#include "zaposleni.hpp"
#include "vozac.hpp"
#include "nadlezni.hpp"

int brojRadnika(string imeFajla);

class BazaPodatakaZaposlenih{
protected:
    vector <Nadlezni> sviNadlezni;
    vector <Vozac> sviVozaci;
    vector <Zaposleni> sviZaposleni;
public:
    void dodajZaposlenog(Zaposleni z){sviZaposleni.push_back(z);}
    void dodajNadleznog(Nadlezni n){sviNadlezni.push_back(n);}
    void dodajVozaca(Vozac v){sviVozaci.push_back(v);}

    void ucitajZaposlene(){
        Zaposleni z;
        int i;
        for(i = abs((int)(sviZaposleni.size() - brojRadnika("zaposleni.txt"))); i > 0; i--) sviZaposleni.push_back(z);
        i = 0;
        for(auto o = sviZaposleni.begin(); o != sviZaposleni.end(); o++){
                o -> ucitajPreset("zaposleni.txt", i);
                i++;}
    }

    void ucitajVozace(){
        Vozac v;
        int i;
        for(i = abs((int)(sviVozaci.size() - brojRadnika("vozaci.txt"))); i > 0; i--) sviVozaci.push_back(v);
        i = 0;
        for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++){
                o -> ucitajPreset("vozaci.txt", i);
                i++;}
    }

    void ucitajNadlezne(){
        Nadlezni n;
        int i;
        for(i = abs((int)(sviNadlezni.size() - brojRadnika("nadlezni.txt"))); i > 0; i--) sviNadlezni.push_back(n);
        i = 0;
        for(auto o = sviNadlezni.begin(); o != sviNadlezni.end(); o++){
                o -> ucitajPreset("nadlezni.txt", i);
                i++;}
    }

    void ucitajSve(){
        ucitajNadlezne();
        ucitajVozace();
        ucitajZaposlene();
    }

    void ispisiVozace(){for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++) cout << *o;}
    void ispisiNadlezne(){for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) cout << *i;}
    void ispisiZaposlene(){for(auto u = sviZaposleni.begin(); u != sviZaposleni.end(); u++) cout << *u;}
    void ispisiSve(){
        ispisiNadlezne();
        ispisiVozace();
        ispisiZaposlene();
    }

    void pretragaZaposlenih(){
        int x,  y;
        string line, line2, line3;
        double p;
        cout << "Pretraga po: 1. Imenu           2. Plati           3. Godinama staza" << endl << "> ";
        cin >> x;
        switch(x){
            case 1:
                cin >> line >> line2;
                line = line + " " + line2;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line) cout << *i;
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line) cout << *i;
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line) cout << *i;
            case 2:
                cin >> p;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getPlata() == p) cout << *i;
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getPlata() == p) cout << *i;
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getPlata() == p) cout << *i;
            case 3:
                cin >> y;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getGodineStaza() == y) cout << *i;
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getGodineStaza() == y) cout << *i;
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getGodineStaza() == y) cout << *i;
        }
    }
};

#endif // BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED
