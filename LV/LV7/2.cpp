#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

/*
    Napravite template funkciju koja prima dva parametra - vektor elemenata tipa T 
    i pokazivac na logicku funkciju koja prima dva parametra tipa T, a koja vraca
    listu (std::list) sa sortiranim elementima iz vektora.

    a) Ispravnost prvo demonstrirajte malim primjerom koji radi sa vektorom
       stringova.
*/

bool kriterij(std::string a, std::string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

template <typename T>
std::list<T> sortiraj(std::vector<T> v, bool (*kriterij)(T, T)) {
    std::list<T> nova_lista(v.begin(), v.end());
    nova_lista.sort(kriterij);

    return nova_lista;
}

int main() {
    std::vector<std::string> v = {"3241", "abcd", "jabuka", "Banana"};
    std::list<std::string> l = sortiraj(v, kriterij);
    for (const auto& lista : l) std::cout << lista << " ";
    std::cout << std::endl;
    return 0;
}