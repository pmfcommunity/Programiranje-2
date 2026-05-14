#include <iostream>
#include <cmath>

/*
    Napisati funkciju f koja ima cetiri parametra, pri cemu su prva dva 
    parametra niz cijelih brojeva A i broj elemenata n tog niza. Funkcija f
    treba u treci i cetvrti parametar redom smjestiti broj jednocifrenih (J)
    i broj dvocifrenih (D) elemenata niza A. Pored toga, funkcija f treba 
    vratiti kao rezultat broj 1 akko je bar jedan element niza A jednak nuli,
    a u suprotnom vraca broj 0.
*/

int f(int* niz, int n, int& J, int& D) {
    int broj_jednocifrenih {0}, broj_dvocifrenih {0};
    bool pojavila_se_nula = false;
    for (int i = 0; i < n; i++) {
        niz[i] = std::abs(niz[i]);
        if (niz[i] >= 1 && niz[i] <= 9) broj_jednocifrenih++;
        if (niz[i] >= 10 && niz[i] <= 99) broj_dvocifrenih++;
        if (niz[i] == 0) pojavila_se_nula = true; 
    }
    J = broj_jednocifrenih;
    D = broj_dvocifrenih;

    if (pojavila_se_nula) return 1;
    return 0;
}

int main() {
    int n;
    std::cout << "Unos velicine niza: ";
    std::cin >> n;
    int* niz = new int[n];
    std::cout << "Unos elemenata niza:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> niz[i];
    }
    int J {0}, D {0};
    int I {f(niz, n, J, D)};
    std::cout << J << " " << D << " " << I << std::endl;

    delete[] niz;
    niz = nullptr;
    return 0;
}