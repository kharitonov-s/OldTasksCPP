#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int n, i=1, j=0;
	int l = 0, k = 0;
	cin >> n;
	double **a = new double *[n];
	for (i = 0;i < n;++i)
	{
		a[i] = new double[n];
		for (j = 0;j < n;++j)
		{
			a[i][j] = 1 + rand() % (9);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 1;i < n;i++)
	{
		
		while (j <= n)
		{
			j = j++;
			a[i][j] = a[i][j] - ((a[i][0] * a[0][j]) / a[0][j]);
		}
		a[i][j] = a[i][j] - ((a[i][0] * a[0][j]) / a[0][j]);
	}
    cout<< endl;
	for (i = 0;i < n;++i)
	{
		for (j = 0;j < n;++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;

}