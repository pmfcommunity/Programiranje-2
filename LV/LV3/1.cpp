#include <iostream>
#include <string>

/*
    Napisati program koji trazi od korisnika broj predmeta jednog smjera u nekom 
    semestru, te broj studenata na tom smjeru. Nakon toga, trazi se trazi se unos imena
    predmeta. Dalje, za svakog studenta trazi se unos imena studenta, te ocjena za svaki
    predmet (u toku unosenja ocjena program ispisuje ime predmeta za koji treba da se u
    tom trenutku unese ocjena). Program treba da ispise prosjek svakog studenta, ali i
    prosjecnu ocjenu za svaki predmet. Za naziv i imena studenta koristiti nizove znakova,
    a za ocjene studenata matricu.
*/

int main() {
    int broj_predmeta, broj_studenata;
    std::cout << "Broj predmeta: ";
    std::cin >> broj_predmeta;
    std::cout << "Broj studenata: ";
    std::cin >> broj_studenata;

    std::string niz_predmeta [100];
    std::string niz_studenata[100];
    
    std::cin.ignore(10000, '\n');
    std::cout << "Unos imena predmeta:\n";
    for (int i = 0; i < broj_predmeta; i++) {
        std::getline(std::cin, niz_predmeta[i]);
    }

    std::cout << "Unos imena studenata:\n";
    for (int i = 0; i < broj_studenata; i++) {
        std::getline(std::cin, niz_studenata[i]);
    }

    int ocjene[100][100];
    for (int i = 0; i < broj_studenata; i++) {
        float ocjena;
        std::cout << "Unos ocjena za studenta: " << niz_studenata[i] << std::endl;
        for (int j = 0; j < broj_predmeta; j++) {
            std::cout << "Predmet: " << niz_predmeta[j] << std::endl;
            std::cin >> ocjena;
            ocjene[i][j] = ocjena;
        }
    }

    for (int i = 0; i < broj_studenata; i++) {
        float suma {0.0};
        std::cout << "Prosjek za studenta: " << niz_studenata[i];
        for (int j = 0; j < broj_predmeta; j++) {
            suma += ocjene[i][j];
        }
        std::cout << " " << suma / (float)broj_predmeta << std::endl;
    }

    for (int j = 0; j < broj_predmeta; j++) {
        float suma {0.0};
        std::cout << "Prosjek za predmet: " << niz_predmeta[j] << std::endl;
        for (int i = 0; i < broj_studenata; i++) {
            suma += ocjene[i][j];
        }
        std::cout << " " << suma / (float)broj_predmeta << std::endl;
    }
    return 0;
}