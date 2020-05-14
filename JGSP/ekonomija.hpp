#ifndef EKONOMIJA_HPP_INCLUDED
#define EKONOMIJA_HPP_INCLUDED

#include "prodaja.hpp"
#include "nabavka.hpp"
#include "skladiste.hpp"
#include "karte.hpp"

class Ekonomija{
protected:
    static int ukupnaPotrosnja;
    static int ukupnaZarada;
    Prodaja mesecnaProdaja;
    vector <Nabavka> mesecnaNabavka;
public:
    void nabavkaKarti(Skladiste &s, Nabavka &n){
        mesecnaNabavka.push_back(n);
        ukupnaPotrosnja -= n.getKolicina();
        s.setKarte(s.getKarte() + n.getKolicina());
    }

    bool prodajKartu(Skladiste &s, Karte &k){
        if(s.getKarte() > 0){
            mesecnaProdaja.setKarte(k);
            ukupnaZarada += k.getCena() * k.getKolicina();
            s.setKarte(s.getKarte() - k.getKolicina());
            return true;
        }

        int x;
        cout << "Nedovoljno resursa za prodaju, da li biste zeleli da nabavite jos?" << endl << "1.  Da            2.  Ne" << endl << "> ";
        cin >> x;
        if(x == 1){
        int d,m,g,kol;
        cout << "Unesite danasnji datum i kolicinu resursa: ";
        cin >> d >> m >> g >> kol;
        Nabavka n(kartaBus, 50, kol, d, m, g, d, m, g + 10);
        nabavkaKarti(s, n);
        cout << "Resursi uspesno nabavljeni, da li biste da pokusate da prodate karte ponovo?" << endl << "1.  Da            2.  Ne" << endl << "> ";
        cin >> x;
        if(x == 1) prodajKartu(s,k);
        }
        return false;
    }
};

#endif // EKONOMIJA_HPP_INCLUDED
