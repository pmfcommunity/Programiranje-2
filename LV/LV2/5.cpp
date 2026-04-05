#include <iostream>

/*
    Napisati funkciju koja prihvata cetiri parametara: niz, n, negativni, razliciti. Prva
    dva parametra predstavljaju niz cijelih brojeva i broj elemenata u proslijedjenom nizu.
    Nakon izvrsavanja, funkcija u treci i cetvrti parametar smjesta broj negativnih brojeva
    u nizu, te broj razlicitih elemenata u nizu, redom.
*/

void pronadji_negativne_i_razlicite(int niz[], int n, int& negativni, int& razliciti) {
    int brojac_negativnih {0};
    for (int i = 0; i < n; i++) 
        if (niz[i] < 0) brojac_negativnih++;
    negativni = brojac_negativnih;

    int brojac_razlicitih {0};
    for (int i = 0; i < n; i++) {
        bool vec_pronadjen = false;
        for (int j = 0; j < i; j++) {
            if (niz[i] == niz[j]) {
                vec_pronadjen = true;
                break;
            }
        }
        if (vec_pronadjen == false) brojac_razlicitih++; 
    }
    razliciti = brojac_razlicitih;
}

int main() {
    int niz[] = {1, 3, 2, -2, 2, -1, 5, 6, 7};

    int negativni {0}, razlicit {0};
    pronadji_negativne_i_razlicite(niz, sizeof(niz) / sizeof(int), negativni, razlicit);
    std::cout << negativni << " " << razlicit << std::endl;
    return 0;
}