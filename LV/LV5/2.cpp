#include <iostream>

/*
    Napisati funkciju void SmjestiMinMax koja prima 4 parametra, pokazivac na pocetak
    niza, pokazivac iza kraja niza, te dva pokazivaca u koja treba smjestiti pokazivac
    na najveci i najmanji element niza. Na primjer. Ako je dat niz {6, 2, 4, 8, 6, 1, 3},
    nakon poziva SmjestiMinMax(niz, niz + 7, Min, Max), pokazivaci Min i Max trebaju
    pokazivati na sesti i cetvrti element niza, redom. Na kraju, promjenite implementaciju
    ove funkcije tako da ona bude genericka.
*/

template <typename T>
void smjesti_min_i_max(T *pocetak, T *iza_kraja, T* &Min, T* &Max) {
    Min = pocetak;
    Max = pocetak;

    for (int *p = pocetak; p < iza_kraja; *p++) {
        if (*p < *Min) Min = p;
        if (*p > *Max) Max = p;
    }
}

int main() {
    int niz[] = {6, 2, 4, 8, 6, 1, 3};
    int n = sizeof(niz) / sizeof(niz[0]);   
    int* Min {nullptr};
    int* Max {nullptr};
    smjesti_min_i_max(&niz[0], &niz[0] + n, Min, Max);
    std::cout << *Min << std::endl;
    std::cout << *Max << std::endl;
    return 0;
}