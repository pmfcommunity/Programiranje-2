#include <iostream>
#include <cmath>

/*
    Napisati program koji od korisnika trazi da unese prirodan broj n. Program ispisuje
    absolutnu vrijednost razlika broja n i broja napisanog obrnutim redoslijedom cifara.
    Ukoliko korisnik unese broj 1234 program ispisuje vrijednost |1234 - 4321|
*/

int main() {
    int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;

    int kopija {n};
    int obrnuta_cifra {0};
    while (kopija != 0) {
        int cifra = kopija % 10;
        obrnuta_cifra = (obrnuta_cifra * 10) + cifra;
        kopija /= 10;
    }

    std::cout << "|" << n << " - " << obrnuta_cifra << "| = ";
    std::cout << abs(n - obrnuta_cifra) << std::endl;
    return 0;
}