// Zadanie 4 - Szablon klasy: podstawowa skladnia
// Cel: struktury danych niezalezne od typu przechowywanych danych.
//
// template <typename T> - ponizsza definicja to wzorzec, nie konkretna klasa.
// T - placeholder zastapiony konkretnym typem w czasie kompilacji.
// Box<int> i Box<double> to technicznie DWA ROZNE typy w systemie typow C++.

#include <iostream>
#include <string>

template <typename T>
class Box {
    T value;
public:
    Box(T value) : value(value) {}
    T getValue() const { return value; }
    void setValue(T newValue) { value = newValue; }
};

int main() {
    Box<int> bi(42);
    std::cout << "Box<int>: " << bi.getValue() << "\n";
    bi.setValue(100);
    std::cout << "po setValue: " << bi.getValue() << "\n";

    Box<std::string> bs("tekst");
    std::cout << "Box<string>: " << bs.getValue() << "\n";
    bs.setValue("nowy tekst");
    std::cout << "po setValue: " << bs.getValue() << "\n";
    return 0;
}
