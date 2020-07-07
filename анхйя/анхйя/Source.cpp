#include <iostream>
#include <fstream>
using namespace std;
int main(int argc char** argv)
{
	int n = 0;
	char str[32];
	char input_file[32];
	char output_file[32];
	if (argc < 3)
	{
		cout << "Error! Not enough filenames!" << endl;
	}
	ifstream in("in.txt");
		if (!in.is_open())
		{
			cout << "Read file error!" << endl;
			system("pause");
			return 1;
		}
	//in >> n >> str;
	//cout << n << " " << str << endl;
		//cout << str << endl;
		
	ofstream out;
	out.open("out.txt"); // ios::app); //ios::app - сохраняет предыдущий вывод программы и добавляет новый (пишет с конца)

	if (!out.is_open())
	{
		cout << "Write file Error" << endl;
		system("pause");
		return 1;
	}

	while (!in.eof())
	{
		in.getline(str, 32);
		cout << str << endl;
		out << str << endl;
	}


	out.close();
	in.close();
	
	system("pause");
	return 0;
}