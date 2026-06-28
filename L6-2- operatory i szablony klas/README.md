# L6-2 - Zaawansowane mechanizmy C++: Operatory i Szablony Klas

Rozwiazania zadan 1-9. Przeciazanie operatorow oraz generyczne struktury danych.
Kazde zadanie to osobny plik `.cpp` z `main`.

## Zadania

| Plik | Temat |
|------|-------|
| `zad1_operatory_binarne.cpp` | Operatory binarne `+`, `-` (klasa `Vector2D`) |
| `zad2_operatory_porownania.cpp` | Operatory `==`, `!=` |
| `zad3_operator_strumieniowy.cpp` | Operator `<<` jako funkcja zaprzyjazniona (`friend`) |
| `zad4_szablon_klasy.cpp` | Szablon klasy `Box<T>` - podstawy |
| `zad5_metody_poza_klasa.cpp` | Definicje metod szablonu poza cialem klasy |
| `zad6_parametry_non_type.cpp` | Parametry non-type (`StaticArray<T, int size>`) |
| `zad7_specjalizacja.cpp` | Pelna specjalizacja szablonu (`Box<bool>`) |
| `zad8_noexcept.cpp` | `noexcept` (specyfikator i operator) + `if constexpr` |
| `zad9_safearray.cpp` | Integracja: `SafeArray<T, size>` (operator `[]` + wyjatki) |

## Kompilacja

Ta labka wymaga **C++17** (`[[nodiscard]]` w zad1, `if constexpr` w zad8).

### Pojedynczy plik (g++)
```bash
g++ -std=c++17 -Wall zad1_operatory_binarne.cpp -o zad1
./zad1
```

### Wszystko naraz (CMake)
```bash
cmake -B build
cmake --build build
./build/zad1
```

## Uwagi do obrony

- **zad1**: operator binarny ma `const` na koncu (nie zmienia `this`), bierze argument przez `const&` (bez kopii), zwraca nowy obiekt przez wartosc. `[[nodiscard]]` ostrzega, gdy zignorujesz wynik.
- **zad2**: operatory relacyjne zwracaja `bool`; `!=` implementujemy jako `!(*this == other)` (DRY). `std::boolalpha` wypisuje `true`/`false`.
- **zad3**: `<<` nie moze byc metoda, bo lewy argument to strumien - dlatego `friend`. Zwracamy `std::ostream&` dla kaskadowosci. W definicji nie ma `Vector2D::`.
- **zad4**: `template <typename T>` to wzorzec; `Box<int>` i `Box<double>` to rozne typy. Kompilator instancjuje osobny kod per typ.
- **zad5**: definicja metody poza klasa musi miec `template <typename T>` i pelna nazwe `Box<T>::metoda`. W praktyce szablony trzyma sie w naglowkach `.hpp`.
- **zad6**: parametr non-type (`int size`) musi byc znany w czasie kompilacji. `StaticArray<int,5>` i `StaticArray<int,6>` to rozne typy. Tablica na stosie, bez `new`.
- **zad7**: `template <>` = pelna specjalizacja. Specjalizacja jest autonomiczna - nie dziedziczy nic z szablonu ogolnego, wlasne pole i metody.
- **zad8**: `noexcept` na koncu funkcji = obietnica (deklaracja); `noexcept(wyr)` w kodzie = sprawdzenie (operator, zwraca bool). Funkcja `noexcept`, ktora rzuci, woła `std::terminate()`. `if constexpr` wybiera galaz w czasie kompilacji.
- **zad9**: laczy szablon + non-type + operator `[]` + wyjatki. Dwie wersje `[]` (zwykla i `const`); zwracanie przez `T&` pozwala modyfikowac element. Kontrola indeksu rzuca `std::out_of_range`.
