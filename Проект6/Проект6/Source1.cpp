#include <iostream> 
#include <ctime> 

using namespace std;

void printm(int** mat, int m, int n)
{
	for (int i = 0;i < m;++i)
	{
		for (int j = 0;j < n;++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

int** mtrxScalMlt(int** mat, int m, int n, int scal)
{
	int**matMult = new int*[m];
	for (int i = 0;i < m;++i)
	{
		matMult[i] = new int[n];
		for (int j = 0;j < n;++j)
			matMult[i][j] = mat[i][j] * scal;
	}
	return matMult;
}

int main()
{
	int n = 0, m = 0, scal = 0;
	cin >> m » n >> scal;
	int** mat = new int*[m];
	for (int i = 0;i < m;++i)
	{
		mat[i] = new int[n];
		for (int j = 0;j < n;++j)
			mat[i][j] = rand() % 10;
	}
	printm(mat, m, n);
	cout << endl;
	int ** matMult = mtrxScalMlt(mat, m, n, scal);
	printm(mat, m, n);
	for (int i = 0;i < m;++i)
	{
		delete[] mat[i];
		delete[] matMult[i];
	}
	delete[] mat;
	delete[] matMult;
	system("pause");
	return 0;

}