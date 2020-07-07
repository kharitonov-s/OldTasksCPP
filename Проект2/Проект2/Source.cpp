#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x1, y1, x2, y2, x3, y3, p, s, x01, y01, x02, y02, x03, y03;
	cout << "VVedite koordinati vershin treugol'nika" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	x01 = x2 - x1;
	y01 = y2 - y1;
	x02 = x3 - x2;
	y02 = y3 - y2;
	x03 = x1 - x3;
	y03 = y1 - y3;
	p = (sqrt(x01*x01 + y01*y01)) + (sqrt(x02*x02 + y02*y02)) + (sqrt(x03*x03 + y03*y03));
	s = 0.5*(sqrt(x03*x03 + y03*y03))*((sqrt(x02*x02 + y02*y02)) + (sqrt(x03*x03 + y03*y03) / 2));
	cout << "Ploshad': " << s << " Perimetr: " << p << endl;
	system("pause");
	return 0;

}