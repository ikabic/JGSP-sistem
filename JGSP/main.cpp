#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

#include "autobus.hpp"
#include "ekonomija.hpp"
#include "kamion.hpp"
#include "skladiste.hpp"
#include "saobracaj.hpp"
#include "vozilo.hpp"
#include "funkcije.hpp"

int Skladiste::slobodanProstor = 10000;
int Ekonomija::ukupnaZarada = 0;
int Ekonomija::ukupnaPotrosnja = 0;

int main()
{
    BazaPodatakaZaposlenih b;
    b.ucitajSve();
    start(b);
    return 0;
}
