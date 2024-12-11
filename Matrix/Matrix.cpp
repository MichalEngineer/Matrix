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