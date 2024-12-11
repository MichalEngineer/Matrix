#pragma once  //<-- zabezpieczenie przed wielokrotnym do³¹czaniem pliku nag³ówkowego
#include <string>  //<-- biblioteka do obs³ugi stringów
#include <iostream>		//<-- biblioteka do obs³ugi strumieni wejœcia/wyjœcia
#include <fstream> //<-- biblioteka do obs³ugi plików
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
	int** tab; //<-- wskaŸnik do macierzy
public:
	/**
	* Konstruktor domyœlny bez alokacji pamiêci
	* 
	* nie przyjmuje ¿adnych argumentów i nie alokuje pamiêci na macierz 
	*/
	matrix(void); 
	/**
	* Konstruktor przeci¹¿eniowy alokuje macierz o wymiarach n na n
	* przyjmuje jeden argument typu int, który okreœla rozmiar macierzy 
	*/
	matrix(int n); 
	/**
	* Konstruktor przeci¹¿eniowy alokuje pamiêæ i przepisuje dane z tabeli
	* przyjmuje dwa argumenty: int n - rozmiar macierzy, int* t - tablica z danymi
	*/
	matrix(int n, int* t);
	/**
	* Konstruktor kopiuj¹cy
	* przyjmuje jeden argument typu matrix, który jest kopiowany
	*/
	matrix(matrix& m); 
	~matrix(void); //<--destruktor,
	/**
	* Metoda alokuj alokuje pamiêæ na macierz
	* Jeœli macierz nie ma zaalokowanej pamiêci to j¹ alokuje w wielkoœci n na n
	* Jeœli ma zaalokowan¹ pamiêæ to rozwa¿a przypadki gdy jest jej mniej lub wiêcej ni¿ n na n przez co odpowiednio usuwa lub dodaje nadmiarowe lub brakuj¹ce komórki
	*/
	matrix& alokuj(int n);
	/**
	* Metoda wstaw wstawia wartoœæ do macierzy
	* przyjmuje trzy argumenty: int x - wiersz, int y - kolumna, int wartosc - wartoœæ
	*/
	matrix& wstaw(int x, int y, int wartosc);
	/**
	* Metoda pokaz zwraca wartoœæ elementu x, y
	* przyjmuje dwa argumenty: int x - wiersz, int y - kolumna
	*/
    int pokaz(int x, int y);
	/**
	* Metoda odwroc zamienia wiersze z kolumnami
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& odwroc(void); 
	/**
	* Metoda losuj wype³nia macierz cyframi od 0 do 9 wszystkie elementy macierzy
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& losuj(void);
	/**
	* Metoda losuj wype³nia macierz cyframi od 0 do 9 elementy macierzy. Zmienna x okreœla ile cyfr bêdziemy losowaæ.
	* przyjmuje jeden argument typu int, który okreœla ile cyfr bêdziemy losowaæ
	*/
	matrix& losuj(int x); 
	/**
	* Metoda diagonalna po przek¹tnej s¹ wpisane dane z tabeli, a pozosta³e elementy s¹ równe 0
	* przyjmuje jeden argument typu int*, który jest tablic¹ z danymi które zostan¹ wpisane na przek¹tn¹
	*/
	matrix& diagonalna(int* t); 
	/**
	* Metoda diagonalna_k po przek¹tnej s¹ wpisane dane z tabeli przesuniête o k, a pozosta³e elementy s¹ równe 0
	* przyjmuje dwa argumenty: int k - przesuniêcie przek¹tnej, int* t - tablica z danymi
	*/
	matrix& diagonalna_k(int k, int* t);
	/**
	* Metoda kolumna przepisuje dane z tabeli do kolumny, któr¹ wskazuje zmienna x
	* przyjmuje dwa argumenty: int x - kolumna, int* t - tablica z danymi
	*/
	matrix& kolumna(int x, int* t);
	/**
	* Metoda wiersz przepisuje dane z tabeli do wiersza, który wskazuje zmienna x
	* przyjmuje dwa argumenty: int y - wiersz, int* t - tablica z danymi
	*/
	matrix& wiersz(int y, int* t);
	/**
	* Metoda przekatna uzupe³nia macierz: 1-na przek¹tnej, 0-poza przek¹tn¹,
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& przekatna(void); 
	/**
	* Metoda pod_przekatna uzupe³nia macierz: 1-pod przek¹tn¹, 0-nad przek¹tn¹ i po przek¹tnej,
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& pod_przekatna(void);
	/**
	* Metoda nad_przekatna uzupe³nia macierz: 1-nad przek¹tn¹, 0-pod przek¹tn¹ i po przek¹tnej,
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& nad_przekatna(void); 
	/**
	* Metoda szachownica uzupelnia macierz w ten sposób dla n=4: 0101 1010 0101 1010
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& szachownica(void);
	/**
	* Metoda operator+ dodaje dwie macierze
	*przyjmuje jeden argument typu matrix, który jest dodawany do macierzy
	*/
	matrix & operator+(matrix & m);
	/**
	* Metoda operator- odejmuje dwie macierze
	* przyjmuje jeden argument typu matrix, który jest odejmowany od macierzy
	*/
	matrix& operator*(matrix& m);
	/**
	* Metoda operator+ dodaje liczbê do macierzy
	* przyjmuje jeden argument typu int, który jest dodawany do macierzy
	*/
	matrix& operator+(int a); 
	/**
	* Metoda operator* mno¿y macierz przez liczbê
	* przyjmuje jeden argument typu int, który jest mno¿ony przez macierz
	*/
	matrix& operator*(int a); 
	/**
	* Metoda operator- odejmuje liczbê od macierzy
	* przyjmuje jeden argument typu int, który jest odejmowany od macierzy
	*/
	matrix& operator-(int a); 
	/** 
	* Metoda operator+ dodaje liczbê do macierzy
	* przyjmuje jeden argument typu double, który jest dodawany do macierzy
	*/ 
	friend matrix operator+(int a, matrix& m); 
	/**
	* Metoda operator* mno¿y macierz przez liczbê
	* przyjmuje jeden argument typu double, który jest mno¿ony przez macierz
	*/
	friend matrix operator*(int a, matrix& m); 
	/**
	* Metoda operator- odejmuje liczbê od macierzy
	* przyjmuje jeden argument typu double, który jest odejmowany od macierzy
	*/
	friend matrix operator-(int a, matrix& m); 
	/**
	* Metoda operator++ wszystkie liczby powiêkszone o 1
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& operator++(int); 
	/**
	* Metoda operator-- wszystkie liczby pomniejszone o 1
	* nie przyjmuje ¿adnych argumentów
	*/
	matrix& operator--(int); 
	/**
	* Metoda operator+= ka¿dy element w macierzy powiêkszamy o „a”
	* przyjmuje jeden argument typu int, który jest dodawany do macierzy
	*/
	matrix& operator+=(int a); 
	/**
	* Metoda operator-= ka¿dy element w macierzy pomniejszamy o „a”
	* przyjmuje jeden argument typu int, który jest odejmowany od macierzy
	*/
	matrix& operator-=(int a); 
	/**
	* Metoda operator*= ka¿dy element w macierzy mno¿ymy o „a”
	* przyjmuje jeden argument typu int, który jest mno¿ony przez macierz
	*/
	matrix& operator*=(int a); 
	/**
	* Metoda operator+= ka¿dy element w macierzy powiêkszamy o „a”
	* przyjmuje jeden argument typu double, który jest dodawany do macierzy
	*/
	matrix& operator+=(double a); 
	/**
	* Metoda operator<< wypisanie macierzy
	*  przyjmuje dwa argumenty: std::ostream& o - strumieñ wyjœciowy, matrix& m - macierz
	*/
	friend std::ostream& operator<<(std::ostream& o, matrix& m); 
	/**
	* Metoda operator== sprawdza, czy ka¿dy element macierzy spe³nia równoœæ ??(??, ??) = ??(??, ??) A = | 1 2 | B = | 1 2| |3 4| |3 4 | jeœli nie, to nie mo¿emy mówiæ, ¿e macierze s¹ równe
	* przyjmuje jeden argument typu matrix, który jest porównywany z macierz¹
	*/
	bool operator==(const matrix& m);
	/**
	* Metoda operator> sprawdza, czy ka¿dy element macierzy spe³nia nierównoœæ ??(??, ??) > ??(??, ??).Jeœli tak, to mo¿emy powiedzieæ, ¿e macierz jest wiêksza, w przeciwnym wypadku nie mo¿emy stwierdziæ,¿e macierz jest wiêksza.
	* przyjmuje jeden argument typu matrix, który jest porównywany z macierz¹
	*/
	bool operator>(const matrix& m); 
	/**
	* Metoda operator< sprawdza, czy ka¿dy element macierzy spe³nia nierównoœæ ??(??, ??) < ??(??, ??).Jeœli tak, to mo¿emy powiedzieæ, ¿e macierz jest mniejsza, w przeciwnym wypadku nie mo¿emy stwierdziæ,¿e macierz jest mniejsza.
	* przyjmuje jeden argument typu matrix, który jest porównywany z macierz¹
	*/
	bool operator<(const matrix& m); 
	/**
	* Metoda wczytaj wczytuje macierz z pliku o nazwie „nazwa”
	* przyjmuje jeden argument typu string, który jest nazw¹ pliku
	*/
	matrix& wczytaj(const std::string& nazwa); 

};

