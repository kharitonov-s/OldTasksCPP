#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int binToDec(char *s) //двоичное в десятичное 
{
	int n, sum, deg, razr = 0;
	n = strlen(s);
	sum = 0;
	deg = 1;
	for (int i = n -1;i >= 0;--i) 
	{
		razr = (int)(s[i] - 48);
		sum += razr*deg;
		deg *= 2;
	}
	return sum;
}
	
int main()
{
	char s[32];
	cin >> s;

	cout << binToDec(s) << endl;

	system("pause");
	return 0;
}