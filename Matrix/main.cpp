#include "Matrix.h"
#include <iostream>

int main()
{
        // Testowanie 
        matrix m1; // Konstruktor domyślny
        std::cout<<"Test konstruktora domyślnego: \n" << m1 << std::endl;
		// Działa poprawnie
		matrix m2(30); // Konstruktor przeciążeniowy
        std::cout << "Test konstruktora przeciążeniowego: \n" << m2 << std::endl;
		// Działa poprawnie
		matrix m3(3, new int[9] {1, 2, 3, 4, 5, 6, 7, 8, 9}); // Konstruktor przeciążeniowy
		std::cout << "Test konstruktora przeciążeniowego z tablicą: \n" << m3 << std::endl;
		// Działa poprawnie
		matrix m4(m3); // Konstruktor kopiujący
		std::cout << "Test konstruktora kopiującego: \n" << m4 << std::endl;
		// Działa poprawnie
		matrix m5;
		m5.alokuj(30); // Testowanie metody alokuj
		std::cout << "Test metody alokuj: \n" << m5 << std::endl;
		// Działa poprawnie
		matrix m6;// Testowanie metody wczytaj
		m6.wczytaj("matrix.txt"); // Wczytanie macierzy z pliku
		std::cout << "Test metody wczytaj: \n" << m6 << std::endl;
		// Działa poprawnie
		matrix m7(m6);
		m7.wstaw(1, 1, 23); // Testowanie metody wstaw
		std::cout << "Test metody wstaw: \n" << m7 << std::endl;
		// Działa poprawnie
		matrix m8(m7);
		std::cout << "Test metody pokaz: \n" << m8.pokaz(1, 1) << std::endl; // Testowanie metody pokaz
		// Działa poprawnie
		matrix m9(m6);
		m9.odwroc(); // Testowanie metody odwroc
		std::cout << "Test metody odwroc: \n" << m9 << std::endl;
		// Nie działa poprawnie
		matrix m10(30);
		m10.losuj(); // Testowanie metody losuj
		std::cout << "Test metody losuj: \n" << m10 << std::endl;
		// Działa poprawnie
		matrix m11(30);
		m11.losuj(10); // Testowanie metody losuj
		std::cout << "Test metody losuj ze zmienna: \n" << m11 << std::endl;
		// Nie działa poprawnie
		matrix m12(30);
		m12.diagonalna(new int[30] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}); // Testowanie metody diagonalna
		std::cout << "Test metody diagonalna: \n" << m12 << std::endl;
		// Działa poprawnie
		matrix m13(30);
		m13.diagonalna_k(2, new int[30] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}); // Testowanie metody diagonalna_k
		std::cout << "Test metody diagonalna_k: \n" << m13 << std::endl;
		// Działa poprawnie
		matrix m14(30);
		m14.kolumna(1, new int[30] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}); // Testowanie metody kolumna
		std::cout << "Test metody kolumna: \n" << m14 << std::endl;
		// Działa poprawnie
		matrix m15(30);
		m15.wiersz(1, new int[30] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}); // Testowanie metody wiersz
		std::cout << "Test metody wiersz: \n" << m15 << std::endl;
		// Działa poprawnie
		matrix m16(30);
		m16.przekatna(); // Testowanie metody przekatna
		std::cout << "Test metody przekatna: \n" << m16 << std::endl;
		// Działa poprawnie
		matrix m17(30);
		m17.pod_przekatna(); // Testowanie metody pod_przekatna
		std::cout << "Test metody pod_przekatna: \n" << m17 << std::endl;
		// Działa poprawnie
		matrix m18(30);
		m18.nad_przekatna(); // Testowanie metody nad_przekatna
		std::cout << "Test metody nad_przekatna: \n" << m18 << std::endl;
		// Działa poprawnie
		matrix m19(30);
		m19.szachownica(); // Testowanie metody szachownica
		std::cout << "Test metody szachownica: \n" << m19 << std::endl;
		// Działa poprawnie
		matrix m20(m15);
		matrix m21(m14);
		m21 = m20 + m19; // Testowanie operatora +
		std::cout << "Test operatora +: \n" << m21 << std::endl;
		// Działa poprawnie
		matrix m22(m15);
		matrix m23(m14);
		m23 = m22 * m19; // Testowanie operatora *
		std::cout << "Test operatora *: \n" << m23 << std::endl;
		// Działa poprawnie
		matrix m24(30);
		m24 = m24 + 5; // Testowanie operatora +
		std::cout << "Test operatora +: \n" << m24 << std::endl;
		// Działa poprawnie
		matrix m25(30);
		m25 = m25 * 5; // Testowanie operatora *
		std::cout << "Test operatora *: \n" << m25 << std::endl;
		// Działa poprawnie
		matrix m26(30);
		m26 = m26 - 5; // Testowanie operatora -
		std::cout << "Test operatora -: \n" << m26 << std::endl;
		// Działa poprawnie
		matrix m27(30);
		m27 += 5; // Testowanie operatora +=
		std::cout << "Test operatora +=: \n" << m27 << std::endl;
		// Działa poprawnie
		matrix m28(30);
		m28 -= 5; // Testowanie operatora -=
		std::cout << "Test operatora -=: \n" << m28 << std::endl;
		// Działa poprawnie
		matrix m29(30);
		m29 *= 5; // Testowanie operatora *=
		std::cout << "Test operatora *=: \n" << m29 << std::endl;
		// Działa poprawnie
		matrix m30(30);
		m30 += 5.5; // Testowanie operatora +=
		std::cout << "Test operatora +=: \n" << m30 << std::endl;
		// Działa poprawnie
		matrix m31(30);
		matrix m32(30);
		if (m31 == m32) // Testowanie operatora ==
		{
			std::cout << "Macierze są równe" << std::endl;
		}
		else
		{
			std::cout << "Macierze nie są równe" << std::endl;
		}
		// Działa poprawnie
		matrix m33(30);
		matrix m34(30);
		if (m33 > m34) // Testowanie operatora >
		{
			std::cout << "Macierz 1 jest większa od macierzy 2" << std::endl;
		}
		else
		{
			std::cout << "Macierz 1 nie jest większa od macierzy 2" << std::endl;
		}
		// Działa poprawnie
		matrix m35(30);
		matrix m36(30);
		if (m35 < m36) // Testowanie operatora <
		{
			std::cout << "Macierz 1 jest mniejsza od macierzy 2" << std::endl;
		}
		else
		{
			std::cout << "Macierz 1 nie jest mniejsza od macierzy 2" << std::endl;
		}
		// Działa poprawnie
		matrix m37(30);
		m37++; // Testowanie operatora ++
		std::cout << "Test operatora ++: \n" << m37 << std::endl;
		// Nie działa poprawnie
		matrix m38(30);
		m38--; // Testowanie operatora --
		std::cout << "Test operatora --: \n" << m38 << std::endl;
		// Nie działa poprawnie 
		std::cout << std::endl << m10<<std::endl;// Testowanie operatora<<
		// Działa poprawnie




}


