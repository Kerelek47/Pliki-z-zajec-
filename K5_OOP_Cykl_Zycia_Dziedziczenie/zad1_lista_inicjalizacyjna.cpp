// Zadanie 1 - Lista Inicjalizacyjna 
// Cel: roznica miedzy inicjalizacja a przypisaniem.
// Pola const oraz referencje MUSZA byc zainicjalizowane w momencie tworzenia.
//
// Obserwacja: konstruktor przypisujacy const w ciele {} (np. id = id;)
// NIE skompiluje sie - const nie da sie nadpisac, mozna go tylko zainicjalizowac.

#include <iostream>
#include <string>

class Employee {
    const int id;        // const -> tylko lista inicjalizacyjna
    std::string name;
public:
    Employee(int id, const std::string& name)
        : id(id), name(name) {}   // poprawnie: inicjalizacja, nie przypisanie

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << "\n";
    }
};

int main() {
    Employee e(1, "Anna");
    e.display();
    return 0;
}
