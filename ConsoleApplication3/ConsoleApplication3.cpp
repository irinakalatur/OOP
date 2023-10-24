#include<iostream>
using namespace std;

void func(double** matrix, int n, int s, int* path, double* last_r)
{
	int i, j;
	int* v;
	double* r;
	bool* mark;
	double temp;
	bool stop;
	double min; int min_i;
	v = new int[n];
	r = new double[n];
	mark = new bool[n];

	for (i = 0; i < n; i++)
	{
		path[i] = s;
		last_r[i] = 0;//заполняем вектор расстояний
		//устанавливаем постоянную метку на стартовую вершину
		//на остальные временные
		if (i == s) mark[i] = true;
		else mark[i] = false;
	}

	//шаг цикла
	do
	{
		stop = true;
		for (j = 0; j < n; j++)
		{
			//если вершина достижима из стартовой и метка временная
			if (matrix[s][j] != 0 && mark[j] == false)
			{
				v[j] = j;//запоминаем достижимую вершину
				r[j] = matrix[s][j];//расстояние от старта до вершины
			}
			else v[j] = -1;
		}
		//пересчитываем расстояние
		for (i = 0; i < n; i++)
		{
			if (v[i] != -1 && mark[i] == false)
			{
				temp = r[i] + last_r[s];
				if (temp < last_r[i] || last_r[i] == 0)
				{
					path[i] = s;
					last_r[i] = temp;
				}
			}
		}
		//находим минимальное расстояние из вершин с временными метками
		for (i = 0; i < n; i++)
		{
			if (last_r[i] != 0 && mark[i] == false)
			{
				min = last_r[i];
				min_i = i;
				break;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (last_r[i] < min && last_r[i] != 0 && mark[i] == false)
			{
				min = last_r[i];
				min_i = i;
			}
		}

		//новая стартовая метка
		s = min_i;
		mark[s] = true;

		//проверяем, все ли вершины с постоянными метками
		for (i = 0; i < n; i++)
		{
			if (mark[i] == false)
			{
				stop = false;
				break;
			}
		}
	} while (stop == false);

}

void main()
{
	setlocale(LC_ALL, "RUS");
	int n, s;
	cout << "Ввести количество вершин: ";
	cin >> n;
	cout << "Ввести стартовую вершину: ";
	cin >> s;
	s = s - 1;

	double** matrix;
	int i, j;
	int temp;
	matrix = new double* [n];
	for (i = 0; i < n; i++)
		matrix[i] = new double[n];

	cout << "\n*Если вершины не связанны введите 0*\n";
	for (i = 0; i < n; i++)
	{
		matrix[i][i] = 0;
		for (j = i + 1; j < n; j++) {
			cout << "Введите расстояние " << i + 1 << " - " << j + 1 << " : ";
			cin >> temp;
			matrix[i][j] = temp;
			matrix[j][i] = temp;
		}
	}

	int* path;
	path = new int[n];
	double* last_r;
	last_r = new double[n];
	func(matrix, n, s, path, last_r);

	//вывод минимальных расстояний
	for (i = 0; i < n; i++)
	{
		cout << "\nМинимальное расстояние от " << s + 1 << " до " << i + 1 << " : ";
		cout << last_r[i];
	}
	cout << endl;

	//вывод путей
	for (int k = 0; k < n; k++)
	{
		cout << "\nМинимальный путь от " << s + 1 << " до " << k + 1 << " : ";
		temp = path[k];
		cout << k + 1 << " - " << temp + 1;
		while (temp != s)
		{
			for (i = 0; i < n; i++)
			{
				if (i == temp)
				{
					temp = path[i];
					cout << " - " << temp + 1;
					if (temp == s) break;
				}
			}
		}
	}
	cout << endl;
}
