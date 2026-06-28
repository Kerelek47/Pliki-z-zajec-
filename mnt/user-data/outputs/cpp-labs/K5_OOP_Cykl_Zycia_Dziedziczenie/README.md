# K5 - Wprowadzenie do Obiektowosci: Cykl Zycia i Dziedziczenie

Rozwiazania zadan 1-9 z laboratorium "Podstawy programowania w C/C++".
Kazde zadanie to osobny, samodzielny plik `.cpp` z funkcja `main`.

## Zadania

| Plik | Temat |
|------|-------|
| `zad1_lista_inicjalizacyjna.cpp` | Lista inicjalizacyjna (inicjalizacja vs przypisanie, pola `const`) |
| `zad2_delegowanie_konstruktorow.cpp` | Delegowanie konstruktorow (DRY) |
| `zad3_destruktor_raii.cpp` | Destruktor i RAII |
| `zad4_skladowe_statyczne.cpp` | Skladowe statyczne (licznik instancji) |
| `zad5_dziedziczenie.cpp` | Podstawy dziedziczenia (relacja "is-a") |
| `zad6_protected.cpp` | Modyfikator `protected` |
| `zad7_wiazanie_statyczne.cpp` | Problem braku wirtualnosci (static binding) |
| `zad8_funkcje_wirtualne.cpp` | Funkcje wirtualne (polimorfizm dynamiczny) |
| `zad9_klasy_abstrakcyjne.cpp` | Klasy abstrakcyjne i wirtualne destruktory |

## Kompilacja

### Pojedynczy plik (g++)
```bash
g++ -std=c++11 -Wall zad1_lista_inicjalizacyjna.cpp -o zad1
./zad1
```

### Wszystko naraz (CMake)
```bash
cmake -B build
cmake --build build
./build/zad1   # ./build/Debug/zad1.exe na Windows/MSVC
```

## Uwagi do obrony

- **zad1**: pola `const` i referencje da sie tylko *zainicjalizowac* na liscie, nie *przypisac* w ciele `{}`.
- **zad2**: przy delegowaniu nie wolno inicjalizowac dodatkowych pol na tej samej liscie.
- **zad3**: `Deallocated` pojawia sie przy wyjsciu z bloku `{}`, przed `End`.
- **zad4**: pole `static` istnieje raz na cala klase; wymaga definicji poza klasa.
- **zad5/zad6**: roznica `private` (potomek nie widzi) vs `protected` (potomek widzi).
- **zad7 vs zad8**: bez `virtual` decyduje typ wskaznika (static binding); z `virtual` - rzeczywisty typ obiektu (vtable, dynamic binding).
- **zad9**: czysta funkcja wirtualna (`= 0`) czyni klase abstrakcyjna; wirtualny destruktor zapobiega wyciekom przy `delete` przez wskaznik bazowy.
