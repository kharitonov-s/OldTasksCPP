#include <iostream>

using namespace std;

int sum(int x, int y)
{
	return x + y;
}

int main()
{
	cout << "Hello world" << endl;
	int(*sumP) (int, int);
	sumP = sum;
	cout << sum(1, 2) << endl;
	cout << sumP(3, 4) << endl;

	system("pause");
	return 0;
}