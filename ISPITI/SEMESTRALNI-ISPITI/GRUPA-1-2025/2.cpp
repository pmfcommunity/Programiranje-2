#include <iostream>
#include <vector>

/*
    Napsite genericku funkciju f sa cetiri parametra tako da je njen prvi parametar niz A
    proizvoljnog tipa, dok je drugi parametar broj elemenata u tom nizu. U treci i cetvrti
    parametar redom se trebaju smjestiti broj lokalnih maksimuma i minimuma niza A. Za
    element an niza A aze se da je lokalni maksimum akko je veci od oba svoja susjeda,
    tj. vrijedi an > an-1 i an > an+1. Takodjer, za element an niza A kaze se da je 
    lokalni minimum akko je manji od oba svoja susjeda, tj. vrijedi an < an-1 i 
    an < an+1. Funkciju main napisite tako da se sa tastature moze unijeti broj
    elemenata niza A (n), kao i niz A, te se pozivom funkcije f u treci i cetvrti
    parametar ispisuju broj lokalnih minimuma (lMin) i broj lokalnih maksimuma (lMax).
    Obavezno oslobodite sve zauzete resurse.
*/

template <typename T>
void f(T niz[], int n, T &lMin, T &lMax) {
    std::vector<T> vektor;
    for (int i = 0; i < n; i++)
        vektor.push_back(niz[i]);
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) continue;
        if (vektor.at(i) > vektor.at(i + 1) && vektor.at(i) > vektor.at(i - 1)) lMax++;
        if (vektor.at(i) < vektor.at(i + 1) && vektor.at(i) < vektor.at(i - 1)) lMin++;
    }
}

int main() {
    int n;
    std::cout << "Unos broja elemenata niza: ";
    std::cin >> n;
    
    double* niz = new double[n];
    std::cout << "Unos elemenata niza:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> niz[i];
    }

    double lMin {0}, lMax {0};
    f(niz, n, lMin, lMax);
    std::cout << "Br. lokalnih minimuma: " << lMin << std::endl;
    std::cout << "Br. lokalnih maksimuma: " << lMax << std::endl;
    return 0;
}