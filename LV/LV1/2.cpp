#include <iostream>
#include <iomanip>

/*
    Napisati program koji simulira jednostavni digitron sa cetiri osnovne aritmeticke operacije. 
    Od korisnika se trazi unos dva cijela broja i znaka za aritmeticku operaciju. Program ispisuje
    rezultat odgovarajuceg izraza. 
    Obratiti paznju na formatiranje ispisa. Pretpostaviti da ce se svaka vrijednost, pa i rezultat
    imati najvise 7 cifara.
*/

int main() {
    int a, b;
    char znak;
    std::cout << "Unesite broj: ";
    std::cin >> a;
    std::cout << "Unesite broj: ";
    std::cin >> b;
    std::cout << "Unesite operaciju: ";
    std::cin >> znak;

    std::cout << std::setw(7);
    std::cout << a << std::endl;
    std::cout << std::setw(7);
    std::cout << b;
    std::cout << " " << znak << std::endl;
    std::cout << "-----------\n";
    std::cout << std::setw(7);
    switch (znak) {
        case '+':
            std::cout << a + b;
            break;
        case '-':
            std::cout << a - b;
            break;
        case '*':
            std::cout << a * b;
            break;
        case '/':
            std::cout << a / (float)b;
            break;
    }
    std::cout << std::endl;
    return 0;
}