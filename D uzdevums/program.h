/*
Klase Nqueue attēlo statisku veselu skaitļu masīvu ar garumu 5 un rindas elementu skaitu.

Realizētās metodes:
konstruktors,
destruktors,
bool enqueue() - pievieno elementu rindai, ja tā nav pilna
int dequeue() - izņem elementu no rindas elementu un atgriež tā vērtību
int getCount() - atgriež elementu skaitu rindā
int isEmpty() - pārbauda vai rinda ir tukša
*/

class Nqueue {
private:
    int mas[5];    // Masīvs rindas elementiem
    int skaits;      // Elementu skaits rindā
    int elements;      // Indekss iepriekšējam elementam
    int nakosaiselements;       // Indekss nākamajam brīvajam vietai

public:
    // Konstruktors
    Nqueue();

    // Destruktors
    ~Nqueue();

    // Metode, kas pievieno elementu rindai
    bool enqueue(int value);

    // Metode, kas izņem elementu no rindas
    int dequeue();

    // Metode, kas atgriež elementu skaitu rindā
    int getCount() const;

    // Metode, kas pārbauda, vai rinda ir tukša
    bool isEmpty() const;
};
