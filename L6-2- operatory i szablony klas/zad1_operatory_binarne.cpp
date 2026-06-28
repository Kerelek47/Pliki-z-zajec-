// Zadanie 1 - Przeciazanie operatorow binarnych (+, -)
// Cel: intuicyjna arytmetyka dla wlasnych typow.
//
// Analiza:
// - const na koncu operatora: nie modyfikujemy lewego argumentu (this).
// - (const Vector2D& other): przekazanie przez stala referencje - bez kopiowania.
// - zwracanie przez wartosc: wynik to nowy obiekt.
// - [[nodiscard]] (C++17): ostrzezenie, gdy wynik zostanie zignorowany.

#include <iostream>

class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x(x), y(y) {}

    [[nodiscard]] Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    [[nodiscard]] Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    void display() const {
        std::cout << "[" << x << ", " << y << "]";
    }
};

int main() {
    Vector2D a(3, 4);
    Vector2D b(1, 2);

    Vector2D suma = a + b;
    Vector2D roznica = a - b;

    a.display(); std::cout << " + "; b.display(); std::cout << " = "; suma.display(); std::cout << "\n";
    a.display(); std::cout << " - "; b.display(); std::cout << " = "; roznica.display(); std::cout << "\n";
    return 0;
}
