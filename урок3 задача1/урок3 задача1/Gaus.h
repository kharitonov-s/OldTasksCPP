#include <iostream>

using namespace std;
void GaussianElimination(double**& x, int n)
{
	int counter1 = 1, counter2 = 0;
	int icounter1 = 1, icounter2 = 0;
	double tmp;

	for (int i = 0; i < (n - 1); ++i)
	{
		while (counter1 < n)
		{
			tmp = x[counter1][icounter2];
			while (counter2 < n)
			{
				x[counter1][counter2] = (x[counter1][counter2] / tmp * x[i][icounter2]) - x[i][counter2];
				++counter2;
			}
			++counter1;
			counter2 = icounter2;
		}
		++icounter1;
		++icounter2;
		counter1 = icounter1;
		counter2 = icounter2;
	}
}

double det(double** x, int n)
{
	double Determinant = 1;

	GaussianElimination(x, n);

	for (int i = 0; i < n; ++i)
	{
		Determinant *= x[i][i];
	}

	return Determinant;
}
