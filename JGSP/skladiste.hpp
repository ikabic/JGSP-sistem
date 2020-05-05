#ifndef SKLADISTE_HPP_INCLUDED
#define SKLADISTE_HPP_INCLUDED

class Skladiste{
protected:
    int rezervniDelovi;
    int karteAutobus;
    static int slobodanProstor; /// koliko proizvoda moze stati u skladiste
public:
    Skladiste(int delovi = 0, int karteA = 0){
        rezervniDelovi = delovi;
        karteAutobus = karteA;
    }

    int getKarte(){return karteAutobus;}
    void setKarte(int karte){karteAutobus = karte;}
};

#endif // SKLADISTE_HPP_INCLUDED
