// Zadanie 2 - override i final (C++11)
// Cel: zwiekszenie bezpieczenstwa i kontrola hierarchii dziedziczenia.
//
// override - mowi kompilatorowi "ta metoda przeslania wirtualna z bazy".
//            Jesli sygnatura sie nie zgadza (literowka, brak const) -> BLAD kompilacji.
// final    - blokuje dalsze przeslanianie metody albo dziedziczenie po klasie.
//
// Zakomentowane fragmenty (TEST 1/2/3) to celowe bledy - odkomentuj, by zobaczyc
// co mowi kompilator. Domyslnie program sie kompiluje i dziala.

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual void display() const = 0;
    virtual double calculate_salary() const = 0;
    virtual ~Employee() = default;
};

class Manager : public Employee {
    float bonus_percentage;
    double base_salary;
public:
    Manager(const std::string& name, int id, double base, float bonus)
        : Employee(name, id), bonus_percentage(bonus), base_salary(base) {}

    // TEST 1 (blad sygnatury): usun ponizej "const" -> kompilator: metoda nie
    // przeslania niczego (bo Employee::display() jest const). Bez "override"
    // bylby to CICHY blad - powstalaby nowa metoda zamiast przeslonienia.
    void display() const override {
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }

    // TEST 2 (final dla metody): "final" blokuje przeslanianie w klasach pochodnych.
    double calculate_salary() const override final {
        return base_salary + base_salary * (bonus_percentage / 100.0);
    }
};

// TEST 2 cd.: odkomentowanie ponizszego da BLAD - calculate_salary jest final:
// class CEO : public Manager {
// public:
//     CEO(const std::string& n, int i, double b, float bo) : Manager(n,i,b,bo) {}
//     double calculate_salary() const override { return 99999.0; }  // BLAD: final
// };

// TEST 3 (final dla klasy): gdyby Manager byl "class Manager final : public Employee",
// to ZADNA klasa nie moglaby po nim dziedziczyc (blad juz przy 'class X : public Manager').

int main() {
    Manager m("Anna", 1, 8000.0, 15.0f);
    m.display();
    std::cout << "Pensja: " << m.calculate_salary() << "\n";
    return 0;
}
