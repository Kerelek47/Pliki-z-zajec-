# K6 - Zaawansowana Obiektowosc, Szablony i Wyjatki

Rozwiazania zadan 1-9 (labka K5-2/K6-1). Kontynuacja hierarchii `Employee`/`Manager`
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

## Uwagi do obrony

- **zad1**: bez `virtual ~Base()` `delete` na wskazniku bazowym wola tylko destruktor bazy -> destruktor pochodnej sie nie wykonuje -> wyciek. Zasada: jesli klasa ma jakakolwiek funkcje wirtualna, destruktor tez powinien byc wirtualny.
  - *Uwaga techniczna*: w tej labce `Employee` jest abstrakcyjna, wiec sam w sobie wymusza wirtualny destruktor. Aby czysto pokazac problem, zad1 uzywa osobnej minimalnej pary `Base`/`Derived` bez innych funkcji wirtualnych.
- **zad2**: `override` zamienia ciche bledy przeslaniania (literowka, brak `const`) na bledy kompilacji. `final` blokuje dalsze przeslanianie metody lub dziedziczenie po klasie. W pliku sa zakomentowane TEST 1/2/3 do odkomentowania.
- **zad3**: kontener wskaznikow bazowych = kolekcja heterogeniczna; petla operuje na `Employee*`, ale dziala konkretna metoda (polimorfizm).
- **zad4**: `dynamic_cast` sprawdza poprawnosc rzutowania w runtime i zwraca `nullptr` przy niepowodzeniu. Wymaga klasy polimorficznej (RTTI). Wolniejszy niz `static_cast`.
- **zad5**: interfejs = klasa z samymi czysto wirtualnymi metodami, bez stanu. `printReport` dziala dla kazdej klasy implementujacej `IReportable`.
- **zad6**: kompozycja (has-a) zamiast dziedziczenia (is-a); pracownik *posiada* liste zadan. Composition over Inheritance.
- **zad7**: `T` to placeholder typu; kompilator instancjuje osobna wersje per typ. Typ musi wspierac uzyte operacje (tu `operator>`) - dla `Employee` trzeba go przeciazyc.
- **zad8**: `throw`/`try`/`catch`; `what()` zwraca komunikat. Hierarchia `invalid_argument -> logic_error -> exception`.
- **zad9**: wlasna hierarchia wyjatkow; `catch` ZAWSZE od najbardziej pochodnego do najbardziej bazowego typu.
