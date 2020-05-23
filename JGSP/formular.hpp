#ifndef FORMULAR_HPP_INCLUDED
#define FORMULAR_HPP_INCLUDED

void formular(BazaPodatakaZaposlenih &b, int a){
    cout << "JGSP - popunjavanje formulara" << endl;
    textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
    string ime, JMBG, mesto, adresa, datum, spol, sdan, smesec, sgodina;
    char v;
    VozackaDozvola voz;
    vector <string> p;
    int dan, mesec, godina;
    double plata;
    Polovi pol;
    textcolor(8); cout << endl << endl << "Puno ime novog zaposlenog: "; textcolor(7);
    fflush(stdin);
    getline(cin, ime);

    do{
        textcolor(8); cout << "Datum rodjenja novog zaposlenog: "; textcolor(7);
        fflush(stdin);
        getline(cin, datum);
        stringstream sve(datum);
        getline(sve, sdan, '.');
        getline(sve, smesec, '.');
        getline(sve, sgodina, '.');
        dan = atoi(sdan.c_str());
        mesec = atoi(smesec.c_str());
        godina = atoi(sgodina.c_str());

        if(dan < 0 || dan > 32 || mesec < 0 || mesec > 13 || godina < 1954 || godina > 2001){
                cout << endl << "Molim Vas unesite validan datum. Pritisnite bilo koje dugme za povratak." << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                while(!kbhit()){}
                getch();
                system("cls");
                cout << "JGSP - popunjavanje formulara" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                textcolor(8); cout << endl << endl << "Puno ime novog zaposlenog: "; textcolor(7);
                cout << ime << endl;
        }

    }while(dan < 0 || dan > 32 || mesec < 0 || mesec > 13 || godina < 1954 || godina > 2001);

    textcolor(8); cout << "JMBG novog zaposlenog: "; textcolor(7);
    fflush(stdin);
    getline(cin, JMBG);

    do{
        textcolor(8); cout << "Pol novog zaposlenog: "; textcolor(7);
        fflush(stdin);
        getline(cin, spol);

        if(spol != "muski" && spol != "zenski" && spol != "0" && spol != "1" && spol != "musko" && spol != "zensko"){
            cout << endl << "Molim Vas unesite validan pol. Pritisnite bilo koje dugme za povratak." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            while(!kbhit()){}
            getch();
            system("cls");
            cout << "JGSP - popunjavanje formulara" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                textcolor(8); cout << endl << endl << "Puno ime novog zaposlenog: "; textcolor(7);
                cout << ime << endl;
                textcolor(8); cout << "Datum rodjenja novog zaposlenog: "; textcolor(7);
                cout << dan << "." << mesec << "." << godina << "." << endl;
                textcolor(8); cout << "JMBG novog zaposlenog: "; textcolor(7);
                cout << JMBG << endl;
        }
        else if(spol == "muski" || spol == "musko" || spol == "0") pol = muski;
        else if(spol == "zenski" || spol == "zensko" || spol == "1") pol = zenski;
    }while(spol != "muski" && spol != "zenski" && spol != "0" && spol != "1" && spol != "musko" && spol != "zensko");

    textcolor(8); cout << "Adresu novog zaposlenog: "; textcolor(7);
    fflush(stdin);
    getline(cin, adresa);
    textcolor(8); cout << "Mesto stanovanja novog zaposlenog: "; textcolor(7);
    fflush(stdin);
    getline(cin, mesto);

    do{
        textcolor(8); cout << "Platu novog zaposlenog: "; textcolor(7);
        cin >> plata;

        if(plata < 20000 || plata > 75000){
            cout << endl << "Plata mora biti u intervalu [20000,75000]. Pritisnite bilo koje dugme za povratak." << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            while(!kbhit()){}
            getch();
            system("cls");
            cout << "JGSP - popunjavanje formulara" << endl;
            textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
            textcolor(8); cout << endl << endl << "Puno ime novog zaposlenog: "; textcolor(7);
            cout << ime << endl;
            textcolor(8); cout << "Datum rodjenja novog zaposlenog: "; textcolor(7);
            cout << dan << "." << mesec << "." << godina << "." << endl;
            textcolor(8); cout << "JMBG novog zaposlenog: "; textcolor(7);
            cout << JMBG << endl;
            textcolor(8); cout << "Pol novog zaposlenog: "; textcolor(7);
            if(pol == 0) cout << "muski" << endl;
            else cout << "zenski" << endl;
            textcolor(8); cout << "Adresu novog zaposlenog: "; textcolor(7);
            cout << adresa << endl;
            textcolor(8); cout << "Mesto stanovanja novog zaposlenog: "; textcolor(7);
            cout << mesto << endl;
        }

    }while(plata < 20000 || plata > 75000);

    cout << endl;
    if(a == 1){
        Nadlezni n(false, ime, JMBG, 0, pol, adresa, mesto, plata, dan, mesec, godina);
        b.dodajNadleznog(n);
        return;
    }
    if(a == 2){
        Zaposleni z(ime, JMBG, 0, pol, adresa , mesto, plata, dan, mesec, godina);
        b.dodajZaposlenog(z);
        return;
    }
    if(a == 3){
        do{
                system("cls");
                cout << "JGSP - popunjavanje formulara" << endl;
                textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                textcolor(8); cout << endl << endl << "Kategorija vozacke dozvole: "; textcolor(7);
                cin >> v;
                if(v != 'b' && v != 'd' && v != 'c' && v != 'B' && v != 'C' && v != 'D'){
                        cout << endl << "Molim Vas unesite validnu kategoriju [B,C,D]. Pritisnite bilo koje dugme za povratak." << endl;
                        textcolor(6); cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"; textcolor(7);
                        while(!kbhit()){}
                        getch();
                }
        }while(v != 'b' && v != 'd' && v != 'c' && v != 'B' && v != 'C' && v != 'D');
        if(v == 'b' || v == 'B') voz = B;
        else if(v == 'c' || v == 'C') voz = C;
        else voz = D;
        Vozac vz(voz, ime, JMBG, 0, pol, adresa, mesto, plata, dan, mesec, godina);
        b.dodajVozaca(vz);
}
}
#endif // FORMULAR_HPP_INCLUDED
