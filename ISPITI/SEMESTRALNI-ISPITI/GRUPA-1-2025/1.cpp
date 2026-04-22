#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

/*
    Napisati genericku funkciju f sa tri parametra. Prvi parametar je pokazivac ili
    iterator koji pokazuje na prvi element niza ili vektora odnosna deka (deque) koji
    se prosljedjuje funkciji f, dok drugi i treci parametar oznacavaju pocetak i kraj
    bloka koji se ispituje na simetricnost. Funkcija f treba vratiti 1 ili -1 u 
    zavisnosti od toga da li je blok omedjem drugim i trecim parametrima simetrican
    (isto cita sa obje strane) ili ne. Na primjer, blok koji se sastoji od cijelih
    brojeva 3, 5, 1, 8, 2, 8, 1, 5, i 3 je simetrican blok. U glavnoj funkciji
    trebati napisati program koji ce omoguciti da se pozivom funkcije f ispituje 
    simetricnost cjelobrojnog niza, vektora ili deka, pocetak i kraj bloka koji 
    ispitujete na simetricnost, kao i slovo koje ukazuje na to da li testirate niz, 
    vektor, ili dek. Npr ako testirate niz, onda se unosi preko tastature slovo N, za
    vektor se unosi V, dok za dek se unosi slovo D. Vodite racuna da oslobodite zauzete
    resurse. 
*/

template <typename T>
int f(T* pocetak, int p, int k) {
    std::vector<T> rezultat, rezultat_kopija;
    for (int i = 0; i < p; i++)
        *pocetak++;
    for (int i = p; i < k; i++) {
        rezultat.push_back(*pocetak);
        rezultat_kopija.push_back(*pocetak);
        *pocetak++;
    }

    std::reverse(rezultat_kopija.begin(), rezultat_kopija.end());
    for (int i = 0; i < rezultat.size(); i++) {
        if (rezultat.at(i) != rezultat_kopija.at(i)) return -1;
    }
    return 1;
}

int main() {
    int n, p, k;
    char s;
    std::cout << "Unsite broj elemenata:\n";
    std::cin >> n;
    std::cout << "Unesite pocetak: ";
    std::cin >> p;
    std::cout << "Unesite kraj: ";
    std::cin >> k;
    std::cout << "Sta testirate?\n";
    std::cin >> s;
    if (s == 'N') {
        int* niz = new int[n];
        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < n; i++) {
            std::cin >> niz[i];
        }
        std::cout << f(niz, p, k) << std::endl;
    }
    if (s == 'V') {
        std::vector<float> vektor;
        std::cout << "Unos elemenata vektora:\n";
        for (int i = 0; i < n; i++) {
            float broj;
            std::cin >> broj;
            vektor.push_back(broj);
        }
        std::cout << f(&vektor.at(0), p, k) << std::endl; 
    }
    if (s == 'D') {
        std::deque<float> dek;
        std::cout << "Unos elemenata deka:\n";
        for (int i = 0; i < n; i++) {
            float broj;
            std::cin >> broj;
            dek.push_back(broj);
        }
        std::cout << f(&dek.at(0), p, k) << std::endl;
    }
    return 0;
}