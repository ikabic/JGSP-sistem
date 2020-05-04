#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

class Datum{
protected:
    int dan, mesec, godina;
public:
    Datum(int d, int m, int g){
        dan = d;
        mesec = m;
        godina = g;
    }
};

#endif // DATUM_HPP_INCLUDED
