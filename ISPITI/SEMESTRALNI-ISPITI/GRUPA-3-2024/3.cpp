#include <iostream>
#include <functional>
#include <cmath>
#include <iomanip>

/*
    Napisite funkciju f, koja kao parametar prima dvije funkcije f1 i f2 koje se
    mogu pozvati sa parametrom realnog tipa i vracaju rezultat tog tipa. Funkcija
    f vraca kao rezultat funkciju g, koja primjenjena na neki argument x daje isti
    rezultat kao kompozicija funkcija f1 i f2, tj. vazi g(x) = f2(f1(x)). 
    U glavnom programu oogucite da se sa tastature moze unijeti vrijednost 
    argumenta x, te napisanu funkciju f testiraje za funkcije f1(x) = sinx i
    f2(x) = 5x^4 - 2x^3 + x^2 - 1. Tokom poziva funkcije f, funkciju f2 
    realizirajte kao lambda funkciju. Rezultati trebaju biti zaokruzeni na 5
    decimala.
*/

std::function<double(double)> f(std::function<double(double)> f1, std::function<double(double)> f2) {
    return [f1, f2](double x) {return f2(f1(x));};
}

double f1(double x) {
    return std::sin(x);
}

int main() {
    int x;
    std::cout << "Unos broja x: ";
    std::cin >> x;
    auto g(f(f1, [](double x) {return 5*x*x*x*x - 2*x*x*x + x*x - 1;}));
    std::cout << std::setprecision(5) << g(x) << std::endl;
    return 0;
}