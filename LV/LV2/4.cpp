#include <iostream>
#include <vector>

/*
    Napisati program koji od korisnika trazi unos brojeva sve dok ne unese nulu. Program
    provjerava koja je najveca cifra koja se pojavljuje u unesenim brojevima, te ispisuje
    koji od unesenih brojeva ima najvise pojavljivanja te cifre. Pretpostaviti da korisnik
    nece unositi vise od 100 brojeva.
*/

int pronadji_najveci(std::vector<int> niz) {
    int najveca_cifra {0};
    for (int i = 0; i < niz.size(); i++) {
        int kopija = niz.at(i);

        while (kopija != 0) {
            int cifra = kopija % 10;
            if (cifra > najveca_cifra) najveca_cifra = cifra;
            kopija /= 10;
        }
    }

    int najveci_brojac {0};
    int najveci_broj {0};
    for (int i = 0; i < niz.size(); i++) {
        int kopija = niz.at(i);
        int brojac {0};
        while (kopija != 0) {
            int cifra = kopija % 10;
            if (cifra == najveca_cifra) brojac++;
            kopija /= 10;
        }
        if (brojac > najveci_brojac) {
            najveci_brojac = brojac;
            najveci_broj = niz.at(i);
        }
    }
    return najveci_broj;
}

int main() {
    std::vector<int> niz;
    int broj;
    while (true) {
        std::cin >> broj;
        if (broj == 0) break;
        niz.push_back(broj);
    }

    std::cout << pronadji_najveci(niz) << std::endl;
    return 0;
}