#include <iostream>
#include <cmath>

/*
    Napisati funkciju F koja prima kao parametre funkciju f, realne brojeve
    a i b, te prirodan broj n (f je funkcija ciji se integral racuna), a kao 
    rezultat vraca pribliznu vrijednost integrala koja se racuna na osnovu
    tzv. Simpsonovog pravila:
    Nepada mi napamet da prepisujem lmao evo vam link zadatka:
    https://drive.google.com/drive/u/5/folders/14UTk_qk1nGKGb3N_dy1g6DJK8I9FZEct
    pri cemu je h duzina svakog podintervala, tj h = (b - a) / n. Napisanu 
    funkciju F testirajte za tri funkcije: sinx, 1 / x i x^3. Druga i treca
    funkcija treba da se tokom poziva funkcije F iskljucivo pozivaju kao lambda
    funkcije.
*/

double F(double f(double), double a, double b, int n) {
    double suma1 {0.0}, suma2 {0.0};
    n = std::abs(n);
    double h {(b - a) / n};
    for (int k = 1; k <= n - 1; k += 2) suma1 += f(a + k * h);
    for (int k = 2; k <= n - 2; k += 2) suma2 += f(a + k * h);
    return (h / 3) * (f(a) + 4 * suma1 + 2 * suma2 + f(b));
}

int main() {
    double a, b;
    int n;
    std::cout << "Unos a: ";
    std::cin >> a;
    std::cout << "Unos b: ";
    std::cin >> b;
    std::cout << "Unos n: ";
    std::cin >> n;
    std::cout << "Rezultat za sinx: ";
    std::cout << F(std::sin, a, b, n) << std::endl;
    std::cout << "Rezultat za 1 / x: ";
    std::cout << F([](double x) { return 1 / x; }, a, b, n) << std::endl;
    std::cout << "Rezultat za x^3: ";
    std::cout << F([](double x) { return x * x * x; }, a, b, n) << std::endl;
    return 0;
}