struct elem{
    int num;
    elem *next;
    elem(int n){ num=n; next=NULL;}
};
bool vienadi(elem* first1, elem* first2);
/**
Funkcija vienadi(first1, first2) -
 atgriež kā rezultātu true, ja vienvirziena saistītie saraksti
 (first1) un (first2) ir vienādi -
 satur vienāda garuma elementu virknes ar vienādām vērtībām vienādās pozīcijās,
 atgriež false pretējā gadījumā.
*/
void append(elem* &first, elem* &last, int n);
/**
Funkcija append(first, last, n) -
 pievieno vienvirziena saistītā saraksta (first, last)
 beigās mezglu ar vērtību n.
*/
void print(elem* first);
/**
Funkcija print(first) -
 izdrukā vienvirziena saistītā saraksta (first) elementus.
*/
void del(elem* &first);
/**
Funkcija del(first) -
 izdzēš vienvirziena saistīto sarakstu (first),
 atbrīvo visu elementu dinamiski pieprasīto atmiņu.
*/
