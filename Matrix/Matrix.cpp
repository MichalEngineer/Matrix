#include "Matrix.h"


matrix::matrix(void)
{
	n = 0;
	tab = nullptr;
}
matrix::matrix(int n)
{
	this->n = n;
	tab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
}
matrix::matrix(int n, int* t)
{
	this->n = n;
	tab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = t[k];
			k++;
		}
	}
}
matrix::matrix(matrix& m)
{
	n = m.n;
	tab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = m.tab[i][j];
		}
	}
}
matrix::~matrix(void)
{
	for (int i = 0; i < n; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}
matrix& matrix::alokuj(int n)
{
	if (tab == nullptr)
	{
		this->n = n;
		tab = new int* [n];
		for (int i = 0; i < n; i++)
		{
			tab[i] = new int[n];
		}
	}
	else
	{
		if (this->n < n)
		{
			for (int i = 0; i < this->n; i++)
			{
				delete[] tab[i];
			}
			delete[] tab;
			this->n = n;
			tab = new int* [n];
			for (int i = 0; i < n; i++)
			{
				tab[i] = new int[n];
			}
		}
	}
	return *this;
}
matrix& matrix::wstaw(int x, int y, int wartosc)
{
	tab[x][y] = wartosc;
	return *this;
}
int matrix::pokaz(int x, int y)
{
	return tab[x][y];
}
matrix& matrix::odwroc(void)
{
	int** temp = new int* [n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = tab[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
	tab = temp;
	return *this;
}
matrix& matrix::losuj(void)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] = rand() % 10;
		}
	}
	return *this;
}
matrix& matrix::losuj(int x)
{
	srand(time(NULL));
	for (int i = 0; i < x; i++)
	{
		tab[rand() % n][rand() % n] = rand() % 10;
	}
	return *this;
}
matrix& matrix::diagonalna(int* t)
{
	for (int i = 0; i < n; i++)
	{
		tab[i][i] = t[i];
	}
	return *this;
}
matrix& matrix::diagonalna_k(int k, int* t)
{
	if (k == 0)
	{
		for (int i = 0; i < n; i++)
		{
			tab[i][i] = t[i];
		}
	}
	else if (k > 0)
	{
		for (int i = 0; i < n - k; i++)
		{
			tab[i][i + k] = t[i];
		}
	}
	else
	{
		for (int i = 0; i < n + k; i++)
		{
			tab[i - k][i] = t[i];
		}
	}
	return *this;
}
matrix& matrix::kolumna(int x, int* t)
{
	for (int i = 0; i < n; i++)
	{
		tab[i][x] = t[i];
	}
	return *this;
}
matrix& matrix::wiersz(int y, int* t)
{
	for (int i = 0; i < n; i++)
	{
		tab[y][i] = t[i];
	}
	return *this;
}
matrix& matrix::przekatna(void)
{
	for (int i = 0; i < n; i++)
	{
		tab[i][i] = 1;
	}
	return *this;
}
matrix& matrix::pod_przekatna(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				tab[i][j] = 1;
			}
			else
			{
				tab[i][j] = 0;
			}
		}
	}
	return *this;
}
matrix& matrix::nad_przekatna(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				tab[i][j] = 1;
			}
			else
			{
				tab[i][j] = 0;
			}
		}
	}
	return *this;
}
matrix& matrix::szachownica(void)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (j % 2 == 0)
				{
					tab[i][j] = 0;
				}
				else
				{
					tab[i][j] = 1;
				}
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (j % 2 == 0)
				{
					tab[i][j] = 1;
				}
				else
				{
					tab[i][j] = 0;
				}
			}
		}
	}
	return *this;
}
matrix& matrix::operator+(matrix& m)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] + m.tab[i][j];
		}
	}
	return *temp;
}
matrix& matrix::operator*(matrix& m)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				temp->tab[i][j] += tab[i][k] * m.tab[k][j];
			}
		}
	}
	return *temp;
}
matrix& matrix::operator+(int a)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] + a;
		}
	}
	return *temp;
}
matrix& matrix::operator*(int a)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] * a;
		}
	}
	return *temp;
}
matrix& matrix::operator-(int a)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] - a;
		}
	}
	return *temp;
}
matrix operator+(int a, matrix& m)
{
	matrix temp(m.n);
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			temp.tab[i][j] = m.tab[i][j] + a;
		}
	}
	return temp;
}
matrix operator*(int a, matrix& m)
{
	matrix temp(m.n);
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			temp.tab[i][j] = m.tab[i][j] * a;
		}
	}
	return temp;
}
matrix operator-(int a, matrix& m)
{
	matrix temp(m.n);
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			temp.tab[i][j] = m.tab[i][j] - a;
		}
	}
	return temp;
}
matrix& matrix::operator++(int)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] + 1;
		}
	}
	return *temp;
}
matrix& matrix::operator--(int)
{
	matrix* temp = new matrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp->tab[i][j] = tab[i][j] - 1;
		}
	}
	return *temp;
}
matrix& matrix::operator+=(int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] += a;
		}
	}
	return *this;
}
matrix& matrix::operator-=(int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] -= a;
		}
	}
	return *this;
}
matrix& matrix::operator*=(int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] *= a;
		}
	}
	return *this;
}
matrix& matrix::operator+=(double a)
{
	int b = a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tab[i][j] += b;
		}
	}
	return *this;
}
std::ostream& operator<<(std::ostream& o, matrix& m)
{
	for (int i = 0; i < m.n; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			o << m.tab[i][j] << " ";
		}
		o << std::endl;
	}
	return o;
}
bool matrix::operator==(const matrix& m)
{
	if (n != m.n)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] != m.tab[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
bool matrix::operator>(const matrix& m)
{
	if (n != m.n)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] <= m.tab[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
bool matrix::operator<(const matrix& m)
{
	if (n != m.n)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i][j] >= m.tab[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
matrix& matrix::wczytaj(const std::string& nazwa)
{
	std::ifstream plik(nazwa);
	if (!plik.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
		return *this;
	}
	plik >> n;
	tab = new int* [n];
	for (int i = 0; i < n; i++)
	{
		tab[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			plik >> tab[i][j];
		}
	}
	plik.close();
	return *this;
}
