#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED

#include "bazaPodatakaZaposlenih.hpp"
#include "formular.hpp"

void textcolor(unsigned short color){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

bool prazanFile(string imeFajla){
    ifstream myFile(imeFajla);
    if(myFile.peek() == EOF) return true;
    else return false;
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

void printLogs(){
    system("cls");
    cout << "JGSP - logs" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << endl;
    readFile("promene.txt");
    cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    while(!kbhit()){}
    getch();
}

void meni(BazaPodatakaZaposlenih &b, Zaposleni* z, int a, Ekonomija &e){
    int x, i = 1, y = 0, w = 0;
    string line;
    system("cls");
    cout << "JGSP - pocetna stranica" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << "Dobrodosli, ovo su Vama trenutno dostupne funkcije naseg sajita:" << endl << endl;
    textcolor(8); cout << i << ".  "; textcolor(7); i++;
    cout << "Lista svih zaposlenih" << endl;
    textcolor(8); cout << i << ".  "; textcolor(7); i++;
    cout << "Pregled rezimea" << endl;

    if(a == 1 || a == 2 || a == 3){
        textcolor(8); cout << i << ".  "; textcolor(7); i++;
        cout << "Prodaja dobara (nedovrsena)" << endl;
    }

    if(a == 2 || a == 3){
        textcolor(8); cout << i << ".  "; textcolor(7); i++;
        cout << "Nabavka resursa (nedovrsena)" << endl;
        textcolor(8); cout << i << ".  "; textcolor(7); i++;
        cout << "Pretraga zaposlenih po karakteristikama" << endl;
        textcolor(8); cout << i << ".  "; textcolor(7); i++;
        cout << "Pregled podataka zaposlenih (nedovrsena)" << endl;
        if(a == 3){
            textcolor(8); cout << i << ".  "; textcolor(7); i++;
            cout << "Zaposljavanje novih radnika" << endl;
            textcolor(8); cout << i << ".  "; textcolor(7); i++;
            cout << "Otpustanje zaposlenih" << endl;
            textcolor(8); cout << i << ".  "; textcolor(7); i++;
            cout << "Dodeljivanje povisica" << endl;
            textcolor(8); cout << i << ". "; textcolor(7); i++;
            cout << "Dodeljivanje ovlascenja" << endl;
        }
    }

    textcolor(8); cout << endl << "0.  "; textcolor(7);
    cout << "Exit" << endl;
    cout << endl << "Ukucajte broj od zeljene funkcije." << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    textcolor(8); cout << "> "; textcolor(7);
    cin >> x;

    switch(x){
    case 0:
        return;
    case 1:
        system("cls");
        cout << "JGSP - lista svih zaposlenih" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        b.ispisiZaposlene(0);
        break;
    case 2:
        system("cls");
        cout << "JGSP - pregled rezimea" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        if(a == 1 || a == 0){
                cout << endl << endl;
                z -> printRezime();
                cout << endl;
        }
        else{
                cout << "Unesite ime zaposlenog ciji rezime zelite da pregledate:" << endl;
                textcolor(8); cout << "> "; textcolor(7);
                fflush(stdin);
                getline(cin, line);
                cout << endl;
                b.pretragaRezime(line, -1);
        }
        break;
    case 3:
        textcolor(8); cout << endl << "Funkcija nije dovrsena." << endl << endl; textcolor(7);
        break;
        if(a < 1){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        system("cls");
        cout << "JGSP - prodaja dobara" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        //e.prodajKartu()
        break;
    case 4:
        textcolor(8); cout << endl << "Funkcija nije dovrsena." << endl << endl; textcolor(7);
        break;
        if(a < 2){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        break;
    case 5:
        if(a < 2){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        system("cls");
        cout << "JGSP - pretraga zaposlenih po karakteristikama" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        b.pretragaZaposlenih();
        break;
    case 6:
        textcolor(8); cout << endl << "Funkcija nije dovrsena." << endl << endl; textcolor(7);
        break;
         if(a < 2){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        break;
    case 7:
        if(a < 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        y = 0;
        do{
            system("cls");
            cout << "JGSP - unos novog zaposlenog" << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            cout << "Izaberite poziciju novog zaposlenog:" << endl << endl;
            textcolor(8); cout << "1.  "; textcolor(7);
            cout << "Nadlezni" << endl;
            textcolor(8); cout << "2.  "; textcolor(7);
            cout << "Obican zaposleni" << endl;
            textcolor(8); cout << "3.  "; textcolor(7);
            cout << "Vozac" << endl;
            cout << endl << "Ukucajte broj od zeljene opcije." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            textcolor(8); cout << "> "; textcolor(7);
            cin >> y;
            if(y < 1 || y > 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl; textcolor(7);
                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                while(!kbhit()){}
                getch();
            }
        }while(y < 1 || y > 3);
        system("cls");
        formular(b, y);
        break;
    case 8:
        if(a < 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        w = 0;
        do{
            system("cls");
            cout << "JGSP - otpustanje zaposlenih" << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            cout << "Unesite poziciju zaposlenog kog zelite da otpustite:" << endl << endl;
            textcolor(8); cout << "1.  "; textcolor(7);
            cout << "Nadlezni" << endl;
            textcolor(8); cout << "2.  "; textcolor(7);
            cout << "Obican zaposleni" << endl;
            textcolor(8); cout << "3.  "; textcolor(7);
            cout << "Vozac" << endl;
            cout << endl << "Ukucajte broj od zeljene opcije." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            textcolor(8); cout << "> "; textcolor(7);
            cin >> w;

            if(w < 1 || w > 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl; textcolor(7);
                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                while(!kbhit()){}
                getch();
                system("cls");
            }
        }while(w < 1 || w > 3);

        system("cls");
        cout << "JGSP - otpustanje zaposlenih" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        cout << "Unesite ime zaposlenog kog zelite da otpustite:" << endl;
        textcolor(8); cout << "> "; textcolor(7);
        fflush(stdin);
        getline(cin, line);
        b.otpustiIliPovisicaZaposlenog(w, line, 1);
        break;
    case 9:
        if(a < 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        w = 0;
        do{
            system("cls");
            cout << "JGSP - dodeljivanje povisica" << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            cout << "Unesite poziciju zaposlenog kom zelite da date povisicu:" << endl << endl;
            textcolor(8); cout << "1.  "; textcolor(7);
            cout << "Nadlezni" << endl;
            textcolor(8); cout << "2.  "; textcolor(7);
            cout << "Obican zaposleni" << endl;
            textcolor(8); cout << "3.  "; textcolor(7);
            cout << "Vozac" << endl;
            cout << endl << "Ukucajte broj od zeljene opcije." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            textcolor(8); cout << "> "; textcolor(7);
            cin >> w;

            if(w < 1 || w > 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl; textcolor(7);
                cout << endl << "Pritisnite bilo koje dugme za povratak" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                while(!kbhit()){}
                getch();
                system("cls");
            }
        }while(w < 1 || w > 3);

        system("cls");
        cout << "JGSP - dodeljivanje povisica" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        cout << "Unesite ime zaposlenog kom zelite da date povisicu:" << endl;
        textcolor(8); cout << "> "; textcolor(7);
        fflush(stdin);
        getline(cin, line);
        b.otpustiIliPovisicaZaposlenog(w, line, 2);
        break;
    case 10:
        if(a < 3){
                cout << endl;
                textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl << endl; textcolor(7);
                break;
        }
        system("cls");
        cout << "JGSP - dodeljivanje ovlascenja" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        cout << "Unesite ime nadleznog kome zelite da dodelite ovlascenja:" << endl;
        textcolor(8); cout << "> "; textcolor(7);
        fflush(stdin);
        getline(cin, line);
        b.dodeliOvlascenje(line);
        b.upisiFajlNadlezni();
        break;
    default:
        cout << endl;
        textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!"; textcolor(7);
        cout << endl << endl << "Pritisnite bilo koje dugme za povratak na pocetni meni." << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        while(!kbhit()){}
        getch();
        system("cls");
        meni(b, z, a, e);
    }

    if(x > 0 && x < 11){
        cout << "Pritisnite bilo koje dugme za povratak na pocetni meni." << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        while(!kbhit()){}
        getch();
        system("cls");
        meni(b, z, a, e);
    }
}

void start(BazaPodatakaZaposlenih &b, Ekonomija &e){
    string line;
    int x;
    bool a;
    Nadlezni n;
    Zaposleni z;
    Vozac v;
    system("cls");
    cout << "JGSP - stranica za prijavu" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    cout << "Da li se prijavljujete kao zaposleni ili kao nadlezni?" << endl << endl;
    textcolor(8); cout << "1.  "; textcolor(7);
    cout << "Nadlezni" << endl;
    textcolor(8); cout << "2.  "; textcolor(7);
    cout << "Obican zaposleni" << endl;
    textcolor(8); cout << "3.  "; textcolor(7);
    cout << "Vozac" << endl;
    cout << endl << "Ukucajte broj od zeljene opcije." << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    textcolor(8); cout << "> "; textcolor(7);
    cin >> x;

    if(x > 0 && x < 4){
        system("cls");
        cout << "JGSP - stranica za prijavu" << endl;
        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
        cout << "Unesite Vase puno ime i prezime." << endl;
        textcolor(8); cout << "> "; textcolor(7);
        fflush(stdin);
        getline(cin, line);
    }
    switch(x){
    case 1:
            n = b.pronadjiNadleznog(line, &a);
            break;
    case 2:
            z = b.pronadjiZaposlenog(line, &a);
            break;
    case 3:
            v = b.pronadjiVozaca(line, &a);
            break;
    default:
            cout << endl;
            textcolor(8); cout << "!!! Nepostojeca funkcija, molim Vas unesite jedan od ponudjenih brojeva !!!" << endl; textcolor(7);
            cout << endl << "Pritisnite bilo koje dugme za povratak na pocetni meni." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            while(!kbhit()){}
            getch();
            system("cls");
            start(b, e);
    }
    if(a == true){
            textcolor(10); cout << endl << "Pristup odobren." << endl; textcolor(7);
            cout << endl << "Pritisnite bilo koje dugme za nastavak." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            while(!kbhit()){}
            getch();
            system("cls");
            if(x == 1 && n.getOvlascenje() == true) meni(b, &n, 3, e);
            else if(x == 1 && n.getOvlascenje() == false) meni(b, &n, 2, e);
            else if(x == 2) meni(b, &z, 1, e);
            else if(x == 3) meni(b, &v, 0, e);
    }
    else{
            textcolor(4); cout << "Pristup odbijen."; textcolor(7);
            cout << endl << endl << "Pritisnite bilo koje dugme za povratak na pocetni meni." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            while(!kbhit()){}
            getch();
            system("cls");
            start(b, e);
    }
}

void resetujFile(string imeFajla){
        ofstream myFile;
        myFile.open(imeFajla);
        myFile << "";
        myFile.close();
}

vector<string> splitSen(string str, char c){
    string w = "";
    vector<string> v;
    for (auto rem : str){
        if (rem == c){
            v.push_back(w);
            w = "";
        }
        else w=w+rem;
    }
    v.push_back(w);
    return v;
}

#endif // FUNKCIJE_HPP_INCLUDED
