/* 
Daiga Leitāne dl25036
Programma izveidota 06.12.2025

Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus un
strukturējot programmu vismaz trīs failos. Klases hederi obligāti novietot atsevišķā
hedera failā (program.h). Visas metodes realizēt ārpus hedera faila – speciālā C++ failā
(program.cpp). Funkcija main ievietojama vēl citā C++ failā (main.cpp).
Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne, kāda tika
prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt).

D6. Izveidot klasi "Skaitļu rinda" - Nqueue (queue, pa vienu pusi ieliek, pa otru izņem!),
kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā pieci un rindas elementu
skaits. Klasei izveidot šādas metodes: (1) konstruktors, (2) destruktors,
kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu
(ja likvidēšanas brīdī rinda nav tukša), (3) metode "Ielikt" - enqueue,
kas pievieno rindai elementu, ja tā nav pilna, (4) metode "Izņemt" - dequeue,
kas izņem no rindas elementu un atgriež tā vērtību, (5) metode "CikElementu" - count,
kas atgriež elementu skaitu rindā, (6) metode "IrTukša" - isEmpty, kas noskaidro, vai
rinda ir tukša.

Klase Nqueue attēlo statisku veselu skaitļu masīvu ar garumu 5 un rindas elementu skaitu.

Realizētās metodes:
konstruktors,
destruktors,
bool enqueue() - pievieno elementu rindai, ja tā nav pilna
int dequeue() - izņem elementu no rindas elementu un atgriež tā vērtību
int getCount() - atgriež elementu skaitu rindā
int isEmpty() - pārbauda vai rinda ir tukša
*/

#include <iostream>
#include "program.h"

using namespace std;

int main() {

    Nqueue rinda;

    cout << "\nElementu skaits: " << rinda.getCount() << endl;
    cout << "Vai rinda ir tukša? " << (rinda.isEmpty() ? "Jā" : "Nē") << endl;

    cout << "\n## Elementu pievienošana ##" << endl;
    for (int i = 1; i <= 6; i++) {
        if (rinda.enqueue(i * 3)) {
            cout << "Pievienots elements: " << i * 3 << endl;
        } else {
            cout << "Neizdevās pievienot: " << i * 3 << " (rinda ir pilna)" << endl;
        }
    }


    cout << "\n## Elementu izņemšana ##" << endl;
    cout << "Elementu skaits pirms izņemšanas: " << rinda.getCount() << endl;

    for (int i = 0; i < 3; i++) {
        int value = rinda.dequeue();
        if (value != -1) {
            cout << "Izņemts elements: " << value << endl;
        }
    }
    cout << "Elementu skaits pēc izņemšanas: " << rinda.getCount() << endl;

    cout << "\n## Visu elementu izņemšana ##" << endl;
    while (!rinda.isEmpty()) {
        cout << "Izņemts elements: " << rinda.dequeue() << endl;
    }
    cout << "Elementu skaits pēc izņemšanas: " << rinda.getCount() << endl;

    cout << "\n## Elementu izņemšana no tukšas rindas ##" << endl;
    int value = rinda.dequeue();
    cout << "Elementu skaits: " << rinda.getCount() << endl;
    if (value == -1) {
        cout << "Nevar izņemt elementus, rinda ir tukša!" << endl;
    }

    cout << "\nProgrammas beigas. Destruktors tika izsaukts automātiski" << endl;

    return 0;
}
