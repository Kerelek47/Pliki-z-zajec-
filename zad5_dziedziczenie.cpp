// Zadanie 5 - Podstawy Dziedziczenia
// Cel: hierarchia klas (relacja "is-a"), Manager "jest" Employee.
//
// Koncepcje:
// - gdyby Manager mial wlasny display(), ukrywalby Employee::display()
//   (trzeba by go wolac przez Employee::display()).
// - obiekt Manager NIE ma dostepu do prywatnych pol Employee (name, id).

#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    void display() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
};

class Manager : public Employee {
private:
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, float bonus)
        : Employee(name, id), bonus_percentage(bonus) {}

    void show() const {
        Employee::display();   // Manager nie widzi prywatnych name/id - uzywa metody bazy
        std::cout << "Bonus: " << bonus_percentage << "%\n";
    }
};

int main() {
    Manager m("Anna", 1, 15.0f);
    m.display();   // metoda dziedziczona z Employee
    m.show();      // metoda wlasna Managera
    return 0;
}
