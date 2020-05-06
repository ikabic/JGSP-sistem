#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "autobus.hpp"
#include "ekonomija.hpp"
#include "kamion.hpp"
#include "skladiste.hpp"
#include "saobracaj.hpp"
#include "vozilo.hpp"
#include "zaposleni.hpp"
#include "vozac.hpp"
#include "nadlezni.hpp"

int Skladiste::slobodanProstor = 10000;
int Ekonomija::ukupnaZarada = 0;
int Ekonomija::ukupnaPotrosnja = 0;

void readFile(string fileName){
    string line;
    ifstream myFile(fileName);
    if (myFile.is_open()){
        while (getline(myFile,line)) cout << line << endl;
        myFile.close();
    }
    else cout << "Greska prilikom otvaranja fajla.";
}

int main()
{
    /// funkcionalnost: omogucavanje zaposlenom nakon logovanja da prodaje ili nabavlja resurse, ako je nadlezni
    Autobus a;
    Datum d;
    Ekonomija e;
    Gorivo g;
    Kamion k;
    Karte ka;
    Nabavka n;
    Nadlezni na;
    Prodaja p;
    Saobracaj s;
    Skladiste sk;
    Usluge u;
    Vozac voz;
    Vozilo v;
    Zaposleni z;
    readFile("zaposleni.txt");
    cout << z;
    cout << v;
    return 0;
}
