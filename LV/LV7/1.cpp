#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

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

    c) Dodajte peti parametar funkcije, koji predstavlja niz stringova - ukoliko se neka
       od rijeci proslijedjenih u prvom parametru nalazi u nizu, onda se ona ignorise
       (ne vraca se u trecem ili cetvrtom parametru). Za pretragu koristite funkcije iz
       algorithm biblioteke.

    d) Promijenite da se ne koriste stringovi, nego pokazivaci na stringove. Treci i 
       cetvrti parametar sada treba da sadrze pokazivace na stringove - iste one koji
       su dati u prvom parametru.

    e) Doputine da se za treci i cetvrti parametar sada kopiraju stringovi, tako da oni
       vise ne pokazuju na izvorne stringove, nego na njihove kopije. Ne zaboravite na 
       kraju dealocirati stringove!

    f) Dodajte parametar koji predstavlja pokazivac na funkciju koja ce se koristiti
       za sortiranje stringova koji se vracaju u trecem i cetvrtom parametru. Napravite
       da sortiranje bude opadajuce.

    g) Napravite sada da sortiranje bude case-insensitive, tj. da nema razlike izmedju
       velikih i malih slova.

    h) Izmijenite sortiranje treceg i cetvrtog parametra, na nacin da tokom punjena 
       treceg i cetvrtog parametra, oni budu cijelo vrijeme sortirani (iteratovino 
       ubacujte rijeci na odgovarajuce pozicije)
*/

// Receno od asistenta da kriterij moze biti bilo sta.
bool kriterij(std::string s) {
    if (s.size() > 3) return true;
    return false;
}

bool case_insensitive_kriterij(std::string* s1, std::string* s2) {
    if (s1 == nullptr || s2 == nullptr) return s1 < s2;
    return std::lexicographical_compare(
        s1->begin(), s1->end(),
        s2->begin(), s2->end(),
        [](char c1, char c2) {
            return std::tolower(static_cast<unsigned char>(c1)) < 
                   std::tolower(static_cast<unsigned char>(c2));
        }
    );
}

void sortiranje(std::vector<std::string*>& v1, std::vector<std::string*>& v2) {
    std::sort(v1.begin(), v1.end(), case_insensitive_kriterij);
    std::sort(v2.begin(), v2.end(), case_insensitive_kriterij);
}

void podijeli(std::string* pocetak, std::string* iza_kraja, bool (*kriterij)(std::string), std::vector<std::string*>& v1, std::vector<std::string*>& v2, std::vector<std::string>& zabrana, void (*sortiranje)(std::vector<std::string*>&, std::vector<std::string*>&)) {
    for (auto p = pocetak; p < iza_kraja; p++) {
        std::string* kopija = new std::string(*p);
        auto it = std::find(zabrana.begin(), zabrana.end(), *kopija);
        if (it != zabrana.end()) continue;
        if (kriterij(*kopija)) {
            v1.push_back(kopija);
        } else v2.push_back(kopija);
        sortiranje(v1, v2);
    }
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
    std::vector<std::string*> v1, v2;
    std::vector<std::string> zabrana = {"1234", "abcd"};
    podijeli(rijeci, rijeci + n, kriterij, v1, v2, zabrana, sortiranje);
    std::cout << "Ispis prvog vektora:\n";
    for (std::string* v : v1) std::cout << *v << " ";
    std::cout << std::endl;
    std::cout << "Ispis drugog vektora\n";
    for (std::string* v : v2) std::cout << *v << " ";
    std::cout << std::endl;

    for (std::string* v : v1) delete v;
    for (std::string* v : v2) delete v;
    delete[] rijeci;
    return 0;
}