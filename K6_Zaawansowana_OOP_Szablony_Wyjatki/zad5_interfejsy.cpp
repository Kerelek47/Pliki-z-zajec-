// Zadanie 5 - Interfejsy jako Kontrakty
// Cel: roznica miedzy dziedziczeniem stanu a implementacja kontraktu.
//
// IReportable to "czysty interfejs" - klasa z samymi czysto wirtualnymi metodami,
// bez zadnych pol. Definiuje CO obiekt potrafi (getReport), nie JAK jest zbudowany.
//
// Funkcja printReport przyjmuje (const IReportable&) - zadziala dla DOWOLNEJ klasy
// implementujacej ten interfejs, nie tylko dla pracownikow.

#include <iostream>
#include <string>

// Interfejs (kontrakt)
class IReportable {
public:
    virtual std::string getReport() const = 0;
    virtual ~IReportable() = default;
};

class Employee : public IReportable {   // Employee implementuje interfejs
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual double calculate_salary() const = 0;
    // getReport() pozostaje czysto wirtualna -> implementuja ja klasy pochodne
};

class Manager : public Employee {
    double base_salary;
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, double base, float bonus)
        : Employee(name, id), base_salary(base), bonus_percentage(bonus) {}
    double calculate_salary() const override {
        return base_salary + base_salary * (bonus_percentage / 100.0);
    }
    std::string getReport() const override {
        return "[RAPORT] Manager " + name + " (ID " + std::to_string(id) +
               "), pensja: " + std::to_string(calculate_salary());
    }
};

class Developer : public Employee {
    double base_salary;
    std::string language;
public:
    Developer(const std::string& name, int id, double base, const std::string& lang)
        : Employee(name, id), base_salary(base), language(lang) {}
    double calculate_salary() const override { return base_salary; }
    std::string getReport() const override {
        return "[RAPORT] Developer " + name + " (ID " + std::to_string(id) +
               "), jezyk: " + language;
    }
};

// Funkcja wolnostojaca - dziala na abstrakcji IReportable
void printReport(const IReportable& obj) {
    std::cout << obj.getReport() << "\n";
}

int main() {
    Manager m("Anna", 1, 8000.0, 15.0f);
    Developer d("Celina", 2, 7000.0, "C++");

    printReport(m);   // ta sama funkcja dla roznych klas
    printReport(d);
    return 0;
}
