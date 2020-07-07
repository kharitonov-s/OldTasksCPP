#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

bool isBinary(char *s) //проверят двоичная ли запись у числа (01011001)
{
	int n = strlen(s);
	for (int i = 0;i < n;++i)
	{
		if (s[i] != '0'&& s[i] != '1')
		{
			return false;
		}
	}
	return true;
}
int main()
{
	char s[32];
	cin >> s;
	cout << isBinary(s) << endl;

	system("pause");
	return 0;

}