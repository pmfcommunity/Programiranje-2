#include <iostream>
#include <string>

/*
    Napisati funkciju koja za proslijedjenu vrijednost prirodnog broja vraca vrijednost
    broja u binarnom obliku.
*/

int pretvori_u_binarni(int n) {
    int kopija {n};
    std::string prvi_prolaz {""};
    while (kopija != 0) {
        if (kopija % 2 == 0) prvi_prolaz += "0";
        if (kopija % 2 != 0) prvi_prolaz += "1";
        kopija /= 2;
    }
    std::string rezultat {""};
    for (int i = prvi_prolaz.size() - 1; i >= 0; i--) {
        rezultat += prvi_prolaz[i];
    }
    return std::stoi(rezultat);
}

int main() {
    int n;
    std::cout << "Unesite prirodan broj: ";
    std::cin >> n;
    if (n > 0) {
        int rezultat = pretvori_u_binarni(n);
        std::cout << rezultat << std::endl;
    } else std::cout << "Broj nije prirodan!\n";
    return 0;
}