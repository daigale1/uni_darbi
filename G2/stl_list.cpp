/***********************************************************************
Izveidot divas programmas valodā C++, kas strādā ar vērtību virkni divos dažādos veidos:
  1) to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
  2) izmantojot STL::list konteineru.
Abās realizācijās ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un
jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās, gan rezultējošās vērtības.
Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu
pievienošanai), kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.
G2. Uzrakstīt funkciju, kas salīdzina, vai divi saraksti ir vienādi.
***********************************************************************/
/// Daiga Leitāne dl25036
/// Programma izveidota: 15.03.2026.

#include<iostream>
#include<list>
using namespace std;
/**
void print(list<int> &lst);
Funkcija print(lst) -
izdrukā saraksta lst elementus.
*/
void print(list<int> &lst){
    if(lst.empty()){cout<<"Tukšs saraksts"<<endl; return;}
    for(auto &a: lst) cout<<a<<" ";
    cout<<endl;
}
/**
bool vienadi(list<int> &lst1, list<int> &lst2);
Funkcija vienadi(lst1, lst2) -
atgriež kā rezultātu true, ja STL saraksti lst1 un lst2
ir vienādi - satur vienāda garuma elementu virknes ar vienādām vērtībām vienādās pozīcijās,
atgriež false pretējā gadījumā.
*/
bool vienadi(list<int> &lst1, list<int> &lst2){
    /// dažāda garuma saraksti nevar būt vienādi
    if(lst1.size()!=lst2.size()) return false;
    auto i1=lst1.begin();
    auto i2=lst2.begin();
    while(i1!=lst1.end()){
        if(*i1!=*i2) return false;
        i1++; i2++;
    }
    return true;
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
list<int> lst1, lst2;
int i;
/// Pirmā saraksta ievade
i = parbaude("Ievadiet 1. saraksta elementu ('-999', ja gribat beigt ievadi):");
while(i!=-999){
    lst1.push_back(i);
    i = parbaude("Ievadiet 1. saraksta elementu ('-999', ja gribat beigt ievadi):");
}
/// Otrā saraksta ievade
i = parbaude("Ievadiet 2. saraksta elementu ('-999', ja gribat beigt ievadi):");
while(i!=-999){
    lst2.push_back(i);
    i = parbaude("Ievadiet 2. saraksta elementu ('-999', ja gribat beigt ievadi):");
}
/// Ievadīto sarakstu izdruka pirms salīdzināšanas
cout<<"1. saraksts: "; print(lst1);
cout<<"2. saraksts: "; print(lst2);
/// Salīdzina abus sarakstus un paziņo rezultātu
if(vienadi(lst1, lst2))
    cout<<"Saraksti ir VIENĀDI"<<endl;
else
    cout<<"Saraksti ir ATŠĶIRĪGI"<<endl;
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
