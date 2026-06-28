// Zadanie 6 - Parametry szablonu niebedace typami (non-type)
// Cel: wykorzystanie stalych wartosci jako parametrow szablonu.
//
// Szablon moze przyjac nie tylko typ (typename T), ale tez wartosc (int size),
// o ile jest znana w czasie KOMPILACJI (literal lub constexpr).
//
// Wnioski:
// - wydajnosc: tablica na stosie, brak dynamicznej alokacji.
// - StaticArray<int,5> i StaticArray<int,6> to ROZNE typy - nie da sie przypisac.
// - size musi byc znane przy kompilacji - nie mozna podac zmiennej od uzytkownika.

#include <iostream>
#include <string>

template <typename T, int size>
class StaticArray {
    T data[size];   // tablica statyczna o rozmiarze z parametru szablonu
public:
    int getSize() const { return size; }
    void set(int index, T value) { data[index] = value; }
    T get(int index) const { return data[index]; }
};

int main() {
    StaticArray<int, 5> a;
    StaticArray<double, 10> b;

    std::cout << "rozmiar a: " << a.getSize() << "\n";   // 5
    std::cout << "rozmiar b: " << b.getSize() << "\n";   // 10

    a.set(0, 11);
    a.set(4, 99);
    std::cout << "a[0] = " << a.get(0) << ", a[4] = " << a.get(4) << "\n";
    return 0;
}
