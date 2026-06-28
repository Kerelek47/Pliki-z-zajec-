// Zadanie 3 - Operator strumieniowy << (funkcje zaprzyjaznione)
// Cel: integracja klasy z iostream.
//
// Problem: lewy argument operatora << to strumien (std::ostream), a nie nasz
// obiekt - dlatego << NIE moze byc metoda klasy. Robimy go funkcja zaprzyjazniona.
//
// friend - daje funkcji zewnetrznej dostep do pol private/protected.
// Zwracamy std::ostream& -> kaskadowosc (cout << a << b << c).
// W definicji NIE ma Vector2D:: - to nie jest metoda klasy.

#include <iostream>

class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& o) const { return Vector2D(x + o.x, y + o.y); }

    // deklaracja funkcji zaprzyjaznionej wewnatrz klasy
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// definicja poza klasa - bez Vector2D::
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;   // zwracamy strumien -> kaskadowosc
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    std::cout << v1 << " + " << v2 << " = " << (v1 + v2) << std::endl;
    return 0;
}
