#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <math.h>

using namespace std;

#include "autobus.hpp"
#include "ekonomija.hpp"
#include "kamion.hpp"
#include "skladiste.hpp"
#include "saobracaj.hpp"
#include "vozilo.hpp"
#include "bazaPodatakaZaposlenih.hpp"

int Skladiste::slobodanProstor = 10000;
int Ekonomija::ukupnaZarada = 0;
int Ekonomija::ukupnaPotrosnja = 0;

void textcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void readFile(string fileName){
    string line;
    ifstream myFile(fileName);
    if (myFile.is_open()){
        while (getline(myFile,line)) cout << line << endl;
        myFile.close();
    }
    else cout << "Greska prilikom otvaranja fajla.";
}

int brojRadnika(string imeFajla){
    int i = 0;
    string line;
    ifstream myFile(imeFajla);
    if (myFile.is_open()){
        while (getline(myFile,line)) i++;
        myFile.close();
    }
    else cout << "Greska prilikom otvaranja fajla.";
    return i;
}

void meni(){

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
    Nadlezni na(true, "Milan Milanovic", "8765432345", 8, muski, "Branka Bajica 38", "Novi Sad", 70000, 4, 5, 1971);
    Prodaja p;
    Saobracaj s;
    Skladiste sk;
    Usluge u;
    Vozac voz;
    Vozilo v;
    Zaposleni z("Marija Marinkovic", "010198835625", 2, zenski, "Brestovaca 9", "Beograd", 35000, 1, 1, 1988);
    BazaPodatakaZaposlenih b;
    z.printRezime();
    cout << endl;
    na.printRezime();
    cout << endl << endl;
    b.ucitajSve();
    b.ispisiSve();
    b.pretragaZaposlenih();
    return 0;
}
