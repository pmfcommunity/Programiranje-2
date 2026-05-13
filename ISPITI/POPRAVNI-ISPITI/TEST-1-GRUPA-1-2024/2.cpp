#include <iostream>
#include <vector>
#include <string>

/*
    Napisite genericku funkciju g koja kao parametar prima vektor (elementi
    vektora mogu biti cijeli ili realni brojevi), a kao rezultat vraca 
    vektor koji se sastoji od elemenata koji predstavljaju najduzi
    monotoni podniz niza brojeva koji se nalaze u vektoru koji joj je
    prenesen kao parametar.

    Pojasnjenje: Za neki podniz {ai, ai+1, ai+2, ..., aj} kazemo da je monoton
    ukoliko za njegove elemente vrijedi: ai <= ai+1 <= ... <= aj ili
    ai >= ai+1 >= ... >= aj. Ukoliko se desi da postoji vise najduzih 
    monotonih podnizova (svi su onda iste duzine), funkcija treba da vrati
    prvi od njih (gledano sa lijeva na desno).

    3 6 7 5 2 4 8 9 8 8 5 3 2 4 9 9 7 1
*/

template <typename T>
std::vector<T> g(const std::vector<T>& brojevi) {
    std::vector<std::vector<T>> monotoni_nizovi;

    std::vector<T> pomocni;
    for (int i = 0; i < brojevi.size() - 1; i++) {
        if (brojevi.at(i) <= brojevi.at(i + 1)) {
            if (pomocni.empty()) pomocni.push_back(brojevi.at(i));
            pomocni.push_back(brojevi.at(i + 1));
        } else {
            if (!pomocni.empty()) {
                monotoni_nizovi.push_back(pomocni);
                pomocni.clear();
            }
        }
    }

    if (!pomocni.empty()) {
        monotoni_nizovi.push_back(pomocni);
        pomocni.clear();
    }
    
    for (int i = 0; i < brojevi.size() - 1; i++) {
        if (brojevi.at(i) >= brojevi.at(i + 1)) {
            if (pomocni.empty()) pomocni.push_back(brojevi.at(i));
            pomocni.push_back(brojevi.at(i + 1));
        } else {
            if (!pomocni.empty()) {
                monotoni_nizovi.push_back(pomocni);
                pomocni.clear();
            }
        }
    }

    if (!pomocni.empty()) {
        monotoni_nizovi.push_back(pomocni);
        pomocni.clear();
    }

    int max_index {0};
    for (int i = 0; i < monotoni_nizovi.size(); i++) {
        if (monotoni_nizovi.at(i).size() > monotoni_nizovi.at(max_index).size()) {
            max_index = i;
        }
    }

    std::vector<T> rezultat;
    for (T broj : monotoni_nizovi.at(max_index)) {
        rezultat.push_back(broj);
    }

    return rezultat;
}

int main() {
    std::vector<double> brojevi = {-1, 2, 6.5, 5.6, 7.1, 7.2, 7.3, 8.9, -10, 33, 12.5, 3.1, 5.4, 1.3, 2.6};
    std::vector<double> rezultat = g(brojevi);

    for (double r : rezultat) std::cout << r << " ";
    std::cout << std::endl;
    return 0;
}