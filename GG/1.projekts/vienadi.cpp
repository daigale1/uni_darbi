#include<iostream>
#include"vienadi.h"
using namespace std;
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
void append(elem* &first, elem* &last, int n){
elem* p = new elem(n);
if(first==NULL){
/// ja saraksts tukšs
/// gan pirmais, gan pēdējais norāda uz jauno elementu
first=last=p;
}
else{
/// ja saraksts nav tukšs
/// pieliek galā beidzamajam
last->next=p;
/// un jaunais kļūst par beidzamo
last=p;
}
}
void print(elem* first){
elem* p=first;
if(!p){cout<<"Tukšs saraksts"<<endl; return;}
/// saraksta izdruka
while(p){
    cout<<p->num<<" ";
    p=p->next;
}
cout<<endl;
}
void del(elem* &first){
/// saraksta iznīcināšana
while(first){
    elem *p = first->next;
    delete first;
    first=p;
}
}
