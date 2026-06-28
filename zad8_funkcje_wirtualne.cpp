// Zadanie 8 - Funkcje Wirtualne
// Cel: polimorfizm dynamiczny za pomoca funkcji wirtualnych.
//
// Obserwacja: teraz dla Manager wyswietla sie pelna informacja z bonusem.
// Wiazanie dynamiczne (late binding): decyzja o wywolaniu metody
// podejmowana jest w czasie wykonania, na podstawie rzeczywistego typu obiektu.
// Mechanizm: tabela wirtualna (vtable) + ukryty wskaznik w kazdym obiekcie.
// override (C++11) - informuje kompilator o przeslanianiu, pomaga wykryc bledy.

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual void display() const {   // virtual!
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
    virtual ~Employee() = default;   // wirtualny destruktor (bezpieczne delete)
};

class Manager : public Employee {
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, float bonus)
        : Employee(name, id), bonus_percentage(bonus) {}
    void display() const override {   // override
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }
};

int main() {
    Employee* team[2];
    team[0] = new Employee("Anna", 1);
    team[1] = new Manager("Bartek", 2, 20.0f);

    for (int i = 0; i < 2; ++i)
        team[i]->display();    // teraz wlasciwa wersja dla kazdego typu

    for (int i = 0; i < 2; ++i)
        delete team[i];
    return 0;
}
