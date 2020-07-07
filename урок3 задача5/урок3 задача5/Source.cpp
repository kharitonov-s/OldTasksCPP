#include <iostream>
#include <ctime>

using namespace std;

bool Check(int **x, int m, int n, int k) //m лини€, n  столбец
{
	int sch = 0;

	for (int i = 0; i < m; ++i) //проверка по лини€м
	{
		for (int j = 0; j < n; ++j)
		{
			if (x[i][j] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
		}
		sch = 0;
	}

	for (int i = 0; i < n; ++i) //проверка по стоблцам
	{
		for (int j = 0; j < m; ++j)
		{
			if (x[j][i] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
		}
		sch = 0;
	}

	int l;

	for (int i = (m - 1); i >= 0; --i) //проверка по побочным диагонал€м
	{
		l = i;
		for (int j = 0; j < n; ++j)
		{
			if (x[l][j] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
			if (l < (m - 1))
			{
				++l;
			}
			else
			{
				break;
			}
		}
		sch = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		l = i;
		for (int j = 0; j < m; ++j)
		{
			if (x[j][l] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
			if (l < (n - 1))
			{
				++l;
			}
			else
			{
				break;
			}
		}
		sch = 0;
	}

	for (int i = 0; i < n; ++i) //проверка по диагонал€м
	{
		l = i;
		for (int j = 0; j < m; ++j)
		{
			if (x[j][l] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
			if (l >= 0)
			{
				--l;
			}
			else
			{
				break;
			}
		}
		sch = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		l = i;
		for (int j = (n - 1); j >= 0; --j)
		{
			if (x[l][j] == 1)
			{
				++sch;
			}
			else
			{
				sch = 0;
			}
			if (sch >= k)
			{
				return true;
			}
			if (l < (m - 1))
			{
				++l;
			}
			else
			{
				break;
			}
		}
		sch = 0;
	}

	return false;
}

int main()
{
	srand(time(NULL));

	int m, n, k;
	cout << "Vvedite m, n, k" << endl;
	cin >> m >> n >> k;
	cout << endl;

	int **x = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		x[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			x[i][j] = rand() % 2;
			if (x[i][j] == 0)
			{
				cout << "O" << " ";
			}
			else
			{
				cout << "X" << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	if (Check(x, m, n, k))
	{
		cout << "Krestiki krasavchiki est' zhi!" << endl;
	}
	else
	{
		cout << "Noliki viigrali" << endl;
	}

	system("pause");
	return 0;
}