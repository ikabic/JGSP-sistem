#ifndef KARTE_HPP_INCLUDED
#define KARTE_HPP_INCLUDED

#include "datum.hpp"
#include "skladiste.hpp"

enum SveZone{I, II, III, IV, V, VI, VII, VIII, IX};
enum Korisnik{dete, student, penzioner, radnoLice, gradjanin};
enum Trajanje{jednokratno, mesecno, godisnje, nedeljno, dnevno};

class Karte{
protected:
    SveZone zona;
    Korisnik tipPoKorisniku;
    Trajanje tipPoTrajanju;
    Datum datumProdaje;
    int kolicina;
    double cena;
public:
    Karte(SveZone z, Korisnik tipK, Trajanje tipT, double c, int k, int d, int m, int g):datumProdaje(d,m,g){
        zona = z;
        tipPoKorisniku = tipK;
        tipPoTrajanju = tipT;
        kolicina = k;
        cena = c;
    }

    int getKolicina(){return kolicina;}
    double getCena(){return cena;}
};

#endif // KARTE_HPP_INCLUDED
