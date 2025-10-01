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
     3          Kļūda. Jāievada vismaz divciparu skaitlis (≥10).

***********************************
"""

turpinat = 1

while turpinat == 1:

    # Skaitļa ievade un tā korektuma nodrošināšana
    n = int(input("Ievadiet naturālu skaitli (≥10): "))
    while n < 10:
        print("Kļūda. Jāievada vismaz divciparu naturāls skaitlis (≥10).")
        n = int(input("Ievadiet naturālu skaitli (≥10): "))

    # Aprēķina pēdējo ciparu
    #
    pedejais = n % 10

    # Aprēķina pirmo ciparu
    pirmais = n
    while pirmais >= 10:
        pirmais = pirmais // 10

    summa = pirmais + pedejais
    print(f"Pirmā un pēdējā cipara summa ir: {summa}")

    # Cikla atkārtošanas iespēja
    turpinat = int(input("Vai vēlaties turpināt (1) vai beigt (0)? "))
    
