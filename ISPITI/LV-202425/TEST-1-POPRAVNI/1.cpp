#include <iostream>
#include <stdexcept>

/*
    Napisati funkcju f koja kao parametre prima niz i broj elemenata tog niza n. 
    Funkcija treba da dinamicki alocira prostor za niz sa n elemenata koji nastaje
    pomjeranjem elemenata pocetnog niza za jedno mjesto, te vrati pokazivac na 
    prvi element tog niza. Npr. ako je proslijedjen niz {5, -1, 4, 2, -3, 7}, 
    rezultujuci niz je {-1, 4, 2, -3, 7, 5}. U slucaju da je n <= 0, funckija treba da
    baci izuzetak. Napisati testni program u kojem korisnik poziva funkciju na nekom
    (obicnom) nizu, ispisuje elemente dobijenog niza i oslobadja zauzetu memoriju. U 
    testnom programu treba predvidjeti hvatanje bacenih izuzetaka.
*/

void f(int* niz, int n) {
    if (n <= 0) throw std::logic_error("Velicina niza mora biti prirodan broj!");
    int* novi_niz = new int[n]; 
    for (int i = 0; i < n - 1; i++)
        novi_niz[i] = niz[i + 1];
    novi_niz[n - 1] = niz[0];
    
    for (int i = 0; i < n; i++)
        std::cout << novi_niz[i] << " ";
    std::cout << std::endl;
    delete[] novi_niz;
}

int main() {
    try {
        int n;
        std::cout << "Broj elemenata niza: ";
        std::cin >> n;

        int* niz = new int[n];

        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < n; i++) 
            std::cin >> niz[i];
        
        f(niz, n);

        delete[] niz;
    } catch (const std::invalid_argument& e) {
        std::cout << "Greska! " << e.what() << std::endl;
    }
    return 0;
}