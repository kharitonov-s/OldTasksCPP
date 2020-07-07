#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
		char s[32];
		for (int i = 0;i < 10;++i) {
			s[i] = rand() % 75 + 48;
			cout << s[i] << endl;
		}

	system("pause");
	return 0;

}