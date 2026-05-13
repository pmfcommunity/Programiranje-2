#include <iostream>
#include <set>
#include <vector>
/*
    Napisite genericku funkciju f, koja kao parametar prima dva objekta tipa
    std::set, tj. dva skupa A i B, ciji su elementi istog tipa, a koja kao
    rezultat vraca novi skup C istog tipa kao i skupovi A i B, koji predstavlja
    simetricnu razliku skupova A i B. Simetricna razlika se definira kao skup
    koji sadrzi one i samo one elemente koji se nalaze ili u jednom, ili u
    drugom skupu, ali ne u oba skupa istovremeno.

    Editors note: posto mi se neda prepisivati same primjere, oba seta ne moraju
    biti iste duzine. 
*/

template <typename T>
std::set<T> f(const std::set<T>& A, std::set<T>& B) {
    std::set<T> C;
    std::vector<T> vektor_a, vektor_b;
    for (T a : A) vektor_a.push_back(a);
    for (T b : B) vektor_b.push_back(b);

    for (int i = 0; i < vektor_a.size(); i++) {
        bool nalazi_se {false};
        for (int j = 0; j < vektor_b.size(); j++) {
            if (vektor_a.at(i) == vektor_b.at(j)) {
                nalazi_se = true;
                break;
            }
        }
        if (!nalazi_se) C.insert(vektor_a.at(i));
    }


    for (int i = 0; i < vektor_b.size(); i++) {
        bool nalazi_se {false};
        for (int j = 0; j < vektor_a.size(); j++) {
            if (vektor_b.at(i) == vektor_a.at(j)) {
                nalazi_se = true;
                break;
            }
        }
        if (!nalazi_se) C.insert(vektor_b.at(i));
    }

    return C;
}

int main() {
    int a, b;
    std::set<double> A, B;
    std::cout << "Velicina seta A: ";
    std::cin >> a;
    std::cout << "Unos seta A:\n";
    for (int i = 0; i < a; i++) {
        double broj;
        std::cin >> broj;
        A.insert(broj);
    } 
    std::cout << "Velicina seta B: ";
    std::cin >> b;
    std::cout << "Unos seta B:\n";
    for (int i = 0; i < b; i++) {
        double broj;
        std::cin >> broj;
        B.insert(broj);
    } 

    std::set<double> C = f(A, B);
    for (double c : C) std::cout << c << " ";
    std::cout << std::endl;
    return 0;
}