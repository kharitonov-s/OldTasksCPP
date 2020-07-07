#include <iostream> 
#include "IntArray.h" 
#include <exception>
using namespace std;

int main()
{
	char* arr[10] = { "1","8","5","2","0","a","b","d","e","c" };
	Vector<char*> arr2(10, arr);
	cout << arr2.getSize() << endl;
	arr2.print();
	arr2.addElem("che");
	arr2.bubble_sort();
	arr2.print();
	system("pause");
	return 0;
}