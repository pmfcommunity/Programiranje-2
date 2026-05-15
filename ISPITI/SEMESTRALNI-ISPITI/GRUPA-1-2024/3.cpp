#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

/*
    Napisite genericku funkciju f, koja kao parametar prima vektor brojeva
    v tipa T, a kao rezultat vraca funkciju F, koja u vidu formalno parametra
    prima broj tipa T, te vraca broj istog tipa kao rezultat. Vracena funkcija
    F za zadani argument racuna vrijednost polinoma, ciji su koefcijenti 
    elementi elementi vektora v, tako da element vektora sa indeksom 0
    predstavlja slobodni clan, element sa indeksom 1 je koefcijent uz prvi
    stepen argumenta, i opcetino, element sa indeksom k predstavlja 
    koefcijent uz k-ti stepent argumenta. Na primjer, za vektor sa 
    elementima v = {3, 5, 0, 4, 1}, funckija f vraca funkciju F tako da vazi
    F(2) = 61.
*/

template <typename T>
std::function<T(T)> f(const std::vector<T>& v) {
    return [v](T x) {
        T suma {0.0};
        for (int i = 0; i < v.size(); i++) {
            suma += v.at(i) * std::pow(x, i);
        }
        return suma;
    };
}

int main() {
    int n;
    std::vector<double> v;
    std::cout << "Unos velicine vektora: ";
    std::cin >> n;
    std::cout << "Unos clanova vektora:\n";
    for (int i = 0; i < n; i++) {
        double broj;
        std::cin >> broj;
        v.push_back(broj);
    }

    auto F = f(v);

    std::cout << "Argument x funkcije F: ";
    double x;
    std::cin >> x;

    std::cout << F(x) << std::endl;
    return 0;
}