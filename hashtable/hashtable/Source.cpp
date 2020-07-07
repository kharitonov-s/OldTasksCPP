#include <iostream>
#include "hashtable.h"
using namespace std;

int keyIntFunc(int val)
{
	return val;
}

int hashIntFunc(const int& keyVal)
{
	return keyVal % 3;
}

int main()
{
	Hashtable<int, int> *htInt = new Hashtable<int,int> (3, keyIntFunc, hashIntFunc);
	for (int i = 0;i < 11;++i)
		htInt->insert(i);

	htInt->print();

	delete htInt;
	system("pause");
	return 0;
}