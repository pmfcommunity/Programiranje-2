#include <iostream>
#include <string>

/*
    Napisati funkciju koja za proslijedjenu vrijednost prirodnog broja vraca vrijednost
    broja u binarnom obliku. 
*/

int pretvori_u_binarni(int broj) {
    std::string binarna_vrijednost = "";
    while (broj != 0) {
        if (broj % 2 == 0) binarna_vrijednost += "0";
        if (broj % 2 != 0) binarna_vrijednost += "1";
        broj /= 2;
    }
    std::string rezultat = "";
    for (int i = binarna_vrijednost.size() - 1; i >= 0; i--) 
        rezultat += binarna_vrijednost[i];
    return std::stoi(rezultat);
}

int main() {
    int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int binarna {pretvori_u_binarni(n)};
    std::cout << binarna << std::endl;
    return 0;
}