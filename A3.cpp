/*
Daiga Leitāne, dl25036
A3. Izveidot C++ programmu, kura ļauj ievadīt naturālu skaitli n un noskaidro
šī skaitļa pirmā un pēdējā cipara summu.
Skaitļa dalīšanu ciparos ir jāveic skaitliski.

Programma izveidota 14.09.2025

************Testa plāns************

    ievade   paredzamais rezultāts
     543              8
     21               3
     3                6
     -1       Kļūda. Jāievada naturāls skaitlis, kas ir >0.

***********************************
*/

#include <iostream>
using namespace std;

int main() {
    int turpinat = 1;

    while (turpinat == 1) {
        int n;

        // Skaitļa ievade un tā korektuma nodrošināšana
        cout << "Ievadiet naturālu skaitli (>0): ";
        cin >> n;

        while (n <= 0) {
            cout << "Kļūda. Jāievada naturāls skaitlis, kas ir >0." << endl;
            cout << "Ievadiet naturālu skaitli (>0): ";
            cin >> n;}

        // Aprēķina pēdējo ciparu
        // Cipars tiek iegūts skaitli dalot ar 10, iegūtais atlikums => pēdējais skaitlis
        int pedejais = n % 10;

        // Aprēķina pirmo ciparu
        // Cipars tiek iegūts skaitli dalot ar 10 līdz skaitlis satur tikai vienu ciparu. Iegūtais cipars => pirmais skaitlis
        int pirmais = n;
        while (pirmais >= 10) {
            pirmais = pirmais / 10;}

        // Aprēķina pirmā un pēdējā cipara summu
        int summa = pirmais + pedejais;
        cout << "Pirmā un pēdējā cipara summa ir: " << summa << endl;

        // Cikla atkārtošanas iespēja
        cout << "Vai vēlaties turpināt (1) vai beigt (0)? ";
        cin >> turpinat;
    }
    return 0;
}
