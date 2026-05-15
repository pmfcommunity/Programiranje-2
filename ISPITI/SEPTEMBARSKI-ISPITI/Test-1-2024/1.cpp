#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

/*
    Napisati genericku funkciju f sa tri parametra. Prvi parametar je pokazivac
    ili iterator koji pokazuje na prvi element niza ili vektora odnosno deka
    koji se prosljedjuje funkciji f, dok drugi i treci parametar oznacavaju
    pocetak i kraj bloka koji se ispituje na simetricnost. Funkcija f treba
    vratiti 1 ili -1 u zavisnosti od toga da li blok omedjen drugim i trecim
    parametrima simetrican (isto cita sa obje strane) ili ne.
    U glavnoj funkciji trebate napisati program koji ce omoguciti da se 
    pozivom funkcije f ispituje simetricnost cjelobrojnog niza, kao i vektora
    i deka ciji su elementi realni brojevi. Preko tastature zadajete broj
    clanova niza, vektora, ili dek.
*/
template <typename T>
int f(T* pocetak, int p, int k) {
    for (int i = 0; i < p; i++) {
        pocetak++;
    }
    std::vector<int> elementi_bloka, elementi_bloka_obrnuto;
    for (int i = p; i < k; i++) {
        elementi_bloka.push_back(*pocetak);
        elementi_bloka_obrnuto.push_back(*pocetak);
        pocetak++;
    }

    std::reverse(elementi_bloka_obrnuto.begin(), elementi_bloka_obrnuto.end());
    for(int i = 0; i < elementi_bloka.size(); i++) {
        if (elementi_bloka.at(i) != elementi_bloka_obrnuto.at(i)) return -1;
    }
    return 1;
}

int main() {
    int n;
    std::cout << "Velicina: ";
    std::cin >> n;
    int p, k;
    std::cout << "Pocetak: ";
    std::cin >> p;
    std::cout << "Kraj: ";
    std::cin >> k;
    char s;
    std::cout << "Niz, vektor, ili dek: ";
    std::cin >> s;
    if (s == 'N' || s == 'n') {
        int *niz = new int[n];
        std::cout << "Unos elemenata niza:\n";
        for (int i = 0; i < (int)n; i++) {
            std::cin >> niz[i];
        }
        std::cout << f(&niz[0], p, k) << std::endl;
    }
    if (s == 'V' || s == 'v') {
        std::vector<double> vektor;
        std::cout << "Unos elemenata vektora:\n";
        double broj;
        for (int i = 0; i < (int)n; i++) {
            std::cin >> broj;
            vektor.push_back(broj);
        }
        std::cout << f(&vektor.at(0), p, k) << std::endl;
    }
    if (s == 'D' || s == 'd') {
        std::deque<double> deka;
        std::cout << "Unos elemanata deka:\n";
        double broj;
        for (int i = 0; i < (int)n; i++) {
            std::cin >> broj;
            deka.push_back(broj);
        }
        std::cout << f(&deka.at(0), p, k) << std::endl;
    }
    return 0;
}