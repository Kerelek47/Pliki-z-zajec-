// Zadanie 4 - dynamic_cast i RTTI
// Cel: bezpieczne rzutowanie w dol hierarchii (downcasting).
//
// Mamy Employee*, ale chcemy wywolac metode istniejaca tylko w Manager.
// dynamic_cast<Manager*>(e):
//   - jesli e faktycznie wskazuje na Managera -> zwraca poprawny wskaznik
//   - jesli nie -> zwraca nullptr (mozemy to bezpiecznie sprawdzic)
//
// RTTI: dynamic_cast dziala tylko dla klas POLIMORFICZNYCH
// (majacych co najmniej jedna funkcje wirtualna).

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
        std::cout << "Manager:   " << name << " (ID: " << id << ")\n";
    }
    double calculate_salary() const override {
        return base_salary + base_salary * (bonus_percentage / 100.0);
    }
    void scheduleMeeting() const {   // metoda specyficzna tylko dla Managera
        std::cout << "  -> " << name << " zwoluje spotkanie zespolu.\n";
    }
};

class Developer : public Employee {
    double base_salary;
public:
    Developer(const std::string& name, int id, double base)
        : Employee(name, id), base_salary(base) {}
    void display() const override {
        std::cout << "Developer: " << name << " (ID: " << id << ")\n";
    }
    double calculate_salary() const override { return base_salary; }
};

int main() {
    std::vector<Employee*> staff;
    staff.push_back(new Manager("Anna", 1, 8000.0, 15.0f));
    staff.push_back(new Developer("Celina", 2, 7000.0));
    staff.push_back(new Manager("Bartek", 3, 9000.0, 20.0f));

    for (Employee* e : staff) {
        e->display();
        Manager* m = dynamic_cast<Manager*>(e);   // proba rozpoznania typu
        if (m != nullptr)
            m->scheduleMeeting();
        else
            std::cout << "  To nie jest Manager\n";
    }

    for (Employee* e : staff)
        delete e;
    return 0;
}
