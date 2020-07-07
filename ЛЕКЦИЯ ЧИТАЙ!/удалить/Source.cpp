#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char c;
	bool state = true;

	while (true)
	{
		cin >> c;
		switch (c)
		{
			cout << "a entered" << endl;
			break;

		case 'c':
		{
			cout << "Something else" << endl;
			break;
		}
		case 'q':
		{
			cout << "Something else" << endl;
			state = false;
			break;
		}
		}
	}
	
	/*while (true)
	{
		cout << "Enter password:";
		cin.getline(str, 32);
		if (!strcmp(str, "hello"))
			cout << "Acces granted" << endl;
		else
			cout << "Acces denied" << endl;
	}*/
	system("pause");
	return 0;
}