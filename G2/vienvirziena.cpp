/***********************************************************************
Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un
jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas
(piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.
G2. Uzrakstīt funkciju, kas salīdzina, vai divi saraksti ir vienādi.
***********************************************************************/
/// Daiga Leitāne dl25036
/// Programma izveidota: 15.03.2026.

#include<iostream>
using namespace std;

struct elem{
    int num;
    elem *next;
    elem(int n){ num=n; next=NULL;}
};
/**
void append(elem* &first, elem* &last, int n);
Funkcija append(first, last, n) -
pievieno saraksta (first, last) beigās
elementu ar vērtību n.
*/
void append(elem* &first, elem* &last, int n){
    elem* p = new elem(n);
    if(first==NULL){
        first=last=p;
    }
    else{
        last->next=p;
        last=p;
    }
}
/**
void del(elem* &first);
Funkcija del(first) -
izdzēš sarakstu first (atbrīvo visu elementu dinamiski pieprasīto atmiņu).
*/
void del(elem* &first){
    while(first){
        elem *p = first->next;
        delete first;
        first=p;
    }
}
/**
void print(elem* first);
Funkcija print(first) -
izdrukā saraksta (first) elementus.
*/
void print(elem* first){
    elem* p=first;
    if(!p){cout<<"Tukšs saraksts"<<endl; return;}
    while(p){
        cout<<p->num<<" ";
        p=p->next;
    }
    cout<<endl;
}
/**
bool vienadi(elem* first1, elem* first2);
Funkcija vienadi(first1, first2) -
atgriež kā rezultātu true, ja vienvirziena saistītie saraksti (first1) un (first2)
ir vienādi - satur vienāda garuma elementu virknes ar vienādām vērtībām vienādās pozīcijās,
atgriež false pretējā gadījumā.
*/
bool vienadi(elem* first1, elem* first2){
    elem* p1=first1;
    elem* p2=first2;
    while(p1!=NULL and p2!=NULL){
        if(p1->num != p2->num) return false;
        p1=p1->next;
        p2=p2->next;
    }
    /// ja viens saraksts ir garāks par otru - tie nav vienādi
    return (p1==NULL and p2==NULL);
}
/**
int parbaude(const string& ievade);
Funkcija parbaude(ievade) -
nolasa un atgriež veselu skaitli, ko ievada lietotājs.
Izdrukā uzvedni ievade, pēc tam gaida ievadi.
Ja ievadītā vērtība nav vesels skaitlis, izdrukā kļūdas paziņojumu
un lūdz ievadīt vērtību atkārtoti.
*/
int parbaude(const string& ievade){
    int n;
    cout << ievade << endl;
    while(!(cin >> n)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Kļūda! Ievadiet skaitli: " << endl;
    }
    return n;
}

int main(){
int ok;
do{
/// first1, last1 - norādes uz pirmā saraksta pirmo un pēdējo mezglu
/// first2, last2 - norādes uz otrā saraksta pirmo un pēdējo mezglu
elem *first1=NULL, *last1=NULL;
elem *first2=NULL, *last2=NULL;
int i;

/// Pirmā saraksta ievade
i = parbaude("Ievadiet 1. saraksta elementu ('-999', ja gribat beigt ievadi):");
while(i!=-999){
    append(first1, last1, i);
    i = parbaude("Ievadiet 1. saraksta elementu ('-999', ja gribat beigt ievadi):");
}

/// Otrā saraksta ievade
i = parbaude("Ievadiet 2. saraksta elementu ('-999', ja gribat beigt ievadi):");
while(i!=-999){
    append(first2, last2, i);
    i = parbaude("Ievadiet 2. saraksta elementu ('-999', ja gribat beigt ievadi):");
}

/// Ievadīto sarakstu izdruka pirms salīdzināšanas
cout<<"1. saraksts: "; print(first1);
cout<<"2. saraksts: "; print(first2);

/// Salīdzina abus sarakstus un paziņo rezultātu
if(vienadi(first1, first2))
    cout<<"Saraksti ir VIENĀDI"<<endl;
else
    cout<<"Saraksti ir ATŠĶIRĪGI"<<endl;

/// Atbrīvo abus sarakstus no dinamiski pieprasītās atmiņas
del(first1);
del(first2);

ok = parbaude("Vai atkārtot (1) vai beigt (0)?");
}while(ok);
}
/******** Testa plāns *************************************************************
ievade 1. saraksts   ievade 2. saraksts   paredzamais rezultāts   kāpēc šāds tests
3 7 1 9 4 0          3 7 1 9 4 0          VIENĀDI                 identiski saraksti
3 7 1 9 4 0          3 7 2 9 4 0          ATŠĶIRĪGI               atšķiras vidū
1 2 3 0              1 2 3 4 0            ATŠĶIRĪGI               1. īsāks par 2.
1 2 3 4 0            1 2 3 0              ATŠĶIRĪGI               1. garāks par 2.
tukšs (0)            tukšs (0)            VIENĀDI                 abi tukši
5 0                  tukšs (0)            ATŠĶIRĪGI               viens tukšs
**********************************************************************************/
