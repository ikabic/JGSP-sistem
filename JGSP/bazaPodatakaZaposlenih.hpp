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
        ofstream myFile;
        myFile.open ("promene.txt", ios_base::app);
        sviZaposleni.push_back(z);
        textcolor(8); cout << z.getIme() << " je zaposljen/a." << endl << endl; textcolor(7);
        myFile << "> " << z.getIme() << " (obican zaposleni) je zaposljen/a." << endl;
        myFile.close();

        upisiFajlZaposleni();
    }
    void dodajNadleznog(const Nadlezni &n){
        ofstream myFile;
        myFile.open ("promene.txt", ios_base::app);
        sviNadlezni.push_back(n);
        textcolor(8); cout << n.getIme() << " je zaposljen/a." << endl << endl; textcolor(7);
        myFile << "> " << n.getIme() << " (nadlezni) je zaposljen/a." << endl;
        myFile.close();

        upisiFajlNadlezni();
    }
    void dodajVozaca(const Vozac &v){
        ofstream myFile;
        myFile.open ("promene.txt", ios_base::app);
        sviVozaci.push_back(v);
        textcolor(8); cout << endl << v.getIme() << " je zaposljen/a." << endl << endl; textcolor(7);
        myFile << "> " << v.getIme() << " (vozac) je zaposljen/a." << endl;
        myFile.close();

        upisiFajlVozaci();
    }

    void ucitajZaposlene(){
        Zaposleni z;

        for(int i = 0; i < brojRadnika("zaposleni.txt"); i++){
            z.ucitajPreset("zaposleni.txt", i);
            sviZaposleni.push_back(z);
        }
    }

    void ucitajVozace(){
        Vozac v;
        for(int i = 0; i < brojRadnika("vozaci.txt"); i++){
            v.ucitajPreset("vozaci.txt", i);
            sviVozaci.push_back(v);
        }
    }

    void ucitajNadlezne(){
        Nadlezni n;
        for(int i = 0; i < brojRadnika("nadlezni.txt"); i++){
            n.ucitajPreset("nadlezni.txt", i);
            sviNadlezni.push_back(n);
        }
    }

    void ucitajSve(){
        ucitajNadlezne();
        ucitajVozace();
        ucitajZaposlene();
    }

    void upisiFajlZaposleni(){
        ofstream myFile;
        myFile.open ("zaposleni.txt");
        for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++){
                myFile << i -> getIme() << "|" << i -> getDan() << "|" << i -> getMesec() << "|" << i -> getGodina() << "|" << i -> getJMBG() << "|" << i -> getGodineStaza() << "|";
                if(i -> getPol() == muski) myFile << "muski";
                else myFile << "zenski";
                myFile << "|" << i -> getAdresa() << "|" << i -> getMestoStanovanja() << "|" << i -> getPlata() << endl;
        }
        myFile.close();
    }

    void upisiFajlNadlezni(){
        ofstream myFile;
        myFile.open ("nadlezni.txt");
        for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++){
                myFile << i -> getIme() << "|" << i -> getDan() << "|" << i -> getMesec() << "|" << i -> getGodina() << "|" << i -> getJMBG() << "|" << i -> getGodineStaza() << "|";
                if(i -> getPol() == muski) myFile << "muski";
                else myFile << "zenski";
                myFile << "|" << i -> getAdresa() << "|" << i -> getMestoStanovanja() << "|" << i -> getPlata() << "|" << i -> getOvlascenje() << endl;
        }
        myFile.close();
    }

    void upisiFajlVozaci(){
        ofstream myFile;
        myFile.open ("vozaci.txt");
        for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++){
                myFile << i -> getIme() << "|" << i -> getDan() << "|" << i -> getMesec() << "|" << i -> getGodina() << "|" << i -> getJMBG() << "|" << i -> getGodineStaza() << "|";
                if(i -> getPol() == muski) myFile << "muski";
                else myFile << "zenski";
                myFile << "|" << i -> getAdresa() << "|" << i -> getMestoStanovanja() << "|" << i -> getPlata() << "|";
                if(i -> getVozackaDozvola() == B) myFile << "B" << endl;
                else if(i -> getVozackaDozvola() == C) myFile << "C" << endl;
                else myFile << "D" << endl;
        }
        myFile.close();
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

    void pretragaRezime(string line) const{
        int z = 0;
        for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){
                z++;
                if(z > 1) cout << endl;
                i -> printRezime();
        }
        for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){i -> printRezime(); z++;}
        for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){i -> printRezime(); z++;}
        if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa takvim imenom." << endl; textcolor(7);}
    }

    void otpustiZaposlenog(int x, string line){
        int y = 0, w;
        string str;
        switch(x){
            case 1:
                y = 0;
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line) y++;
                if(y > 1){
                    vector <Nadlezni> n;
                    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line) n.push_back(*i);
                    do{
                        system("cls");
                        cout << "JGSP - otpustanje zaposlenih" << endl;
                        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                        cout << "Postoji vise zaposlenih s tim imenom, ukucajte redni broj od zaposlenog kog zelite da otpustite:" << endl << endl;
                        pretragaRezime(line);
                        textcolor(8); cout << endl << "> "; textcolor(7);
                        cin >> w;
                        cout << endl;
                        if(w < 1 || w > y){
                                cout << endl;
                                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od brojeva u intervalu [1," << y << "] !!!" << endl; textcolor(7);
                                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                                while(!kbhit()){}
                                getch();
                        }
                    }while(w < 1 || w > y);
                    ofstream myFile;
                    y = 0;
                    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){
                            y++;
                            if(y == w){
                            if(i -> getOvlascenje() == true){
                                textcolor(8); cout << endl << "Ne mozete otpustiti nadleznog koji je istog statusa kao Vi." << endl; textcolor(7);
                                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                                while(!kbhit()){}
                                getch();
                                break;
                            }
                            sviNadlezni.erase(i);
                            textcolor(8); cout << line << " je otpusten/a." << endl << endl; textcolor(7);
                            myFile.open ("promene.txt", ios_base::app);
                            myFile << "> " << i -> getIme() << " (nadlezni) je otpusten/a." << endl;
                            myFile.close();
                            upisiFajlNadlezni();
                            return;
                            }
                    }
                }
                else{
                        for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){
                                if(i -> getOvlascenje() == true){
                                textcolor(8); cout << endl << "Ne mozete otpustiti nadleznog koji je istog statusa kao Vi." << endl; textcolor(7);
                                break;;
                                }
                                ofstream myFile;
                                sviNadlezni.erase(i);
                                textcolor(8); cout << endl << line << " je otpusten/a." << endl << endl; textcolor(7);
                                myFile.open ("promene.txt", ios_base::app);
                                myFile << "> " << i -> getIme() << " (nadlezni) je otpusten/a." << endl;
                                myFile.close();
                                upisiFajlNadlezni();
                                return;
                    }
                    cout << endl;
                    textcolor(8); cout << line << " nije otpusten/a." << endl << endl; textcolor(7);
                }
                upisiFajlNadlezni();
                break;
            case 2:
                y = 0;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line) y++;
                if(y > 1){
                    vector <Zaposleni> z;
                    for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line) z.push_back(*i);
                    do{
                        system("cls");
                        cout << "JGSP - otpustanje zaposlenih" << endl;
                        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                        cout << "Postoji vise zaposlenih s tim imenom, ukucajte redni broj od zaposlenog kog zelite da otpustite:" << endl << endl;
                        pretragaRezime(line);
                        textcolor(8); cout << endl << "> "; textcolor(7);
                        cin >> w;
                        cout << endl;
                        if(w < 1 || w > y){
                                cout << endl;
                                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od brojeva u intervalu [1," << y << "] !!!" << endl; textcolor(7);
                                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                                while(!kbhit()){}
                                getch();
                        }
                    }while(w < 1 || w > y);
                    ofstream myFile;
                    y = 0;
                    for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){
                            y++;
                            if(y == w){
                            sviZaposleni.erase(i);
                            textcolor(8); cout << line << " je otpusten/a." << endl << endl; textcolor(7);
                            myFile.open ("promene.txt", ios_base::app);
                            myFile << "> " << i -> getIme() << " (nadlezni) je otpusten/a." << endl;
                            myFile.close();
                            upisiFajlZaposleni();
                            return;
                            }
                    }
                }
                else{
                        for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){
                                ofstream myFile;
                                sviZaposleni.erase(i);
                                textcolor(8); cout << endl << line << " je otpusten/a." << endl << endl; textcolor(7);
                                myFile.open ("promene.txt", ios_base::app);
                                myFile << "> " << i -> getIme() << " (obican zaposleni) je otpusten/a." << endl;
                                myFile.close();
                                upisiFajlZaposleni();
                                return;
                        }
                cout << endl;
                textcolor(8); cout << line << " nije otpusten/a." << endl << endl; textcolor(7);
                }
                upisiFajlZaposleni();
                break;
            case 3:
                y = 0;
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line) y++;
                if(y > 1){
                    vector <Vozac> v;
                    for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line) v.push_back(*i);
                    do{
                        system("cls");
                        cout << "JGSP - otpustanje zaposlenih" << endl;
                        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                        cout << "Postoji vise zaposlenih s tim imenom, ukucajte redni broj od zaposlenog kog zelite da otpustite:" << endl << endl;
                        pretragaRezime(line);
                        textcolor(8); cout << "> "; textcolor(7);
                        cin >> w;
                        cout << endl;
                        if(w < 1 || w > y){
                                cout << endl;
                                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od brojeva u intervalu [1," << y << "] !!!" << endl; textcolor(7);
                                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                                while(!kbhit()){}
                                getch();
                        }
                    }while(w < 1 || w > y);
                    ofstream myFile;
                    y = 0;
                    for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){
                            y++;
                            if(y == w){
                            sviVozaci.erase(i);
                            textcolor(8); cout << line << " je otpusten/a." << endl << endl; textcolor(7);
                            myFile.open ("promene.txt", ios_base::app);
                            myFile << "> " << i -> getIme() << " (nadlezni) je otpusten/a." << endl;
                            myFile.close();
                            upisiFajlVozaci();
                            return;
                            }
                    }
                }
                else{
                        for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){
                                ofstream myFile;
                                sviVozaci.erase(i);
                                cout << endl;
                                textcolor(8); cout << line << " je otpusten/a." << endl << endl; textcolor(7);
                                myFile.open ("promene.txt", ios_base::app);
                                myFile << "> " << i -> getIme() << " (vozac) je otpusten/a." << endl;
                                myFile.close();
                                upisiFajlVozaci();
                                return;
                        }
                cout << endl;
                textcolor(8); cout << line << " nije otpusten/a." << endl << endl; textcolor(7);
                }
                upisiFajlVozaci();
                break;
        }

        upisiFajlNadlezni();
        upisiFajlZaposleni();
        upisiFajlVozaci();
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

    void pretragaZaposlenih() const{
        int x, y, z;
        string line;
        double p;
        cout << "Opcije za pretragu: " << endl << endl; textcolor(7);
        textcolor(8); cout  << "1.  "; textcolor(7);
        cout << "Pretraga po imenu zaposlenog" << endl;
        textcolor(8); cout  << "2.  "; textcolor(7);
        cout << "Pretraga po plati zaposlenog" << endl;
        textcolor(8); cout  << "3.  "; textcolor(7);
        cout << "Pretraga po godinama staza zaposlenog" << endl;
        textcolor(8); cout  << "4.  "; textcolor(7);
        cout << "Pretraga po polu zaposlenog" << endl;
        textcolor(8); cout  << "5.  "; textcolor(7);
        cout << "Pretraga po kategoriji vozacke dozvole zaposlenog" << endl;
        textcolor(8); cout  << "6.  "; textcolor(7);
        cout << "Pretraga po mestu stanovanja zaposlenog" << endl;
        textcolor(8); cout  << "7.  "; textcolor(7);
        cout << "Pretraga po ovlascenjima zaposlenog" << endl << endl;
        cout << "Ukucajte broj zeljenog nacina pretrage." << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        textcolor(8); cout << "> "; textcolor(7);
        cin >> x;
        switch(x){
            case 1:
                z = 0;
                fflush(stdin);
                cout << endl << "Unesite puno ime zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                getline(cin, line);
                cout << endl;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getIme() == line){cout << *i; z++;}
                if(z == 0){textcolor(8);  cout << "Nepostoji zaposleni sa takvim imenom." << endl << endl; textcolor(7);}
                break;
            case 2:
                z = 0;
                cout << endl << "Unesite platu zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                cin >> p;
                cout << endl;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getPlata() == p){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa takvom platom." << endl << endl; textcolor(7);}
                break;
            case 3:
                z = 0;
                cout << endl << "Unesite godine staza zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                cin >> y;
                cout << endl;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getGodineStaza() == y){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa toliko godina staza." << endl << endl; textcolor(7);}
                break;
            case 4:
                z = 0;
                cout << endl << "Unesite pol zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                cin >> line;
                cout << endl;
                if(line == "muski") x = 0;
                else if(line == "zenski") x = 1;
                else{
                        textcolor(8); cout << "Nepostoji zaposleni tog pola." << endl << endl; textcolor(7);
                        break;
                }
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getPol() == x){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa toliko godina staza." << endl << endl; textcolor(7);}
                break;
            case 5:
                z = 0;
                cout << endl << "Unesite kategoriju vozacke dozvole zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                cin >> line;
                cout << endl;
                if(line == "B") x = 0;
                else if(line == "C") x = 1;
                else if(line == "D") x = 2;
                else{
                    textcolor(8); cout << "Nepostoji zaposleni sa takvom vozackom dozvolom." << endl << endl; textcolor(7);
                    break;
                }
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getVozackaDozvola() == x){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa takvom vozackom dozvolom." << endl << endl; textcolor(7);}
                break;
            case 6:
                z = 0;
                fflush(stdin);
                cout << endl << "Unesite mesto stanovanja zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                getline(cin, line);
                cout << endl;
                for(auto i = sviZaposleni.begin(); i != sviZaposleni.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                for(auto i = sviVozaci.begin(); i != sviVozaci.end(); i++) if(i -> getMestoStanovanja() == line){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni sa tim mestom stanovanja." << endl << endl; textcolor(7);}
                break;
            case 7:
                z = 0;
                cout << endl << "Unesite ovlascenja zaposlenih koje zelite da pronadjete:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                cin >> line;
                cout << endl;
                if(line == "true" || line == "1") x = 1;
                else if(line == "false" || line == "0") x = 0;
                else{
                        textcolor(8); cout << "Nepostoji zaposleni tog ovlascenja." << endl << endl; textcolor(7);
                        break;
                }
                for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getOvlascenje() == x){cout << *i; z++;}
                if(z == 0){textcolor(8); cout << "Nepostoji zaposleni tog ovlascenja." << endl << endl; textcolor(7);}
                break;
        }
    }

    void dodeliOvlascenje(string line){
    int y = 0, w = 0;
    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line) y++;
    if(y > 1){
    vector <Nadlezni> n;
    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line) n.push_back(*i);
    do{
            system("cls");
            cout << "JGSP - dodeljivanje ovlascenja" << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            cout << "Postoji vise zaposlenih s tim imenom, ukucajte redni broj od zaposlenog kome zelite da dodelite ovlascenja:" << endl << endl;
            pretragaRezime(line);
            textcolor(8); cout << "> "; textcolor(7);
            cin >> w;
            cout << endl;
            if(w < 1 || w > y){
                    cout << endl;
                    textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od brojeva u intervalu [1," << y << "] !!!" << endl; textcolor(7);
                    cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                    while(!kbhit()){}
                    getch();
            }
        }while(w < 1 || w > y);
    ofstream myFile;
    y = 0;
    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){
            y++;
            if(y == w){
                if(i -> getOvlascenje() == true){
                    textcolor(8); cout << endl << "Ne mozete dodeliti ovlascenja nadleznom koji vec ima ovlascenja." << endl; textcolor(7);
                    cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                    while(!kbhit()){}
                    getch();
                    break;
                }
                i -> setOvlascenje(true);
                textcolor(8); cout << line << " je dobio/la ovlascenja." << endl << endl; textcolor(7);
                myFile.open ("promene.txt", ios_base::app);
                myFile << "> " << i -> getIme() << " je dobio/la ovlascenja." << endl;
                myFile.close();
                return;
            }
        }
    }
    else{
            for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) if(i -> getIme() == line){
                    if(i -> getOvlascenje() == true){
                        textcolor(8); cout << endl << "Ne mozete dodeliti ovlascenja nadleznom koji vec ima ovlascenja." << endl; textcolor(7);
                        break;;
                    }
                    ofstream myFile;
                    i -> setOvlascenje(true);
                    textcolor(8); cout << endl << line << " je dobio/la ovlascenja." << endl << endl; textcolor(7);
                    myFile.open ("promene.txt", ios_base::app);
                    myFile << "> " << i -> getIme() << " je dobio/la ovlascenja." << endl;
                    myFile.close();
                    return;
            }
            cout << endl;
            textcolor(8); cout << line << " nije dobio/la ovlascenja." << endl << endl; textcolor(7);
    }
}

    void upisiBazu(){
    ofstream myFile;
    myFile.open ("sviZaposleni.txt");
    textcolor(8); myFile << "Obicni zaposleni:" << endl; textcolor(7);
    for(auto u = sviZaposleni.begin(); u != sviZaposleni.end(); u++) myFile << *u;
    textcolor(8); myFile << endl << "Vozaci:" << endl; textcolor(7);
    for(auto o = sviVozaci.begin(); o != sviVozaci.end(); o++) myFile << *o;
    textcolor(8); myFile << endl << "Nadlezni:" << endl; textcolor(7);
    for(auto i = sviNadlezni.begin(); i != sviNadlezni.end(); i++) myFile << *i;
    myFile.close();
}
};

#endif // BAZAPODATAKAZAPOSLENIH_HPP_INCLUDED
