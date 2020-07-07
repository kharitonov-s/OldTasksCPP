#include <iostream>
#include <ctime>

using namespace std;

void Gaus(double**& x, int n)
{
	//schetchiki
	int sch1 = 1, sch2 = 0; 
	int isch1 = 1, isch2 = 0;
	double tmp;

	for (int i = 0; i < (n - 1); ++i)
	{
		while (sch1 < n)
		{
			tmp = x[sch1][isch2];
			while (sch2 < n)
			{
				x[sch1][sch2] = (x[sch1][sch2] / tmp * x[i][isch2]) - x[i][sch2];
				++sch2;
			}
			++sch1;
			sch2 = isch2;
		}
		++isch1;
		++isch2;
		sch1 = isch1;
		sch2 = isch2;
	}
}

double det(double** x, int n)
{
	double Det = 1;

	Gaus(x, n);

	for (int i = 0; i < n; ++i)
	{
		Det *= x[i][i];
	}
	return Det;
}

int main()
{
	srand(time(NULL));
	int n;
	cout << "Vvedite chislo strok, stolbtsov:" << endl;
	cin >> n;
	cout << endl;

	double **matrix = new double*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[n];
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = rand() % 9 + 1;
			cout << matrix[i][j] << "\t";
		}
		cout <<  endl;
	}

	Gaus(matrix, n);
	cout << endl << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		delete[]matrix[i];
		cout << endl;
	}

	delete[]matrix;

	system("pause");
	return 0;
}