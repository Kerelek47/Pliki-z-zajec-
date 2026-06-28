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

Ta zadania wymagaja **C++17** (`[[nodiscard]]` w zad1, `if constexpr` w zad8).

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


