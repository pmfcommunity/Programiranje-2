#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <stdexcept>

/*
    (Koristi se prethodni zadatak) 
    Sada uradite razlicita unapredjenja prethodne klase. 
    a) Napravite da se narudzba moze ispisivati na stream (preklopite operator
    <<)
    b) Napravite da se narudzbe mogu "sabirati", na nacin da se time dobije nova
    narudzba, koja sadrzi stavke i iz jedne i iz druge narudzbe. Ukoliko se 
    jedan te isti artikal pojavljuje u obje narudzbe, potrebno je onda sabrati
    kolicine i imati samo jednu stavku za dati artikal, ali samo pod uslovom da
    je cijena ista. U suprotnom, napravite exception.
    c) Preklopite operator [], cime dajete pristup odgovarajucoj stavki narudzbe
    (npr. ako je n objekat narudzbe, n[3] vraca cetvrtu stavku narudzbe)
    d) Dodavanje nove stavke treba da ima odgovarajucu validaciju: da li dodajemo
    artikal koji se vec nalazi u narudzbi? Ukoliko je odgovor potvrdan, to je 
    moguce samo ako je cijena ista, u suprotnom javite exception 
    e) Napravite citanje objekta narudzbe iz streama (preklopite operator >>) 
*/

class Datum {
    private:
        int godina, mjesec, dan;
    public:
        Datum() {
            std::time_t t = std::time(nullptr);
            std::tm* sada = std::localtime(&t);
            dan = sada->tm_mday;
            mjesec = sada->tm_mon + 1;      // tm_mon ide od 0 do 11
            godina = sada->tm_year + 1900;
        }

        Datum(int d, int m, int g) {
            godina = g;
            mjesec = m;
            dan = d;
        }

        void ispis_datuma() const {
            std::cout << dan << "." << mjesec << "." << godina << std::endl;
        }
};

class Komercijalista {
    private:
        std::string ime;
        std::string prezime;
    public:
        Komercijalista() {
            ime = "";
            prezime = "";
        }

        Komercijalista(std::string i, std::string p) {
            ime = i;
            prezime = p;
        }

        void set_ime(std::string i) { ime = i; }
        void set_prezime(std::string p) { prezime = p; }

        std::string get_ime() { return ime; }
        std::string get_prezime() { return prezime; }
        
        friend std::istream& operator>>(std::istream& ulaz, Komercijalista& k) {
            std::string i, p;
            ulaz >> i >> p;
            k.set_ime(i);
            k.set_prezime(p);

            return ulaz;
        }
};

class Adresa {
    private:
        std::string ulica;
        std::string grad;
        std::string drzava;
    public:
        Adresa() {
            ulica = "";
            grad = "";
            drzava = "";
        }

        Adresa(std::string u, std::string g, std::string d) {
            ulica = u;
            grad = g;
            drzava = d;
        }

        void set_ulica(std::string u) { ulica = u; }
        void set_grad(std::string g) { grad = g; } 
        void set_drzava(std::string d) { drzava = d; }

        std::string get_ulica() { return ulica; }
        std::string get_grad() { return grad; }
        std::string get_drzava() { return drzava; }

        friend std::istream& operator>>(std::istream& ulaz, Adresa& a) {
            std::string u, g, d;
            ulaz >> u >> g >> d;
            a.set_ulica(u);
            a.set_grad(g);
            a.set_drzava(d);

            return ulaz;
        }
};

class Kupac {
    private:
        std::string naziv;
        Adresa adresa;
    public:
        Kupac() {
            naziv = "";
        }
        Kupac(std::string n, Adresa a) : naziv(n), adresa(a) {}

        void set_naziv(std::string n) { naziv = n; }
        void set_adresa(Adresa a) { adresa = a; }

        std::string get_naziv() { return naziv; }
        Adresa get_adresa() { return adresa; }

        friend std::istream& operator>>(std::istream& ulaz, Kupac& k) {
            std::string n;
            std::getline(ulaz >> std::ws, n);
            k.set_naziv(n);

            Adresa a;
            ulaz >> a;
            k.set_adresa(a);

            return ulaz;
        }
};

class StavkeNarudzbe {
    private:
        std::string naziv_artikla;
        int kolicina;
        double cijena;
    public:
        StavkeNarudzbe() {
            naziv_artikla = "";
            kolicina = 0;
            cijena = 0.0;
        }

        StavkeNarudzbe(std::string n, int k, double c) {
            naziv_artikla = n;
            kolicina = k;
            cijena = c;
        }

        void set_naziv_artikla(std::string n) { naziv_artikla = n; }
        void set_kolicina(int k) { kolicina = k; }
        void set_cijena(double c) { cijena = c; }

        std::string get_naziv_artikla() const { return naziv_artikla; }
        int get_kolicina() const { return kolicina; }
        double get_cijena() const { return cijena; }

        friend std::istream& operator>>(std::istream& ulaz, StavkeNarudzbe& sn) {
            std::string n;
            int k;
            double c;
            
            std::getline(ulaz >> std::ws, n);
            ulaz >> k >> c;
            
            sn.set_naziv_artikla(n);
            sn.set_kolicina(k);
            sn.set_cijena(c);

            return ulaz;
        }
};

