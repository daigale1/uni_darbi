///vienvirziena_main.cpp
/***********************************************************************
Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un
jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas
(piemēram, elementu pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.
G2. Uzrakstīt funkciju, kas salīdzina, vai divi saraksti ir vienādi.
** Papildinājums:
   x) Ievades pārbaude realizēta, izmantojot izņēmumsituāciju apstrādes mehānismu.
   y) Funkcija vienadi() iznesta ārā failā vienadi.cpp / vienadi.h un
      testēta atsevišķā projektā (skatīt vienadi_testi.cpp).
***********************************************************************/

/// Daiga Leitāne dl25036
/// Programma izveidota: 15.03.2026. Papildināta: x) un y) prasībām 17.05.2026

#include<iostream>
#include<string>
#include"vienadi.h"
using namespace std;
/**
int lasit(const string& ievade);
Funkcija lasit(ievade) -
 nolasa un atgriež veselu skaitli, ko ievada lietotājs.
 Izdrukā uzvedni ievade, pēc tam gaida ievadi.
 Ja ievadītā vērtība nav vesels skaitlis, izmet izņēmumsituāciju
 ar argumentu "Nav vesels skaitlis!".
*/
int lasit(const string& ievade){
int n;
cout << ievade << endl;
if(!(cin >> n)){
    cin.clear();
    cin.ignore(1000, '\n');
    throw string("Nav vesels skaitlis!");
}
return n;
}
/**
int parbaude(const string& ievade);
Funkcija parbaude(ievade) -
 nolasa un atgriež veselu skaitli, ko ievada lietotājs.
 Izdrukā uzvedni ievade, pēc tam gaida ievadi.
 Apstrādā izņēmumsituāciju no funkcijas lasit():
 ja ievadītā vērtība nav vesels skaitlis, izdrukā kļūdas paziņojumu
 un lūdz ievadīt vērtību atkārtoti.
*/
int parbaude(const string& ievade){
while(true){
    try{
        return lasit(ievade);
    }
    catch(const string& kļūda){
        cout << "Kļūda! " << kļūda << " Ievadiet skaitli: " << endl;
    }
}
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
tukšs (-999)         tukšs (-999)         VIENĀDI                 abi tukši
5 -999               tukšs (-999)         ATŠĶIRĪGI               viens tukšs
abc (ievade)         -                    kļūdas paziņojums       nederīga ievade
**********************************************************************************/
