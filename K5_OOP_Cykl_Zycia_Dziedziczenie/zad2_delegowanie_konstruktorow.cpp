// Zadanie 2 - Delegowanie Konstruktorow (C++11)
// Cel: eliminacja duplikacji kodu (DRY) przy wielu konstruktorach.
//
// Ograniczenie: jesli delegujemy, NIE mozna na tej samej liscie
// inicjalizowac dodatkowych pol, np.:
//   Window() : Window(800, 600), width(800) {}  // BLAD!

#include <iostream>
#include <string>

class Window {
    int width, height;
    std::string title;
public:
    // Glowny konstruktor
    Window(int w, int h, const std::string& t)
        : width(w), height(h), title(t) {
        std::cout << "Window: " << width << "x" << height
                  << " \"" << title << "\"\n";
    }
    // Deleguje do glownego (tytul domyslny)
    Window(int w, int h) : Window(w, h, "Untitled") {}
    // Deleguje do konstruktora 2-argumentowego (wymiary domyslne)
    Window() : Window(800, 600) {}
};

int main() {
    Window a(1920, 1080, "Game");
    Window b(640, 480);
    Window c;
    return 0;
}
