#include <iostream>
#include <vector>
#include <string>
/*
    Napisati program koji trazi od korisnika unos imena studenata, pri cemu se unos 
    zavrsava kada korisnik unese rijec "KRAJ". Nakon toga, program pita korisnika da
    za svakog studenata unese predmete koji taj student slusa, a kraj unosa predmeta 
    je takodjer kada korisnik unese "KRAJ". Za cuvanje studenata koristiti vektor
    stringova, a za predmete koje studenti slusaju koristiti vektor ciji su elementi
    vektori stringova (tj. grbavu matrcu). Na kraju, napisati funkcije brojStudenataNaPredmetu
    ispsiStudenteNaPredmetu i dodajPredmet. Prva funkcija za predmet koji joj je proslijedjen
    kao parametar vraca broj studenata koji slusaju taj predmet, druga za proslijedjeni
    predmet ispisuje sve studente koji slusaju taj predmet, a treca proslijedjenom
    studentu dodaje predmet (koji joj je takodjer proslijedjen kao parametar). Ove 
    funkcije trebaju primati i neophodne vektore (ili matrice) koje su potrebne da bi
    ispravno funkcionisale.
*/

void broj_studenata_na_predmetu(std::vector<std::vector<std::string>>& predmeti, std::string predmet) {
    int brojac {0};
    for (int i = 0; i < predmeti.size(); i++) {
        for (int j = 0; j < predmeti.at(i).size(); j++) {
            if (predmeti.at(i).at(j) == predmet) brojac++;
        }
    }
    std::cout << brojac << std::endl;
}

void ispisi_studente_na_predmetu(std::vector<std::vector<std::string>>& predmeti, std::vector<std::string>& studenti, std::string predmet) {
    for (int i = 0; i < predmeti.size(); i++) {
        for (int j = 0; j < predmeti.at(i).size(); j++) {
            if (predmet == predmeti.at(i).at(j)) std::cout << studenti.at(i) << std::endl;
        }
    }
}

void dodaj_predmet(std::vector<std::vector<std::string>>& predmeti, std::vector<std::string>& studenti, std::string predmet, std::string student) {
    for (int i = 0; i < studenti.size(); i++) {
        if (studenti.at(i) == student) {
            predmeti.at(i).push_back(predmet);
        }
    }
}

int main() {
    std::vector<std::string> studenti;
    std::string student;
    std::cout << "Unos studenata\n";
    while (true) {
        std::getline(std::cin, student);
        if (student == "KRAJ") break;
        studenti.push_back(student);
    }

    std::cout << "Unos predmeta:\n";
    std::vector<std::vector<std::string>> predmeti;
    for (int i = 0; i < studenti.size(); i++) {
        std::vector<std::string> pomocni;
        std::string predmet;
        std::cout << "Za studenta: " << studenti.at(i) << std::endl;
        while (true) {
            std::getline(std::cin, predmet);
            if (predmet == "KRAJ") break;
            pomocni.push_back(predmet);
        }
        predmeti.push_back(pomocni);
    }
    broj_studenata_na_predmetu(predmeti, "Programiranje 2");
    ispisi_studente_na_predmetu(predmeti, studenti, "Programiranje 2");
    dodaj_predmet(predmeti, studenti, "Programiranje 2", "Luka Lukovic");
    return 0;
}