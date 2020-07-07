#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	double kch = 0, sch=0,ch;
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Read file error!" << endl;
		system("pause");
		return 1;
	}
	while (!in.eof())
	{
		in >> ch;
		sch += ch;
		++kch;
		cout << ch << endl;
	}
	cout << sch / kch << " " << sch<< " "<<kch<< endl;

	
	system("pause");
	return 0;
}