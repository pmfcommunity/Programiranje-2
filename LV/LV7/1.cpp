#include <iostream>
#include <vector>
#include <string>

/*
    Napraviti program koji od korisnika trazi unos rijeci sa tastature, koje se smjestaju
    u vektor stringova, sve dok se ne unese rijec "KRAJ". Napraviti funkciju podijeli
    koja kao u prvi parametar prima dati vektor, kao drugi parametar prima pokazivac na
    funkciju koja prima string i vraca bool, a u trecem i cetvrtom parametru vraca vektor
    stringova. U trecem parametru trebaju biti vraceni svi oni stringovi za koje je 
    proslijedjena funkcija vratila true, a u cetvrtom parametru trebaju biti vraceni
    stringovi za koji ne zadovoljavaju uslov.
*/

// Receno od asistenta da kriterij moze biti bilo sta.
bool kriterij(std::string s) {
    if (s.size() > 3) return true;
    return false;
}

void podijeli(const std::vector<std::string>& rijeci, bool (*kriterij)(std::string), std::vector<std::string>& v1, std::vector<std::string>& v2) {
    for (int i = 0; i < rijeci.size(); i++) {
        if (kriterij(rijeci.at(i))) {
            v1.push_back(rijeci.at(i));
        } else v2.push_back(rijeci.at(i));
    }
}

int main() {
    std::string rijec;
    std::vector<std::string> rijeci;

    while (true) {
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if (rijec == "KRAJ") break;
        rijeci.push_back(rijec);
    }
    std::vector<std::string> v1, v2;
    podijeli(rijeci, kriterij, v1, v2);
    std::cout << "Ispis prvog vektora:\n";
    for (std::string v : v1) std::cout << v << " ";
    std::cout << std::endl;
    std::cout << "Ispis drugog vektora\n";
    for (std::string v : v2) std::cout << v << " ";
    std::cout << std::endl;
    return 0;
}