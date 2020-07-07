#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

//������� ��� ������ �������
void printm(double** mat, int n)
{
	for (int i = 0;i<n;++i)
	{
		for (int j = 0;j<n;++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


//����������� ������� ��� ����������
//������������ ������������� �������
//������� ���������� �� �������
double det(double** matrx, int n)
{
	if (n == 1)
	{
		return matrx[0][0];
	}

	double sum = 0;
	double **minor;

	int decr = 0;

	//���� ��� ������ �������� ��������
	//� 0-� �������
	for (int i = 0;i<n;++i)
	{
		//��� ������� �������� � �������
		//����� ������������ ��������������� �����
		minor = new double*[n - 1];
		//���� �� ���� ��������
		for (int j = 0;j<n;++j)
		{
			//���� ������� ������� -- ��� �������,
			//������� �������� ������� �������,
			//�� ������ decr = 1, � ��������� �� ���������
			//(������������� �� ��������� �������)
			if (j == i)
			{
				decr = 1;
				continue;
			}

			//������� ������ ��� ����� � ������
			//���� ����������� ����� �������,
			//�� ������ ��� ���������� � �����
			//����� ��������� �� �������,
			//��� ��� ��� ������ = n-1
			minor[j - decr] = new double[n - 1];
			//���� ��� ���������� ������ � ����� �����������
			//���������� � 1, ��� ��� 0-� ������� �����������
			for (int k = 1;k<n;++k)
			{
				//��������� � ������ ���������� � ����,
				//������� k-1
				//j-decr -- ��������� ������ �� �������,
				//���� ����������� ����� ������
				minor[j - decr][k - 1] = matrx[j][k];
			}
		}
		//��� ��������� �������� �������� decr
		decr = 0;
		//��������� ��������� � ����� �� �����������
		//det(minor,n-1) -- ����������� ����������
		//������������ ������
		sum += matrx[i][0] * pow(-1, i + 0)*det(minor, n - 1);

		for (int j = 0;j<n - 1;++j)
			delete[] minor[j];
		delete[] minor;
	}

	return sum;
}

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Hello World!" << endl;
	cin >> n;

	//�������� ���������� �������
	//������� nxn, ����������
	//���������� �������
	//�� 1 �� 9
	double **matrx = new double*[n];
	for (int i = 0;i<n;++i)
	{
		matrx[i] = new double[n];
		for (int j = 0;j<n;++j)
			matrx[i][j] = rand() % 9 + 1;
	}

	//����� �������
	printm(matrx, n);

	//������ � ����� ������������
	cout << det(matrx, n) << endl;

	system("pause");
	return 0;
}