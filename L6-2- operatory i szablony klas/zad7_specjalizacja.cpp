// Zadanie 7 - Specjalizacja szablonu klasy
// Cel: dedykowana implementacja szablonu dla konkretnego typu.
//
// Problem: ogolny Box<T> dla bool zwracalby 1/0. Chcemy "TAK"/"NIE".
//
// template <> class Box<bool> - pelna specjalizacja.
// Autonomia: specjalizacja NIE dziedziczy nic z szablonu ogolnego.
// Trzeba w niej zdefiniowac wlasne pole value, konstruktor i metody.

#include <iostream>
#include <string>

// szablon ogolny
template <typename T>
class Box {
    T value;
public:
    Box(T value) : value(value) {}
    T getValue() const { return value; }
};

// pelna specjalizacja dla bool - osobna, autonomiczna klasa
template <>
class Box<bool> {
    bool value;
public:
    Box(bool value) : value(value) {}
    bool getValue() const { return value; }
    std::string getStatus() const { return value ? "TAK" : "NIE"; }
};

int main() {
    Box<int> bi(42);
    std::cout << "Box<int>: " << bi.getValue() << "\n";

    Box<bool> bt(true);
    Box<bool> bf(false);
    std::cout << "Box<bool>(true).getStatus():  " << bt.getStatus() << "\n";  // TAK
    std::cout << "Box<bool>(false).getStatus(): " << bf.getStatus() << "\n";  // NIE
    return 0;
}
