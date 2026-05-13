#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

/*
    Napisite funkciju F koja u vidu formalnog parametra prima vektor v 
    sastavljen od n realnih brojeva a1, a2, ..., an, a kao rezultat racuna
    i vraca vrijednost sljedeceg izraza:
    sqrt(a1 + sqrt(a2 + sqrt(... + an)))
    U slucaju da su elementi vektora v takvi da da je potkorijena velicina manja
    od nule, funkcija treba baciti izuzetak. Obavezno predvidite i hvatanje
    eventualno hvatanje bacenih izuzetaka iz funkcije. 
*/

double F(const std::vector<double>& v) {
    if (v.empty()) throw std::logic_error("Vektor nema elemenata.");
    double rezultat {0.0};
    for (int i = v.size() - 1; i >= 0; i--) {
        rezultat = rezultat + v.at(i);
        if (rezultat <= 0) throw std::domain_error("Potkorijena velicina je negativna.");
        rezultat = std::sqrt(rezultat);
    }
    return rezultat;
}

int main() {
    try {
        int n;
        std::cout << "Velicina vektora: ";
        std::cin >> n;
        std::cout << "Unos elemenata vektora:\n";
        std::vector<double> v;
        for (int i = 0; i < n; i++) {
            double broj;
            std::cin >> broj;
            v.push_back(broj);
        }
        std::cout << F(v) << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}