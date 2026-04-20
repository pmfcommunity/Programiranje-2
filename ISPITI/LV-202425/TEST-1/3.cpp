#include <iostream>

/*
    Napisati funkciju sa dva parametra: prvi parametar je kvadratna matrica A koja
    je proslijedjena kao dvostruki pokazivac, a drugi parametar je prirodan broj n koji
    predstavlja dimenziju matrice. Funkcija treba zamijeniti matricu A novom matricom
    koja se dobije tako sto se svaki element matrice A zamijeni prosjekom vrijednosti
    tog elementa i njemu dva susjedna elementa u istom redu. Prosjek treba biti zaokruzen
    na manji cijeli broj. Ako je neki element u prvoj ili posljednjoj koloni, onda se 
    trazi prosjek samo 2 elementa: tog elementa i njemu susjednog. Npr. ako je n = 3 i
    A = 
    100 200 100
    200 50  200
    100 200 100

    Matrica A postaje:
    150 133 150
    125 150 125
    150 133 150
    U testnom programu treba dinamicki alocirati kvadratnu matricu, proslijediti je funkciji
    i ispisati rezultat. Potrebno je osloboditi zauzetu memoriju.
*/

void zamijeni_matricu(int** matrica, int n) {
    int** kopija = new int*[n];
    for (int i = 0; i < n; i++) {
        kopija[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int suma {0}, brojac {0};
            suma += matrica[i][j];
            brojac++;
            if (j > 0) {
                suma += matrica[i][j - 1];
                brojac++;
            }
            if (j < n - 1) {
                suma += matrica[i][j + 1];
                brojac++;
            }

            kopija[i][j] = suma / brojac;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrica[i][j] = kopija[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        delete[] kopija[i];
    delete[] kopija;
}

int main() {
    int n;
    std::cout << "Dimenzija matrice (n x n): ";
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

    zamijeni_matricu(matrica, n);

    std::cout << "Izmjenjena matrica:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrica[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++)
        delete[] matrica[i];
    delete[] matrica;
    return 0;
}