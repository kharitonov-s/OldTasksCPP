#include <ctime>
#include <iostream> 
#include <exception>

using namespace std;

template <typename T>
class Vector
{
public://����� ��������� ������� � ������ (�� ��� �������� ����, � ������ � �������������)

	   //���������� ������ �������
	int getSize() const; //cons � ������� �������� ��� ������ ������ ��������� �������

     //������ ������ ������� �������� ������ �� �����������
	void setSize(int n);

	//�������� ������� ���-�� ��������� ��������
	static int getArrCount()
	{
		return arrCount;
	}

	//����� ������������ �������� �������� ������� � �������� index
	T getElem(int index) const;

	//����� �������� �������� �������� ������� � �������� index
	void  setElem(int index, T val);

	//����� ��������� ������� � �������� index 
	void deleteElem(int index);

	//����� ���������� �������� � �����
	void addElem(T val);

	//����� ����������� ������� � ������������ ����� �������
	void addElemMiddle(int index, T val);

	//�����, ������������ ������� ������ � ������  �� �������
	Vector& VectorCompare(Vector& anotherArr);

	//�����������
	//����������� �� ���������
	Vector();
	Vector(int n, bool random = false);
	//����������� � �������� �������
	Vector(int n, const T* arr);
	//���������� ����������� 
	Vector(const Vector &sec_arr);

	//����������
	~Vector();

	void print() const;

	//����� ����������
	void bubble_sort(bool(*comp)(T, T) = Greater);

private:
	//����������� ����������
	//������������ ���-�� �������� ������� ������
	static T arrCount;

	//�������� ������ ������ ������ � �������
	int size;
	//��������� �� ������
	T* array;

	//protected://�� ���� � �� ������ ������� �������� ��� ������ ������ ��� � ��� �������� (����������� � �������)
};

template <typename T>
int Vector<T>::getSize() const
{
	return size;
}
template <typename T>
void Vector<T>::setSize(int n) //������� � ������ ���������� ��������! 
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
//����� ������������ �������� �������� ������� � �������� index
T Vector<T>::getElem(int index) const
{
	if (index > size - 1)
		throw range_error("Index is greater than size");

	return array[index];
}
template <typename T>
//����� �������� �������� �������� ������� � �������� index 
void Vector<T>::setElem(int index, T val)
{
	array[index] = val;
}
template <typename T>
//����� ��������� ������� � �������� index 
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
//����� ���������� � ������������ ����� �������
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

//����� ���������� �������� � ����� 
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
//�����, ������������ ������� ������ � ������ �� ������� 
Vector<T>& Vector<T>::VectorCompare(Vector<T>& anotherArr)
{
	if (anotherArr.getSize() > this->getSize())
		return anotherArr;
	else
		return *this;
}
template <typename T>
//����������� 
Vector<T>::Vector()
{
	++arrCount;
	size = 0;
	array = nullptr;
}
template <typename T>
//����������� � �������� ������� 
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
//����������� � �������� �������
Vector<T>::Vector(int n, const T* arr)
{
	++arrCount;
	size = n;
	array = new T[size];
	for (int i = 0;i < size;++i)
		array[i] = arr[i];
}
template <typename T>
//��������� ����������� 
Vector<T>::Vector(const Vector& sec_arr)// ����� ������������� ��������� �������� ����������� �� ������ 
{
	++arrCount;
	size = sec_arr.getSize();
	array = new T[size];
	for (int i = 0;i < size;++i)
		array[i] = sec_arr.getElem(i);// ����� ������������ ������ const
}
template <typename T>
//���������� 
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
//����������
template < typename T>
void Vector<T>::bubble_sort(bool(*comp)(T, T) = Greater)
{
	for (int i = 1;i < size;++i)
		for (int j = 0;j < size - i;++j)
			if (comp(array[j], array[j + 1]) == true)
				Swap(array[j], array[j + 1]);
}
