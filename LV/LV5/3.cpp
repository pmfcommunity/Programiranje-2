#include <iostream>
#include <vector>

/*
    Napisati funkciju void Sortiraj(vector<vector<int>>) koja sortira vektor vektora. Jedan vektor
    smatramo manjim od drugog ako mu je prva koordinata manja (npr. {5, 10, 3} < {6, 1}), a ako im
    je prva koordinata ista, onda poredimo druge koordinate (npr. {5, 10, 3} < {5, 11, 1}), ako su 
    one iste, poredime trece koordinate, i tako dalje, pri cemu ako pri tom poredjenu neki
    vektor ostane bez elemenata, on je manji od drugog (npr. {4, 1, 2} < {4, 1, 2, 0}). 
    Sortiranje vektora se vrsi preko algoritma "bubble sort".
*/

bool Kriterij(std::vector<int>& v1, std::vector<int>& v2) {
    int n = std::min(v1.size(), v2.size());
    for (int i = 0; i < n; i++) {
        if (v1.at(i) < v2.at(i)) return true;
        else return false;
    }
    return v1.size() <= v2.size();
}

void Sortiraj(std::vector<std::vector<int>>& matrica) {
    std::vector<int> pomocni;
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica.size() - i - 1; j++) {
            if (Kriterij(matrica.at(j), matrica.at(j + 1))) {
                pomocni = matrica.at(j);
                matrica.at(j) = matrica.at(j + 1);
                matrica.at(j + 1) = pomocni; 
            }
        }
    }
    std::cout << "Ispis sortiranog vektora:\n";
    for (int i = 0; i < matrica.size(); i++) {
        for (int j = 0; j < matrica.at(i).size(); j++) {
            std::cout << matrica.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrica;
    std::vector<int> red1 = {1, 2};
    std::vector<int> red2 = {5, 3, 1};
    std::vector<int> red3 = {3, 8, 5, 2};

    matrica.push_back(red1);
    matrica.push_back(red2);
    matrica.push_back(red3);
    Sortiraj(matrica);
    return 0;
}