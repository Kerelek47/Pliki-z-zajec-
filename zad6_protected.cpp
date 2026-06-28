// Zadanie 6 - Modyfikator protected
// Cel: klasy pochodne maja dostep do skladowych bazy, ale swiat zewnetrzny nie.
//
// Poziomy dostepu:
//   public    - dostep dla kazdego
//   protected - dostep dla klasy i jej potomkow (dziedziczenie)
//   private   - dostep tylko dla tej konkretnej klasy (potomkowie nie widza)
//
// Odpowiedz: mgr.name = "Test"; z poziomu main NIE zadziala (protected).

#include <iostream>
#include <string>

class Employee {
protected:                 // bylo private -> teraz protected
    std::string name;
    int id;
public:
    Employee(const std::string& name, int id) : name(name), id(id) {}
    void display() const {
        std::cout << "Employee: " << name << " (ID: " << id << ")\n";
    }
};

class Manager : public Employee {
    float bonus_percentage;
public:
    Manager(const std::string& name, int id, float bonus)
        : Employee(name, id), bonus_percentage(bonus) {}

    void display() const {
        // teraz mamy dostep do name i id bezposrednio
        std::cout << "Manager: " << name << " (ID: " << id
                  << "), bonus: " << bonus_percentage << "%\n";
    }
};

int main() {
    Manager mgr("Anna", 1, 15.0f);
    mgr.display();
    // mgr.name = "Test";  // BLAD KOMPILACJI: protected niedostepne z main
    return 0;
}
