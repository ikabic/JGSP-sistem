#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

class Datum{
protected:
    int dan, mesec, godina;
public:
    Datum(int d = 1, int m = 1, int g = 2000){
        dan = d;
        mesec = m;
        godina = g;
    }

    friend ostream& operator<<(ostream& output, const Datum &d);
};

ostream& operator<<(ostream& output, const Datum &d){
    output << d.dan << "." << d.mesec << "." << d.godina << "." << endl;
    return output;
}

#endif // DATUM_HPP_INCLUDED
