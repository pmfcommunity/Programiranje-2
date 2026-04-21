#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>

/*
    Napisati funkciju f koja kao formalni parametar prima vektor od n realnih brojeva 
    x1, x2, ...., xn, a kao rezultat vraca vrijednost izraza:
    sqrt(x1 + sqrt(x2 + sqrt(... + sqrt(xn))))

    U slucaju da su elementi takvi da rezultat nije realan broj, funkcija treba baciti
    izuzetak "Podkorijena velicina je negativna". Na primjer, za vektor sastavljen od 
    brojeva 2, 4, i 9, funkcija treba vratiti broj 2.1554. Vodite racuna da rezultat 
    zaokruzite na cetiri decimale. 
*/

double korijen(const std::vector<double>& niz) {
    int n = niz.size();
    double rezultat {0.0};
    double suma {0.0};
    for (int i = n - 1; i >= 0; i--) {
        suma = rezultat + (double)niz.at(i);
        if (suma < 0) throw std::logic_error("Podkorijena velicina je negativna.");
        rezultat = std::sqrt(suma);
    }

    return rezultat;
}

int main() {
    try {
        int n;
        std::cout << "Unesite velicinu vektora: ";
        std::cin >> n;

        std::vector<double> niz;
        std::cout << "Unos elemenata vektora:\n";
        double broj;
        for (int i = 0; i < n; i++) {
            std::cin >> broj;
            niz.push_back(broj);
        }

        std::cout << std::fixed << std::setprecision(4) << korijen(niz) << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}