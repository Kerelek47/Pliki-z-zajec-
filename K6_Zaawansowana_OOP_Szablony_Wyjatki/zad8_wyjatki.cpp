// Zadanie 8 - Wyjatki (try-catch)
// Cel: mechanizm obslugi bledow za pomoca wyjatkow.
//
// throw - zglasza wyjatek, przerywa normalny przeplyw i szuka pasujacego catch.
// try   - blok, w ktorym monitorujemy potencjalne wyjatki.
// catch - blok obslugujacy wyjatek pasujacego typu.
//
// Hierarchia: std::invalid_argument -> std::logic_error -> std::exception.
// Metoda what() zwraca komunikat bledu.

#include <iostream>
#include <stdexcept>   // std::invalid_argument

double podziel(double licznik, double mianownik) {
    if (mianownik == 0)
        throw std::invalid_argument("Dzielenie przez zero!");
    return licznik / mianownik;
}

int main() {
    // Poprawne argumenty
    try {
        std::cout << "10 / 2 = " << podziel(10, 2) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Blad: " << e.what() << "\n";
    }

    // Mianownik = 0 -> wyjatek
    try {
        std::cout << "10 / 0 = " << podziel(10, 0) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Blad: " << e.what() << "\n";
    }

    std::cout << "Program dziala dalej (wyjatek zostal obsluzony).\n";
    return 0;
}
