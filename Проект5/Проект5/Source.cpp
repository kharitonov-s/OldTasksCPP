#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUS");
	int A = 1;
	double B = 6.5;
	cout << "значение A= " << A;
	cout << "адресс A= " << &A << endl;
	cout << " значение B=" << B;
	cout << " адресс B=" << &B << endl;
	system("pause");
	return 0;
	


}