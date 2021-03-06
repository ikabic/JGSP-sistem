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

    Datum(const Datum &d){
        dan = d.dan;
        mesec = d.mesec;
        godina = d.godina;
    }

    int getDan() const{return dan;}
    int getMesec() const{return mesec;}
    int getGodina() const{return godina;}
    void setDan(int d){dan = d;}
    void setMesec(int m){mesec = m;}
    void setGodina(int g){godina = g;}

    friend ostream& operator<<(ostream& output, const Datum &d);
};

ostream& operator<<(ostream& output, const Datum &d){
    output << d.dan << "." << d.mesec << "." << d.godina << "." << endl;
    return output;
}

#endif // DATUM_HPP_INCLUDED
