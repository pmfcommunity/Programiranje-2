#include <iostream>
#include <vector>

/*
    Napisati genericku funkciju Obrni(Tip *pocetak, Tip *iza_kraja) koja prima dva
    pokazivaca, a koja obrne dio niza (ili vektora) izmedju tih pokazivaca. 
    Podrazumijevajte da pocetak pokazuje na element koji je prije elementa na koji
    pokazuje pokazivac iza_kraja.
*/

template <typename T>
void Obrni(T *pocetak, T *iza_kraja) {
    *iza_kraja--;
    while (pocetak < iza_kraja) {
        std::swap(*pocetak, *iza_kraja);
        *pocetak++;
        *iza_kraja--;
    }
}

int main() {
    int niz[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int velicina = sizeof(niz) / sizeof(niz[0]);
    Obrni(&niz[0], &niz[0] + velicina);
    for (int i = 0; i < velicina; i++) {
        std::cout << niz[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> vektor = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Obrni(vektor.data(), vektor.data() + vektor.size());
    for (int broj : vektor) 
        std::cout << broj << " ";
    std::cout << std::endl;
    return 0;
}