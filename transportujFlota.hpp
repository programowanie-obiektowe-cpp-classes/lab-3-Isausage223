#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0u) {
        return 0u;
    }

    Stocznia stocznia{};              // fabryka statków
    unsigned int suma = 0u;           // sumarycznie przetransportowany towar
    unsigned int liczbaZaglowcow = 0; // liczba UTWORZONYCH żaglowców

    while (suma < towar) {
        Statek* s = stocznia();       // 1) utwórz statek (Tankowiec lub Żaglowiec)

        // 2) policz, czy to żaglowiec
        if (dynamic_cast<Zaglowiec*>(s) != nullptr) {
            ++liczbaZaglowcow;
        }

        // 3) dodaj, ile ten statek przewiózł
        suma += s->transportuj();

        // 4) zniszcz statek, aby nie było wycieku pamięci
        delete s;
    }

    // 5) suma >= towar -> koniec, zwróć liczbę żaglowców
    return liczbaZaglowcow;
}