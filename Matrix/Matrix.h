#pragma once  //<-- zabezpieczenie przed wielokrotnym do��czaniem pliku nag��wkowego
#include <string>  //<-- biblioteka do obs�ugi string�w
#include <iostream>		//<-- biblioteka do obs�ugi strumieni wej�cia/wyj�cia
#include <fstream> //<-- biblioteka do obs�ugi plik�w
/**
 * @class matrix
 * @brief Klasa reprezentujaca macierz kwadratowa.
 *
 * Klasa ta pozwala na tworzenie i manipulowanie macierzami kwadratowymi
 * o dynamicznie alokowanej pamieci. Zawiera metody umozliwiajace wykonywanie
 * roznych operacji na macierzach, takich jak dodawanie, mnozenie, wstawianie
 * wartosci, czy odwracanie macierzy.
 */
class matrix 
{
private:
	int n; //<-- rozmiar macierzy
	int** tab; //<-- wska�nik do macierzy
public:
	/**
	* Konstruktor domy�lny bez alokacji pami�ci
	* 
	* nie przyjmuje �adnych argument�w i nie alokuje pami�ci na macierz 
	*/
	matrix(void); 
	/**
	* Konstruktor przeci��eniowy alokuje macierz o wymiarach n na n
	* przyjmuje jeden argument typu int, kt�ry okre�la rozmiar macierzy 
	*/
	matrix(int n); 
	/**
	* Konstruktor przeci��eniowy alokuje pami�� i przepisuje dane z tabeli
	* przyjmuje dwa argumenty: int n - rozmiar macierzy, int* t - tablica z danymi
	*/
	matrix(int n, int* t);
	/**
	* Konstruktor kopiuj�cy
	* przyjmuje jeden argument typu matrix, kt�ry jest kopiowany
	*/
	matrix(matrix& m); 
	~matrix(void); //<--destruktor,
	/**
	* Metoda alokuj alokuje pami�� na macierz
	* Je�li macierz nie ma zaalokowanej pami�ci to j� alokuje w wielko�ci n na n
	* Je�li ma zaalokowan� pami�� to rozwa�a przypadki gdy jest jej mniej lub wi�cej ni� n na n przez co odpowiednio usuwa lub dodaje nadmiarowe lub brakuj�ce kom�rki
	*/
	matrix& alokuj(int n);
	/**
	* Metoda wstaw wstawia warto�� do macierzy
	* przyjmuje trzy argumenty: int x - wiersz, int y - kolumna, int wartosc - warto��
	*/
	matrix& wstaw(int x, int y, int wartosc);
	/**
	* Metoda pokaz zwraca warto�� elementu x, y
	* przyjmuje dwa argumenty: int x - wiersz, int y - kolumna
	*/
    int pokaz(int x, int y);
	/**
	* Metoda odwroc zamienia wiersze z kolumnami
	* nie przyjmuje �adnych argument�w
	*/
	matrix& odwroc(void); 
	/**
	* Metoda losuj wype�nia macierz cyframi od 0 do 9 wszystkie elementy macierzy
	* nie przyjmuje �adnych argument�w
	*/
	matrix& losuj(void);
	/**
	* Metoda losuj wype�nia macierz cyframi od 0 do 9 elementy macierzy. Zmienna x okre�la ile cyfr b�dziemy losowa�.
	* przyjmuje jeden argument typu int, kt�ry okre�la ile cyfr b�dziemy losowa�
	*/
	matrix& losuj(int x); 
	/**
	* Metoda diagonalna po przek�tnej s� wpisane dane z tabeli, a pozosta�e elementy s� r�wne 0
	* przyjmuje jeden argument typu int*, kt�ry jest tablic� z danymi kt�re zostan� wpisane na przek�tn�
	*/
	matrix& diagonalna(int* t); 
	/**
	* Metoda diagonalna_k po przek�tnej s� wpisane dane z tabeli przesuni�te o k, a pozosta�e elementy s� r�wne 0
	* przyjmuje dwa argumenty: int k - przesuni�cie przek�tnej, int* t - tablica z danymi
	*/
	matrix& diagonalna_k(int k, int* t);
	/**
	* Metoda kolumna przepisuje dane z tabeli do kolumny, kt�r� wskazuje zmienna x
	* przyjmuje dwa argumenty: int x - kolumna, int* t - tablica z danymi
	*/
	matrix& kolumna(int x, int* t);
	/**
	* Metoda wiersz przepisuje dane z tabeli do wiersza, kt�ry wskazuje zmienna x
	* przyjmuje dwa argumenty: int y - wiersz, int* t - tablica z danymi
	*/
	matrix& wiersz(int y, int* t);
	/**
	* Metoda przekatna uzupe�nia macierz: 1-na przek�tnej, 0-poza przek�tn�,
	* nie przyjmuje �adnych argument�w
	*/
	matrix& przekatna(void); 
	/**
	* Metoda pod_przekatna uzupe�nia macierz: 1-pod przek�tn�, 0-nad przek�tn� i po przek�tnej,
	* nie przyjmuje �adnych argument�w
	*/
	matrix& pod_przekatna(void);
	/**
	* Metoda nad_przekatna uzupe�nia macierz: 1-nad przek�tn�, 0-pod przek�tn� i po przek�tnej,
	* nie przyjmuje �adnych argument�w
	*/
	matrix& nad_przekatna(void); 
	/**
	* Metoda szachownica uzupelnia macierz w ten spos�b dla n=4: 0101 1010 0101 1010
	* nie przyjmuje �adnych argument�w
	*/
	matrix& szachownica(void);
	/**
	* Metoda operator+ dodaje dwie macierze
	*przyjmuje jeden argument typu matrix, kt�ry jest dodawany do macierzy
	*/
	matrix & operator+(matrix & m);
	/**
	* Metoda operator- odejmuje dwie macierze
	* przyjmuje jeden argument typu matrix, kt�ry jest odejmowany od macierzy
	*/
	matrix& operator*(matrix& m);
	/**
	* Metoda operator+ dodaje liczb� do macierzy
	* przyjmuje jeden argument typu int, kt�ry jest dodawany do macierzy
	*/
	matrix& operator+(int a); 
	/**
	* Metoda operator* mno�y macierz przez liczb�
	* przyjmuje jeden argument typu int, kt�ry jest mno�ony przez macierz
	*/
	matrix& operator*(int a); 
	/**
	* Metoda operator- odejmuje liczb� od macierzy
	* przyjmuje jeden argument typu int, kt�ry jest odejmowany od macierzy
	*/
	matrix& operator-(int a); 
	/** 
	* Metoda operator+ dodaje liczb� do macierzy
	* przyjmuje jeden argument typu double, kt�ry jest dodawany do macierzy
	*/ 
	friend matrix operator+(int a, matrix& m); 
	/**
	* Metoda operator* mno�y macierz przez liczb�
	* przyjmuje jeden argument typu double, kt�ry jest mno�ony przez macierz
	*/
	friend matrix operator*(int a, matrix& m); 
	/**
	* Metoda operator- odejmuje liczb� od macierzy
	* przyjmuje jeden argument typu double, kt�ry jest odejmowany od macierzy
	*/
	friend matrix operator-(int a, matrix& m); 
	/**
	* Metoda operator++ wszystkie liczby powi�kszone o 1
	* nie przyjmuje �adnych argument�w
	*/
	matrix& operator++(int); 
	/**
	* Metoda operator-- wszystkie liczby pomniejszone o 1
	* nie przyjmuje �adnych argument�w
	*/
	matrix& operator--(int); 
	/**
	* Metoda operator+= ka�dy element w macierzy powi�kszamy o �a�
	* przyjmuje jeden argument typu int, kt�ry jest dodawany do macierzy
	*/
	matrix& operator+=(int a); 
	/**
	* Metoda operator-= ka�dy element w macierzy pomniejszamy o �a�
	* przyjmuje jeden argument typu int, kt�ry jest odejmowany od macierzy
	*/
	matrix& operator-=(int a); 
	/**
	* Metoda operator*= ka�dy element w macierzy mno�ymy o �a�
	* przyjmuje jeden argument typu int, kt�ry jest mno�ony przez macierz
	*/
	matrix& operator*=(int a); 
	/**
	* Metoda operator+= ka�dy element w macierzy powi�kszamy o �a�
	* przyjmuje jeden argument typu double, kt�ry jest dodawany do macierzy
	*/
	matrix& operator+=(double a); 
	/**
	* Metoda operator<< wypisanie macierzy
	*  przyjmuje dwa argumenty: std::ostream& o - strumie� wyj�ciowy, matrix& m - macierz
	*/
	friend std::ostream& operator<<(std::ostream& o, matrix& m); 
	/**
	* Metoda operator== sprawdza, czy ka�dy element macierzy spe�nia r�wno�� ??(??, ??) = ??(??, ??) A = | 1 2 | B = | 1 2| |3 4| |3 4 | je�li nie, to nie mo�emy m�wi�, �e macierze s� r�wne
	* przyjmuje jeden argument typu matrix, kt�ry jest por�wnywany z macierz�
	*/
	bool operator==(const matrix& m);
	/**
	* Metoda operator> sprawdza, czy ka�dy element macierzy spe�nia nier�wno�� ??(??, ??) > ??(??, ??).Je�li tak, to mo�emy powiedzie�, �e macierz jest wi�ksza, w przeciwnym wypadku nie mo�emy stwierdzi�,�e macierz jest wi�ksza.
	* przyjmuje jeden argument typu matrix, kt�ry jest por�wnywany z macierz�
	*/
	bool operator>(const matrix& m); 
	/**
	* Metoda operator< sprawdza, czy ka�dy element macierzy spe�nia nier�wno�� ??(??, ??) < ??(??, ??).Je�li tak, to mo�emy powiedzie�, �e macierz jest mniejsza, w przeciwnym wypadku nie mo�emy stwierdzi�,�e macierz jest mniejsza.
	* przyjmuje jeden argument typu matrix, kt�ry jest por�wnywany z macierz�
	*/
	bool operator<(const matrix& m); 
	/**
	* Metoda wczytaj wczytuje macierz z pliku o nazwie �nazwa�
	* przyjmuje jeden argument typu string, kt�ry jest nazw� pliku
	*/
	matrix& wczytaj(const std::string& nazwa); 

};

