#include <iostream>
#include <string>

/*
    Kreirati apstraktnu klasu Radnik koja cuva podatke o imenu i prezimenu te 
    datumu rodjenja (napraviti i strukturu Datum). Klasa radnik treba da 
    sadrzi apstraktnu funkciju getPlata() koja vraca mjesecnu platu radnika i
    apstraktnu funkciju ispisiPodatke() koja ispisuje podatke o radniku (
    njegov polozaj u firmi, ime nadredjenog ukolio ga ima, te mjesecnu platu)
    Kreirati klase Zaposlenik, SefOdjela i Direktor koji nasljeduju klasu Radnik
    Klase Zaposlenik i SefOdjela trebaju imati parametre satnica i brojRadnihSati
    na osnovu kojih se racuna njihova plata. Direktor treba da ima parametar 
    plata koji je konstantan. Zaposlenik i SefOdjela imaju parametar nadredjeni
    koji je redom tipa SefOdjela i Direktor. Napraviti konstruktore za klase koji
    postavljaju atribute. 
*/

struct Datum {
    int dan;
    int mjesec;
    int godina;
};

class Radnik {
    protected:
        std::string ime;
        std::string prezime;
        Datum datum;
    public:
        Radnik(std::string i, std::string p, Datum d) {
            ime = i;
            prezime = p;
            datum = d;
        }

        virtual ~Radnik() {}

        virtual float get_plata() const = 0;
        virtual void ispisi_podatke() const = 0;
}; 

class Direktor : public Radnik {
    private:
        const float plata;
    public:
        Direktor(std::string i, std::string p, Datum d, float pl) : Radnik(i, p, d), plata(pl) {}
        float get_plata() const override {
            return plata;
        }     

        void ispisi_podatke() const override {
            std::cout << "Polozaj: Direktor\n";
            std::cout << "Ime i prezime: ";
            std::cout << ime << " " << prezime << std::endl;
            std::cout << "Mjesecna plata: " << get_plata() << std::endl;
        }
};

class SefOdjela : public Radnik {
    private:
        float satnica;
        int broj_radnih_sati;
        Direktor* nadredjeni;
    public:
        SefOdjela(std::string i, std::string p, Datum d, float s, int br_r_s, Direktor* nad) : Radnik(i, p, d), satnica(s), broj_radnih_sati(br_r_s), nadredjeni(nad) {}
        
        float get_plata() const override {
            return satnica * broj_radnih_sati;
        }

        void ispisi_podatke() const override {
            std::cout << "Polozaj: Sef Odjela\n";
            std::cout << "Ime i prezime: ";
            std::cout << ime << " " << prezime << std::endl;
            std::cout << "Mjesecna plata: " << get_plata() << std::endl;

            if (nadredjeni != nullptr) {
                std::cout << "--- Podaci o nadredjenom ---\n";
                nadredjeni->ispisi_podatke();
            }
        }
};

class Zaposlenik : public Radnik {
    private:
        float satnica;
        int broj_radnih_sati;
        SefOdjela* nadredjeni;
    public:
        Zaposlenik(std::string i, std::string p, Datum d, float s, int br_r_s, SefOdjela* nad) : Radnik(i, p, d) {
            satnica = s;
            broj_radnih_sati = br_r_s;
            nadredjeni = nad;
        }

        float get_plata() const override {
            return satnica * broj_radnih_sati;
        } 

        void ispisi_podatke() const override {
            std::cout << "Polozaj: Zaposlenik\n";
            std::cout << "Ime i prezime: ";
            std::cout << ime << " " << prezime << std::endl;
            std::cout << "Mjesecna plata: " << get_plata() << std::endl;

            if (nadredjeni != nullptr) {
                std::cout << "--- Podaci o nadredjenom ---\n";
                nadredjeni->ispisi_podatke();
            }
        }
};

int main() {
    Datum d = {1, 1, 1980};

    Direktor dir("Meho", "Mehic", d, 5000.0f);

    SefOdjela sef("Suljo", "Suljic", d, 25.0f, 160, &dir);

    Zaposlenik zap("Mujo", "Mujic", d, 15.0f, 160, &sef);

    std::cout << "=======================================\n";
    std::cout << "   TESTIRANJE ISPISA PREKO POLIMORFIZMA\n";
    std::cout << "=======================================\n\n";

    Radnik* firma[3] = { &dir, &sef, &zap };

    for (int i = 0; i < 3; i++) {
        firma[i]->ispisi_podatke();
        std::cout << "---------------------------------------\n";
    }

    return 0;
}