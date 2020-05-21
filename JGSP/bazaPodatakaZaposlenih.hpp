#ifndef BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED
#define BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED

#include "zaposleni.hpp"
#include "vozac.hpp"
#include "nadlezni.hpp"

int brojRadnika(string imeFajla);
void textcolor(unsigned short color);

class BazaPodatakaZaposlenih{
protected:
    vector <Nadlezni> sviNadlezni;
    vector <Vozac> sviVozaci;
    vector <Zaposleni> sviZaposleni;
public:
    void dodajZaposlenog(const Zaposleni &z){
        sviZaposleni.push_back(z);
        cout << z.getIme() << " je zaposljen/a." << endl;
    }
    void dodajNadleznog(const Nadlezni &n){
        sviNadlezni.push_back(n);
        cout << n.getIme() << " je zaposljen/a." << endl;
    }
    void dodajVozaca(const Vozac &v){
        sviVozaci.push_back(v);
        cout << v.getIme() << " je zaposljen/a." << endl;
    }

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

    void ispisiZaposlene(int x) const{
        if(x == 0){
            cout << endl << endl;
            textcolor(8); cout << "Obicni zaposleni:" << endl; textcolor(7);
            for(auto u = sviZaposleni.begin(); u != sviZaposleni.end(); u++) cout << "   " << u -> getIme() << endl;
            textcolor(8); cout << endl << "Vozaci:" << endl; textcolor(7);
            for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++) cout << "   " << o -> getIme() << endl;
            textcolor(8); cout << endl << "Nadlezni:" << endl; textcolor(7);
            for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) cout << "   " << i -> getIme() << endl;
            cout << endl;
        }

        else{
            switch(x){
            case 1:
                for(auto u = sviZaposleni.begin(); u != sviZaposleni.end(); u++) cout << *u;
                break;
            case 2:
                for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++) cout << *o;
                break;
            case 3:
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) cout << *i;
                break;
            case 4:
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) cout << *i;
                for(auto u = sviZaposleni.begin(); u != sviZaposleni.end(); u++) cout << *u;
                for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++) cout << *o;
                break;
            }
        }
    }

    void otpustiZaposlenog(int x){
        string line;
        switch(x){
            case 1:
                fflush(stdin);
                cout << "> ";
                getline(cin, line);
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){
                        sviZaposleni.erase(i);
                        cout << line << " je otpusten/a." << endl;
                        return;
                }
                cout << line << " nije otpusten/a." << endl;
                break;
            case 2:
                fflush(stdin);
                cout << "> ";
                getline(cin, line);
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){
                        sviVozaci.erase(i);
                        cout << line << " je otpusten/a." << endl;
                        return;
                }
                cout << line << " nije otpusten/a." << endl;
                break;
            case 3:
                fflush(stdin);
                cout << "> ";
                getline(cin, line);
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){
                        sviNadlezni.erase(i);
                        cout << line << " je otpusten/a." << endl;
                        return;
                }
                cout << line << " nije otpusten/a." << endl;
                break;
        }
    }

    Nadlezni pronadjiNadleznog(string line, bool* b){
        for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){*b = true; return *i;}
        textcolor(8); cout << endl << "Nepostoji zaposleni sa takvim imenom. "; textcolor(7);
        *b = false;
        return *(sviNadlezni.begin());
    }
    Zaposleni pronadjiZaposlenog(string line, bool* b){
        for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){*b = true; return *i;}
        textcolor(8); cout << endl << "Nepostoji zaposleni sa takvim imenom. "; textcolor(7);
        *b = false;
        return *(sviZaposleni.begin());
    }
    Vozac pronadjiVozaca(string line, bool* b){
        for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){*b = true; return *i;}
        textcolor(8); cout << endl << "Nepostoji zaposleni sa takvim imenom. "; textcolor(7);
        *b = false;
        return *(sviVozaci.begin());
    }

    void pretragaRezime(string line) const{
        int z = 0;
        for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){i -> printRezime(); z++;}
        for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){i -> printRezime(); z++;}
        for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){i -> printRezime(); z++;}
        if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa takvim imenom." << endl; textcolor(7);}
    }

    void pretragaZaposlenih() const{
        int x, y, z;
        string line;
        double p;
        textcolor(4);
        cout << "Pretraga po: "; textcolor(7);
        cout << "1. Imenu           2. Plati           3. Godinama staza           4. Polu"  << endl << "             5. Vozackoj dozvoli           6. Ovlascenje            7. Mestu stanovanja" << endl << "> ";
        cin >> x;
        switch(x){
            case 1:
                z = 0;
                fflush(stdin);
                getline(cin, line);
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa takvim imenom.";}
                break;
            case 2:
                z = 0;
                cin >> p;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa takvom platom.";}
                break;
            case 3:
                z = 0;
                cin >> y;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa toliko godina staza.";}
                break;
            case 4:
                z = 0;
                cin >> line;
                if(line == "muski") x = 0;
                else if(line == "zenski") x = 1;
                else{
                        cout << "Nepostoji zaposleni tog pola.";
                        break;
                }
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa toliko godina staza.";}
                break;
            case 5:
                z = 0;
                cin >> line;
                if(line == "B") x = 0;
                else if(line == "C") x = 1;
                else if(line == "D") x = 2;
                else{
                    cout << "Nepostoji zaposleni sa takvom vozackom dozvolom.";
                    break;
                }
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getVozackaDozvola() == x){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa takvom vozackom dozvolom.";}
                break;
            case 6:
                z = 0;
                cin >> line;
                if(line == "true" || line == "1") x = 1;
                else if(line == "false" || line == "0") x = 0;
                else{
                        cout << "Nepostoji zaposleni tog ovlascenja.";
                        break;
                }
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getOvlascenje() == x){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni tog ovlascenja.";}
                break;
            case 7:
                z = 0;
                fflush(stdin);
                getline(cin, line);
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                if(z == 0){cout << "Nepostoji zaposleni sa tim mestom stanovanja.";}
                break;
        }
    }
};

#endif // BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED
