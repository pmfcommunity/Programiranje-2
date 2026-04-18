#include <iostream>
#include <algorithm>

/*
    Napisati funkciju void Rotiraj(int **matrica, int n) koja rotira datu matricu
    za 90 stepeni (u smjeru suprotnom od smjera kazaljke na satu)
*/

void Rotiraj(int** matrica, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::swap(matrica[i][j], matrica[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::reverse(matrica[i], matrica[n - 1 - 1]);
    }

    std::cout << "Ispis matrice:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrica[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Unos nxn matrice: ";
    std::cin >> n;
    int** matrica = new int*[n];

    for (int i = 0; i < n; i++) {
        matrica[i] = new int[n];
    }

    std::cout << "Unos vrijednosti matrice:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "(" << i << " " << j << "): ";
            std::cin >> matrica[i][j];
            std::cout << std::endl;  
        }
    }
    Rotiraj(matrica, n);

    for (int i = 0; i < n; i++) {
        delete[] matrica[i];
    }

    delete[] matrica;
    return 0;
}