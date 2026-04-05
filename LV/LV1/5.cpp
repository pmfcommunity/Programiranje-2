#include <iostream>

/*
    Napisati program koji od korisnika trazi da unosi nenegativne cijele brojeve sve dok
    ne unese broj 0. Program ispisuje broj sa najvise neparnih cifara od svih unesenih
    brojeva.
*/

int main() {
    int broj;
    int najveci_brojac {0};
    int najveci_neparni {0};
    while (true) {
        std::cin >> broj;
        if (broj == 0) break;
        if (broj > 0) {
            int kopija = broj;
            int brojac {0};
            while (kopija != 0) {
                int cifra = kopija % 10;
                if (cifra % 2 != 0) brojac++;
                kopija /= 10;
            }
            if (brojac > najveci_brojac) {
                najveci_brojac = brojac;
                najveci_neparni = broj;
            }
        }
    }
    std::cout << najveci_neparni << std::endl;
    return 0;
}