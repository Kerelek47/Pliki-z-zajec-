// Zadanie 3 - Destruktor i RAII
// Cel: automatyczne zarzadzanie pamiecia (idiom RAII).
// W C++ nie ma Garbage Collectora - pamiec z new musi zwolnic delete.
//
// Pytanie: kiedy pojawi sie "Deallocated"?
// Odpowiedz: przy wyjsciu z bloku { ... }, czyli PRZED "End".
// Kolejnosc: Start -> Allocated 100 -> Deallocated -> End.

#include <iostream>

class Buffer {
    int* data;
    int size;
public:
    Buffer(int size) : size(size) {
        data = new int[size];
        std::cout << "Allocated " << size << "\n";
    }
    ~Buffer() {
        delete[] data;
        std::cout << "Deallocated\n";
    }
};

int main() {
    std::cout << "Start\n";
    {
        Buffer b(100);
    } // koniec zakresu -> destruktor
    std::cout << "End\n";
    return 0;
}
