#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

/*
    Napisati funkciju koja prima dva vektora stringova v1 i v2. Funkcija treba da ukloni
    sve razmake iz stringova u prvom vektoru, te da rezultujuce stringove smjesti u 
    drugi vektor. Npr. ako je v1 = {"a b c", "123 456  ", "  123"}, nakon pozivanja
    funkcije, vektor v2 postaje: v2 = {"abc", "123456", "123"}. Ako je vektor v1 prazan,
    funkcija baza izuzetak. Napisati kratki testni program. Zadatak uraditi bez koristenja
    ugradjenih funkcija za stringove.
*/

void ukloni_razmake(const std::vector<std::string>& v1, std::vector<std::string>& v2) {
    if (v1.empty()) throw std::logic_error("Prvi vektor NE smije biti prazan!");
    for (int i = 0; i < v1.size(); i++) {
        std::string rijec = "";
        std::string trenutna_rijec = v1.at(i);
        for (int j = 0; j < trenutna_rijec.length(); j++) {
            if (trenutna_rijec[j] == ' ') continue;
            rijec += trenutna_rijec[j];
        }
        v2.push_back(rijec);
    }
}

int main() {
    try {
        std::vector<std::string> v1 = {"a b c", "123 456  ", "  123"}, v2;
        ukloni_razmake(v1, v2);
        std::cout << "Vektor sa uklonjenim razmacima:\n";
        for (std::string v : v2) std::cout << v << " ";
        std::cout << std::endl;
    }
    catch (const std::logic_error& e) {
        std::cout << "Greska! " << e.what() << std::endl;
    }
    return 0;
}