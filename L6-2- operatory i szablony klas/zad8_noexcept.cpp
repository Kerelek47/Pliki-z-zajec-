// Zadanie 8 - Wyjatki i specyfikator noexcept
// Cel: rola gwarancji braku wyjatkow.
//
// noexcept (na koncu funkcji) - DEKLARACJA: "ta funkcja nie rzuci wyjatku".
//   Jesli mimo to rzuci -> std::terminate() konczy program (bez szukania catch).
// noexcept(wyrazenie) - OPERATOR: zapytanie w czasie kompilacji, czy dane
//   wyrazenie jest oznaczone jako noexcept (zwraca true/false).
//
// if constexpr (C++17) - galaz wybierana w czasie kompilacji.

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class SimpleContainer {
    T value;
public:
    SimpleContainer(T value) : value(value) {}

    T getValue() const noexcept { return value; }   // obiecujemy: bez wyjatkow

    void checkAndSet(T val) {                        // NIE noexcept - moze rzucic
        if (val < 0)
            throw std::out_of_range("Wartosc nie moze byc ujemna");
        value = val;
    }
};

// Funkcja szablonowa: sprawdza w czasie kompilacji, czy getValue jest noexcept,
// i wypisuje odpowiedni komunikat przed wlasciwym wywolaniem.
template <typename T>
void safe_call(const T& obj) {
    if constexpr (noexcept(obj.getValue())) {
        std::cout << "getValue() jest bezpieczne (noexcept), wynik: "
                  << obj.getValue() << "\n";
    } else {
        std::cout << "getValue() moze rzucic wyjatek, wynik: "
                  << obj.getValue() << "\n";
    }
}

int main() {
    SimpleContainer<int> c(42);

    // operator noexcept(...) w czasie kompilacji:
    std::cout << std::boolalpha;
    std::cout << "noexcept(getValue()):    " << noexcept(c.getValue()) << "\n";    // true
    std::cout << "noexcept(checkAndSet()): " << noexcept(c.checkAndSet(1)) << "\n"; // false

    safe_call(c);

    // demonstracja rzucenia wyjatku przez checkAndSet
    try {
        c.checkAndSet(-5);
    } catch (const std::out_of_range& e) {
        std::cout << "Zlapano: " << e.what() << "\n";
    }
    return 0;
}
