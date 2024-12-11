#include "Matrix.h"
#include <iostream>

int main()
{
    // Testowanie konstruktorów
    matrix m1; // Konstruktor domyślny
    matrix m2(30); // Konstruktor przeciążeniowy z rozmiarem
    int t[900];
    for (int i = 0; i < 900; ++i) {
        t[i] = i + 1;
    }
    matrix m3(30, t); // Konstruktor przeciążeniowy z danymi

    // Testowanie metody alokuj
    m1.alokuj(30);

    // Testowanie metody wstaw i pokaz
    m1.wstaw(0, 0, 5);
    std::cout << "m1(0,0): " << m1.pokaz(0, 0) << std::endl;

    // Testowanie metody odwroc
    m3.odwroc();
    std::cout << "m3 po odwroceniu: " << std::endl;
    std::cout << m3;

    // Testowanie metody losuj
    m2.losuj();
    std::cout << "m2 po losowaniu: " << std::endl;
    std::cout << m2;

    // Testowanie metody losuj z parametrem
    m2.losuj(50);
    std::cout << "m2 po losowaniu 50 elementów: " << std::endl;
    std::cout << m2;

    // Testowanie metody diagonalna
    int diag[30];
    for (int i = 0; i < 30; ++i) {
        diag[i] = i + 1;
    }
    m1.diagonalna(diag);
    std::cout << "m1 po diagonalna: " << std::endl;
    std::cout << m1;

    // Testowanie metody diagonalna_k
    m1.diagonalna_k(1, diag);
    std::cout << "m1 po diagonalna_k(1): " << std::endl;
    std::cout << m1;

    // Testowanie metody kolumna
    int col[30];
    for (int i = 0; i < 30; ++i) {
        col[i] = i + 1;
    }
    m1.kolumna(1, col);
    std::cout << "m1 po kolumna: " << std::endl;
    std::cout << m1;

    // Testowanie metody wiersz
    int row[30];
    for (int i = 0; i < 30; ++i) {
        row[i] = i + 1;
    }
    m1.wiersz(2, row);
    std::cout << "m1 po wiersz: " << std::endl;
    std::cout << m1;

    // Testowanie metody przekatna
    m1.przekatna();
    std::cout << "m1 po przekatna: " << std::endl;
    std::cout << m1;

    // Testowanie metody pod_przekatna
    m1.pod_przekatna();
    std::cout << "m1 po pod_przekatna: " << std::endl;
    std::cout << m1;

    // Testowanie metody nad_przekatna
    m1.nad_przekatna();
    std::cout << "m1 po nad_przekatna: " << std::endl;
    std::cout << m1;

    // Testowanie metody szachownica
    m1.szachownica();
    std::cout << "m1 po szachownica: " << std::endl;
    std::cout << m1;

    // Testowanie operatorów
    matrix m4 = m2 + m3;
    std::cout << "m2 + m3: " << std::endl;
    std::cout << m4;

    matrix m5 = m2 * m3;
    std::cout << "m2 * m3: " << std::endl;
    std::cout << m5;

    matrix m6 = m2 + 5;
    std::cout << "m2 + 5: " << std::endl;
    std::cout << m6;

    matrix m7 = m2 * 2;
    std::cout << "m2 * 2: " << std::endl;
    std::cout << m7;

    matrix m8 = m2 - 3;
    std::cout << "m2 - 3: " << std::endl;
    std::cout << m8;


    m2++;
    std::cout << "m2++: " << std::endl;
    std::cout << m2;

    m2--;
    std::cout << "m2--: " << std::endl;
    std::cout << m2;

    m2 += 5;
    std::cout << "m2 += 5: " << std::endl;
    std::cout << m2;

    m2 -= 3;
    std::cout << "m2 -= 3: " << std::endl;
    std::cout << m2;

    m2 *= 2;
    std::cout << "m2 *= 2: " << std::endl;
    std::cout << m2;

    m2 += 2.5;
    std::cout << "m2 += 2.5: " << std::endl;
    std::cout << m2;

    // Testowanie operatorów porównania
    if (m2 == m3)
        std::cout << "m2 jest równe m3" << std::endl;
    else
        std::cout << "m2 nie jest równe m3" << std::endl;

    if (m2 > m3)
        std::cout << "m2 jest większe od m3" << std::endl;
    else
        std::cout << "m2 nie jest większe od m3" << std::endl;

    if (m2 < m3)
        std::cout << "m2 jest mniejsze od m3" << std::endl;
    else
        std::cout << "m2 nie jest mniejsze od m3" << std::endl;

    // Testowanie metody wczytaj
    m1.wczytaj("matrix.txt");
    std::cout << "m1 po wczytaniu z pliku: " << std::endl;
    std::cout << m1;

    return 0;
}


