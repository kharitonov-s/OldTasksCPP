#include"IntArray.h"
#include <iostream>
#include <ctime>
#include <exception>//�������� ������ ���������� ������ �����

using namespace std;

//�����, ������������ 
int IntArray::getSize() const
	{
		return size;
	}

	void IntArray::setSize(int n) //������� � ������ ���������� ��������!
	{
		int* tmpArr = new int[n];
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
	//����� ������������ �������� �������� ������� � �������� index
	 int IntArray::getElem(int index) const
	{
		if (index > size - 1)
			throw range_error("Index is greater than size");
		return array[index];
	}

	 //�������� ������� ���-�� ��������� ��������
	 //static int IntArray::getArrCount()
	// {
	//	 return arrCount;
	// }

	int IntArray::arrCount = 0;


	//����� �������� �������� �������� ������� � �������� index
	void IntArray::setElem(int index, int val)
	{
		array[index] = val;
	}
	//����� ��������� ������� � �������� index 
	void IntArray::deleteElem(int index)
	{
		if (index > size - 1 || index<0)
			return; 
		int* tmp = new int[size - 1];
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
	//����� ���������� �������� � �����
	
		void IntArray::addElem(int val)
	{
		int *tmp = new int[size + 1];
		for (int i = 0;i < size;++i)
			tmp[i] = array[i];
		tmp[size] = val;
		++size;
		delete[] array;
		array = tmp;
	}

		//�����, ����������� ������� � ������������ ����� �������
		void IntArray::addElemMiddle(int index, int val)
		{
			int* tmp = new int[size + 1];
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

		//�����, ������������ ������� ������ � ������  �� �������
		IntArray& IntArray::intArrayCompare(IntArray& anotherArr)
		{
			if (anotherArr.getSize() > this->getSize())
				return anotherArr;
			else
				return *this;
		}

	//����������� (��������������)
	IntArray::IntArray()
	{
		++arrCount;
		size = 0;
		array = nullptr;
	}

	//����������� � �������� ������� 
	IntArray::IntArray(int n, bool random)
	{
		++arrCount;
		srand(time(NULL));
		size = n;
		array = new int[size];

		for (int i = 0;i < size;++i)
		{
			if (random == false)
				array[i] = 0;
			else
				array[i] = rand() % 10;
		}
	}

	//����������� � �������� �������
	IntArray::IntArray(int n, const int* arr)
	{
		++arrCount;
		size = n;
		array = new int[size];
		for (int i = 0;i < size;++i)
			array[i] = arr[i];
	}

	//���������� ����������� 
	IntArray::IntArray(const IntArray &sec_arr)
	{
		++arrCount;
		//sec_arr.setSize(3);

		size = sec_arr.getSize();
		array = new int[size];
		for (int i = 0;i < size;++i)
			array[i] = sec_arr.getElem(i);
	}

	//����������
	IntArray::~IntArray()
	{
		--arrCount;
		delete[] array;
	}

	void IntArray::print() const
	{
		for (int i = 0;i < size;++i)
			cout << array[i] << " ";
		cout << endl;

	}

	
