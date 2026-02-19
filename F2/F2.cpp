/*******************************************************

Daiga Leitāne dl25036
F2. Doti divi teksta faili. Izveidot programmu, kura 
izveido trešo failu sekojoši: katras pirmā faila 
rindiņas galā ir pierakstīta atbilstoša otrā faila 
rindiņa. Ja rindiņu skaits atšķiras, atlikušās rindiņas
trešajā failā sakrīt ar garākā faila rindiņām.

Programma izveidota: 14.02.2026

********************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int ok;

    do
    {
        string fails1, fails2, rezultats;

        cout << "Ievadiet pirmā faila nosaukumu: ";
        cin >> fails1;

        cout << "Ievadiet otrā faila nosaukumu: ";
        cin >> fails2;

        cout << "Ievadiet rezultāta faila nosaukumu: ";
        cin >> rezultats;

        ifstream fails1_apstrade(fails1);
        ifstream fails2_apstrade(fails2);
        ofstream rezultats_fails(rezultats);

        if (!fails1_apstrade)
        {
            cout << "Kļūda! Nevar atvērt pirmo failu." << endl;
        }
        else if (!fails2_apstrade)
        {
            cout << "Kļūda! Nevar atvērt otro failu." << endl;
        }
        else if (!rezultats_fails)
        {
            cout << "Kļūda! Nevar izveidot rezultāta failu." << endl;
        }
        else
        {
            string rinda1, rinda2;

            while (true)
            {
                bool ir1 = false;
                bool ir2 = false;

                if (getline(fails1_apstrade, rinda1))
                    ir1 = true;

                if (getline(fails2_apstrade, rinda2))
                    ir2 = true;

                if (!ir1 && !ir2)
                    break;

                if (ir1 && ir2)
                    rezultats_fails << rinda1 << rinda2 << endl;
                else if (ir1)
                    rezultats_fails << rinda1 << endl;
                else
                    rezultats_fails << rinda2 << endl;
            }

            cout << "Apstrāde pabeigta veiksmīgi." << endl;
        }

        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;

    } while (ok == 1);

    return 0;
}

/*******************************************************
 Testa plāns

 1) Faili satur vienādu rindu skaitu:
    fails1.txt:
    A
    B
    C
    D

    fails2.txt:
    1
    2
    3
    4
    5

    rezultats.txt:
    A1
    B2
    C3
    D4

2) Faili satur atšķirīgu rindu skaitu:
    fails1.txt:
    A
    B
    C

    fails2.txt:
    1
    2
    3
    4
    5

    rezultats.txt:
    A1
    B2
    C3
    4
    5

3) Viens fails ir tukšs:
    fails1.txt:
    (tukšs)

    fails2.txt:
    1
    2
    3

    rezultats.txt:
    1
    2
    3

4) Viens fails neeksistē:
    Netiek izveidots rezultāta fails, un tiek izvadīts paziņojums:
    "Kļūda! Nevar atvērt pirmo/otro failu."
********************************************************/
