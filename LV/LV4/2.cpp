#include <iostream>

/*
    Dat je niz od n brojeva proizvoljnog tipa. Kreairati novi niz od n brojeva, gdje je 
    i-ti element tog niza jednak proizvodu svih brojeva niza koji nisu na poziciji i.
    Uraditi to bez operacije dijeljenja i bez upotrebe petlji u petljama. Pri radu
    kreirati genericku funkciju.
*/

void pomnozi_niz(int* niz, int n) {
    int pomocni[100];
    int proizvod {1};
    for (int i = 0; i < n; i++) {
        pomocni[i] = proizvod;
        proizvod *= niz[i];
    }

    proizvod = 1;
    for (int i = n - 1; i >= 0; i--) {
        pomocni[i] *= proizvod;
        proizvod *= niz[i];
    }

    std::cout << "Ispis pomnozenog niza:\n";
    for (int i = 0; i < n; i++) {
        std::cout << pomocni[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Unos velicine niza: ";
    std::cin >> n;
    int niz[100];
    std::cout << "Unos elemenata niza:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> niz[i];
    }
    pomnozi_niz(niz, n);
    return 0;
}