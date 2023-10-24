#include<iomanip>
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
using namespace std;
//прототип функции для ввода динамической матрицы
double** inputm(int n, int m);
//прототип функции для вывода динамической матрицы
void outputm(double** a, int n, int m);
//прототип функции для определения количества столбцов, содержащих хотя бы один нулевой элемент
int kol(double** a, int n, int m);
//прототип функции для определения строки, в которой находится самая длинная серия одинаковых элементов
double* dlin(double** a, int n, int m, int& k);
//главная функция
void main()
{
	setlocale(LC_ALL, "Russian");
	//объявление переменных
	double** x;
	int n, m, ko;
	//ввод матрицы
	cout << "\n Ввести через пробел размер матрицы: \n";
	cin >> n >> m;
	cout << "\n Ввести матрицу: \n";
	x = inputm(n, m);
	//вывод матрицы
	cout << "\n***Матрица***\n";
	outputm(x, n, m);
	//определение количества столбцов
	ko = kol(x, n, m);
	cout << "\n Количество столбцов, содержащих хотя бы один нулевой элемент: " << ko;
	//определение строки, в которой находится самая длинная серия одинаковых элементов
	cout << "\n Строка с самой длинной серией одинаковых элементов: ";
	double* z;
	int ka;
	z = dlin(x, n, m, ka);
	cout << ka;
	cout << endl;
}

//определение функции для ввода динамической матрицы
double** inputm(int n, int m)
{//объявление переменных
	int i, j;
	//выделение ОП под матрицу
	double** a;
	a = new double* [n];
	if (a == NULL)
	{
		cout << "\n не хватило ОП\n";
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		a[i] = new double[m];
		if (a[i] == NULL)
		{
			cout << "\n не хватило ОП\n";
			exit(1);
		}
	}
	//ввод
	for (i = 0; i < n; i++)
	{
		cout << "\n Ввести " << i << " строку:\n";
		for (j = 0; j < m; j++)
			cin >> a[i][j];
	}
	return a;
}
//определение функции для вывода динамической матрицы
void outputm(double** a, int n, int m)
{//объявление переменных
	int i, j;
	//вывод
	for (i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < m; j++)
			cout << setw(10) << a[i][j];
	}
}
//определение функции для определения количества столбцов, содержащих хотя бы один нулевой элемент
int kol(double** a, int n, int m)
{//объявление переменных
	int i, j;
	int k = 0;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i][j] == 0)
			{
				k++;
				break;
			}
		}
	}
	return k;
}
//определение функции для определения строки, в которой находится самая длинная серия одинаковых элементов
double* dlin(double** a, int n, int m, int& k)
{
	double* z;
	//выделение ОП под массив
	z = new double[n];
	//проверка
	if (z == NULL)
	{
		cout << "\nне хватило ОП";
		exit(1);
	}
	int i, j;
	for (i = 0; i < n; i++)
	{
		z[i] = 0;
		for (j = 0; j < m; j++)
			if (a[i][j] == a[i][j + 1]) z[i] = z[i] + 1;
	}
	k = 0;
	for (i = 0; i < n; i++)
		if (z[i] > k) k = i;
	return z;
}