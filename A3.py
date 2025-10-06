"""
Daiga Leitāne, dl25036
A3. Izveidot Python programmu, kura ļauj ievadīt naturālu skaitli n un noskaidro 
šī skaitļa pirmā un pēdējā cipara summu.
Skaitļa dalīšanu ciparos ir jāveic skaitliski.

Programma izveidota 13.09.2025

************Testa plāns************

    ievade   paredzamais rezultāts
     543              8
     21               3
     3                6
     -1       Kļūda. Jāievada naturāls skaitlis, kas ir >0.      

***********************************
"""

turpinat = 1

while turpinat == 1:

    # Skaitļa ievade un tā korektuma nodrošināšana
    n = int(input("Ievadiet naturālu skaitli (>0): "))
    while n <= 0:
        print("Kļūda. Jāievada naturāls skaitlis, kas ir >0.")
        n = int(input("Ievadiet naturālu skaitli (>0): "))


    # Aprēķina pēdējo ciparu
    # Cipars tiek iegūts skaitli dalot ar 10, iegūtais atlikums => pēdējais skaitlis
    pedejais = n % 10

    # Aprēķina pirmo ciparu
    # Cipars tiek iegūts skaitli dalot ar 10 līdz skaitlis satur tikai vienu ciparu. Iegūtais cipars => pirmais skaitlis
    pirmais = n
    while pirmais >= 10:
        pirmais = pirmais // 10

    # Aprēķina pirmā un pēdējā cipara summu
    summa = pirmais + pedejais
    print(f"Pirmā un pēdējā cipara summa ir: {summa}")

    # Cikla atkārtošanas iespēja
    turpinat = int(input("Vai vēlaties turpināt (1) vai beigt (0)? "))
    
