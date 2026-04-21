#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*
    Napisati funkciju sa dva parametra: prvi parametar je vektor stringova "stringovi",
    a drugi parametar je string "s". Funkija treba (kao vektor) vratiti stringove koji
    sadrze sve znakove iz stringa s. Mozete pretpostaviti da su svi znakovi string "s"
    razliciti.
    Npr. ako je stringovi = {"abcd", "dafbc", "bcad", "cdbf"} i ako je s = "abc", 
    funkcija vraca {"abcd", "dafbc", "bcad"}. Napisati kratki testni program.
*/

void sortiraj_string(std::string& s) {
    std::vector<char> karakteri;

    for (int i = 0; i < s.length(); i++) {
        karakteri.push_back(s[i]);
    }

    std::sort(karakteri.begin(), karakteri.end());

    for (int i = 0; i < s.length(); i++) {
        s[i] = karakteri.at(i);
    }
}

bool poredi_stringove(std::string s1, std::string s) {
    if (s1.length() >= s.length()) {
        for (int i = 0; i < s.length(); i++) {
            if (s1[i] != s[i]) return false;
        }
    }
    if (s1.length() <= s.length()) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s[i]) return false;
        }
    }
    return true;
}

std::vector<std::string> pronadji_iste(const std::vector<std::string>& stringovi, std::string& s) {
    sortiraj_string(s);
    std::vector<std::string> sortirani_stringovi;
    for (std::string rijec : stringovi) {
        sortiraj_string(rijec);
        sortirani_stringovi.push_back(rijec);
    }

    std::vector<std::string> rezultati;
    for (int i = 0; i < sortirani_stringovi.size(); i++) {
        if (poredi_stringove(sortirani_stringovi.at(i), s))
            rezultati.push_back(stringovi.at(i));
    }

    return rezultati;
} 

int main() {
    std::vector<std::string> stringovi = {"abcd", "dafbc", "bcad", "cdbf"};
    std::string s = "abc";

    std::vector<std::string> rezultat = pronadji_iste(stringovi, s);

    for (std::string r : rezultat) std::cout << r << " ";
    std::cout << std::endl;
    return 0;
}