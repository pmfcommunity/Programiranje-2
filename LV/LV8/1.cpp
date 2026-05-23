#include <iostream>
#include <ctime>
#include <string>
#include <vector>

/*
    Napraviti klasu Narudzba, ciji ce objekti cuvati podatke o jednoj narudzbi
    napravljenoj nasoj zamisljenoj veletrgovini. Tipicno, druge firme narucuju
    robu od nse veletrgovine i zelimo zabiljeziti sve sto karakterise tu 
    narudzbu, a takoder i napraviti odgovarajuce funkcije clanice koje ce nam
    pomoci da radimo sa narudzbama (na primjer da ispisemo narudzbu, ili da
    saznamo ukupan iznos nadruzbe). Podaci koje je potrebno sacuvati za jednu
    narudzbu su:
    1. Datum narudzbe
    2. Komercijalista (ime i prezme radinka ko je napravio narudzbu)
    3. Kupac (firma kojoj ce se isporuciti roba). Zelimo zabiljeziti naziv
    kupca, adresu kupca, mjesto, drzavu, itd.
    4. Stavke narudzbe. To je niz (vektor) koji se sastoji od jednog ili vise
    elemenata: koji artikal je narucen, u kojoj koliicini i po kojoj cijeni.
    
    Za stavke narudzbe je potrebno napraviti posebnu klasu koja ima svoje 
    varijable: naziv artikla, kolicina, cijena. Eventualno napravite 
    konstruktor, ettere, settere. Po potrebi se mogu napraviti i nove 
    klase za: oercijalistcu, kupca, ili npr. adresu.
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
        Komercijalista(std::string i, std::string p) {
            ime = i;
            prezime = p;
        }

        void set_ime(std::string i) { ime = i; }
        void set_prezime(std::string p) { prezime = p; }

        std::string get_ime() { return ime; }
        std::string get_prezime() { return prezime; }
};

class Adresa {
    private:
        std::string ulica;
        std::string grad;
        std::string drzava;
    public:
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
};

class Kupac {
    private:
        std::string naziv;
        Adresa adresa;
    public:
        Kupac(std::string n, Adresa a) : naziv(n), adresa(a) {}

        void set_naziv(std::string n) { naziv = n; }
        void set_adresa(Adresa a) { adresa = a; }

        std::string get_naziv() { return naziv; }
        Adresa get_adresa() { return adresa; }
};

class StavkeNarudzbe {
    private:
        std::string naziv_artikla;
        int kolicina;
        double cijena;
    public:
        StavkeNarudzbe(std::string n, int k, double c) {
            naziv_artikla = n;
            kolicina = k;
            cijena = c;
        }

        void set_naziv_artikla(std::string n) { naziv_artikla = n; }
        void set_kolicina(int k) { kolicina = k; }
        void set_cijena(double c) { cijena = c; }

        std::string get_naziv_artikla() { return naziv_artikla; }
        int get_kolicina() { return kolicina; }
        double get_cijena() { return cijena; }
};

class Narudzba {
    private:
        Datum datum;
        Komercijalista komercijalista;
        Kupac kupac;
    public:
        std::vector<StavkeNarudzbe> stavke;

        Narudzba(Komercijalista k1, Kupac k2, Datum d = Datum()) : komercijalista(k1), kupac(k2), datum(d) {}
        
        void set_datum(Datum d) { datum = d; }
        void set_komercijalista(Komercijalista k) { komercijalista = k; };
        void set_kupac(Kupac k) { kupac = k; }

        Datum get_datum() { return datum; }
        Komercijalista get_komercijalista() { return komercijalista; }
        Kupac get_kupac() { return kupac;}
};

int main() {
    Adresa adr("Zmaja od Bosne bb", "Sarajevo", "BiH");
    Kupac firma("Tehno d.o.o", adr);

    Komercijalista radnik("Neko", "Nekic");

    Narudzba nova_narudzba(radnik, firma);
    
    nova_narudzba.stavke.push_back(StavkeNarudzbe("Laptop", 2, 1200.50));
    nova_narudzba.stavke.push_back(StavkeNarudzbe("Mis", 5, 25.00));

    std::cout << "Narudzbu napravio: " << nova_narudzba.get_komercijalista().get_ime() << std::endl;
    std::cout << "Kupac: " << nova_narudzba.get_kupac().get_naziv() << std::endl;
    std::cout << "Broj stavki: " << nova_narudzba.stavke.size() << std::endl;
    return 0;
}
