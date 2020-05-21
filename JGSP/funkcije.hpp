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

void meni(BazaPodatakaZaposlenih &b, int a){
    int x, i = 1;
    string line;
    cout << "JGSP - pocetna stranica" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << "Dobrodosli, ovo su trenutno dostupne funkcije naseg sajita:" << endl << endl;
    textcolor(8); cout << i << ". "; textcolor(7); i++;
    cout << "Lista svih zaposlenih" << endl;
    textcolor(8); cout << i << ". "; textcolor(7); i++;
    cout << "Pregled rezimea" << endl;
    textcolor(8); cout << i << ". "; textcolor(7); i++;
    cout << "Prodaja dobara" << endl;

    if(a == 2 || a == 3){
        textcolor(8); cout << i << ". "; textcolor(7); i++;
        cout << "Nabavka resursa" << endl;
        textcolor(8); cout << i << ". "; textcolor(7); i++;
        cout << "Pretraga zaposlenih po karakteristikama" << endl;
        textcolor(8); cout << i << ". "; textcolor(7); i++;
        cout << "Pregled podataka zaposlenih" << endl;
        if(a == 3){
            textcolor(8); cout << i << ". "; textcolor(7); i++;
            cout << "Zaposljavanje novih radnika" << endl;
            textcolor(8); cout << i << ". "; textcolor(7); i++;
            cout << "Otpustanje zaposlenih" << endl;
        }
    }

    textcolor(8); cout << endl << "0. "; textcolor(7);
    cout << "Exit" << endl;
    cout << endl << "Ukucajte broj od zeljene funkcije." << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    textcolor(8); cout << "> "; textcolor(7);
    cin >> x;
    system("cls");

    switch(x){
    case 0:
        exit(0);
    case 1:
        cout << "JGSP - lista svih zaposlenih" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        b.ispisiZaposlene(0);
        break;
    case 2:
        cout << "JGSP - pregled rezimea" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        if(a == 1){}
        else{
                cout << "Unesite ime zaposlenog ciji rezime zelite da pregledate:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                fflush(stdin);
                getline(cin, line);
                cout << endl;
                //b.pretragaRezime(line);
                cout << endl;
        }
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    default:
        cout << endl;
        textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite broj u intervalu [1,8] !!!"; textcolor(7);
        Sleep(2000);
        system("cls");
        meni(b, a);
    }
    if(x > 0 && x < 9){
        cout << "Pritisnite bilo koje dugme za povratak na pocetni meni" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        while(!kbhit()){}
        system("cls");
        meni(b, a);
    }


}

void start(BazaPodatakaZaposlenih &b){
    string line;
    cout << "JGSP - stranica za prijavu" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << endl << endl << endl;


}

#endif // FUNKCIJE_HPP_INCLUDED
