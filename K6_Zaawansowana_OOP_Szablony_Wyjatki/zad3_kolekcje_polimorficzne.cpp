// Zadanie 3 - Kolekcje Polimorficzne
// Cel: zarzadzanie grupa roznych obiektow przez wspolny interfejs (Employee*).
//
// Kontener wskaznikow bazowych (std::vector<Employee*>) pozwala trzymac
// rozne typy (Manager, Developer) w jednej kolekcji - kolekcja heterogeniczna.
// Petla operuje na abstrakcji Employee*, ale dzieki funkcjom wirtualnym
// wywoluje sie konkretna wersja metody.

#include <iostream>
#include <string>
#include <vector>

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
    void display() const override {
        std::cout << "Manager:   " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }
    double calculate_salary() const override {
        return base_salary + base_salary * (bonus_percentage / 100.0);
    }
};

class Developer : public Employee {
    std::string language;
    double base_salary;
public:
    Developer(const std::string& name, int id, double base, const std::string& lang)
        : Employee(name, id), language(lang), base_salary(base) {}
    void display() const override {
        std::cout << "Developer: " << name << " (ID: " << id
                  << "), jezyk: " << language << "\n";
    }
    double calculate_salary() const override {
        return base_salary;
    }
};

int main() {
    std::vector<Employee*> staff;
    staff.push_back(new Manager("Anna", 1, 8000.0, 15.0f));
    staff.push_back(new Manager("Bartek", 2, 9000.0, 20.0f));
    staff.push_back(new Developer("Celina", 3, 7000.0, "C++"));
    staff.push_back(new Developer("Dawid", 4, 7500.0, "Python"));

    double suma = 0.0;
    for (Employee* e : staff) {
        e->display();
        suma += e->calculate_salary();
    }
    std::cout << "Suma pensji: " << suma << "\n";

    for (Employee* e : staff)   // sprzatanie
        delete e;
    return 0;
}
