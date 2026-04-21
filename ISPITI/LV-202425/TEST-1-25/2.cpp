#include <iostream>
#include <vector>
#include <stdexcept>

/*
    Napisati genericku funkciju f:
        vector < tip > rezultat f(tip * niz1, int n1, int * niz2, int n2)
    Pri cemu su prvi i treci parametar pokazivaci na pocetak nizova (prvi niz ima 
    elemente proizvoljnog tipa, a drugi cijele brojeve), dok su drugi i cetvrti
    parametar duzine tih nizova. Funkcija treba vratiti vektor elemenata koji se 
    formira od elemenata niza1, pri cemu brojevu u nizu2 odredjuju koliko puta se 
    odredjeni element niza1 pojavljuje u rezultatu. Npr. ako je niz1 = {2, 4, 9, 10}
    i niz2 = {1, 1, 3, 4}, rezultat je {2, 4, 9, 9, 9, 10, 10, 10, 10}. Ako je n1 != n2,
    funkcija baca izuzetak. U testnom programu treba dimaciki alocirati nizove. Predvidjeti
    hvatanje izuzetaka, kao i oslobadjanje memorije.
*/

template <typename T>

std::vector<T> f(T* niz1, int n1, int* niz2, int n2) {
    if (n1 != n2) throw std::logic_error("Velicine nizova ne mogu biti razlicite velicine!");
    std::vector<T> rezultat;
    std::vector<int> broj_ponavljanja;
    for(int *p = niz2; p < niz2 + n2; p++) {
        broj_ponavljanja.push_back(*p);
    }
    
    int index {0};
    for (T *p = niz1; p < niz1 + n1; p++) {
        int trenutni_broj = broj_ponavljanja.at(index);
        for (int i = 0; i < trenutni_broj; i++)
            rezultat.push_back(*p);
        index++;
    }

    return rezultat;
}

int main() {
    try {
        int n1;
        std::cout << "Unos broja elemenata niza:\n";
        std::cin >> n1;
        int* niz1 = new int[n1];
        
        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < n1; i++)
            std::cin >> niz1[i];
        
        int n2;
        std::cout << "Unos broja elemenata niza:\n";
        std::cin >> n2;
        int* niz2 = new int[n2];
        
        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < n2; i++) 
            std::cin >> niz2[i];
        
        std::vector<int> rezultat = f(niz1, n1, niz2, n2);
        std::cout << "Rezultat:\n";
        for (int r : rezultat) std::cout << r << " ";
        std::cout << std::endl;
        
        delete[] niz1;
    delete[] niz2;
    }
    catch (const std::logic_error& e) {
        std::cout << "Greska! " << e.what() << std::endl;
    }
    return 0;
}