// Zadanie 1 - Wirtualny Destruktor
// Cel: pokazac, dlaczego destruktor klasy bazowej musi byc wirtualny
// w hierarchiach polimorficznych.
//
// Problem: delete na wskazniku bazowym przy NIEwirtualnym destruktorze
// wola TYLKO destruktor bazy -> destruktor klasy pochodnej sie nie wykona
// -> wyciek zasobow zaalokowanych w klasie pochodnej.
//


#include <iostream>

// ---------- WERSJA ZLA: destruktor bazy NIE jest wirtualny ----------
class BaseNoVirtual {
public:
    BaseNoVirtual()  { std::cout << "  Konstruktor Base\n"; }
    ~BaseNoVirtual() { std::cout << "  Destruktor Base\n"; }   // brak virtual!
};
class DerivedNoVirtual : public BaseNoVirtual {
    int* zasob;
public:
    DerivedNoVirtual()  { zasob = new int[100]; std::cout << "  Konstruktor Derived (alokacja)\n"; }
    ~DerivedNoVirtual() { delete[] zasob;       std::cout << "  Destruktor Derived (zwolnienie)\n"; }
};

// ---------- WERSJA DOBRA: destruktor bazy JEST wirtualny ----------
class BaseVirtual {
public:
    BaseVirtual()          { std::cout << "  Konstruktor Base\n"; }
    virtual ~BaseVirtual() { std::cout << "  Destruktor Base\n"; } // virtual!
};
class DerivedVirtual : public BaseVirtual {
    int* zasob;
public:
    DerivedVirtual()  { zasob = new int[100]; std::cout << "  Konstruktor Derived (alokacja)\n"; }
    ~DerivedVirtual() { delete[] zasob;       std::cout << "  Destruktor Derived (zwolnienie)\n"; }
};

int main() {
    std::cout << "=== BEZ wirtualnego destruktora ===\n";
    {
        BaseNoVirtual* p = new DerivedNoVirtual();
        delete p;  // wola TYLKO ~BaseNoVirtual -> ~DerivedNoVirtual sie NIE wykona -> WYCIEK
    }
    std::cout << "(destruktor Derived sie nie wykonal -> zasob nie zwolniony)\n\n";

    std::cout << "=== Z wirtualnym destruktorem ===\n";
    {
        BaseVirtual* p = new DerivedVirtual();
        delete p;  // wola ~DerivedVirtual, potem ~BaseVirtual -> poprawnie
    }
    std::cout << "(oba destruktory sie wykonaly -> pamiec zwolniona)\n";
    return 0;
}
