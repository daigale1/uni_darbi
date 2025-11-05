/*
Daiga Leitāne, dl25036
C6. Izveidot C++ programmu, kur ir dota naturāls skaitlis n un veseli skaitļi a(1), a(2), ... a(n).
Atrast skaitli, kurš dotajā virknē atkārtojas visvairāk reižu pēc kārtas. Noteikt cik reizes tas atkārtojas.
Ja tādi skaitļi ir vairāki, tad izdrukāt lielāko.

Programma izveidota 6.11.2025

************Testa plāns************
n      Virkne                   Paredzamais rezultāts
5      3, 3, 2, 2, 2           Skaitlis: 2, atkārtojumu skaits: 3
4      1, 1, 2, 2              Skaitlis: 2, atkārtojumu skaits: 2 // lielākais no vienādiem
3      7, 7, 7                 Skaitlis: 7, atkārtojumu skaits: 3
5      1, 2, 3, 4, 5           Neviens skaitlis neatkārtojas. Lielākais skaitlis virknē: 5
0      -                       Kļūda, n jābūt naturālam skaitlim (n >= 1).
***********************************
*/

#include <iostream>
#include <vector>
using namespace std;

/*
int atrastlielako(const vector<int>& m):
int atrastlielako(m) -
kā rezultātu atgriež naturālu skaitļu vektora 'm' lielāko skaitli.
*/
int atrastlielako(const vector<int>& m) {
    int lielakais = m[0];
    for (int num : m) {
        if (num > lielakais) {
            lielakais = num;
        }
    }
    return lielakais;
}

/*
int atrastatkartojumu(const vector<int>& m):
int atrastatkartojumu(m) -
kā rezultātu atgriež naturālu skaitļu vektora 'm' skaitli ar vislielāko atkārtojumu skaitu.
*/
int atrastatkartojumu(const vector<int>& m) {
    int lielakaisatkartojums = 1; // Garākā atkārtoto skaitļu virkne
    int atkartojums = 1; // Pašreizējā atkārtojumu virkne
    int skaitlis = m[0]; // Skaitlis ar vislielāko atkārtojumu skaitu
    bool atkartojas = false;

    for (int i = 1; i < m.size(); i++) {
        if (m[i] == m[i - 1]) {
            atkartojums++;
            atkartojas = true;

            // Ja atrasta garāka atkārtojumu virkne
            if (atkartojums > lielakaisatkartojums) {
                lielakaisatkartojums = atkartojums;
                skaitlis = m[i];
            }
            // Ja atrasta tāda paša garuma virkne ar lielāku skaitli
            else if (atkartojums == lielakaisatkartojums && m[i] > skaitlis) {
                skaitlis = m[i];
            }
        } else {
            atkartojums = 1;
        }
    }

    if (!atkartojas) {
        int lielakais = atrastlielako(m);
        cout << "Neviens skaitlis neatkārtojas." << endl;
        cout << "Lielākais skaitlis virknē: " << lielakais << endl;
        return lielakais;
    } else {
        cout << "Skaitlis: " << skaitlis << ", atkārtojumu skaits: " << lielakaisatkartojums << endl;
        return skaitlis;
    }
}

int main() {
    int turpinat = 1;

    do{
        int n;

        do{
            cout << "Ievadiet naturālu skaitli n: ";
            cin >> n;

            if (n <= 0) cout << "Kļūda, n jābūt naturālam skaitlim (n >= 1)." << endl;
        } while (n <= 0);

        vector<int> m(n);
        cout << "Ievadiet " << n << " veselus skaitļus:" << endl;
        for (int i = 0; i < n; i++) {
            cin >> m[i];
        }

        cout << endl << "Ievadītie skaitļi: ";
        for (int sk : m) {
            cout << sk << " ";
        }
        cout << endl;

        int result = atrastatkartojumu(m);

        cout << "Vēlaties turpināt (1) vai beigt (0)? ";
        cin >> turpinat;

    } while (turpinat == 1);

    return 0;
}
