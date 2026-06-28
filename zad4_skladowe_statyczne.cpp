// Zadanie 4 - Skladowe Statyczne
// Cel: wspoldzielenie danych miedzy wszystkimi obiektami klasy.
// Statyczne pole istnieje raz na cala klase, nie raz na obiekt.

#include <iostream>
#include <string>

class Employee {
    const int id;
    std::string name;
    static int active_instances;   // deklaracja pola statycznego
public:
    Employee(int id, const std::string& name) : id(id), name(name) {
        ++active_instances;
    }
    ~Employee() { --active_instances; }

    static int get_active_instances() { return active_instances; }
};

int Employee::active_instances = 0;  // definicja poza klasa (wymagana)

int main() {
    std::cout << "Aktywne: " << Employee::get_active_instances() << "\n"; // 0
    Employee e1(1, "Anna");
    Employee e2(2, "Bartek");
    std::cout << "Aktywne: " << Employee::get_active_instances() << "\n"; // 2
    {
        Employee e3(3, "Cezary");
        std::cout << "Aktywne: " << Employee::get_active_instances() << "\n"; // 3
    } // e3 niszczony tutaj
    std::cout << "Aktywne: " << Employee::get_active_instances() << "\n"; // 2
    return 0;
}
