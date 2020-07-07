#include <iostream>
#include <ctime> 

using namespace std;

int** Peremnozh(int** x, int** y, int m, int q,int j,int i)
{
	int** mat3 = new int *[i];

	for (int i = 0; i < m; i++)
		mat3[i] = new int[j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < q; j++)
		{
			mat3[i][j] = 0;
			for (int k = 0; k < q; k++)
				mat3[i][j] += (x[i][k] * y[k][j]);
		}

	return mat3;
	/*for (int i = 0; i < q;++i)
		delete[] mat3[i];
	delete[] mat3;*/
}

int main()
{
	int n, m, q, i, j,z;
	setlocale(LC_CTYPE, "rus");
	cout << "Введите кол-во столбцов в первой матрице ";
	cin >> n;
	cout << "Введите кол-во строк в первой матрице ";
	cin >> m;
	cout << "Введите кол-во столбцов во второй матрице ";
	cin >> q;
	cout << "Введите кол-во строк второй матрицы ";
	cin >> z;
	int **mat1 = new int *[m];
	for (i = 0; i < m; i++)
		mat1[i] = new int[n];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			mat1[i][j] = rand() % 9 + 1;
		}
	}
	cout << "Первая" << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			cout <<  mat1[i][j]<<" ";
		cout << endl;
	}
	int **mat2 = new int *[z];
	for (i = 0; i < z; i++)
		mat2[i] = new int[q];
	for (i = 0; i < z; i++)
	{
		for (j = 0; j < q; j++)
		{
			mat2[i][j] = rand() % 9 + 1;
		}
	}
	cout << "Вторая" << endl;
	for (i = 0; i < z; i++)
	{
		for (j = 0; j < q; j++)
			cout <<  mat2[i][j]<< " ";
		cout << endl;
	}

	int** mat3 = new int *[m];

	for (int i = 0; i < m; i++)
		mat3[i] = new int[q];

	if (n != z)
	{
		cout << "Строки не равны столбцам" << endl;
	}
	else
		mat3 = Peremnozh(mat1, mat2,m,q,j,i);

	cout << "Результат умножения:" << endl;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < q; j++)
			cout << mat3[i][j] << " ";
		cout << endl;
	}
			
	for (int i = 0; i < n; ++i)
		delete[] mat1[i];
	delete[] mat1;

	for (int i = 0; i < j; ++i)
		delete[] mat2[i];
	delete[] mat2;

	for (int i = 0; i < q;++i)
		delete[] mat3[i];
	delete[] mat3;

	system("pause");
	return 0;
}