/***
H2. Dots teksta fails. Saskaitīt tekstā vārdus pēc to garumiem (1-burtīgie, 2-burtīgie utt.).
Programmai statistika pa vārdu garumiem jāsaliek tabulā, kas realizēta kā vārdnīca (STL map).
Programmas rezultātā iegūt failu, kas sastāv no skaitļu pārīšiem, kurā katram vārdu garumam dots vārdu skaits (piemēram, 1 110, 2 406, 3 632 utt.).
Par vārdiem tiek uzskatītas simbolu virknes, kas atdalītas ar tukšumiem un pieturzīmēm.

Autors: Daiga Leitāne
Programma izveidots: 11.04.2026
***/

#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

/**
void saskaitVardus(ifstream &fin, map<int,int> &garumi);
Funkcija saskaitVardus(fin, garumi) -
 nolasa tekstu no ieejas faila plūsmas fin,
 sadala tekstu vārdos (atdalītāji - tukšumi un pieturzīmes),
 katrā aizpildītajā map ierakstā (garumi) atslēga ir vārda garums,
 vērtība - cik reizes tekstā ir sastopami vārdi ar attiecīgo garumu.
*/
void saskaitVardus(ifstream &fin, map<int,int> &garumi){
    string vards = "";
    char c;
    while(fin.get(c)){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            vards += c;
        } else {
            if(!vards.empty()){
                garumi[(int)vards.length()]++;
                vards = "";
            }
        }
    }
    /// apstrādā pēdējo vārdu, ja fails nebeidzas ar atdalītāju
    if(!vards.empty()){
        garumi[(int)vards.length()]++;
    }
}

/**
void rezultats(ofstream &fout, const map<int,int> &garumi);
Funkcija rezultats(fout, garumi) -
 ieraksta rezultātu izejas faila plūsmā fout:
 katrā rindā - vārda garums un attiecīgo vārdu skaits, atdalīts ar atstarpi.
*/
void rezultats(ofstream &fout, const map<int,int> &garumi){
    for(auto &ieraksts : garumi){
        fout << ieraksts.first << " " << ieraksts.second << endl;
    }
}

int main(){
    int ok;

    do{
    string ievFails, izvFails;
    cout << "Ievadiet ieejas faila nosaukumu: " << endl;
    cin >> ievFails;
    cout << "Ievadiet izejas faila nosaukumu: " << endl;
    cin >> izvFails;

    ifstream fin(ievFails);
    if(!fin){
        cout << "Kļūda: nevar atvērt ieejas failu " << ievFails << endl;
        cout << "Vai vēlaties atkārtot(1) vai beigt(0)?" << endl;
        cin >> ok;
        continue;
    }
    ofstream fout(izvFails);
    if(!fout){
        cout << "Kļūda: nevar atvērt izejas failu " << izvFails << endl;
        fin.close();
        cout << "Vai vēlaties atkārtot(1) vai beigt(0)?" << endl;
        cin >> ok;
        continue;
    }

    map<int,int> garumi;
    saskaitVardus(fin, garumi);
    rezultats(fout, garumi);

    fin.close();
    fout.close();

    cout << "Rezultāts ierakstīts failā " << izvFails << endl;

    cout << "Vai vēlaties turpināt(1) vai beigt(0)?" << endl;
    cin >> ok;

    }while(ok == 1);

    return 0;
}

/**************  Testa plāns **********************************
ieejas faila saturs   paredzamais rezultāts
"Hello, world!"        5 2

"a bbb ccc dddd        1 1
 e ff"                 2 2
                       3 2
                       4 1

tukšs fails           tukšs izejas fails
***************************************************************/
