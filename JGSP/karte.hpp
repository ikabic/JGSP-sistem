#ifndef KARTE_HPP_INCLUDED
#define KARTE_HPP_INCLUDED

#include "datum.hpp"

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
public:
    Karte(SveZone z, Korisnik tipK, Trajanje tipT, int k, int d, int m, int g):datumProdaje(d,m,g){
        zona = z;
        tipPoKorisniku = tipK;
        tipPoTrajanju = tipT;
        kolicina = k;
    }
};

#endif // KARTE_HPP_INCLUDED
