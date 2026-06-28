// Zadanie 2 - Operatory porownania (==, !=)
// Cel: logiczna weryfikacja tozsamosci obiektow.
//
// Dobre praktyki:
// - typ zwracany: zawsze bool.
// - DRY: != implementujemy jako zaprzeczenie == (spojnosc logiczna).
// - double porownujemy bezposrednio (dydaktycznie); w praktyce uzywa sie epsilon.
// - std::boolalpha: wypisuje true/false zamiast 1/0.

#include <iostream>

class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x(x), y(y) {}

    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);   // DRY: wykorzystujemy operator==
    }

    void display() const { std::cout << "[" << x << ", " << y << "]"; }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(3, 4);   // takie same jak a
    Vector2D c(1, 2);   // inne

    std::cout << std::boolalpha;   // true/false zamiast 1/0
    std::cout << "a == b: " << (a == b) << "\n";   // true
    std::cout << "a == c: " << (a == c) << "\n";   // false
    std::cout << "a != c: " << (a != c) << "\n";   // true
    return 0;
}
