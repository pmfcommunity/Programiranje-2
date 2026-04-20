#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

/*
    Napisati funkciju
        vector izdvojiSamolasnickeParove(const string& recenica)
    koja prima recenicu kao string, razdvaja je u rijeci, te vraca vektor rijeci koje
    imaju barem dva uzastopna samoglasnika. Rezultat sortirajte tako da se rijeci sa 
    vise slova ispisu prve, a ukoliko dvije rijeci imaju isti broj slova, sortirajte
    ih abecedno rastuce. Bacite invalid_argument ako takve rijeci ne postoje u unesenoj
    recenici. U main funkciji pozovite funkciju i ispisite braceni vektor, te uhvatite
    bacene izuzetke. Testni primjer:
    Input:
    Ucestvovao je na aeromitingu gdje je predstavio kooperativni projekat iz teatra.
    
    Output:
    Ucestvovao, aeromitingu, predstavio, koopeartivni, teatra
*/

bool jel_samoglasnik(char c, std::vector<char>& samoglasnici) {
    for (int i = 0; i < samoglasnici.size(); i++) {
        if (c == samoglasnici.at(i)) return true;
    }
    return false;
}

std::vector<std::string> izdvoji_samoglasnicke_parove(const std::string& recenica) {
    std::vector<char> samoglasnici = {'a', 'e', 'i', 'o', 'u'};
    std::vector<std::string> rezultat;

    std::vector<std::string> rijeci;
    std::string rijec = "";

    bool ima_samoglasnik = false;
    for (int i = 0; i < recenica.length(); i++) {
        bool nova_rijec = false;
        if (recenica[i] == ' ') {
            rijeci.push_back(rijec);
            rijec = "";
            nova_rijec = true;
        } 
        if (jel_samoglasnik(recenica[i], samoglasnici)) ima_samoglasnik = true;
        if (!nova_rijec) rijec += recenica[i];
    }
    if (!recenica.empty()) rijeci.push_back(rijec);

    if (!ima_samoglasnik) throw std::invalid_argument("Recenica nema samoglasnika!\n");

    for (int i = 0; i < rijeci.size(); i++) {
        std::string trenutna_rijec = rijeci.at(i);
        int brojac {0};

        for (int i = 0; i < trenutna_rijec.length(); i++) {
            if (jel_samoglasnik(trenutna_rijec[i], samoglasnici)) brojac++;
            else brojac = 0;

            if (brojac > 1) {
                rezultat.push_back(trenutna_rijec);
                break;
            }
        }  
    }

    std::sort(rezultat.begin(), rezultat.end(), [](const std::string& a, const std::string& b) {
        bool a_veliko = !a.empty() && std::isupper((a)[0]);
        bool b_veliko = !b.empty() && std::isupper((b)[0]);

        if (a_veliko != b_veliko) {
            return a_veliko; 
        }

        if (a.length() != b.length()) return a.length() > b.length();

        return a > b;
    });

    return rezultat;
}

int main() {
    try {
        std::string recenica;
        std::cout << "Unesite recenicu: ";
        std::getline(std::cin, recenica);

        std::vector<std::string> rezultat = izdvoji_samoglasnicke_parove(recenica);

        for (std::string r : rezultat) std::cout << r << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Greska! " << e.what() << std::endl;
    }
    return 0;
}