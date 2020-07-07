#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

/*void transpon(double** mat, int n,int m)
{
	//int f = 0;
	/*for (int k = 0;k < n;++k)
	{
		for (int i = f;i < n;++i)
		{
			for (int j = i;j < m;++j)
			{
				if (i == j)
				{
					continue;
				}
				mat[i][j] = mat[i][j] + mat[j][i];
				mat[j][i] = mat[i][j] - mat[j][i];
				mat[i][j] = mat[i][j] - mat[j][i];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < m; ++j)
		{
			cout << i << " " << j << endl;
			mat[i][j] = mat[i][j] + mat[j][i];
			mat[j][i] = mat[i][j] - mat[j][i];
			mat[i][j] = mat[i][j] - mat[j][i];
		}
	}
}*/

double** transpon2(double** mat, int n, int m)
{
	int f = 0;

	double** result = new double*[m];
	for (int i = 0; i < m; i++) {
		result[i] = new double[n];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			result[i][j] = mat[j][i];
		}
	}
	return result;
}

int main()
{
	int n,m;
	cout << "vvedite kol-vo strok, stolbcov" << endl;
	cin >> n >> m;
	srand(time(NULL));
	double**mat = new double*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new double[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = rand() % 9 + 1;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	double**result = new double*[m];
	for (int i = 0; i < m; i++)
		result[i] = new double[n];

	result = transpon2(mat,n,m);

	for (int i = 0;i < m;++i)
	{
		for (int j = 0;j < n;++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n;++i)
		delete[] mat[i];
	delete[] mat;
	for (int i = 0; i < m;++i)
		delete[] result[i];
	delete[] result;
	system("pause");
	return 0;
}
