#pragma once
#include <string>
#include <iostream>				
class matrix
{
private:
	int n; //rozmiar macierzy,
	int** tab; //wska�nik do macierzy,
public:
	matrix(void); //konstruktor domy�lny bez alokacji pami�ci,
	matrix(int n); //konstruktor przeci��eniowy alokuje macierz o wymiarach n na n,
	matrix(int n, int* t); //konstruktor przeci��eniowy alokuje pami�� i przepisuje dane z tabeli,
	matrix(matrix& m); //konstruktor kopiuj�cy,
	~matrix(void); //destruktor,
	matrix& alokuj(int n); //je�li macierz nie ma zaalokowanej pami�ci to j� alokuje w wielko�ci n na n, je�li macierz ma zaalokowan� pami�� to sprawdza czy rozmiar alokacji jest r�wny zdeklarowanemu rozmiarowi.W przypadku gdy tej pami�ci jest mniej, pami�� ma zosta� zwolniona i zaalokowana ponownie w ��danym rozmiarze. W przypadku gdy tej pami�ci jest wi�cej pozostawi� alokacj� bez zmian.
	matrix& wstaw(int x, int y, int wartosc); //wiersz, kolumna, warto��,
    int pokaz(int x, int y); //zwraca warto�� elementu x, y,
	matrix& odwroc(void); //zamienia wiersze z kolumnami
	matrix& losuj(void); //wype�niamy cyframi od 0 do 9 wszystkie elementy macierzy
	matrix& losuj(int x); //wype�niamy cyframi od 0 do 9 elementy macierzy. Zmienna x okre�la ile cyfr b�dziemy losowa�.Nast�pnie algorytm losuje, w kt�re miejsca wstawi wylosowane cyfry,
	matrix& diagonalna(int* t); //po przek�tnej s� wpisane dane z tabeli, a pozosta�e elementy s� r�wne 0,
	matrix& diagonalna_k(int k, int* t); // po przek�tnej s� wpisane dane z tabeli, a pozosta�e elementy s� r�wne 0. Parametr k mo�e oznacza� : 0 - przek�tna przechodz�ca przez �rodek (czyli tak jak metoda diagonalna), cyfra dodatnia przesuwa diagonaln� do g�ry macierzy o podan� cyfr�, cyfra ujemna przesuwa diagonaln� w d� o podan� cyfr�,
	matrix& kolumna(int x, int* t); //przepisuje dane z tabeli do kolumny, kt�r� wskazuje zmienna x,
	matrix& wiersz(int y, int* t); //przepisuje dane z tabeli do wiersza, kt�ry wskazuje zmienna x,
	matrix& przekatna(void); //uzupe�nia macierz: 1-na przek�tnej, 0-poza przek�tn�,
	matrix& pod_przekatna(void); //uzupe�nia macierz: 1-pod przek�tn�, 0-nad przek�tn� i po przek�tnej,
	matrix& nad_przekatna(void); //uzupe�nia macierz: 1-nad przek�tn�, 0-pod przek�tn� i po przek�tnej,
	matrix& szachownica(void); //uzupe�nia macierz w ten spos�b dla n=4: 0101 1010 0101 1010
	matrix & operator+(matrix & m); //A+B
	matrix& operator*(matrix& m); //A*B
	matrix& operator+(int a); //A+int
	matrix& operator*(int a); //A*int
	matrix& operator-(int a); //A-int
	friend matrix operator+(int a, matrix& m); //int+A
	friend matrix operator*(int a, matrix& m); //int*A
	friend matrix operator-(int a, matrix& m); //int-A
	matrix& operator++(int); //A++ wszystkie liczby powi�kszone o 1
	matrix& operator--(int); //A-- wszystkie liczby pomniejszone o 1
	matrix& operator+=(int a); //ka�dy element w macierzy powi�kszamy o �a�
	matrix& operator-=(int a); //ka�dy element w macierzy pomniejszamy o �a�
	matrix& operator*=(int a); //ka�dy element w macierzy mno�ymy o �a�
	matrix& operator+=(double a); //wszystkie cyfry s� powi�kszone o cz�� ca�kowit� z wpisanej cyfry
	friend std::ostream& operator<<(std::ostream& o, matrix& m); //wypisanie macierzy
	bool operator==(const matrix& m); //sprawdza, czy ka�dy element macierzy spe�nia r�wno�� ??(??, ??) = ??(??, ??) A = | 1 2 | B = | 1 2| |3 4| |3 4 | je�li nie, to nie mo�emy m�wi�, �e macierze s� r�wne,
	bool operator>(const matrix& m); //operator wi�kszo�ci sprawdza, czy ka�dy element macierzy spe�nia nier�wno�� ??(??, ??) > ??(??, ??).Je�li tak, to mo�emy powiedzie�, �e macierz jest wi�ksza, w przeciwnym wypadku nie mo�emy stwierdzi�,�e macierz jest wi�ksza.
	bool operator<(const matrix& m); //tak jak wy�ej tylko operator mniejszo�ci. Na marginesie macierzy mo�emy nie da� rady okre�li�, �e jest r�wna, mniejsza i wi�ksza, wtedy m�wimy �e jest r�na
	matrix& wczytaj(const std::string& nazwa);
};

