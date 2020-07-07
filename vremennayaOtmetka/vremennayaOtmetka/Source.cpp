#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	VO obj1("01:00:05");
	VO obj2("2343:12:10");

	cout << (obj1 - obj2);
	system("pause");
	return 0;
}