#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

/*
    Napisati genericku funkciju f koja prima matricu M predstavljenu kao vektor vektora,
    koordinate elementa (i, j), a koja po referenci vraca maksimalni element glavne 
    dijagonale kroz element (i, j), bez ukljucivanja elementa (i, j), te zbir elemenata
    sporedne dijagonale kroz element (i, j), takodjer bez ukljucivanja elemenata (i, j).
    Funkcija f po vrijednosti treba vratiti proizvod svih elemenata matrice koji ne leze ni na 
    glavnoj ni na sporednoj dijagonali definisanoj kroz (i, j). Takodjer, funkcija treba
    baciti izuzetak ako matrice nije pravougaona ili je prazna, te ukoliko indeksi nisu u
    opsegu 0 <= i < r, 0 <= j < k, gdje r i k redom predstavljaju broj redova i kolona 
    matrice. 
*/

template <typename T>

std::vector<T> f(const std::vector<std::vector<T>>& matrica, int i, int j) {
    if (matrica.empty()) throw std::domain_error("Matrica je prazna!\n");
    std::vector<T> rezultati;

    int n = matrica.size();
    int m = matrica.at(0).size();

    if (i < 0 || i >= n || j < 0 || j >= m)
        throw std::domain_error("Indeksi su van dozvoljenih granica.");

    for (int r = 0; r < matrica.size(); r++) {
        for (int k = 0; k < matrica.at(r).size(); k++) {
            if (matrica.at(r).size() != m) 
                throw std::domain_error("Matrica nije pravougaona!");
        }
    }

    std::vector<T> glavna_dijagonala;
    T zbir_sporedne_dijagonale {0};
    T proizvod_ostalih {1};
    for (int r = 0; r < n; r++) {
        for (int k = 0; k < m; k++) {
            bool na_glavnoj = (r - k == i - j);
            bool na_sporednoj = (r + k == i + j);
            if (i == r && k == j) continue;
            if (na_glavnoj) glavna_dijagonala.push_back(matrica.at(r).at(k));
            if (na_sporednoj) zbir_sporedne_dijagonale += matrica.at(r).at(k);
            if (!na_glavnoj && !na_sporednoj) proizvod_ostalih *= matrica.at(r).at(k);
        }   
    }

    auto maximum = std::max_element(glavna_dijagonala.begin(), glavna_dijagonala.end());
    rezultati.push_back(*maximum);
    rezultati.push_back(zbir_sporedne_dijagonale);
    rezultati.push_back(proizvod_ostalih);

    return rezultati;
}

int main() {
    try {
        int n, m;
        std::cout << "Broj redova i kolona matrice: ";
        std::cin >> n >> m;
        int i, j;
        std::cout << "Unos koordinatnih tacaka: ";
        std::cin >> i >> j;
        std::vector<std::vector<float>> matrica;

        std::cout << "Unos elemenata matrice:\n";
        for (int i = 0; i < n; i++) {
            std::vector<float> pomocni;
            float broj;
            for (int j = 0; j < m; j++) {
                std::cout << "(" << i << " " << j << "): ";
                std::cin >> broj;
                pomocni.push_back(broj);
            }
            matrica.push_back(pomocni);
        }

        std::vector<float> rezultat = f(matrica, i, j);
        
        for (int r : rezultat) std::cout << r << " ";
        std::cout << std::endl;
    }
    catch (const std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}