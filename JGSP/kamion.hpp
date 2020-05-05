#ifndef KAMION_HPP_INCLUDED
#define KAMION_HPP_INCLUDED

enum VelicinaKamiona{mali = 50, srednji = 100, veliki = 150};

class Kamion:public Vozilo{
protected:
    VelicinaKamiona velicina;
public:
    Kamion(VelicinaKamiona v = mali, string mark = "", string registr = "", int godine = 0, TipGoriva gorivo = dizel, int k = 0, int d = 1, int m = 1, int g = 2000):Vozilo(mark, registr, godine, gorivo, k, d, m, g){
        velicina = v;
    }
};

#endif // KAMION_HPP_INCLUDED
