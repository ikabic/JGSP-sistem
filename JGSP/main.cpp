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
   /* /// funkcionalnost: omogucavanje zaposlenom nakon logovanja da prodaje ili nabavlja resurse, ako je nadlezni
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
    Vozac voz(C, "Katarina Katarinovic", "8536853685343", 2, zenski, "Narodnih heroja 9", "Sabac", 45000, 27, 6, 2000);
    Vozilo v;
    Zaposleni za("Marija Marinkovic", "010198835625", 2, zenski, "Brestovaca 9", "Beograd", 35000, 1, 1, 1988);

    Zaposleni* z = &za;
    textcolor(4); cout << "Ispis 2 rezimea:" << endl << endl; textcolor(7);
    z -> printRezime(); /// ispis virtuelne metode
    cout << endl;
    z = &na;
    z -> printRezime(); /// ispis redefinisane virtuelne metode
    cout << endl << endl;

    /// drugi primer virtualnosti je u zaposleni.hpp i klasama koje nasledjuju klasu Zaposleni kod rada s fajlovima, ali to bas ne mogu da prikazem u mainu

    BazaPodatakaZaposlenih b;
    b.ucitajSve(); /// ucitavanje vec upisanih zaposlenih iz fajla u vektor

    textcolor(4); cout << "Ispis pre zaposljavanja:" << endl << endl; textcolor(7);
    b.ispisiZaposlene(2);
    b.dodajVozaca(voz); /// dodavanje u vektor
    textcolor(4); cout << endl << "Ispis posle zaposljavanja:" << endl << endl; textcolor(7);
    b.ispisiZaposlene(2);

    /// isti sistem za obicne zaposlene i nadlezne^

    textcolor(4); cout << "Ispis svih zaposlenih:" << endl << endl; textcolor(7);
    b.ispisiZaposlene(4);

    textcolor(4); cout << "Ispis pre otpustanja:" << endl << endl; textcolor(7);
    b.ispisiZaposlene(2);
    b.otpustiZaposlenog(2);
    textcolor(4); cout << endl << "Ispis posle otpustanja:" << endl << endl; textcolor(7);
    b.ispisiZaposlene(2);

    /// isti sistem za obicne zaposlene i nadlezne^

    b.pretragaZaposlenih(); /// pretraga zaposlenih u vektoru po razlicitim kriterijumima*/

    BazaPodatakaZaposlenih b;
    b.ucitajSve();
    meni(b, 3);
    start(b);

    return 0;
}
