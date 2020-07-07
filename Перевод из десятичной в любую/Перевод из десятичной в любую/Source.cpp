#include <iostream>
using namespace std;

int perevod(int number, int numberSystem);

int main()
{
	int number, numberSystem;
	cout << "Vvedite chislo v desyatichnoi sisteme schisleniya" << endl;
	cin >> number;
	cout << "Vvedite nuzhnuyu sistemu schisleniya (ot 2 do 9)" << endl;
	cin >> numberSystem;
	cout << endl;
	cout << "Chislo " << number << " v sisteme schisleniya" << numberSystem << " = " << perevod(number, numberSystem) << endl;

	system("pause");
	return 0;
}

int perevod(int number, int numberSystem)
{
	int result = 0;
	int sch = 1;
	while (number > 0)
	{
		result += (number % numberSystem) * sch;
		number = (number - (number % numberSystem)) / numberSystem;
		sch *= 10;
	}

	return result;
}