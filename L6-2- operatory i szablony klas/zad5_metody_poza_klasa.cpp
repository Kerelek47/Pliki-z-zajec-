// Zadanie 5 - Definiowanie metod szablonu poza cialem klasy
// Cel: separacja deklaracji od definicji.
//
// Specyfika szablonow: kazda definicja metody poza klasa musi miec:
//   - naglowek template <typename T>
//   - pelna nazwe klasy z parametrem: Box<T>::nazwaMetody
//
// Uwaga: definicje szablonow zwykle trzyma sie w pliku naglowkowym (.h/.hpp),
// bo kompilator musi je instancjonowac w kazdym .cpp, ktory ich uzywa.
// Tu dla prostoty wszystko jest w jednym pliku.

#include <iostream>
#include <string>

template <typename T>
class Box {
    T value;
public:
    Box(T value) : value(value) {}
    T getValue() const;            // tylko deklaracja
    void setValue(T newValue);     // tylko deklaracja
};

// definicje poza klasa
template <typename T>
T Box<T>::getValue() const {
    return value;
}

template <typename T>
void Box<T>::setValue(T newValue) {
    value = newValue;
}

int main() {
    Box<int> bi(42);
    std::cout << "getValue: " << bi.getValue() << "\n";
    bi.setValue(7);
    std::cout << "po setValue: " << bi.getValue() << "\n";

    Box<std::string> bs("abc");
    std::cout << "getValue: " << bs.getValue() << "\n";
    return 0;
}
