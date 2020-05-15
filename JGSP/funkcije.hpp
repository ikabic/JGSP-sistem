#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED

#include "bazaPodatakaZaposlenih.hpp"

void textcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
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

void readFile(string fileName){
    string line;
    ifstream myFile(fileName);
    if (myFile.is_open()){
        while (getline(myFile,line)) cout << line << endl;
        myFile.close();
    }
    else cout << "Greska prilikom otvaranja fajla.";
}

void meni(BazaPodatakaZaposlenih &b){
    //int x;
    string line;
    cout << "JGSP - pocetna stranica" << endl;
    textcolor(8); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << "Dobrodosli, ovo su trenutno dostupne funkcije naseg sajita:" << endl;
    textcolor(8); cout << "1. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "2. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "3. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "4. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "5. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "6. "; textcolor(7);
    cout << endl;
    textcolor(8); cout << "7. "; textcolor(7);
    cout << endl << "Ukucajte broj od zeljene funkcije." << endl;
    textcolor(8); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
}

#endif // FUNKCIJE_HPP_INCLUDED
