#include <iostream>
#include <cstring>
#include <string>

/*
    Implementirati klasu String koje ce oponasati rad klase string iz biblioteke
    string, a koja ce u pozadini koristiti dinamicki alocirani niz znakova.
    Voditi racuna da se objekti ove klase mogu bezbjedno kopirati i dodjeljivati
    jedan drugome, te da ne dolazi do curenja memorije kad neki objekat 
    prestane postojati. Klasa treba podrzavati indeksiranje, ispisivanje na
    ekran pomocu znaka <<, te operatore <, >, ==, !=, <=, >=, + i +=.
*/

class String {
    private:
        int velicina;
        int kapacitet;
        char *karakteri;
    public:
        String() {
            velicina = 0;
            kapacitet = velicina + 1;
            karakteri = new char[kapacitet];
            karakteri[0] = '\0';
        }
        String(const String& kopija) {
            velicina = kopija.velicina;
            kapacitet = kopija.kapacitet;
            karakteri = new char[kapacitet];
            std::strcpy(karakteri, kopija.karakteri);
        }
        String(const char* tekst) {
            if (tekst == nullptr) {
                velicina = 0;
                kapacitet = velicina + 1;
                karakteri = new char[kapacitet];
                karakteri[0] = '\0';
            }
            else {
                velicina = std::strlen(tekst);
                kapacitet = velicina + 1;
                karakteri = new char[kapacitet];

                std::strcpy(karakteri, tekst);
            }
        }
        ~String() { delete[] karakteri; }

        String& operator=(const String& izvor) {
            if (this == &izvor) return *this;
            delete[] karakteri;

            velicina = izvor.velicina;
            kapacitet = izvor.kapacitet;
            karakteri = new char[kapacitet];
            std::strcpy(karakteri, izvor.karakteri);

            return *this;
        }

        char& operator[](int indeks) { return karakteri[indeks]; }
        const char& operator[](int indeks) const { return karakteri[indeks]; }

        friend std::ostream& operator<<(std::ostream& izlaz, const String& izvor) {
            for (int i = 0; i < izvor.velicina; i++) izlaz << izvor[i];
            return izlaz;
        }

        friend bool operator==(const String& s1, const String& s2) {
            if (s1.velicina != s2.velicina) return false;

            for (int i = 0; i < s1.velicina; i++) {
                if (s1[i] != s2[i]) return false;
            }

            return true;
        }

        friend bool operator!=(const String& s1, const String& s2) {
            return !(s1 == s2);
        }

        friend bool operator<(const String& s1, const String& s2) {
            int min_velicina {std::min(s1.velicina, s2.velicina)};

            for (int i = 0; i < min_velicina; i++) {
                if (s1[i] < s2[i]) return true;
                if (s1[i] > s2[i]) return false;
            }

            return s1.velicina < s2.velicina;
        }

        friend bool operator>(const String& s1, const String& s2) {
            return !(s1 < s2) && !(s1 == s2);
        }

        friend bool operator<=(const String& s1, const String& s2) {
            return (s1 == s2) || (s1 < s2);
        }

        friend bool operator>=(const String& s1, const String& s2) {
            return !(s1 <= s2);
        }

        String& operator+=(const String& desni) {
            int nova_velicina = velicina + desni.velicina;
            if (nova_velicina + 1 > this->kapacitet) {
                this->kapacitet = nova_velicina + 1;
                char* novi_niz = new char[this->kapacitet];

                for (int i = 0; i < this->velicina; i++) {
                    novi_niz[i] = this->karakteri[i];
                }

                delete[] this->karakteri;
                this->karakteri = novi_niz;
            }

            for (int i = 0; i < desni.velicina; i++) {
                this->karakteri[this->velicina + i] = desni.karakteri[i];
            }

            this->velicina = nova_velicina;   
            this->karakteri[this->velicina] = '\0';

            return *this;
        }

        friend String operator+(const String& s1, const String& s2) {
            String rezultat = s1;
            rezultat += s2;
            return rezultat;
        }
};

int main() {
    std::cout << "=== TESTIRANJE KLASE STRING ===\n\n";

    String s1("Auto");
    String s2("Bus");
    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n\n";

    String s3 = s1; 
    std::cout << "s3 (kopija s1): " << s3 << "\n";

    s3[0] = 'M';
    std::cout << "Nakon izmjene s3[0] u 'M':\n";
    std::cout << "s3 je sada: " << s3 << " (Muto)\n";
    std::cout << "s1 je i dalje: " << s1 << " (Auto) -> Deep Copy radi!\n\n";

    std::cout << "--- Spajanje stringova (+) ---\n";
    String spojeno; 
    spojeno = s1 + s2; // s1 + s2 stvara "Autobus", a '=' to dodjeljuje u 'spojeno'
    std::cout << "s1 + s2 = " << spojeno << "\n\n";

    std::cout << "--- Nadopisivanje (+=) ---\n";
    String baza("Programiranje");
    std::cout << "Prije +=: " << baza << "\n";
    baza += " 2"; // Dodajemo razmak i broj 2
    std::cout << "Nakon +=: " << baza << "\n\n";

    std::cout << "--- Poređenje (== i <) ---\n";
    String rijec1("Jabuka");
    String rijec2("Kruška");

    if (rijec1 == rijec2) {
        std::cout << rijec1 << " i " << rijec2 << " su iste rijeci.\n";
    } else {
        std::cout << rijec1 << " i " << rijec2 << " NISU iste rijeci.\n";
    }

    if (rijec1 < rijec2) {
        std::cout << rijec1 << " dolazi PRIJE " << rijec2 << " u rječniku.\n";
    } else {
        std::cout << rijec1 << " dolazi POSLIJE " << rijec2 << " u rječniku.\n";
    }

    std::cout << "\n=== KRAJ TESTA ===" << std::endl;
    return 0;
}