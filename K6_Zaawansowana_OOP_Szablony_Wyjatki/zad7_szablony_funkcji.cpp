// Zadanie 7 - Szablony Funkcji (wprowadzenie do K6)
// Cel: kod uniwersalny, niezalezny od typu danych.
//
// template <typename T> - T to placeholder na typ. Kompilator generuje
// osobna wersje funkcji dla kazdego uzytego typu (instancjacja).
//
// Wymaganie: typ T musi wspierac operacje uzyte w szablonie - tutaj operator>.
// Jesli przekazemy typ bez operatora> (np. Employee bez przeciazenia),
// blad pojawi sie w MIEJSCU WYWOLANIA, nie w definicji szablonu.

#include <iostream>
#include <string>

template <typename T>
T znajdzWiekszy(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// Aby szablon zadzialal dla Employee, trzeba przeciazyc operator>.
// Porownujemy np. po pensji.
class Employee {
    std::string name;
    double salary;
public:
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}
    bool operator>(const Employee& other) const {  // wymagany przez znajdzWiekszy
        return salary > other.salary;
    }
    const std::string& getName() const { return name; }
};

int main() {
    std::cout << "int:    " << znajdzWiekszy(7, 3) << "\n";
    std::cout << "double: " << znajdzWiekszy(2.5, 9.1) << "\n";
    std::cout << "string: " << znajdzWiekszy(std::string("abc"), std::string("xyz")) << "\n";

    // Dziala dla Employee, bo zdefiniowalismy operator>
    Employee e1("Anna", 8000), e2("Bartek", 9500);
    std::cout << "lepiej platny: " << znajdzWiekszy(e1, e2).getName() << "\n";
    return 0;
}
