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
};

#endif // GORIVO_HPP_INCLUDED
