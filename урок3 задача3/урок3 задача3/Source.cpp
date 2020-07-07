#include <iostream>
#include <ctime>

using namespace std;

int** minor(int** matrix, int row, int col, int n)
{
	int **minor = new int *[n];
	for (int i = 0, tmpRow = 0; i < n; i++, tmpRow++)
	{
		minor[i] = new int[n];
		if (i == row)
		{
			tmpRow++;
		}
		for (int j = 0, tmpCol = 0; j < n; j++, tmpCol++)
		{
			if (j == col)
			{
				tmpCol++;
			}
			minor[i][j] = matrix[tmpRow][tmpCol];
		}
	}
	return minor;
}

int determinant(int** matrix, int n)
{
	if (n == 1)
	{
		return matrix[0][0];
	}
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		result += matrix[0][i] * pow(-1, i) * determinant(minor(matrix, 0, i, n - 1), n - 1);
	}
	return result;
}


int main()
{
	srand(time(NULL));
	int n;
	cout << "Vvedite chislo strok, stolbtsov:" << endl;
	cin >> n;
	cout << endl;

	int **matrix = new int *[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = rand() % 9 + 1;
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}

	cout << endl << "Determinant = " << determinant(matrix, n) << endl;
	system("pause");
	return 0;
}

