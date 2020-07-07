#include <iostream>
#include "intarray.h"


using namespace std;

int main()
{
	cout << "Hello World!" << endl;

	//Инициализация объекта класса IntArray
	//(здесь вызывается конструктор по умолчанию)
	IntArray arr;

	//попытка обращения к private-элементам
	//выдаст ошибку компилятора
	//cout << arr2.size << endl;

	//Для доступа к размеру мы реализовали
	//специальный метод
	cout << arr.getSize() << endl;
	arr.print();

	int manArray[5] = { 1,2,3,4,5 };

	//Инициализация объекта класса IntArray
	//Здесь вызывается конструктор, копирующий
	//значения из переданного массива
	IntArray arr2(5, manArray);
	cout << arr2.getSize() << endl;

	arr2.print();
	arr2.setElem(0, 10); // эквавиалентно arr2.array[0] = 10;
	arr2.setElem(1, 3);  // эквавиалентно arr2.array[0] = 10;
	arr2.print();

	arr2.setSize(5);
	arr2.print();

	arr2.setSize(15);
	arr2.print();

	arr2.deleteElem(1);
	arr2.print();

	arr2.addElem(28);
	arr2.print();

	IntArray arr3(arr2);
	arr3.print();

	arr2.addElem(100500);
	arr2.print();
	arr3.print();

	//Динамическое создание объекта через указатель
	//(здесь вызывается конструктор с присвоением размера)
	IntArray* arr_pointer = new IntArray(10, true);
	arr_pointer->print();

	//Пример задания массива объектов
	IntArray* arr_pointers = new IntArray[3];

	for (int i = 0;i<3;++i)
		arr_pointers[i].print();

	//Применение копирующего конструктора
	IntArray arr_cmp = arr.intArrayCompare(arr2);
	arr_cmp.print();

	cout << arr_pointer->getArrCount() << endl;
	cout << IntArray::getArrCount() << endl;

	//Очищение памяти за динамически созданными
	//объектами. Здесь вызываются деструкторы.
	delete arr_pointer;
	delete[] arr_pointers;

	//Потенциальном опасный код помещаем в try
	/*try
	{
		double x = 1, y = 0;
		if (y == 0)
			throw runtime_error("Division by zero");

		if (x == 1)
			throw "c";
		double div = x / y;
		throw - 1;
	}
	catch (runtime_error rt_err)
	{
		cout << rt_err.what() << endl;
	}
	catch (char* err_str) //ловит то, что выкинул try
	{
		cout << err_str << endl;
	}
	catch (int err_num)
	{
		cout << "error code:" << err_num << endl;
	}
	catch (...) //отлавливает все подряд, но не принимает значение 
	{
		cout << "Smth happend" << endl;
	}*/

	cout << arr2.getSize() << endl;
	try
	{
		cout << arr2.getElem(15) << endl;
	}
	catch (range_error rng_err)
	{
		cout << rng_err.what() << endl;
	}

	system("pause");
	return 0;
}