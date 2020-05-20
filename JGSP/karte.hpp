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
    Karte(SveZone z = I, Korisnik tipK = gradjanin, Trajanje tipT = jednokratno, double c = 0, int k = 0, int d = 1, int m = 1, int g = 2000):datumProdaje(d,m,g){
        zona = z;
        tipPoKorisniku = tipK;
        tipPoTrajanju = tipT;
        kolicina = k;
        cena = c;
    }

    int getKolicina() const{return kolicina;}
    double getCena() const{return cena;}
};

#endif // KARTE_HPP_INCLUDED
