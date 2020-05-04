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

int Skladiste::slobodanProstor = 100;
int Ekonomija::ukupnaZarada = 0;
int Ekonomija::ukupnaPotrosnja = 0;

void citajFile(string fileName){
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
    return 0;
}
