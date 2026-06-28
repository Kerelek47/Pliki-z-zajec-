# K6 - Zaawansowana Obiektowosc, Szablony i Wyjatki

Rozwiazania zadan 1-9 (laboratorium K5-2/K6-1). Kontynuacja hierarchii `Employee`/`Manager`
z poprzednich zajec, rozszerzona o `Developer`. Kazde zadanie to osobny plik `.cpp` z `main`.

## Zadania

| Plik | Temat |
|------|-------|
| `zad1_wirtualny_destruktor.cpp` | Wirtualny destruktor (demonstracja wycieku bez `virtual`) |
| `zad2_override_final.cpp` | `override` i `final` |
| `zad3_kolekcje_polimorficzne.cpp` | Kolekcje polimorficzne (`std::vector<Employee*>`) |
| `zad4_dynamic_cast.cpp` | `dynamic_cast` i RTTI |
| `zad5_interfejsy.cpp` | Interfejsy jako kontrakty (`IReportable`) |
| `zad6_kompozycja.cpp` | Kompozycja (relacja "has-a", klasa `Task`) |
| `zad7_szablony_funkcji.cpp` | Szablony funkcji (`template <typename T>`) |
| `zad8_wyjatki.cpp` | Wyjatki (`try`/`catch`, `std::invalid_argument`) |
| `zad9_wlasne_wyjatki.cpp` | Wlasne klasy wyjatkow (hierarchia + kaskadowy `catch`) |

## Kompilacja

### Pojedynczy plik (g++)
```bash
g++ -std=c++11 -Wall zad1_wirtualny_destruktor.cpp -o zad1
./zad1
```

### Wszystko naraz (CMake)
```bash
cmake -B build
cmake --build build
./build/zad1
```

