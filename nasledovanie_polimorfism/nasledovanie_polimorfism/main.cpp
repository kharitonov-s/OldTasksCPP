#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	A a(1, 2, 'a');
	//cout << a.get_x() << " " << a.z << endl;
	a.print();
	B b;
	//cout << b.get_x() << " " << b.z << endl;
	b.print();
	B b1(1, 2, 3, 4);
	C c;
	//c.ptint(); //не сработает т.к. лежит в protected
	//cout << (int)c.get_x() << endl;
	A* ab = new B;

	ab->print();

	delete ab;

	system("pause");
	return 0;
}