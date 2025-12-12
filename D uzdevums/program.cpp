#include "program.h"
#include <iostream>
using namespace std;

// Konstruktors
Nqueue::Nqueue() {
    skaits = 0;
    elements = 0;
    nakosaiselements = 0;
}

// Destruktors
Nqueue::~Nqueue() {
    cout << "\nLikvidēts objekts.";
    if (skaits > 0) {
        cout << " Likvidēto elementu skaits: " << skaits;
    }
    cout << endl;
}

// Metode, kas pievieno elementu rindai
bool Nqueue::enqueue(int value) {
    if (skaits >= 5) { 
        return false;
    }

    mas[nakosaiselements] = value;
    nakosaiselements = (nakosaiselements + 1) % 5;
    skaits++;
    return true;
}

// Metode, kas izņem elementu no rindas
int Nqueue::dequeue() {
    if (isEmpty()) {
        return -1; 
    }
    int value = mas[elements];
    elements = (elements + 1) % 5;
    skaits--;
    return value;
}

// Metode, kas atgriež elementu skaitu rindā
int Nqueue::getCount() const {
    return skaits;
}

// Metode, kas pārbauda, vai rinda ir tukša
bool Nqueue::isEmpty() const {
    return (skaits == 0);
}
