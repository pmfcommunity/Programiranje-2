#include <iostream>
#include <vector>
#include <stdexcept>

/*
    Napisati funkcju f koja prima dva parametra: vektor brojeva v i funkciju bool g (int).
    Funkcija treba vratiti novi vektor sastavljen od onih elemenata vektora v za koje
    funkcija g vraca true. Elementi se u rezultujucem vektoru ne bi trebali ponavljati.
    Npr. ako je funkciji proslijedjen vektor {12, 2, 1, 7, 5, 8, 2, 2, 4} i ako funkcija
    g vraca true za sve parne brojeve, a false za neparne, rezultujuci vektor ce biti
    {12, 2, 8, 4}. Funkcija bi trebala vratiti izuzetak ako je proslijedjen prazan vektor.
    U testnom programu trebalo bi predivjdeti hvatanje bacenih izuzetaka.
*/

bool kriterij(int broj) {
    if (broj % 2 == 0) return true;
    return false;
}

void f(const std::vector<int>& v, bool (*g)(int)) {
    if (v.empty()) throw std::logic_error("Vektor ne smije bit prazan!");
    std::vector<int> parni;
    for (int broj : v) {
        if (g(broj)) parni.push_back(broj);
    }

    std::vector<int> rezultat;
    for (int i = 0; i < parni.size(); i++) {
        int trenutni = parni.at(i);
        bool ponavlja_se = false;
        for (int j = 0; j < i; j++) {
            if ((trenutni == parni.at(j))) {
                ponavlja_se = true;
                break;
            } 
        }
        if (!ponavlja_se) rezultat.push_back(parni.at(i));
    }
    for (int r : rezultat) std::cout << r << " ";
    std::cout << std::endl;
}

int main() {
    try {
        std::vector<int> vektor = {12, 2, 1, 7, 5, 8, 2, 2, 4};
        f(vektor, kriterij);
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}