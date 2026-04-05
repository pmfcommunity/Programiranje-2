#include <iostream>
#include <vector>

/*
    Napisati program koji od korisnika trazi unos broja n, te zatim unosi n prirodnih brojeva.
    Program provjerava koja je najveca cifra koja se pojavljuje u unesenim brojevima, 
    te ispisuje koji od unesenih brojeva ima najvise pojavljivanja te cifre.
*/

int pronadji_najveceg(std::vector<int>& niz) {
    int najveca {0};
    for (int i = 0; i < niz.size(); i++) {
        int kopija = niz.at(i);
        while (kopija != 0) {
            int cifra = kopija % 10;
            if (cifra > najveca) najveca = cifra;
            kopija /= 10;
        }
    }
    int najveci_brojac {0};
    int najveca_cifra {0};
    for (int i = 0; i < niz.size(); i++) {
        int kopija = niz.at(i);
        int brojac {0};
        while (kopija != 0) {
            int cifra = kopija % 10;
            if (cifra == najveca) brojac++;
            kopija /= 10;
        }
        if (brojac > najveci_brojac) {
            najveci_brojac = brojac;
            najveca_cifra = niz.at(i);
        }
    }
    return najveca_cifra;
}

int main() {
    int n;
    std::vector<int> niz;
    std::cin >> n;

    int broj;
    for (int i = 0; i < n; i++) {
        std::cin >> broj;
        niz.push_back(broj);
    }

    std::cout << pronadji_najveceg(niz) << std::endl;
    return 0;
}