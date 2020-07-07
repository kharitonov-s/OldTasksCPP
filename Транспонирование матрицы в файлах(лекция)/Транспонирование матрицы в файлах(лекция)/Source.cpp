#include<iostream>
#include<fstream>
using namespace std;
int**mat(int**x, int n)
{
	int**y = new int*[n];
	for (int i = 0;i < n;++i)
	{
		y[i] = new int[n];
		for (int j = 0;j < n;++j)
		{
			cout << x[i][j] << " ";
		}
	}
	return 0;
}

int main()
{
	int n = 0;
	char str[32];
	double**x = new double*[n];
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Read file error!" << endl;
		system("pause");
		return 1;
	}

	ofstream out;
	out.open("out.txt");

	if (!out.is_open())
	{
		cout << "Write file Error" << endl;
		system("pause");
		return 1;
	}

	while (!in.eof())
	{
		
		for (int i = 0;i < 5;++i)
		{
			for (int j = 0;j < 5;++j)
			{
				in >> x[i][j];
			}
		}
	}

	while (!out.eof())
	{

		for (int i = 0;i < 5;++i)
		{
			for (int j = 0;j < 5;++j)
			{
				cout << x[j][i] << endl;
			}
		}
	}
	system("pause");
	return 0;
}