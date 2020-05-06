#ifndef GORIVO_HPP_INCLUDED
#define GORIVO_HPP_INCLUDED

enum TipGoriva{dizel, benzin, gas};

class Gorivo{
protected:
    TipGoriva tip;
    int kolicina;
public:
    Gorivo(TipGoriva t = dizel, int k = 0){
        kolicina = k;
        tip = t;
    }

    friend ostream& operator<<(ostream& output, const Gorivo &g);
};

ostream& operator<<(ostream& output, const Gorivo &g){
    output << "Tip goriva: " << g.tip << endl << "Kolicina goriva: " << g.kolicina <<endl;
    return output;
}

#endif // GORIVO_HPP_INCLUDED
