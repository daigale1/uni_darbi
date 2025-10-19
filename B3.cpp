/*
Daiga Leitāne, dl25036
A3. Izveidot C++ programmu, kura dotajam skaitļu intervālam [m,n] izdrukā visus tos skaitļus,
kuri pieder šim intervālam un kurus var izteikt kā divu naturālu skaitļu kvadrātu summu
(izmantojot funkciju, kas pazīst vesela skaitļa kvadrātu).

Programma izveidota 11.10.2025

************Testa plāns************
    m    n        paredzamais rezultāts
    1   10        2, 5, 8, 10
    0    5        2, 5
    1    1        Šajā intervālā nav skaitļu, kurus var izteikt kā divu
                  naturālu skaitļu kvadrātu summu.
   32    2        Kļūda. Beigu vērtībai jābūt lielākai vai vienādai ar sākuma vērtību.
   -5    x        Kļūda. Sākuma vērtībai jābūt >= 0.
    x   -12       Kļūda. Beigu vērtībai jābūt >= 0.
***********************************
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
Funkcija kvadrats(sk) -
pārbauda, vai vesels skaitlis sk ir kāda vesela skaitļa kvadrāts.
Ja sakne no sk, noapaļota līdz veselam skaitlim, reizināta pati ar sevi dod sākotnējo sk,
tad funkcija atgriež true, pretējā gadījumā - false.
*/
bool kvadrats(int sk) {
    int sakne = int(sqrt(sk));
    return sakne * sakne == sk;
}

/*
Funkcija divu_kvadratu_summa(x) -
pārbauda, vai vesels skaitlis x var tikt izteikts kā divu naturālu skaitļu kvadrātu summa.
Funkcija pārbauda visus naturālos skaitļus a, sākot no 1 līdz √x, katram aprēķinot b² = x - a².
Ja b² ir pozitīvs un ir perfekts kvadrāts, funkcija atgriež true,
pretējā gadījumā - false.
*/
bool divu_kvadratu_summa(int x) {
    for (int a = 1; a <= int(sqrt(x)); a++) {
        int b_kv = x - a * a;
        if (b_kv > 0 && kvadrats(b_kv)) {
            return true;
        }
    }
    return false;
}

int main() {
    int turpinat = 1;

    while (turpinat == 1) {
        int m, n; // Lietotāja ievadītais intervāla [m,n] sākums un beigas
        int garums = n - m + 1; // Masīva garums
        int *rezultati = new int[garums]; // Masīvs, kurā saglabā atrastos skaitļus
        int skaits = 0; // Atrasto skaitļu skaits

        // Intervāla sākuma skaitļa ievade un skaitļa korektuma nodrošināšana.
        // Kamēr lietotāja ievade neatbilst nosacījumam m >= 0 tiek pieprasīta atkārtota skaitļa ievade.
        while (true) {
            cout << "Ievadi intervāla sākumu m (≥0): ";
            cin >> m;
            if (m < 0) {
                cout << "Kļūda. Sākuma vērtībai jābūt ≥0." << endl;
                continue;
            }
            break;
        }

        // Intervāla beigu skaitļa ievade un skaitļa korektuma nodrošināšana.
        // Kamēr lietotāja ievade neatbilst nosacījumam n >= 0 un n > m tiek pieprasīta atkārtota skaitļa ievade.
        while (true) {
            cout << "Ievadi intervāla beigas n (≥0): ";
            cin >> n;
            if (n < 0) {
                cout << "Kļūda. Beigu vērtībai jābūt ≥0." << endl;
                continue;
            }
            if (n < m) {
                cout << "Kļūda. Beigu vērtībai jābūt lielākai vai vienādai par sākuma vērtību." << endl;
                continue;
            }
            break;
        }

        // Saraksts, kurā tiek saglabāti visi skaitļi, kuri var tikt izteikti kā divu naturālu skaitļu kvadrātu summa.
        /* "for" cikls izskata visus skaitļus intervālā [m,n], funkcija divu_kvadratu_summa pārbauda
           vai konkrētais skaitlis num var tikt izteikts kā divu naturālu skaitļu kvadrātu summa, ja True, tas tiek
           pievienots sarakstam rezultati.
        */
        for (int num = m; num <= n; num++) {
            if (divu_kvadratu_summa(num)) {
                rezultati[skaits++] = num;
            }
        }

        // Rezultātu izvade
        cout << "\nSkaitļi intervālā [" << m << ", " << n
             << "], kurus var izteikt kā divu naturālu skaitļu kvadrātu summu:" << endl;

        // "for" cikls izskata visus sarakstā saglabātos elementus un izdrukā tos
        // if (i != skaits - 1) ievieto komatus starp skaitļiem izņemot pēc pēdējā skaitļa sarakstā
        if (skaits > 0) {
            for (int i = 0; i < skaits; i++) {
                cout << rezultati[i];
                if (i != skaits - 1)
                    cout << ", ";
            }
            cout << endl;
        } else {
            cout << "Šajā intervālā nav skaitļu, kurus var izteikt kā divu naturālu skaitļu kvadrātu summu." << endl;
        }

        // Atbrīvo atmiņu
        delete[] rezultati;

        // Cikla atkārtošanas iespēja
        cout << "\nVai vēlaties turpināt (1) vai beigt (0)? ";
        cin >> turpinat;
        cout << endl;
    }

    return 0;
}