class Narudzba {
    private:
        Datum datum;
        Komercijalista komercijalista;
        Kupac kupac;
        std::vector<StavkeNarudzbe> stavke;
    public:
        Narudzba(Komercijalista k1, Kupac k2, Datum d = Datum()) : komercijalista(k1), kupac(k2), datum(d) {}
        
        void set_datum(Datum d) { datum = d; }
        void set_komercijalista(Komercijalista k) { komercijalista = k; };
        void set_kupac(Kupac k) { kupac = k; }

        Datum get_datum() { return datum; }
        Komercijalista get_komercijalista() { return komercijalista; }
        Kupac get_kupac() { return kupac;}

        friend std::ostream& operator<<(std::ostream& izlaz, Narudzba& narudzba) {
            izlaz << "==NARUDZBA==\n";
            narudzba.get_datum().ispis_datuma();
            izlaz << "Komercijalista: " << narudzba.get_komercijalista().get_ime();
            izlaz << " " << narudzba.get_komercijalista().get_prezime() << std::endl;
            izlaz << "Kupac: " << narudzba.get_kupac().get_naziv() << std::endl;

            izlaz << "Stavke:\n";
            for (auto s : narudzba.stavke) {
                izlaz << "Naziv artikla: " << s.get_naziv_artikla() << std::endl;
                izlaz << "Kolicina: " << s.get_kolicina() << std::endl;
                izlaz << "Cijena: " << s.get_cijena() << std::endl; 
                izlaz << std::endl;
            }

            return izlaz;
        }

        friend Narudzba operator+(Narudzba& n1, Narudzba& n2) {
            Narudzba rezultat(n1.get_komercijalista(), n1.get_kupac(), n1.get_datum());
            rezultat.stavke = n1.stavke;

            for (auto& s2 : n2.stavke) {
                bool pronadjen {false};
                for (auto& s1 : rezultat.stavke) {
                    if (s1.get_naziv_artikla() == s2.get_naziv_artikla()) {
                        pronadjen = true;

                        if (s1.get_cijena() == s2.get_cijena()) {
                            s1.set_kolicina(s1.get_kolicina() + s2.get_kolicina());
                        } else {
                            throw std::runtime_error("Greska! Artikal " + s2.get_naziv_artikla() + " ima razlicitu cijenu!");
                        }
                        break;
                    }
                }
                if (!pronadjen) { rezultat.stavke.push_back(s2); }
            }   
            return rezultat;
        }

        StavkeNarudzbe operator[](int indeks) { return stavke[indeks]; }
        StavkeNarudzbe operator[](int indeks) const { return stavke[indeks]; }

        void dodaj_stavku(const StavkeNarudzbe& nova) {
            for (auto& s : stavke) {
                if (s.get_naziv_artikla() == nova.get_naziv_artikla()) {
                    if (s.get_cijena() == nova.get_cijena()) {
                        s.set_kolicina(s.get_kolicina() + nova.get_kolicina());
                        return;
                    } else {
                        throw std::runtime_error("Greska! Artikal " + nova.get_naziv_artikla() + " ima razlicitu cijenu!");
                    }
                }
            }
            stavke.push_back(nova);
        }

        friend std::istream& operator>>(std::istream& ulaz, Narudzba& n) {
            std::cout << "Unos ime i prezime komercijaliste:\n";
            Komercijalista k;
            ulaz >> k;
            n.set_komercijalista(k);

            std::cout << "Unos kupca:\n";
            Kupac k1;
            ulaz >> k1;
            n.set_kupac(k1);

            std::cout << "Koliko stavki zelite unijeti? ";
            int broj_stavki;
            ulaz >> broj_stavki;

            n.stavke.clear();

            for (int i = 0; i < broj_stavki; i++) {
                std::cout << "\n--- Stavka " << i + 1 << " ---\n";
                StavkeNarudzbe privremena_stavka;
                
                std::cout << "Unesite naziv artikla: ";
                ulaz >> privremena_stavka; 
                
                try {
                    n.dodaj_stavku(privremena_stavka);
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << " Pokusajte ponovo za ovu stavku.\n";
                    i--; // Vratimo brojač unazad da ponovimo unos za ovu stavku
                }
            }
            return ulaz;
        }
};

int main() {
    Komercijalista k("Danin", "Kadic");
    Adresa adresa("Mamma Mia", "Maranello", "Italija");
    Kupac firma("Ferrari", adresa);
    Narudzba n(k, firma);

    try {
        // 1. Dodajemo prvi put - prolazi regularno
        n.dodaj_stavku(StavkeNarudzbe("Guma Soft", 4, 300.0));

        // 2. Dodajemo isti artikal sa ISTOM cijenom - sabraće količine na 6
        n.dodaj_stavku(StavkeNarudzbe("Guma Soft", 2, 300.0)); 
        std::cout << "Uspjesno azurirana kolicina guma!\n";

        // 3. Dodajemo isti artikal sa RAZLIČITOM cijenom - Ovdje program baca exception!
        n.dodaj_stavku(StavkeNarudzbe("Guma Soft", 1, 350.0));
        
        std::cout << "Ovo se nece ispisati.\n";
    } 
    catch (const std::runtime_error& e) {
        std::cout << "Uhvacena greska pri dodavanju: " << e.what() << "\n";
    }

    return 0;
}