#ifndef SKLADISTE_HPP_INCLUDED
#define SKLADISTE_HPP_INCLUDED

class Skladiste{
protected:
    int rezervniDelovi;
    int karteAutobus;
    int karteVoz;
    static int slobodanProstor; /// koliko proizvoda moze stati u skladiste
public:
    Skladiste(int delovi = 0, int karteA = 0, int karteV = 0){
        rezervniDelovi = delovi;
        karteAutobus = karteA;
        karteVoz = karteV;
    }
};

#endif // SKLADISTE_HPP_INCLUDED
