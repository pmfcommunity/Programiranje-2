#include <iostream>
#include <string>
#include <algorithm>

/*
    Iskoristiti funkciju sort iz biblioteke algorithm za sortiranje niza stringova po 
    broju razlicitih slova koja se nalaze u stringu. Ako neka dva stringa imaju isti
    broj razlicitih slova, string koji je abecedno manji treba biti prije u nizu.
    U kratkom testnom programu dinamicki alocirati niz stringova.
*/

int broj_razlicitih(std::string& s) {
    int brojac {0};
    for (int i = 0; i < s.length(); i++) {
        bool nije_se_ranije_pojavio = true;
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    nije_se_ranije_pojavio = false;
                    break;
                }
            }
        }
        if (nije_se_ranije_pojavio) brojac++;
    }
    return brojac;
}

bool kriterij(std::string& s1, std::string& s2) {
    if (broj_razlicitih(s1) < broj_razlicitih(s2)) return true;
    else return false;
    return s1 <= s2;
}

int main() {
    int n;
    std::cout << "Koliko stringova?\n";
    std::cin >> n;

    std::string* s = new std::string[n];

    std::cout << "Unos:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::sort(s, s + n, kriterij);

    for (int i = 0; i < n; i++) {
        std::cout << s[i] << std::endl;
    }

    delete[] s;
    return 0;
}