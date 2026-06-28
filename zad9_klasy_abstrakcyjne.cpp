// Zadanie 9 - Klasy Abstrakcyjne
// Cel: wspolny interfejs dla hierarchii + zakaz tworzenia obiektow klasy bazowej.
//
// Klasa abstrakcyjna: ma co najmniej jedna czysta funkcje wirtualna (= 0).
// Odpowiedz: Employee emp(...) NIE skompiluje sie - klasa abstrakcyjna.
//
// Wirtualny destruktor: krytyczny w polimorficznych klasach bazowych.
// Gwarantuje, ze delete wskaznik_do_bazy; wywola destruktor klasy pochodnej.

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual void display() const = 0;            // czysto wirtualna
    virtual double calculate_salary() const = 0; // czysto wirtualna
    virtual ~Employee() = default;               // wirtualny destruktor
};

class Manager : public Employee {
    float bonus_percentage;
    double base_salary;
public:
    Manager(const std::string& name, int id, float bonus, double base)
        : Employee(name, id), bonus_percentage(bonus), base_salary(base) {}

    void display() const override {
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }
    double calculate_salary() const override {
        return base_salary + base_salary * (bonus_percentage / 100.0);
    }
};

int main() {
    // Employee emp("X", 1);  // BLAD: nie mozna tworzyc obiektu klasy abstrakcyjnej

    Manager m("Anna", 1, 15.0f, 8000.0);
    m.display();
    std::cout << "Pensja: " << m.calculate_salary() << "\n";  // 9200

    // Polimorficznie przez wskaznik bazowy:
    Employee* ptr = new Manager("Bartek", 2, 20.0f, 10000.0);
    ptr->display();
    std::cout << "Pensja: " << ptr->calculate_salary() << "\n"; // 12000
    delete ptr;  // dzieki virtual ~Employee() zwolni sie poprawnie
    return 0;
}
