#include "Matrix.h" //<-- plik nagłówkowy

matrix::matrix(void)  //<-- konstruktor domyślny bez alokacji pamięci
{
	n = 0;  //<-- rozmiar macierzy
	tab = nullptr;  //<-- wskaźnik do macierzy
}

matrix::matrix(int n)  //<-- konstruktor przeciążeniowy alokuje macierz o wymiarach n na n
{
	this->n = n; //<-- rozmiar macierzy
	tab = new int* [n];  //<-- wskaźnik do macierzy
	for (int i = 0; i < n; i++) //<-- pętla przechodząca przez elementy macierzy
	{
		tab[i] = new int[n];  //<-- przypisywanie elementu macierzy do elementu macierzy
		for (int j = 0; j < n; j++) //<-- pętla przechodząca przez elementy macierzy
		{
			tab[i][j] = 0; //<-- inicjalizacja elementu macierzy wartością 0
		}
	}
}
matrix::matrix(int n, int* t)  //<-- konstruktor przeci��eniowy alokuje pami�� i przepisuje dane z tabeli
{
	this->n = n; //<-- rozmiar macierzy
	tab = new int* [n];  //<-- wska�nik do macierzy
	for (int i = 0; i < n; i++)  //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[i] = new int[n];  //<-- nowa macierz
	}
	int k = 0; //<-- wska�nik do macierzy
	for (int i = 0; i < n; i++)  //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++)  //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] = t[k];  //<-- przypisanie elementu macierzy do elementu macierzy
			k++;  //<-- zwiększenie wskaźnika
		}
	}
}
matrix::matrix(matrix& m) //<-- konstruktor kopiuj�cy
{
	n = m.n; //<-- przypisanie elementu macierzy do elementu macierzy
	tab = new int* [n]; //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[i] = new int[n]; //<-- nowa macierz
	}
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] = m.tab[i][j]; //<-- przypisanie elementu macierzy do elementu macierzy
		}
	}
}
matrix::~matrix(void) //<-- destruktor
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		delete[] tab[i]; //<-- usuwanie elementu macierzy
	}
	delete[] tab; //<-- usuwanie elementu macierzy
}
matrix& matrix::alokuj(int n) //<-- je�li macierz nie ma zaalokowanej pami�ci to j� alokuje w wielko�ci n na n, je�li macierz ma zaalokowan� pami�� to sprawdza czy rozmiar alokacji jest r�wny zdeklarowanemu rozmiarowi.W przypadku gdy tej pami�ci jest mniej, pami�� ma zosta� zwolniona i zaalokowana ponownie w ��danym rozmiarze. W przypadku gdy tej pami�ci jest wi�cej pozostawi� alokacj� bez zmian.
{
	if (tab == nullptr) //<-- sprawdzenie czy tab jest r�wne nullptr
	{
		this->n = n; //<-- przypisanie elementu macierzy do elementu macierzy
		tab = new int* [n]; //<-- nowa macierz
		for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i] = new int[n]; //<-- nowa macierz
		}
	}
	else //<-- je�li tab nie jest r�wne nullptr
	{
		if (this->n < n)  //<-- sprawdzenie czy n jest wi�ksze od this->n
		{
			for (int i = 0; i < this->n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				delete[] tab[i]; //<-- usuwanie elementu macierzy
			}
			delete[] tab; //<-- usuwanie elementu macierzy
			this->n = n; //<-- przypisanie elementu macierzy do elementu macierzy
			tab = new int* [n];		//<-- nowa macierz
			for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				tab[i] = new int[n]; //<-- nowa macierz
			}
		}
		else if (this->n > n)  //<-- sprawdzenie czy n jest mniejsze od this->n
		{
			for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				delete[] tab[i]; //<-- usuwanie elementu macierzy
			}
			delete[] tab; //<-- usuwanie elementu macierzy
			this->n = n; //<-- przypisanie elementu macierzy do elementu macierzy
			tab = new int* [n]; //<-- nowa macierz
			for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				tab[i] = new int[n]; //<-- nowa macierz
			}
		}
		else  //<-- sprawdzenie czy n jest r�wne this->n
		{
			for (int i = 0; i < this->n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				delete[] tab[i]; //<-- usuwanie elementu macierzy
			}
			delete[] tab; //<-- usuwanie elementu macierzy
			this->n = n; //<-- przypisanie elementu macierzy do elementu macierzy 
			tab = new int* [n]; //<-- nowa macierz
			for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				tab[i] = new int[n]; //<-- nowa macierz
			}
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::wstaw(int x, int y, int wartosc) //<-- wiersz, kolumna, warto��
{
	tab[x][y] = wartosc; //<-- przypisanie elementu macierzy do elementu macierzy
	return *this; //<-- zwracamy macierz
}
int matrix::pokaz(int x, int y) //<-- zwraca warto�� elementu x, y
{
	return tab[x][y]; //<-- zwracamy element macierzy
}
matrix& matrix::odwroc(void) //<-- zamienia wiersze z kolumnami
{
	int** temp = new int* [n]; //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		temp[i] = new int[n]; //<-- nowa macierz
	}
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp[i][j] = tab[j][i]; //<-- zamiana wierszy z kolumnami
		}
	}
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		delete[] tab[i]; //<-- usuwanie elementu macierzy
	}
	delete[] tab; //<-- usuwanie elementu macierzy
	tab = temp; //<-- przypisanie elementu macierzy do elementu macierzy
	return *this; //<-- zwracamy macierz
}
matrix& matrix::losuj(void) //<-- wype�niamy cyframi od 0 do 9 wszystkie elementy macierzy
{
	srand(time(NULL)); //<-- losowanie
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] = rand() % 10; //<-- losowanie elementu macierzy
		}
	}
	return *this;
}
matrix& matrix::losuj(int x) //<-- wype�niamy cyframi od 0 do 9 elementy macierzy. Zmienna x okre�la ile cyfr b�dziemy losowa�. Nast�pnie algorytm losuje, w kt�re miejsca wstawi wylosowane cyfry
{
	srand(time(NULL)); //<-- losowanie
	for (int i = 0; i < x; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[rand() % n][rand() % n] = rand() % 10; //<-- losowanie elementu macierzy
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::diagonalna(int* t) //<-- po przek�tnej s� wpisane dane z tabeli, a pozosta�e elementy s� r�wne 0
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[i][i] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::diagonalna_k(int k, int* t) //<-- po przek�tnej s� wpisane dane z tabeli, a pozosta�e elementy s� r�wne 0. Parametr k mo�e oznacza� : 0 - przek�tna przechodz�ca przez �rodek (czyli tak jak metoda diagonalna), cyfra dodatnia przesuwa diagonaln� do g�ry macierzy o podan� cyfr�, cyfra ujemna przesuwa diagonaln� w d� o podan� cyfr�
{
	if (k == 0) //<-- sprawdzenie czy k jest r�wne 0
	{
		for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][i] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
		}
	}
	else if (k > 0) //<-- sprawdzenie czy k jest wi�ksze od 0
	{
		for (int i = 0; i < n - k; i++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][i + k] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
		} 
	}
	else //<-- sprawdzenie czy k jest mniejsze od 0
	{ 
		for (int i = 0; i < n + k; i++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i - k][i] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
		} 
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::kolumna(int x, int* t) //<-- przepisuje dane z tabeli do kolumny, kt�r� wskazuje zmienna x
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[i][x] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
	}
	return *this;	//<-- zwracamy macierz
}
matrix& matrix::wiersz(int y, int* t) //<-- przepisuje dane z tabeli do wiersza, kt�ry wskazuje zmienna x
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		tab[y][i] = t[i]; //<-- przypisanie elementu macierzy do elementu macierzy
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::przekatna(void) //<-- uzupełnia macierz: 1-na przekątnej, 0-poza przekątną,
{
	for (int i = 0; i < n; i++) //<-- pętla przechodząca przez elementy macierzy
	{
		tab[i][i] = 1; //<-- przypisanie 1 do elementu macierzy
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::pod_przekatna(void) //<-- uzupełnia macierz: 1-pod przekątną, 0-nad przekątną i po przekątnej,
{
	for (int i = 0; i < n; i++) //<-- pętla przechodząca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- pętla przechodząca przez elementy macierzy
		{
			if (i > j) //<-- sprawdzenie czy i jest większe od j
			{
				tab[i][j] = 1; //<-- przypisanie 1 do elementu macierzy
			}
			else //<-- jeśli i nie jest większe od j
			{
				tab[i][j] = 0; //<-- przypisanie 0 do elementu macierzy
			}
		}
	}
	return *this; //<-- zwracamy macierz
} 
matrix& matrix::nad_przekatna(void) //<-- uzupełnia macierz: 1-nad przekątną, 0-pod przekątną i po przekątnej,
{
	for (int i = 0; i < n; i++) //<-- pętla przechodząca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- pętla przechodząca przez elementy macierzy
		{
			if (i < j) //<-- sprawdzenie czy i jest mniejsze od j
			{
				tab[i][j] = 1; //<-- przypisanie 1 do elementu macierzy
			}
			else //<-- jeśli i nie jest mniejsze od j
			{
				tab[i][j] = 0; //<-- przypisanie 0 do elementu macierzy
			}
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::szachownica(void) //<-- uzupelnia macierz w ten spos�b dla n=4: 0101 1010 0101 1010
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		if (i % 2 == 0) // <-- sprawdzenie czy i jest parzyste
		{
			for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				if (j % 2 == 0) //<-- sprawdzenie czy j jest parzyste
				{
					tab[i][j] = 0; //<-- przypisanie 0 do elementu macierzy
				}
				else //<-- je�li j nie jest parzyste
				{
					tab[i][j] = 1; //<-- przypisanie 1 do elementu macierzy
				}
			}
		}
		else //<-- je�li i nie jest parzyste
		{
			for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				if (j % 2 == 0) //<-- sprawdzenie czy j jest parzyste
				{
					tab[i][j] = 1; //<-- przypisanie 1 do elementu macierzy
				}
				else //<-- je�li j nie jest parzyste
				{
					tab[i][j] = 0; //<-- przypisanie 0 do elementu macierzy
				}
			}
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::operator+(matrix& m) //<-- dodawanie macierzy do macierzy
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] + m.tab[i][j]; //<-- dodanie elementu macierzy do elementu macierzy
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator*(matrix& m) //<-- mno�enie macierzy przez macierz
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = 0; //<-- zerowanie elementu macierzy
			for (int k = 0; k < n; k++) //<-- p�tla przechodz�ca przez elementy macierzy
			{
				temp->tab[i][j] += tab[i][k] * m.tab[k][j]; //<-- mno�enie elementu macierzy przez element macierzy
			}
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator+(int a) //<-- dodawanie liczby do macierzy
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{ 
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] + a; //<-- dodanie elementu macierzy do a
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator*(int a) //<-- mno�enie macierzy przez liczb�
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] * a; //<-- mno�enie elementu macierzy przez a
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator-(int a) //<-- odejmowanie liczby od macierzy
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] - a; //<-- odejmowanie elementu macierzy od a
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix operator+(int a, matrix& m) //<-- dodawanie liczby do macierzy
{
	matrix temp(m.n); //<-- nowa macierz
	for (int i = 0; i < m.n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < m.n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp.tab[i][j] = m.tab[i][j] + a; //<-- dodanie elementu macierzy do a
		}
	}
	return temp; //<-- zwracamy macierz
}
matrix operator*(int a, matrix& m) //<-- mno�enie macierzy przez liczb�
{
	matrix temp(m.n); //<-- nowa macierz
	for (int i = 0; i < m.n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < m.n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp.tab[i][j] = m.tab[i][j] * a; //<-- mno�enie elementu macierzy przez a
		}
	}
	return temp; //<-- zwracamy macierz
}
matrix operator-(int a, matrix& m) //<-- odejmowanie macierzy od liczby
{
	matrix temp(m.n); //<-- nowa macierz
	for (int i = 0; i < m.n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < m.n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp.tab[i][j] = m.tab[i][j] - a; //<-- odejmowanie elementu macierzy od a
		}
	}
	return temp; //<-- zwracamy macierz
}
matrix& matrix::operator++(int) //<-- wszystkie liczby powi�kszone o 1
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] + 1; //<-- powi�kszenie elementu macierzy o 1
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator--(int) //<-- wszystkie liczby pomniejszone o 1
{
	matrix* temp = new matrix(n); //<-- nowa macierz
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			temp->tab[i][j] = tab[i][j] - 1; //<-- pomniejszenie elementu macierzy o 1
		}
	}
	return *temp; //<-- zwracamy macierz
}
matrix& matrix::operator+=(int a) //<-- ka�dy element w macierzy powi�kszamy o „a”
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] += a; //<-- powi�kszenie elementu macierzy o a
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::operator-=(int a) //<-- ka�dy element w macierzy pomniejszamy o „a”
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] -= a; //<-- pomniejszenie elementu macierzy o a
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::operator*=(int a) //<-- ka�dy element w macierzy mno�ymy o „a”
{
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] *= a; //<-- mno�enie elementu macierzy przez a
		}
	}
	return *this; //<-- zwracamy macierz
}
matrix& matrix::operator+=(double a) //<-- wszystkie cyfry s� powi�kszone o cz�� ca�kowit� z wpisanej cyfry
{
	int b = a; //<-- zmienna b przechowuje cz�� ca�kowit� z wpisanej cyfry
	for (int i = 0; i < n; i++) //<-- p�tla przechodz�ca przez elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla przechodz�ca przez elementy macierzy
		{
			tab[i][j] += b; //<-- dodanie cz�ci ca�kowitej do elementu macierzy
		}
		
	}
	return *this; //<-- zwracamy macierz
}
std::ostream& operator<<(std::ostream& o, matrix& m) //<-- wypisanie macierzy
{
	for (int i = 0; i < m.n; i++) //<-- p�tla wypisuj�ca elementy macierzy
	{
		for (int j = 0; j < m.n; j++) //<-- p�tla wypisuj�ca elementy macierzy
		{
			o << m.tab[i][j] << " "; //<-- wypisanie elementu macierzy
		}
		o << std::endl; //<-- przej�cie do nowej linii
	}
	return o; //<-- zwracamy strumie� wyj�ciowy
}
bool matrix::operator==(const matrix& m) //<-- sprawdza, czy ka�dy element macierzy spe�nia r�wno�� ??(??, ??) = ??(??, ??) A = | 1 2 | B = | 1 2| |3 4| |3 4 | je�li nie, to nie mo�emy m�wi�, �e macierze s� r�wne
{
	if (n != m.n)  //<-- sprawdzenie czy macierze maj� taki sam rozmiar
	{
		return false; //<-- je�li nie to zwracamy false
	}
	for (int i = 0; i < n; i++) //<-- p�tla sprawdzaj�ca elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla sprawdzaj�ca elementy macierzy
		{
			if (tab[i][j] != m.tab[i][j])	//<-- sprawdzenie czy elementy s� r�wne
			{
				return false; //<-- je�li nie to zwracamy false
			}
		}
	}
	return true; //<-- je�li wszystkie elementy s� r�wne to zwracamy true
}
bool matrix::operator>(const matrix& m) //<-- operator wi�kszo�ci sprawdza, czy ka�dy element macierzy spe�nia nier�wno�� ??(??, ??) > ??(??, ??).Je�li tak, to mo�emy powiedzie�, �e macierz jest wi�ksza, w przeciwnym wypadku nie mo�emy stwierdzi�,�e macierz jest wi�ksza.
{
	if (n != m.n)  //<-- sprawdzenie czy macierze maj� taki sam rozmiar
	{
		return false; //<-- je�li nie to zwracamy false
	}
	for (int i = 0; i < n; i++) //<-- p�tla sprawdzaj�ca elementy macierzy
	{
		for (int j = 0; j < n; j++)  //<-- p�tla sprawdzaj�ca elementy macierzy
		{
			if (tab[i][j] <= m.tab[i][j]) //<-- sprawdzenie czy elementy s� wi�ksze od siebie
			{
				return false;  //<-- je�li nie to zwracamy false
			}
		}
	}
	return true;  //<-- je�li wszystkie elementy s� wi�ksze to zwracamy true
}
bool matrix::operator<(const matrix& m)  //<-- tak jak wy�ej tylko operator mniejszo�ci. Na marginesie macierzy mo�emy nie da� rady okre�li�, �e jest r�wna, mniejsza i wi�ksza, wtedy m�wimy �e jest r�na
{
	if (n != m.n)  //<-- sprawdzenie czy macierze maj� taki sam rozmiar
	{
		return false;  //<-- je�li nie to zwracamy false
	}
	for (int i = 0; i < n; i++)  //<-- p�tla sprawdzaj�ca elementy macierzy
	{
		for (int j = 0; j < n; j++) //<-- p�tla sprawdzaj�ca elementy macierzy
		{
			if (tab[i][j] >= m.tab[i][j]) //<-- sprawdzenie czy elementy s� mniejsze od siebie
			{
				return false;  //<-- je�li nie to zwracamy false
			}
		}
	}
	return true; //<-- je�li wszystkie elementy s� mniejsze to zwracamy true
}
matrix& matrix::wczytaj(const std::string& nazwa)  //<-- wczytuje macierz z pliku o nazwie „nazwa”
{
	std::ifstream plik(nazwa);  //<-- otwarcie pliku
	if (!plik.is_open())  //<-- sprawdzenie czy plik zosta� otwarty
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl; //<-- komunikat o b��dzie
		return *this;  //<-- zwr�cenie macierzy
	}
	int n;  //<-- rozmiar macierzy
	plik >> n; //<-- wczytanie rozmiaru macierzy
	this->alokuj(n);  //<-- alokacja pami�ci
	if (n <= 0)  //<-- sprawdzenie czy rozmiar macierzy jest wi�kszy od zera
	{
		std::cout << "Niepoprawny rozmiar macierzy" << std::endl; //<-- komunikat o b��dzie
		plik.close();  //<-- zamkni�cie pliku
		return *this;  //<-- zwr�cenie macierzy
	}
	for (int i = 0; i < n; i++)   // <--- Petla wczytujaca wartosci do macierzy
	{
		for (int j = 0; j < n; j++) // <--- Petla wczytujaca wartosci do macierzy
		{
			plik >> tab[i][j]; // <--- Wczytanie wartosci do macierzye
		}
	}

	plik.close(); //<-- zamkni�cie pliku
	return *this; //<-- zwr�cenie macierzy
}
