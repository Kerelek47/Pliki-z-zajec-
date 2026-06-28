// Zadanie 9 - Wlasne Klasy Wyjatkow
// Cel: tworzenie specyficznych typow bledow dla logiki biznesowej.
//
// Wlasna hierarchia:
//   InvalidSalaryException -> EmployeeException -> std::runtime_error -> std::exception
//
// Kolejnosc catch: ZAWSZE od typu najbardziej pochodnego do najbardziej bazowego.
// Gdyby catch(std::exception) byl pierwszy, zlapalby wszystko i bardziej
// szczegolowe bloki nigdy by sie nie wykonaly (a kompilator zwykle to ostrzega).

#include <iostream>
#include <string>
#include <stdexcept>

// Wlasne wyjatki
class EmployeeException : public std::runtime_error {
public:
    explicit EmployeeException(const std::string& msg) : std::runtime_error(msg) {}
};

class InvalidSalaryException : public EmployeeException {
public:
    explicit InvalidSalaryException(const std::string& msg) : EmployeeException(msg) {}
};

class Manager {
    std::string name;
    double base_salary;
    static constexpr double PLACA_MINIMALNA = 4000.0;
public:
    Manager(const std::string& name, double base) : name(name), base_salary(base) {
        if (base_salary < PLACA_MINIMALNA)
            throw InvalidSalaryException(
                "Pensja " + std::to_string(base_salary) +
                " ponizej placy minimalnej (" + std::to_string(PLACA_MINIMALNA) + ")");
    }
    void display() const {
        std::cout << "Manager: " << name << ", pensja: " << base_salary << "\n";
    }
};

int main() {
    // Poprawny obiekt
    try {
        Manager m("Anna", 8000.0);
        m.display();
    } catch (const std::exception& e) {
        std::cout << "Blad: " << e.what() << "\n";
    }

    // Niepoprawna pensja -> InvalidSalaryException, lapane kaskadowo
    try {
        Manager m("Bartek", 2000.0);
        m.display();
    } catch (const InvalidSalaryException& e) {
        std::cout << "[InvalidSalary] " << e.what() << "\n";
    } catch (const EmployeeException& e) {
        std::cout << "[Employee] " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "[exception] " << e.what() << "\n";
    }
    return 0;
}
