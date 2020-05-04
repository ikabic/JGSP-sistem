#ifndef KAMION_HPP_INCLUDED
#define KAMION_HPP_INCLUDED

enum VelicinaKamiona{mali = 50, srednji = 100, veliki = 150};

class Kamion:public Vozilo{
protected:
    VelicinaKamiona velicina;
public:
    Kamion(VelicinaKamiona v, string mark, string registr, int godine, TipGoriva gorivo, int k, int d, int m, int g):Vozilo(mark, registr, godine, gorivo, k, d, m, g){
        velicina = v;
    }
};

#endif // KAMION_HPP_INCLUDED
