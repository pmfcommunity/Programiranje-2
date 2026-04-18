#include <iostream>
#include <algorithm>

/*
    Napisati genericku funkciju vratiSortiran koja prima niz i broj elemenata niza, a 
    vraca sortirani niz (tj. pokazivac na njegov prvi element), pri tome ne mijenjajuci
    originalni niz.
*/

int* vrati_sortiran(int* niz, int n) {
    int* novi_niz = new int[n];

    for (int i = 0; i < n; i++) {
        novi_niz[i] = niz[i];
    }

    std::sort(novi_niz, novi_niz + n);

    return novi_niz;
}

int main() {
    int n;
    std::cout << "Velicina niza?\n";
    std::cin >> n;

    int* niz = new int[n];
    std::cout << "Unos elemenata niza:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> niz[i];
    }

    int* novi_niz = vrati_sortiran(niz, n);

    std::cout << "Ispis originalnog niza:\n";
    for (int i = 0; i < n; i++) {
        std::cout << niz[i] << " ";
    }
    std::cout << "\nNovi, sortirani niz:\n";
    for (int i = 0; i < n; i++) {
        std::cout << novi_niz[i] << " ";
    } 
    std::cout << std::endl;
    delete[] niz;
    delete[] novi_niz;
    return 0;
}