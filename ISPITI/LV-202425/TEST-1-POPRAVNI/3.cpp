#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

/*
    Napisati genericku funkciju sa dva parametra: prvi parametar je kvadratna matrica
    (proslijedjena kao dvostruki pokazivac) formata n x n proizvoljnog tipa, a drugi
    parametar je cijeli broj koji predstavlja dimenziju matrice n. Funkcija vraca
    dvostruki pokazivac na novu matricu koja je nastala zamjenom dijagonala originalne
    matrice. Pri tome se ne smije mijenjati sadrzaj originalne matrice.

    Npr. ako je data matrica:
    1 2 3 
    4 5 6
    7 8 9
    rezultat je:
    3 2 1
    4 5 6
    9 8 7
    U testnom programu treba predvidjeti hvatanje bacenih izuzetaka. Takodjer, ne smije 
    doci do curenja memorije. 
*/

template <typename T>

T** zamijeni_dijagonale(T** matrica, int n) {
    if (n <= 0) throw std::logic_error("Velicina matrice mora biti prirodan broj!");
    std::vector<std::vector<T>> vektor;

    for (int i = 0; i < n; i++) {
        std::vector<T> pomocni;
        for (int j = 0; j < n; j++) {
            pomocni.push_back(matrica[i][j]);
        }
        vektor.push_back(pomocni);
    }

    std::vector<T> lijeva, desna;
    for (int i = 0; i < vektor.size(); i++) {
        for (int j = 0; j < vektor.at(i).size(); j++) {
            if (i == j) {
                lijeva.push_back(vektor.at(i).at(j));
            } 
            if (i + j == n - 1) {
                desna.push_back(vektor.at(i).at(j));
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) vektor.at(i).at(j) = desna.at(i);
            if (i + j == n - 1) vektor.at(i).at(j) = lijeva.at(i);
        }

    }

    int** nova_matrica = new int*[n];
    for (int i = 0; i < n; i++) 
        nova_matrica[i] = new int[n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nova_matrica[i][j] = vektor.at(i).at(j);
        }
    }

    return nova_matrica;
}

int main() {
    try {
        int n;
        std::cout << "Unesite dimenziju matrice (n x n): ";
        std::cin >> n;
        int** matrica = new int*[n];
        for (int i = 0; i < n; i++) {
            matrica[i] = new int[n];
        }

        std::cout << "Unos elemenata matrice:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << "(" << i << " " << j << "): ";
                std::cin >> matrica[i][j]; 
            }
        }

        int** rezultat = zamijeni_dijagonale(matrica, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << rezultat[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        for (int i = 0; i < n; i++) {
            delete[] matrica[i];
            delete[] rezultat[i];
        }

        delete[] matrica;
        delete[] rezultat;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}