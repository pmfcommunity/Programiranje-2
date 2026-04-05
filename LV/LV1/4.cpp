#include <iostream>

/*
    Napisati program koji od korisnika trazi da unese prirodan broj n. Program u konzolu
    ispisuje oblik dijamanta visine 2n-1. 
*/

int main() {
    int n;
    std::cout << "Unesite n: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n - i - 1; j++) {
            std::cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}