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

    b) Potom napravite primjer sa vektorom pokazivaca na stringove.

    c) Zatim koristite labda funkciju za drugi parametar.

    d) Na kraju, napravite puni primjer: unos stringova dok se ne dodje do rijeci "KRAJ",
       zatim dodatni parametar - string - koji oznacava rastuci ili opadajuci sort 
       ("R" ili "O"), i potom se vrst sortiranje shodno zahtijevanoj vrsti. Ispisite
       rezultat.
*/

template <typename T>
std::list<T> sortiraj(std::vector<T> v, bool (*kriterij)(T, T), std::string sortiranje) {
    std::list<T> nova_lista(v.begin(), v.end());
    if (sortiranje == "O") nova_lista.sort(kriterij);
    if (sortiranje == "R") nova_lista.sort([](std::string* a, std::string* b) {
        return *a > *b;
    });
    return nova_lista;
}

int main() {
    std::vector<std::string*> v;
    std::string rijec;
    std::cout << "Unos rijeci:\n";
    while (true) {
        std::getline(std::cin, rijec);
        if (rijec == "KRAJ") break;
        v.push_back(new std::string(rijec));
    }
    std::list<std::string*> l = sortiraj<std::string*>(v, [](std::string* a, std::string* b) {
        if (a->length() == b->length()) return *a < *b;
        return a->length() < b->length();
    }, "R");
    for (const auto& lista : l) std::cout << *lista << " ";
    std::cout << std::endl;

    for (auto a : v) delete a;
    return 0;
}