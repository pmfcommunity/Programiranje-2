#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

/*
    Napisite funkciju f sa tri parametra tako da prvi parametar bude neki cijeli
    broj n. Funkcija treba formirati dva nova broja koji se sastoje respektivno od 
    parnih i neparnih cifara polaznog broja, u istom redoslijedu u kojem se nalaze
    u polaznom broju n. Novoformirane broejve smjestite redom u drugi m i treci
    k parametar funkcije f. Na primjer, ukoliko se kao prvi parametar zada broj
    123456789, u drugi i treci parametar terba da se redom smjeste brojevi
    2468 i 13579. ZNak broja trebate ignorisati, odnosno isti efekat se dobija
    ukoliko se kao prvi parametar zada broj -123456789. Glavnu funkciju main
    napisite tako da se sa tastature moze unijeti cijeli broj n, te pozvati
    funkcija f.
*/

void f(long int n, long int& m, long int& k) {
    n = std::abs(n);
    long int kopija {n};

    std::string parni = "", neparni = "";
    while (kopija != 0) {
        long int cifra = kopija % 10;
        if (cifra % 2 == 0) parni += std::to_string(cifra);
        else neparni += std::to_string(cifra);
        kopija /= 10;
    }

    std::reverse(parni.begin(), parni.end());
    std::reverse(neparni.begin(), neparni.end());

    if (!parni.empty())
        m = std::stoi(parni);
    if (!neparni.empty())
        k = std::stoi(neparni);
}

int main() {
    long int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n;
    long int m {}, k {};
    f(n, m, k);
    std::cout << m << std::endl << k << std::endl; 
    return 0;
}