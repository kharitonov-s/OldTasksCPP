#include <iostream>

using namespace std;
int main()
{
	cout << "vvedite k, p, r" << endl;
	double k, p, r;
	cin >> k >> p >> r;
	cout << endl;

	p = 1 + (p / 100);

	if (k > ((k * p) - r))
	{
		int years = 0;
		while (k > 0)
		{
			k = (k * p) - r;
			++years;
		}
		cout << years << " kol-vo let" << endl;
	}
	else
	{
		cout << "Kredit ne budet pogashen" << endl;
	}

	system("pause");
	return 0;
}