#include <iostream>
#include <vector>
#include <stdexcept>

/*
    Napisati funkciju f koja za svoj prvi formalni parametar uzima prirodan broj n,
    a kao rezultat vraca dimanizni kreiran niz A, ciji su elementi sve kombinacije
    od tri prirodna broja, koji zadovoljavaju uslov Pitagorine teoreme i manji su
    ili jednaki broju n. Kombinacije se ne smiju ponavljati. Takodjer, ukoliko
    broj n nije prirodan broj, funkcija f treba izbaciti izuzetak "Broj nije
    prirodan". Osim toga, broj pronadjenih kombinacija se treba vratiti po 
    referenci kroz drugi formalni parametar m funkcije f, te ukoliko je broj 
    pronadjenih kombinacija jednak nuli, funkcija f treba vratiti nul-pokazivac.
*/

int* f(int n, int& m) {
    if (n < 0) throw std::logic_error("Broj nije prirodan.");
    std::vector<int> kombinacije;
    int brojac {0};
    for (int c = 1; c <= n; c++) {
        for (int a = 1; a <= c; a++) {
            for (int b = a; b <= c; b++) {
                if (a * a + b * b == c * c) {
                    kombinacije.push_back(a);
                    kombinacije.push_back(b);
                    kombinacije.push_back(c);
                    brojac++;
                }
            }
        }
    }
    m = brojac;
    if (m == 0) return nullptr;

    int* niz = new int[3 * m];
    for (int i = 0; i < 3 * m; i++) {
        niz[i] = kombinacije.at(i);
    }

    return niz;
}

int main() {
    try {
        int m {0};
        int n {-10};
        int *niz {f(n, m)};
        if (niz == nullptr) {
            std::cout << m << " ";
            std::cout << "Nema kombinacija.\n";
        } else {
            for (int i = 0; i < 3 * m; i++) {
                std::cout << niz[i] << " ";
            }
            std::cout << std::endl << m << std::endl;
        }
        delete niz;
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}