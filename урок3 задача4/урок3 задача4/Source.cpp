#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	int x = 0;
	int max = 0;
	int y = 0;
	int min = 0;
	srand(time(NULL));
	int n ;
	int f = 0;
	cin >> n;
	double **mat = new double*[n];
	for (int i = 0; i < n; ++i)
	{
		mat[i] = new double[n];
		for (int j = 0; j < n; ++j)
		{
			mat[i][j] = rand() % 10;
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
	{

		min = mat[i][0];
		for (int j = 0; j < n; ++j)
		{
			max = mat[0][j];
			if (min > mat[i][j])
			{
				min = mat[i][j];
				x = j;
			}
			for (int k = 0; k < n; ++k)
			{
				if (max < mat[k][j])
					max = mat[k][j];
				y = i;
			}
		}
		if (min == max)
		{
			cout << min << "[" << y << "]" << "[" << x << "]" << endl;
			f = 1;
		}
	}

	if(f==0)
		cout << "sedlovoi tochki net" << endl;
	
	
	for (int i = 0; i < n; ++i)
	{
		delete[]mat[i];
	}
	delete[]mat;
	system("pause");
	return 0;
}