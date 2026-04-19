#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    Napraviti program koji od korisnika trazi unos rijeci sa tastature, koje se smjestaju
    u vektor stringova, sve dok se ne unese rijec "KRAJ". Napraviti funkciju podijeli
    koja kao u prvi parametar prima dati vektor, kao drugi parametar prima pokazivac na
    funkciju koja prima string i vraca bool, a u trecem i cetvrtom parametru vraca vektor
    stringova. U trecem parametru trebaju biti vraceni svi oni stringovi za koje je 
    proslijedjena funkcija vratila true, a u cetvrtom parametru trebaju biti vraceni
    stringovi za koji ne zadovoljavaju uslov.

    a) Sada napravite da se prvo unosi broj stringova (i na kraju se ne unosi "KRAJ").
    Promijenite da se vise ne koristi tip vektor, odaberite tip podatka.

    b) Nakon toga, napravite da funkcija vraca sortirane vektore u trecem i cetvrtom
       parametru.
*/

// Receno od asistenta da kriterij moze biti bilo sta.
bool kriterij(std::string s) {
    if (s.size() > 3) return true;
    return false;
}

void podijeli(std::string* pocetak, std::string* iza_kraja, bool (*kriterij)(std::string), std::vector<std::string>& v1, std::vector<std::string>& v2) {
    for (auto *p = pocetak; p < iza_kraja; *p++) {
        if (kriterij(*p)) {
            v1.push_back(*p);
        } else v2.push_back(*p);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
}

int main() {
    int n;
    std::cout << "Unesite broj rijeci: ";
    std::cin >> n;
    std::string rijec;
    std::string* rijeci = new std::string[n];

    int index {0};
    std::cin.ignore();
    while (index < n) {
        std::cout << "Unesite " << index + 1 << ". rijec: ";
        std::getline(std::cin, rijeci[index]);
        index++;
    }
    std::vector<std::string> v1, v2;
    podijeli(rijeci, rijeci + n, kriterij, v1, v2);
    std::cout << "Ispis prvog vektora:\n";
    for (std::string v : v1) std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "Ispis drugog vektora\n";
    for (std::string v : v2) std::cout << v << " ";
    std::cout << std::endl;
    delete[] rijeci;
    return 0;
}