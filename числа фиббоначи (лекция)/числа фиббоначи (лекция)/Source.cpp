#include <iostream>

using namespace std;

//n!=(n-1)!*n
//f(n)=f(n-1)+f(n-2);
//f(0)=1; f(1)=1;
//1 1 2 3 5 8 13 21 34 ...
//34/21=-1,618

double fact_rec(int n)//recursivnoe vyshislenie n!
{
	cout << n << endl;
	if (n == 0 || n == 1)//elementarnye slychai
		return 1;

	return n*fact_rec(n - 1);//recursija
}

int fib_rec(int n)//recursivnoe vychislenie n-go chlena posled-ti Fibonacci
{
	int fib = 0;
	if (n == 0 || n == 1)
	{
		fib = 1;
		return fib;
	}

	fib = fib_rec(n - 1) + fib_rec(n - 2);
	return fib;
}


int main()
{
	double n = 0;
	cin >> n;
	cout << endl;

	/*
	double fact = 1;
	for (int i = 1; i <= n; ++i)
	fact *= i;//fact=fact*i
	cout << "Factorial iterative:" << fact << endl;
	cout << "Factorial recursive:" << fact_rec(n) << endl;
	*/
	/*
	int f = 0;
	int f_prev = 0;
	int f_prev_prev = 1;

	//Fibonacci_iterative

	for (int i = 1;i <= n;++i)
	{
	f = f_prev + f_prev_prev;
	f_prev_prev = f_prev;
	f_prev = f;
	cout << f << " ";

	}


	cout << endl;
	*/

	cout << "Fibonacci recursive" << endl;
	for (int i = 0; i < n; i++)
		cout << fib_rec(i);

	cout << endl;
	system("pause");
	return 0;
}