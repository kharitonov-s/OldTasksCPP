#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	VO obj1("05:12:10");
	VO obj2("22:00:05");
	
	cout << (obj1 - obj2) << endl;
	system("pause");
	return 0;
}