#include <ctime>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{

	setlocale(LC_ALL, "RUS");
	int x = 10;
	int *p = &x;
	cout << " " <<p<< endl;
	*p = 5;
	cout << " " << p << endl;
	const 
	system("pause");
	return 0;
}













/*#include <iostream>

int main()
{
	double a, b, c, d;

	std::cin >> a >> b >> c;
	d = b * b - 4 * a * c;

	std::cout << a << "x^2 + " << b << "x + " << c << " = 0\n"
		"D = " << d << " - " << (d < 0 ? "no roots\n" : "have roots\n");

	if (d >= 0)
		std::cout << "x1 = " << -b + sqrt(d) / 2 * a;
	if (d > 0)
		std::cout << ", x2 = " << -b - sqrt(d) / 2 * a << "\n";

	system("pause");
}*/