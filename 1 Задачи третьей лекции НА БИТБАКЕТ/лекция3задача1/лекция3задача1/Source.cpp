#include <iostream>
#include <ctime> 
#include <cmath>
using namespace std;

void gauss(double**mat, int n)
{
	//Цикл для выбора ведущей строки
	for (int k = 0;k < n - 1;++k)
	{
		//Цикл по всем строчкам, которые ниже
	    double el_0 = mat[k][k];
		for (int i = k + 1;i < n;++i)
		{
			//Ведущий элемент в текущей строке
			double den_c = mat[i][k];
			//Цикл по элементам в строке
			for (int j = 0;j < n;++j)
				mat[i][j] = mat[i][j] * el_0 / den_c - mat[k][j];
		}
	}
}

int main(int n, double**argv)
{
	cout << "vvedite kol-vo strok, stolbcov" << endl;
	cin >> n;
	srand(time(NULL));
	double**mat = new double*[n];
	for (int i = 0;i < n;++i)
	{
		mat[i] = new double[n];
		for (int j = 0;j < n;++j)
		{
			mat[i][j] = rand() % 9 + 1;
			cout << mat[i][j] << " ";
		}
		cout << endl;
		
	}
	cout << endl;
	gauss(mat, n);
	for (int i = 0;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	delete[] mat;
	system("pause");
	return 0;
}
