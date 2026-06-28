// Zadanie 7 - Problem braku wirtualnosci (Wiazanie Statyczne)
// Cel: zrozumienie static binding.
//
// Obserwacja: dla obiektu Manager NIE wyswietli sie premia.
// Kompilator widzi wskaznik typu Employee* i juz w czasie kompilacji
// decyduje, ze ptr->display() wola Employee::display().
// Typ wskaznika jest decydujacy, nie rzeczywisty typ obiektu.
// Szybkie, ale NIE polimorficzne.

#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    void display() const {     // brak virtual
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
};

class Manager : public Employee {
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, float bonus)
        : Employee(name, id), bonus_percentage(bonus) {}
    void display() const {
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }
};

int main() {
    Employee* team[2];
    team[0] = new Employee("Anna", 1);
    team[1] = new Manager("Bartek", 2, 20.0f);

    for (int i = 0; i < 2; ++i)
        team[i]->display();    // dla obu wywola Employee::display()!

    for (int i = 0; i < 2; ++i)
        delete team[i];
    return 0;
}
