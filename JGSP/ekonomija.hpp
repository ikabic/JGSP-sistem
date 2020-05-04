#ifndef EKONOMIJA_HPP_INCLUDED
#define EKONOMIJA_HPP_INCLUDED

#include "prodaja.hpp"
#include "nabavka.hpp"

class Ekonomija{
protected:
    static int ukupnaZarada;
    static int ukupnaPotrosnja;
    Prodaja mesecnaProdaja;
    vector <Nabavka> mesecnaNabavka;
};

#endif // EKONOMIJA_HPP_INCLUDED
