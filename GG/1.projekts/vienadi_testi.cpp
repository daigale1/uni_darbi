///vienadi_testi.cpp
/***********************************************************************
Sastādīt C++ projektu, kas veic G2 uzdevuma risinājumā
izveidotās funkcijas vienadi(first1, first2) vienībtestēšanu
sešos variantos.
***********************************************************************/
/// Daiga Leitāne dl25036
/// Programma izveidota: 17.05.2026.
#include<iostream>
#include"../vienvirziena_main/vienadi.h"
using namespace std;
void test1(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst identiski vienādus sarakstus (3 7 1) un (3 7 1)
elem *first1=NULL, *last1=NULL;
elem *first2=NULL, *last2=NULL;
append(first1, last1, 3); 
append(first1, last1, 7); 
append(first1, last1, 1);
append(first2, last2, 3); 
append(first2, last2, 7); 
append(first2, last2, 1);
  
if(vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
  
del(first1); del(first2);
}
void test2(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst sarakstus, kas atšķiras vidū: (3 7 1) un (3 9 1)
elem *first1=NULL, *last1=NULL;
elem *first2=NULL, *last2=NULL;
append(first1, last1, 3); 
append(first1, last1, 7); 
append(first1, last1, 1);
append(first2, last2, 3); 
append(first2, last2, 9); 
append(first2, last2, 1);
  
if(!vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
  
del(first1); del(first2);
}
void test3(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst, ka 1. saraksts ir īsāks par 2.: (1 2 3) un (1 2 3 4)
elem *first1=NULL, *last1=NULL;
elem *first2=NULL, *last2=NULL;
append(first1, last1, 1); 
append(first1, last1, 2); 
append(first1, last1, 3);
append(first2, last2, 1); 
append(first2, last2, 2); 
append(first2, last2, 3); 
append(first2, last2, 4);
  
if(!vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
  
del(first1); del(first2);
}
void test4(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst, ka 1. saraksts ir garāks par 2.: (1 2 3 4) un (1 2 3)
elem *first1=NULL, *last1=NULL;
elem *first2=NULL, *last2=NULL;
append(first1, last1, 1); 
append(first1, last1, 2); 
append(first1, last1, 3); 
append(first1, last1, 4);
append(first2, last2, 1); 
append(first2, last2, 2); 
append(first2, last2, 3);
  
if(!vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
  
del(first1); del(first2);
}
void test5(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst, ka abi tukšie saraksti ir vienādi
elem *first1=NULL;
elem *first2=NULL;
if(vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
}
void test6(){ /// testē funkciju vienadi(first1, first2) -
              /// vai atpazīst, ka tukšs un netukšs saraksts nav vienādi: () un (5)
elem *first1=NULL;
elem *first2=NULL, *last2=NULL;
append(first2, last2, 5);
if(!vienadi(first1, first2)) cout<<1<<endl;
else cout<<0<<endl;
del(first2);
}
int main(){
    test1();  /// 1
    test2();  /// 1
    test3();  /// 1
    test4();  /// 1
    test5();  /// 1
    test6();  /// 1
}
