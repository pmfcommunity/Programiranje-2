#include <iostream>
#include <vector>
#include <algorithm>

/*
    Napisati genericku funkciju sa 2 parametra: prvi parametar je kvadratna matrica
    A sa elementima proizvoljnog tipa (proslijedjena kao dvostruki pokazivac), a drugi
    parametar je prordan broj n koji predstavlja dimenziju matrice. Funkcija vraca 
    dvostruki pokazivac na matricu formata n x n, koja se dobije tako sto sve parne 
    redove matrice A prepisemo (indeksiranje redova pocinje od nule), a sve
    neparne obrnemo. Matrica A se pri tome ne mijenja. Npr. ako je n = 4 i A:
    1 2 -1 4
    -8 -3 4 2
    3 8 10 -8
    -4 -1 1 7
    Rezultujuca matrica je:
    1 2 -1 4
    2 4 -3 -8
    3 8 10 -8
    7 1 -1 -4
    U testnom programu treba dinamicki alocirati kvadratnu matricu i proslijediti je 
    funkciji, ispisati rezultat, te na kraju osloboditi zauzetu memoriju.
*/

template <typename T>

T** f(T** matrica, int n) {
    std::vector<std::vector<T>> v_matrica;
    int index {1};
    for (int i = 0; i < n; i++) {
        std::vector<T> pomocni;
        for (int j = 0; j < n; j++) {
            pomocni.push_back(matrica[i][j]);
        }
        if (index % 2 == 0) std::reverse(pomocni.begin(), pomocni.end());
        v_matrica.push_back(pomocni);
        index++;
    }

    int** rezultat = new int*[n];
    for (int i = 0; i < n; i++) {
        rezultat[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rezultat[i][j] = v_matrica.at(i).at(j);
        }
    }

    return rezultat;
}

int main() {
    int n;
    std::cout << "Unesite velicinu kvadratne matrice: ";
    std::cin >> n;
    int** matrica = new int*[n];
    for (int i = 0; i < n; i++) 
        matrica[i] = new int[n];

    std::cout << "Unos elemenata matrice:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "(" << i << " " << j << "): ";
            std::cin >> matrica[i][j]; 
        }
    }

    int** rezultat = f(matrica, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << rezultat[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrica[i];
        delete[] rezultat[i];
    }
    delete[] matrica;
    delete[] rezultat;
    return 0;
}