#include <iostream>
#include <string>

/*
    Napisati funkciju koja za proslijedjenu vrijednost prirodnog broja ispisuje vrijednost
    broja u binarnom obliku.
*/

void pretvori_u_binarni(int broj) {
    std::string rezultat = "";
    while (broj != 0) {
        if (broj % 2 == 0) rezultat += "0";
        if (broj % 2 != 0) rezultat += "1";
        broj /= 2;
    }

    for (int i = rezultat.size() - 1; i >= 0; i--) {
        std::cout << rezultat[i];
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Upisite broj: ";
    std::cin >> n;
    pretvori_u_binarni(n);
    return 0;
}