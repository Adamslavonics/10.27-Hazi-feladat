#include <iostream>
#include <string>
#include <cstdlib> // Véletlenszám-generáláshoz

using namespace std;

// Diák struktúra létrehozása
struct Diak {
    string nev;
    int szulEv;
    int mathJegy;
    int fizikaJegy;
    int testnevelesJegy;
};

int main() {
    srand((unsigned int)time(0)); // Véletlenszám-generálás inicializálása

    const int MAX_LETSZAM = 20;
    Diak diakok[MAX_LETSZAM];
    int letszam;
    float mathAtlag = 0, fizikaAtlag = 0, testnevelesAtlag = 0;

    // Osztály létszámának bekérése és ellenõrzése
    do {
        cout << "Adja meg az osztaly letszamat: ";
        cin >> letszam;
    } while (letszam < 1 || letszam > MAX_LETSZAM);

    // Diákok adatainak bekérése
    for (int i = 0; i < letszam; i++) {
        cin.ignore(); 
        cout << "\nAdja meg a(z) " << i + 1 << ". diak nevet: ";
        getline(cin, diakok[i].nev);

        cout << "Adja meg a szuletesi evet: ";
        cin >> diakok[i].szulEv;

        do {
            cout << "Matematika jegy: ";
            cin >> diakok[i].mathJegy;
        } while (diakok[i].mathJegy < 1 || diakok[i].mathJegy > 5);

        do {
            cout << "Fizika jegy: ";
            cin >> diakok[i].fizikaJegy;
        } while (diakok[i].fizikaJegy < 1 || diakok[i].fizikaJegy > 5);

        // Testnevelés jegy véletlenszerû generálása
        diakok[i].testnevelesJegy = rand() % 5 + 1;
        cout << "Testneveles jegy: " << diakok[i].testnevelesJegy << "\n";

        // Átlagok számítása
        mathAtlag += diakok[i].mathJegy;
        fizikaAtlag += diakok[i].fizikaJegy;
        testnevelesAtlag += diakok[i].testnevelesJegy;
    }

    // Osztályátlagok kiszámítása
    mathAtlag /= letszam;
    fizikaAtlag /= letszam;
    testnevelesAtlag /= letszam;

    // Legidõsebb diák keresése
    int legoregebbEv = diakok[0].szulEv;
    string legoregebbNev = diakok[0].nev;
    for (int i = 1; i < letszam; i++) {
        if (diakok[i].szulEv < legoregebbEv) {
            legoregebbEv = diakok[i].szulEv;
            legoregebbNev = diakok[i].nev;
        }
    }

    // Eredmények kiírása
    cout << "\nAz osztaly atlagai:\n";
    cout << "Matematika atlaga: " << mathAtlag << endl;
    cout << "Fizika atlaga: " << fizikaAtlag << endl;
    cout << "Testneveles atlaga: " << testnevelesAtlag << endl;

    cout << "\nA legidosebb diak:\n";
    cout << "Nev: " << legoregebbNev << endl;
    cout << "Szuletesi ev: " << legoregebbEv << endl;

    return 0;
}
