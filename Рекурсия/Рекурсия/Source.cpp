#include <iostream>
#include <ctime>

using namespace std;

//n! = (n-1)!*n
// F(n) = F(n-1) + F(n-2);
// F(0) == 1
// F(1) == 1
// 1 1 2 3 5 8 13 21 34 ...
// 34/21 = ~ 1.618

//����������� ���������� ����������
double fact_rec(int n)
{
	cout << n << endl;
	//������������ ������
	if (n == 0 || n == 1)
		return 1;
	//��������
	return n*fact_rec(n - 1);
}

//����������� ���������� n-�� �����
//������������������ ���������
int fib_rec(int n, bool out)
{
	int fib = 0;
	if (n == 0 || n == 1)
	{
		fib = 1;
		if (out == true)
			cout << fib << " ";
		return fib;
	}

	if (out == true)
	{
		fib = fib_rec(n - 1, true) + fib_rec(n - 2, false);
		cout << fib << " ";
	}
	else
		fib = fib_rec(n - 1, false) + fib_rec(n - 2, false);

	return fib;
}

int main()
{
	cout << "Hello World!" << endl;
	double n = 0;
	cin >> n;
	cout << endl;
	clock_t start = clock();
	//    double fact = 1;
	//    for (int i=1;i<=n;++i)
	//        fact *= i; //fact = fact * i;

	//    cout << "Factorial iterative: "<< fact << endl;

	//    cout << "Factorial recursive: " << fact_rec(n)<<endl;
	int f = 0;
	int f_prev = 0;
	int f_prev_prev = 1;
	//���������
	cout << "Fibonacci iterative:" << endl;
	for (int i = 0;i<n;++i)
	{
		f = f_prev + f_prev_prev;
		f_prev_prev = f_prev;
		f_prev = f;

		cout << f << " ";
	}
	cout << endl << endl;
	cout << "Fibonacci recursive:" << endl;

	//����� ������������������ � �����
	//for (int i=0;i<n;++i)
	//    cout<<fib_rec(i)<<" ";

	//����� ������������������
	//����� ������ �������
	fib_rec(5, true);

	cout << endl;
	clock_t end = clock();
	double t = 1000 * (double)(end - start) / CLOCKS_PER_SEC;
	cout << t << endl;

	system("pause");
	return 0;
}
