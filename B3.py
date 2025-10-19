"""
Daiga Leitāne, dl25036
B3. Izveidot Python programmu, kura dotajam skaitļu intervālam [m,n] izdrukā visus tos skaitļus,
kuri pieder šim intervālam un kurus var izteikt kā divu naturālu skaitļu kvadrātu summu (izmantojot funkciju,
kas pazīst vesela skaitļa kvadrātu).

Programma izveidota 11.10.2025

************Testa plāns************
    m    n        paredzamais rezultāts
    1   10        2, 5, 8, 10
    0    5        2, 5
    1    1        Šajā intervālā nav skaitļu, kurus var izteikt kā divu 
                  naturālu skaitļu kvadrātu summu.
   32    2        Kļūda. Beigu vērtībai jābūt lielākai vai vienādai ar sākuma vērtību.
   -5    x        Kļūda. Sākuma vērtībai jābūt >= 0.
    x   -12       Kļūda. Beigu vērtībai jābūt >= 0.
***********************************
"""
"""
Funkcija kvadrats(sk) -
pārbauda, vai vesels skaitlis sk ir kāda vesela skaitļa kvadrāts.
Ja sakne no sk, noapaļota līdz veselam skaitlim, reizināta pati ar sevi dod sākotnējo sk,
tad funkcija atgriež True, pretējā gadījumā - False.

"""
def kvadrats(sk):
    sakne = int(sk ** 0.5)
    return sakne * sakne == sk
"""
Funkcija divu_kvadratu_summa(x) -
pārbauda, vai vesels skaitlis x var tikt izteikts kā divu naturālu skaitļu kvadrātu summa.
Funkcija pārbauda visus naturālos skaitļus a, sākot no 1 līdz √x, katram aprēķinot b^2 = x - a^2.
Ja b^2 ir pozitīvs un ir perfekts kvadrāts, funkcija atgriež True,
pretējā gadījumā - False.
"""
def divu_kvadratu_summa(x):
    for a in range(1, int(x**0.5) + 1):
        b_kv = x - a*a
        if b_kv > 0 and kvadrats(b_kv):
            return True
    return False

turpinat = 1
while turpinat == 1:

    # Intervāla sākuma skaitļa m ievade un skaitļa korektuma nodrošināšana.
    # Kamēr lietotāja ievade neatbilst nosacījumam m >= 0 tiek pieprasīta atkārtota skaitļa ievade (while True cikls).
    while True:
        m = int(input("Ievadi intervāla sākumu m (≥0): "))
        if m < 0:
            print("Kļūda. Sākuma vērtībai jābūt ≥0.")
            continue
        break

    # Intervāla beigu skaitļa n ievade un skaitļa korektuma nodrošināšana
    # Kamēr lietotāja ievade neatbilst nosacījumam n >= 0 un n > m tiek pieprasīta atkārtota skaitļa ievade (while True cikls).
    while True:
        n = int(input("Ievadi intervāla beigas n (≥0): "))
        if n < 0:
             print("Kļūda. Beigu vērtībai jābūt ≥0.")
             continue
        if n < m:
            print("Kļūda. Beigu vērtībai jābūt lielākai vai vienādai par sākuma vērtību.")
            continue
        break
    
    # Saraksts, kurā tiek saglabāti visi skaitļi, kuri var tikt izteikti kā divu naturālu skaitļu kvadrātu summa.
    """
    "for" cikls izskata visus skaitļus intervālā [m,n], funkcija divu_kvadratu_summa pārbauda
    vai konkrētais skaitlis num var tikt izteikts kā divu naturālu skaitļu kvadrātu summa, ja True, tas tiek
    pievienots sarakstam rezultati.
    """
    rezultati = []
    for num in range(m, n + 1):
        if divu_kvadratu_summa(num):
            rezultati.append(str(num))

    # Rezultātu izvade.
    # ", ".join(rezultati) apvieno visus iegūtos skatļus vienā tekstā un drukājot atdala tos ar komatu.
    # Ja saraksts ir tukšs tiek izdrukāts atbilstošs ziņojuma.
    print(f"\nSkaitļi intervālā [{m}, {n}], kurus var izteikt kā divu naturālu skaitļu kvadrātu summu:")
    if rezultati:
        print(", ".join(rezultati))
    else:
        print("Šajā intervālā nav skaitļu, kurus var izteikt kā divu naturālu skaitļu kvadrātu summu.")

    # Cikla atkārtošanas iespēja.
    turpinat = int(input("\nVai vēlaties turpināt (1) vai beigt (0)? "))

