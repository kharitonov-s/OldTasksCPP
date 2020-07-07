#include <ctime>
#include <iostream> 
#include <exception>

using namespace std;

template <typename T>
class Vector
{
public://можно доставать функции и данные (то что доступно всем, и классу и пользователям)

	   //возвращает размер массива
	int getSize() const; //cons в функции означает что нельзя менять состояние объекта

     //меняет размер массива сохраняя данные по возможности
	void setSize(int n);

	//получает текущее кол-во созданных объектов
	static int getArrCount()
	{
		return arrCount;
	}

	//метод возвращающий значение элемента массива с индексом index
	T getElem(int index) const;

	//метод задающий значение элемента массива с индексом index
	void  setElem(int index, T val);

	//Метод удаляющий элемент с индексом index 
	void deleteElem(int index);

	//Метод добавления элемента в конец
	void addElem(T val);

	//Метод добавляющий элемент в произвольное место массива
	void addElemMiddle(int index, T val);

	//Метод, сравнивающий текущий массив с другим  по размеру
	Vector& VectorCompare(Vector& anotherArr);

	//конструктор
	//Конструктор по умолчанию
	Vector();
	Vector(int n, bool random = false);
	//Конструктор с заданием массива
	Vector(int n, const T* arr);
	//Копирующий конструктор 
	Vector(const Vector &sec_arr);

	//Деструктор
	~Vector();

	void print() const;

	//Метод сортировки
	void bubble_sort(bool(*comp)(T, T) = Greater);

private:
	//статическая переменная
	//подсчитывает кол-во объектов данного класса
	static T arrCount;

	//доступно только внутри класса и друзьям
	int size;
	//указатель на массив
	T* array;

	//protected://те поля и те методы которые доступны как самому классу так и его потомкам (наследникам и друзьям)
};

template <typename T>
int Vector<T>::getSize() const
{
	return size;
}
template <typename T>
void Vector<T>::setSize(int n) //функции в классе называются МЕТОДАМИ! 
{
	T* tmpArr = new T[n];
	if (n <= size)
	{
		for (int i = 0;i < n;++i)
			tmpArr[i] = array[i];
	}
	else
	{
		for (int i = 0;i < n;++i)
			tmpArr[i] = array[i];
		for (int i = size;i < n;++i)
			tmpArr[i] = 0;
	}

	size = n;
	delete[] array;
	array = tmpArr;

}
template <typename T>
//метод возвращающий значение элемента массива с индексом index
T Vector<T>::getElem(int index) const
{
	if (index > size - 1)
		throw range_error("Index is greater than size");

	return array[index];
}
template <typename T>
//метод задающий значение элемента массива с индексом index 
void Vector<T>::setElem(int index, T val)
{
	array[index] = val;
}
template <typename T>
//Метод удаляющий элемент с индексом index 
void Vector<T>::deleteElem(int index)
{
	if (index > size - 1 || index<0)
		return;
	int* T = new T[size - 1];
	int j = 0;
	for (int i = 0;i < size;++i)
	{
		if (i == index)
			continue;
		tmp[j] = array[i];
		++j;
	}
	--size;
	delete[] array;
	array = tmp;
}
template <typename T>
//Метод добавления в произвольный место массива
void Vector<T>::addElemMiddle(int index, T val)
{
	int* T = new T[size + 1];
	int j = 0;
	for (int i = 0;i < size + 1;++i)
	{
		if (i == index)
		{
			tmp[i] = val;
			continue;
		}
		tmp[i] = array[j];
		++j;
	}
	++size;
	delete[] array;
	array = tmp;
}

template <typename T>
T Vector<T>::arrCount = 0;

//Метод добавления элемента в конец 
template <typename T>
void Vector<T>::addElem(T val)
{
	T *tmp = new T[size + 1];
	for (int i = 0;i < size;++i)
		tmp[i] = array[i];
	tmp[size] = val;
	++size;
	delete[] array;
	array = tmp;
}
template <typename T>
//Метод, сравнивающий текущий массив с другим по размеру 
Vector<T>& Vector<T>::VectorCompare(Vector<T>& anotherArr)
{
	if (anotherArr.getSize() > this->getSize())
		return anotherArr;
	else
		return *this;
}
template <typename T>
//конструктор 
Vector<T>::Vector()
{
	++arrCount;
	size = 0;
	array = nullptr;
}
template <typename T>
//Конструктор с заданием размера 
Vector<T>::Vector(int n, bool random)
{
	++arrCount;
	srand(time(NULL));
	size = n;
	array = new T[size];

	for (int i = 0;i < size;++i)
	{
		if (random == false)
			array[i] = 0;
		else
			array[i] = rand() % 10;
	}

}
template <typename T>
//Конструктор с заданием массива
Vector<T>::Vector(int n, const T* arr)
{
	++arrCount;
	size = n;
	array = new T[size];
	for (int i = 0;i < size;++i)
		array[i] = arr[i];
}
template <typename T>
//Копирующй конструктор 
Vector<T>::Vector(const Vector& sec_arr)// чтобы предотвратить изменение элемента переданного по ссылке 
{
	++arrCount;
	size = sec_arr.getSize();
	array = new T[size];
	for (int i = 0;i < size;++i)
		array[i] = sec_arr.getElem(i);// можно использовать только const
}
template <typename T>
//Деструктор 
Vector<T>::~Vector()
{
	--arrCount;
	delete[] array;
}
template <typename T>
void Vector<T>::print() const
{
	for (int i = 0;i < size;++i)
		cout << array[i] << " ";
	cout << endl;

}
template <typename T>
bool Greater(T a, T b);

bool Greater(char* a, char* b);

template <typename T>
void Swap(T &a, T &b);

template <typename T>
bool Greater(T a, T b)
{
	return a > b;
}
bool Greater(char*a, char*b)
{
	return strcmp(a, b) == 1;
}

template <typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
//Сортировка
template < typename T>
void Vector<T>::bubble_sort(bool(*comp)(T, T) = Greater)
{
	for (int i = 1;i < size;++i)
		for (int j = 0;j < size - i;++j)
			if (comp(array[j], array[j + 1]) == true)
				Swap(array[j], array[j + 1]);
}
