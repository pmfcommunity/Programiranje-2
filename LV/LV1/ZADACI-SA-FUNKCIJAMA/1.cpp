#include <iostream>
#include <string>

/*
    Napiasti funkciju koja za proslijedjenu vrijednost prirodnog broja ispisuje 
    vrijednost broja u binarnom obliku.
*/

void pretvori_u_binarni(int n) {
    int kopija {n};
    std::string prvi_prolaz {""};
    while (kopija != 0) {
        if (kopija % 2 == 0) prvi_prolaz += "0";
        if (kopija % 2 != 0) prvi_prolaz += "1";
        kopija /= 2;
    }

    for (int i = prvi_prolaz.length() - 1; i >= 0; i--)
        std::cout << prvi_prolaz[i];
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Unesite prirodni broj: ";
    std::cin >> n;
    if (n > 0) {
        pretvori_u_binarni(n);
    }
    else std::cout << "Broj nije prirodan!\n";
    return 0;
}