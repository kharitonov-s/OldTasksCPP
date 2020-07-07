#include <iostream>

using namespace std;
int main()
{
	cout << "Vvedite x1, x2 (0<x<=2), shag, i tochost'." << endl;
	double x1, x2, dx, epsilon, sum;
	int n;
	cin >> x1 >> x2 >> dx >> epsilon;

	n = 0;
	sum = 0;

	cout << "x" << "\t" << "y" << endl;

	while (x1 <= x2)
	{
		cout << x1 << "\t";
		while (((pow(-1, n)*pow((x1 - 1), (n + 1))) / (n + 1)) >= epsilon)
		{
			sum += ((pow(-1, n)*pow((x1 - 1), (n + 1))) / (n + 1));
			++n;
		}
		cout << sum << endl;
		n = 0;
		sum = 0;
		x1 = x1 + dx;
	}

	system("pause");
	return 0;
}