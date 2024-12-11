#pragma once
#include <string>
#include <iostream>				
class matrix
{
private:
	int n; //rozmiar macierzy,
	int** tab; //wskaŸnik do macierzy,
public:
	matrix(void); //konstruktor domyœlny bez alokacji pamiêci,
	matrix(int n); //konstruktor przeci¹¿eniowy alokuje macierz o wymiarach n na n,
	matrix(int n, int* t); //konstruktor przeci¹¿eniowy alokuje pamiêæ i przepisuje dane z tabeli,
	matrix(matrix& m); //konstruktor kopiuj¹cy,
	~matrix(void); //destruktor,
	matrix& alokuj(int n); //jeœli macierz nie ma zaalokowanej pamiêci to j¹ alokuje w wielkoœci n na n, jeœli macierz ma zaalokowan¹ pamiêæ to sprawdza czy rozmiar alokacji jest równy zdeklarowanemu rozmiarowi.W przypadku gdy tej pamiêci jest mniej, pamiêæ ma zostaæ zwolniona i zaalokowana ponownie w ¿¹danym rozmiarze. W przypadku gdy tej pamiêci jest wiêcej pozostawiæ alokacjê bez zmian.
	matrix& wstaw(int x, int y, int wartosc); //wiersz, kolumna, wartoœæ,
    int pokaz(int x, int y); //zwraca wartoœæ elementu x, y,
	matrix& odwroc(void); //zamienia wiersze z kolumnami
	matrix& losuj(void); //wype³niamy cyframi od 0 do 9 wszystkie elementy macierzy
	matrix& losuj(int x); //wype³niamy cyframi od 0 do 9 elementy macierzy. Zmienna x okreœla ile cyfr bêdziemy losowaæ.Nastêpnie algorytm losuje, w które miejsca wstawi wylosowane cyfry,
	matrix& diagonalna(int* t); //po przek¹tnej s¹ wpisane dane z tabeli, a pozosta³e elementy s¹ równe 0,
	matrix& diagonalna_k(int k, int* t); // po przek¹tnej s¹ wpisane dane z tabeli, a pozosta³e elementy s¹ równe 0. Parametr k mo¿e oznaczaæ : 0 - przek¹tna przechodz¹ca przez œrodek (czyli tak jak metoda diagonalna), cyfra dodatnia przesuwa diagonaln¹ do góry macierzy o podan¹ cyfrê, cyfra ujemna przesuwa diagonaln¹ w dó³ o podan¹ cyfrê,
	matrix& kolumna(int x, int* t); //przepisuje dane z tabeli do kolumny, któr¹ wskazuje zmienna x,
	matrix& wiersz(int y, int* t); //przepisuje dane z tabeli do wiersza, który wskazuje zmienna x,
	matrix& przekatna(void); //uzupe³nia macierz: 1-na przek¹tnej, 0-poza przek¹tn¹,
	matrix& pod_przekatna(void); //uzupe³nia macierz: 1-pod przek¹tn¹, 0-nad przek¹tn¹ i po przek¹tnej,
	matrix& nad_przekatna(void); //uzupe³nia macierz: 1-nad przek¹tn¹, 0-pod przek¹tn¹ i po przek¹tnej,
	matrix& szachownica(void); //uzupe³nia macierz w ten sposób dla n=4: 0101 1010 0101 1010
	matrix & operator+(matrix & m); //A+B
	matrix& operator*(matrix& m); //A*B
	matrix& operator+(int a); //A+int
	matrix& operator*(int a); //A*int
	matrix& operator-(int a); //A-int
	friend matrix operator+(int a, matrix& m); //int+A
	friend matrix operator*(int a, matrix& m); //int*A
	friend matrix operator-(int a, matrix& m); //int-A
	matrix& operator++(int); //A++ wszystkie liczby powiêkszone o 1
	matrix& operator--(int); //A-- wszystkie liczby pomniejszone o 1
	matrix& operator+=(int a); //ka¿dy element w macierzy powiêkszamy o „a”
	matrix& operator-=(int a); //ka¿dy element w macierzy pomniejszamy o „a”
	matrix& operator*=(int a); //ka¿dy element w macierzy mno¿ymy o „a”
	matrix& operator+=(double a); //wszystkie cyfry s¹ powiêkszone o czêœæ ca³kowit¹ z wpisanej cyfry
	friend std::ostream& operator<<(std::ostream& o, matrix& m); //wypisanie macierzy
	bool operator==(const matrix& m); //sprawdza, czy ka¿dy element macierzy spe³nia równoœæ ??(??, ??) = ??(??, ??) A = | 1 2 | B = | 1 2| |3 4| |3 4 | jeœli nie, to nie mo¿emy mówiæ, ¿e macierze s¹ równe,
	bool operator>(const matrix& m); //operator wiêkszoœci sprawdza, czy ka¿dy element macierzy spe³nia nierównoœæ ??(??, ??) > ??(??, ??).Jeœli tak, to mo¿emy powiedzieæ, ¿e macierz jest wiêksza, w przeciwnym wypadku nie mo¿emy stwierdziæ,¿e macierz jest wiêksza.
	bool operator<(const matrix& m); //tak jak wy¿ej tylko operator mniejszoœci. Na marginesie macierzy mo¿emy nie daæ rady okreœliæ, ¿e jest równa, mniejsza i wiêksza, wtedy mówimy ¿e jest ró¿na
	matrix& wczytaj(const std::string& nazwa);
};

