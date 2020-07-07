#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double  a1, a2, b1, b2, c1, c2, x, y;
	cout << "vvedite koeficienti:" << endl;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	y = ((a2*c1) - (a1*c2)) / ((b2*a1) - (a2*b1));
	x = ((-b2*y) - c2) / a2;
	cout << "x=" << x << "y=" << y << endl;

	system("pause");
	return 0;

}