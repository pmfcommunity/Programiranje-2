#include <iostream>
#include <cmath>

/*
    Napisite funkciju f sa pet parametara tako da prvi parametar bude neki
    cijeli broj n. Funkcija treba formirati cetiri nova broja koji se sastoje
    respektivno od sume parnih, proizvoda prostih, sume neparnih, proizvoda
    slozenih cifara polaznog broja n. Novoformirane brojeve smjestite redom
    u drugi n1, treci n2, cetvrti n3, peti n4 parametar funkcije f. Na primjer,
    ukoliko se kao prvi parametar zada broj 1234567, u parametre n1, n2, n3, i
    n4 redom treba smjestiti brojeve 48, 210, 17, i 24. Znak broja trebate
    ignorisati, odnosno isti efekat se dobija ukoliko se kao prvi parametar
    zada broj -1234567.
*/

bool jel_prost(long int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

void f(long int n, long int& n1, long int& n2, long int& n3, long int& n4) {
    n = std::abs(n);
    long int kopija {n};
    while (kopija != 0) {
        long int cifra = kopija % 10;
        if (cifra % 2 == 0) n1 += cifra;
        if (jel_prost(cifra)) n2 *= cifra;
        if (cifra % 2 != 0) n3 += cifra;
        if (!jel_prost(cifra)) n4 *= cifra;
        kopija /= 10;
    }
}

int main() {
    long int n;
    std::cout << "Unos broja n: ";
    std::cin >> n;
    long int n1 {0}, n2 {1}, n3 {0}, n4 {1};
    f(n, n1, n2, n3, n4);
    std::cout << n1 << " " << n2 << " " << n3 << " " << n4 << std::endl;
    return 0;
}