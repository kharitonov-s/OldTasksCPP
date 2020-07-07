#include <iostream>
#include <fstream>
//#include <ctype>

using namespace std;

int main()
{
	
	char symb, symb_res;

	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Read file error!" << endl;
		system("pause");
		return 1;
	}
	while (!in.eof())
	{
		in >> symb;
		if (islower(symb))
			symb_res = toupper(symb);
	}
	cout << symb_res << " " << endl;

	system("pause");
	return 0;
} 
