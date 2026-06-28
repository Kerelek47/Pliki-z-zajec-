// Zadanie 9 - Integracja - Szablonowy SafeArray
// Cel: bezpieczny kontener laczacy szablony + operatory + wyjatki.
//
// SafeArray<T, size> chroni przed dostepem poza zakres.
// operator[] sprawdza index i rzuca std::out_of_range przy bledzie.
//
// Dwie wersje operatora[]:
//   - T& operator[](int)        -> pozwala modyfikowac element (arr[0] = ...)
//   - const T& operator[](int) const -> dla obiektow const
// To przeciazenie przez const jest niezbedne dla kompletnosci interfejsu.

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, int size>
class SafeArray {
    T data[size];
public:
    // wersja modyfikujaca
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index " + std::to_string(index) +
                                    " poza zakresem [0, " + std::to_string(size - 1) + "]");
        return data[index];
    }
    // wersja const (dla obiektow const, tylko odczyt)
    const T& operator[](int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index " + std::to_string(index) +
                                    " poza zakresem [0, " + std::to_string(size - 1) + "]");
        return data[index];
    }
    int getSize() const { return size; }
};

int main() {
    SafeArray<std::string, 3> words;
    words[0] = "Ala";       // zapis przez referencje
    words[1] = "ma";
    words[2] = "kota";

    for (int i = 0; i < words.getSize(); ++i)
        std::cout << words[i] << " ";
    std::cout << "\n";

    // celowy blad - dostep poza zakres
    try {
        std::cout << words[5] << "\n";   // index 5 nie istnieje
    } catch (const std::out_of_range& e) {
        std::cout << "Blad: " << e.what() << "\n";
    }

    try {
        std::cout << words[-1] << "\n";  // index -1 tez bledny
    } catch (const std::out_of_range& e) {
        std::cout << "Blad: " << e.what() << "\n";
    }
    return 0;
}
