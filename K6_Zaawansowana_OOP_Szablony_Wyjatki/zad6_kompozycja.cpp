// Zadanie 6 - Kompozycja (relacja "has-a")
// Cel: budowanie zlozonych obiektow z prostszych komponentow.
//
// Dziedziczenie (is-a) nie zawsze pasuje. Pracownik nie "jest" lista zadan -
// on te liste "POSIADA" (has-a). Realizujemy to przez pole-kontener w klasie.
//
// Zasada: Composition over Inheritance - preferuj kompozycje tam, gdzie to mozliwe.

#include <iostream>
#include <string>
#include <vector>

// Prosty komponent
class Task {
public:
    std::string description;
    int priority;
    Task(const std::string& desc, int prio) : description(desc), priority(prio) {}
};

class Employee {
protected:
    std::string name;
    int id;
    std::vector<Task> tasks;   // Employee POSIADA zadania (kompozycja)
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    virtual void display() const = 0;
    virtual ~Employee() = default;

    void assignTask(const std::string& desc, int prio) {
        tasks.push_back(Task(desc, prio));
    }

protected:
    void displayTasks() const {     // pomocnicza - wypisuje liste zadan
        if (tasks.empty()) {
            std::cout << "   (brak zadan)\n";
            return;
        }
        for (const Task& t : tasks)
            std::cout << "   - [" << t.priority << "] " << t.description << "\n";
    }
};

class Manager : public Employee {
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, float bonus)
        : Employee(name, id), bonus_percentage(bonus) {}
    void display() const override {
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
        displayTasks();
    }
};

class Developer : public Employee {
    std::string language;
public:
    Developer(const std::string& name, int id, const std::string& lang)
        : Employee(name, id), language(lang) {}
    void display() const override {
        std::cout << "Developer: " << name << " (ID: " << id
                  << "), jezyk: " << language << "\n";
        displayTasks();
    }
};

int main() {
    Manager m("Anna", 1, 15.0f);
    m.assignTask("Przeglad budzetu", 1);
    m.assignTask("Rekrutacja", 2);

    Developer d("Celina", 2, "C++");
    d.assignTask("Naprawa buga #42", 1);

    m.display();
    d.display();
    return 0;
}
