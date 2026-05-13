#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

/*
    Napisite funkciju f sa tri parametra tako da prvi parametar bude neki cijeli
    broj n. Funkcija treba formirati dva nova broja koji se sastoje respektivno
    od prostih i slozenih cifara polaznog broja, u istom redoslijedu u kojem se
    nalaze u polaznom broju n. Novoformrane brojeve smjestite redom u drig m i 
    treci k parametar funkcije f. Na primjer, ukoliko se kao prvi parametar 
    zada broj 123456789, u drugi i treci parametar treba da se redom smjeste
    brojevi 2357 i 14689. Znak broja trebate ignorisati, odnosno isti efekat
    se dobija ukoliko se kao prvi parametar zada broj -123456789. GLavnu funkciju
    main napisite tako da se sa tastature moze unijeti cijeli broj n, te pozvati
    funkcija f.
*/

bool jel_prost(long int broj) {
    if (broj <= 1) return false;
    if (broj == 2) return true;
    if (broj % 2 == 0) return false;

    for (int i = 3; i * i <= broj; i += 2) {
        if (broj % i == 0) return false;
    }

    return true;
}

void f(long int n, long int& m, long int& k) {
    n = std::abs(n);
    long int kopija {n};
    std::string prosti = "", slozeni = "";
    while (kopija != 0) {
        long int cifra = kopija % 10;
        if (jel_prost(cifra)) {
            prosti += std::to_string(cifra);
        } else slozeni += std::to_string(cifra);
        kopija /= 10;
    }

    std::reverse(prosti.begin(), prosti.end());
    std::reverse(slozeni.begin(), slozeni.end());

    m = std::stoi(prosti);
    k = std::stoi(slozeni);
}

int main() {
    long int n;
    std::cout << "Unesite broj n: ";
    std::cin >> n; 
    long int m, k;
    f(n, m, k);
    std::cout << m << " " << k << std::endl;
    return 0;
}
