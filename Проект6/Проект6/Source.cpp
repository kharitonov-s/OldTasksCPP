#include<iostream>
using namespace std;

/*int summ(int n,...)
{
	//int s = summ(3,1,2,5); тут первый аргумет (3) это кол-во следующих аргументов!
	int sum = 0;
	int *p = &n + 1;
	for (int i = 0;i < n;++i)
	{
		sum += *p;
		++p;
	}
	return sum;
}

int mult(int n, ...)
{
	int pr = 1;
	int *p = &n;

	while (*p != 0) // = while (*p); можно писать и так и так
	{
		pr *= *p;
		++p;
	}
	return pr;
}*/


int  main()
{
	//for (int i = 0, j = 0;i < 5;++i,j += 2)
	//{
	//	cout << i << " " << j << endl;
	//}

/*	double x = 0.1;
	// так-как у double есть погрешность, надо ввести int y, и умножить в цикле на 10
	int y = 0;
	cout.precision(32); // кол-во знаков (32) после запятой 
	while (x < 2)
	{
		cout << y << " " << abs(x - 1) << " " << abs((x - 1) >= 0.1)<<endl;
		x += 0.1;
		y = x * 10;
		abs(y - 10) >= 1;
	}*/
	void stat()
		static int c = 0;
		cout << ++c << endl;

		stat();
		stat();
	system("pause");
    return 0;
}