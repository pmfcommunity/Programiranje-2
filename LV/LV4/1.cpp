#include <iostream>
#include <cmath>

/*
    Napisite funkciju koja prima niz od n realnih brojeva a1, a2, ... an kao parametar,
    i koja racuna i vraca kao rezulat vrijednost izraza:
    sqrt(a1 + sqrt(a2 + sqrt(... + sqrt(an))))
    U slucaju da su elementi takvi da rezultat nije realan broj, funkcije treba baciti 
    izuzetak. Napisite i kratki testni program u kojem cete demonstrirati napisanu
    funkciju na sekvenci od n brojeva koji se unose sa tastature (prethodno se n
    takodjer unosi sa tastature). Obavezno predvidite i hvatanje eventualno bacenih
    izuzetaka iz funkcije.
*/

float korijen_u_korijenu(int* niz, int n) {
    float rezultat {0.0};
    float suma {0.0};
    for (int i = n - 1; i >= 0; i--) {
        suma = rezultat + niz[i];
        if (suma < 0) throw -1;
        rezultat = std::sqrt(suma);
        if (rezultat < 0) throw -2;
    }
    return rezultat;
}

int main() {
    try {
        int n;
        std::cin >> n;
        int niz[100];
        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < n; i++) {
            std::cin >> niz[i];
        }

        std::cout << korijen_u_korijenu(niz, n) << std::endl;
    }
    catch (int greska1) {
        std::cout << "Greska! Suma unutar korijena negativna!\n";
    }
    return 0;
}