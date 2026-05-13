#include <iostream>
#include <vector>
#include <stdexcept>

/*
    Napisati funkciju F koja u vidu formalnog parametra prima vektor v sastavljen
    od n realnih brojeva a1, a2, ..., an, a kao rezultat racuna i vraca 
    vrijednost sljedeceg izraza:
    (1 / a1) + (1 / (a1 + a2)) + (1 / (a1 + a2 + a3)) + ... + (1 / (a1 + a2
    + ... + an))
    U slucaju da su elementi vektora v takvi da se neki od nazivnika anulira,
    funkcija treba baciti izuzetak. Obavezno predvidite i hvatanje eventualno
    bacenih izuzetaka iz funkcije. 
*/

double F(const std::vector<double>& v) {
    if (v.empty()) throw std::logic_error("Vektor nema elemenata.");
    double suma_nazivnika {0.0};
    double suma_razlomka {0.0};
    double rezultat {0.0};
    for (int i = 0; i < v.size(); i++) {
        suma_nazivnika += v.at(i);
        if (suma_nazivnika == 0) throw std::domain_error("Dijeljenje sa nulom nije definisano.");
        suma_razlomka = (1 / suma_nazivnika);
        rezultat += suma_razlomka;
    }
    return rezultat;
}

int main() {
    try {
        int n;
        std::vector<double> v;
        std::cout << "Velicina vektora: ";
        std::cin >> n;
        std::cout << "Unos elemenata vektora:\n";
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