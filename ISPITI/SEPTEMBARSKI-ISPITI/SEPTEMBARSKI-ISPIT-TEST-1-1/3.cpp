#include <iostream>
#include <tuple>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iterator>

/*
    Napisati funkciju g sa cetiri parametra: f, xmin, xmax, dx, pri cemu funkcija f prima
    realni broj kao parametar i vraca realan broj kao rezultat, dok su xmin, xmax, dx,
    realni brojevi. Ukoliko se desi da unesena vrijednost xmin je veca od vrijednosti
    xmax, tada se treba baciti izuzetak "Neispravan opseg". Funkcija g treba kao rezultat
    u vidu trojke (koristite std::tuple) vratiti najmanji, srednji i najveci element liste
    L, pri cemu se lista L kreira na osnovu vrijednosti funkcije f uzimajuci sve vrijednosti
    argumenata od xmin do xmax sa korakom dx, odnosno uzimajuci ove vrijednosti: 
    f(xmin), f(xmin + dx), f(xmin + 2dx), ..., f(xmax). Funkciju g se treba tako implementirati
    da u glavnom programu ona moze primiti jednu od tri lambda funkcije, koje joj se 
    prosljedjuju u vidu formalnog parametra:
    - ako je izbor jednak 0, tada funkcija f ima ovaj oblik: f(x) = 3x^2 - 5;
    - ako je izbor jednak 1, funkcija f je ovako zadata: f(x) = sin(x);
    - ako je izbor jednak 2, prosljeduje se ova funkcija: f(x) = e^(-x);
    Ukoliko se za izbor nese broj koji nije jednak 0, 1, ili 2, tada se treba baciti izuzetak
    sa porukom: "Nepoznata funkcija". Na primjer, ako se funkciji g proslijedi funkcija
    f(x) = 3x^2 - 5, xmin = 0, xmax = 10, dx = 0.1, tada ona vraca trojiku (-5, 70, 295)
*/

std::tuple<double, double, double> g(double (*f)(double), double xmin, double xmax, double dx) {
    if (xmin > xmax) throw std::logic_error("Neispravan opseg.");
    std::list<double> L;
    double trenutni_x = xmin;
    while (trenutni_x <= xmax + 0.000001) {
        double y = f(trenutni_x);
        L.push_back(y);
        trenutni_x += dx;
    }
    if (L.empty()) throw std::domain_error("Lista prazna!");
    auto najmanji = std::min_element(L.begin(), L.end());
    auto najveci = std::max_element(L.begin(), L.end());
    auto srednji = L.begin();
    std::advance(srednji, L.size() / 2);

    return std::make_tuple(*najmanji, *srednji, *najveci);
}

int main() {
    try {
        double xmin, xmax, dx;
        int izbor;
        double (*izbor_funkcija)(double);
        std::cout << "Unos xmin: ";
        std::cin >> xmin;
        std::cout << "Unos xmax: ";
        std::cin >> xmax;
        std::cout << "Unos koraka: ";
        std::cin >> dx;
        std::cout << "Unos izbora funkcije: ";
        std::cin >> izbor;
        if (izbor >= 0 && izbor <= 2) {
            switch (izbor) {
                case 0:
                    izbor_funkcija = [](double x) {return 3 * x * x - 5;};
                    break;
                case 1:
                    izbor_funkcija = [](double x) {return std::sin(x);};
                    break;
                case 2:
                    izbor_funkcija = [](double x) {return std::exp(-x);};
                    break;
            }
            std::tuple<double, double, double> rezultat = g(izbor_funkcija, xmin, xmax, dx);
            std::cout << std::get<0>(rezultat) << std::endl;
            std::cout << std::get<1>(rezultat) << std::endl;
            std::cout << std::get<2>(rezultat) << std::endl;
        } else {
            throw std::runtime_error("Nepoznata funkcija.");
        }
    }
    catch (const std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}