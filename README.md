# Pliki z zajęć - Podstawy programowania w C/C++

Rozwiązania zadań laboratoryjnych z C++. Każda labka ma własny katalog z plikami `.cpp`,
plikiem `CMakeLists.txt` i własnym README.

## Laboratorium

| Katalog | Tematyka |
|---------|----------|
| `K5_OOP_Cykl_Zycia_Dziedziczenie` | Cykl życia obiektu (RAII), dziedziczenie, polimorfizm, klasy abstrakcyjne |
| `K6_Zaawansowana_OOP_Szablony_Wyjatki` | Wirtualne destruktory, `override`/`final`, kolekcje polimorficzne, `dynamic_cast`, interfejsy, kompozycja, szablony funkcji, wyjątki |
| `L6-2_Operatory_Szablony_Klas` | Przeciążanie operatorów, szablony klas, parametry non-type, specjalizacja, `noexcept`, `SafeArray` |

## Kompilacja

Każdy plik jest samodzielny (zawiera `main`). Pojedyncze zadanie:

```bash
g++ -std=c++17 -Wall plik.cpp -o program
./program
```

Albo wszystko w danej labce naraz przez CMake:

```bash
cd nazwa_katalogu_labki
cmake -B build
cmake --build build
```

Szczegóły i uwagi do każdej labki są w README wewnątrz jej katalogu.
