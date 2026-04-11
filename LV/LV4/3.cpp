#include <iostream>

/*
    Napisite funkciju koja prihvata dva parametra. Parametri su pokazivaci koji omeduju
    niz cjelobrojnih elemenata (tj. prvi pokazivac pokazuje na prvi element niza, dok
    drugi pokazivac pokazuje iza posljednjeg elementa niza). Funkcija kao rezultat treba
    da vrati broj trocifrenih brojeva u zadanom nizu. Napisite i mali testni program u 
    kojem cete demonstrirati kako se upotrebljava napisana funkcija na nizu cijelih
    brojeva.
*/

int broj_trocifrenih(int* pocetak, int* kraj, int velicina) {
    int brojac {0};
    for (int *i = pocetak; i < kraj; i++) {
        if (*i > 99 && *i < 1000) brojac++;
    }
    return brojac;
}

int main() {
    int niz[] = {1, 200, 3, 400, 5, 600, 700, 99, 1000, 800};
    int velicina = sizeof(niz) / sizeof(niz[0]);
    std::cout << broj_trocifrenih(&niz[0], &niz[0] + velicina, velicina) << std::endl;
    return 0;
}