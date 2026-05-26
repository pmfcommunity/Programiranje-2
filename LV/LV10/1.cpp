#include <iostream>
#include <cmath>
#include <string>

/*
    Implementirati klasu Polinom koja treba da sadrzi:
    a) Privatni atribut: dinamicki alociran niz realnih brojeva koefcijenti
    i privatni atribut stepen polinoma koji treba biti cjelobrojnog tipa. Ovaj
    niz treba imati za jedan veci broj elemenata od stepena polinoma. Prvi 
    element niza odgovara slobodnom clanu polinoma, drugi element niza 
    predstavlja koefcijent ispred clana polinoma koji je stepena 1, itd. 
    Posljednji element niza se nalazi na poziciji koja odgovara vrijednosti
    privatnog atributa stepen i predstavlja vodeci clan polinoma.
    b) defaultni konstruktor koji postavlja stepen polinoma na 0.
    c) Destruktor, koji oslobadja zauzetu memoriju.
    d) KOnstruktor kopije i preklopljeni operator dodjele. 
    e) Metodu evaluiraj koja prima jedan parametar tipa double i kao rezultat
    vraca vrijednost polinoma kada se sve nepoznate zamijene proslijedjenom
    vrijednosti.
    f) Preklopljeni operator + koji vrsti sabiranje dva polinoma (operanda) i
    kao rezultat vraca novi polinom sa odgovarajucim nizom koefcijanata i 
    vrijednoscu za njegov stepen.
    g) Preklopljeni unarni operator - koji vraca novi objekat tipa Polinoma 
    koji se dobije tako ste se izracuna izvod polinoma.
    h) Preklopljen operator << koji treba da podrzi ispis polinoma. Polinom
    se treba ispisati od clana sa najvecim stepenom prema slobodnom clanu. 
    Svaki clan polinoma treba biti ispisan u obliku ai* x^i pri cemu je ai 
    koefcijent clana polinoma dok je i stepen tog clana. Prilikom ispisivanja
    je potrebno obratiti paznju na predznak svakog clana (ne ispisati 2 * x
    + -1 nego 2 * x - 1). Ukoliko je koefcijent jednak broju 0 tada se taj clan
    ne smije nalaziti u ispisu.
    i) Preklopljen binarni operator == koji vrsi poredjenje polinoma na nacin 
    da poredi njihove nizove koefcijenata. Rezultat treba biti logicka vrijednost
    true ukoliko su nizovi koefcijenata isti a false u suprotnom.
*/

class Polinom {
    private:
        double* koefcijenti;
        int stepen;
    public:
        Polinom() {
            stepen = 0;
            koefcijenti = new double[stepen + 1];
            koefcijenti[0] = 0.0;
        }
        Polinom(const Polinom& kopija) {
            stepen = kopija.stepen;
            koefcijenti = new double[stepen + 1];
            for (int i = 0; i <= stepen; i++) {
                koefcijenti[i] = kopija.koefcijenti[i];
            }
        }
        Polinom(int novi_stepen) {
            stepen = novi_stepen;
            koefcijenti = new double[stepen + 1];
        }
        ~Polinom() {
            delete[] koefcijenti;
        }
        Polinom& operator=(const Polinom& desni) {
            if (this == &desni) return *this;
            delete[] koefcijenti;

            stepen = desni.stepen;
            koefcijenti = new double[stepen + 1];
            for (int i = 0; i < stepen; i++) {
                koefcijenti[i] = desni.koefcijenti[i];
            }
            return *this;
        }
        double evaluiraj(double x) {
            double suma {0.0};
            for (int i = 0; i <= stepen; i++) {
                suma += koefcijenti[i] * std::pow(x, i);
            }
            return suma;
        }
        friend Polinom& operator+(const Polinom& p1, const Polinom& p2) {
            int max_stepen = std::max(p1.stepen, p2.stepen);
            Polinom rezultat(max_stepen);

            for (int i = 0; i <= p1.stepen; i++) {
                rezultat.koefcijenti[i] = p1.koefcijenti[i];
            }

            for (int i = 0; i <= p2.stepen; i++) {
                double stari_koefcijent = rezultat.koefcijenti[i];
                rezultat.koefcijenti[i] = stari_koefcijent + p2.koefcijenti[i];
            }

            return rezultat;
        }

        Polinom operator-() {
            if (stepen == 0) return Polinom();
            Polinom izvod(stepen - 1);

            for (int i = 1; i <= stepen; i++) {
                double stari_koefcijent = koefcijenti[i] * i;
                koefcijenti[i - 1] = stari_koefcijent; 
            }

            return izvod;
        }

        friend bool operator==(const Polinom& p1, const Polinom& p2) {
            if (p1.stepen != p2.stepen) return false;
            for (int i = 0; i <= p1.stepen; i++) {
                if (p1.koefcijenti[i] != p2.koefcijenti[i]) return false;
            }
            return true;
        }

        friend std::ostream& operator<<(std::ostream& izlaz, const Polinom& p1) {
            bool prvi_ispisani = true;
            for (int i = p1.stepen; i >= 0; i--) {
                double koefcijent = p1.koefcijenti[i];

                if (prvi_ispisani) {
                    if (koefcijent < 0) {
                        izlaz << "-";
                        koefcijent = -koefcijent;
                    }
                    prvi_ispisani = false;
                }
                else {
                    if (koefcijent < 0) {
                        izlaz << " - ";
                        koefcijent = -koefcijent;
                    }
                    else {
                        izlaz << " + ";
                    }
                }

                izlaz << koefcijent << " * x ^ " << i;
            }
            return izlaz;
        }
};

int main() {

    return 0;
}