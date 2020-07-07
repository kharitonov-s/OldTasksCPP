#pragma once
//stack - ����������� ���������� ������. �� ����� �������� ������� �� �����, ��� ���� � ����� ������� ���������

#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
	T* data;//������ � �������
	int top;//������ ���������� ������������� ��������
	int size;//������ �����
	static int incr;//���-�� ���������, �� ������� �� �������� ���� ����� �� �����
public:
	Stack(int s = 10);
	~Stack();
	void push(const T&); //������� ��������� ������� �� ������� �����
	bool pop(T&); //�������: �������� ������� � ������� �����

	bool is_full() const;//�������� ������� �����
	bool is_empty() const;//�������� ������� �����
	
	//���������� ��������� ������
	template<typename T>
	friend ostream& operator<<(ostream&, const Stack<T> &st);
};
//���������� ��������� ������
template<typename T>
ostream& operator<<(ostream& out, const Stack<T> &st)
{
	if (st.is_empty())
	{
		cout << "Empty stack!" << endl;
		return out;
	}

	for (int i = 0;i < st.top;++i)
		out << st.data[i] << "\t";
	out << endl;
	return out;
}

template <typename T>
int Stack<T>::incr = 10;

//�����������
//��� ������ ������� ������ �������� ��������� ������� 
template <typename T>
Stack<T>::Stack(int s)
{
	size = (s > 0) ? s : 10;//�������� �����������
	data = new T[size];
	top = 0;
}

//����������
template <typename T>
Stack<T>::~Stack()
{
	if (data != nullptr)
		delete[] data;
}

//���������� ��������
template <typename T>
void Stack<T>::push(const T& item)
{
	//���� ������ ������� ����� ������ ������� ����� 
	if (top < size)
	{
		data[top] = item;
		++top;
	}
	else
	{
		T* tmp = new T[size + incr];
		for (int i = 0;i < size;++i)
			tmp[i] = data[i];
		tmp[top] = item;
		++top;
		size += incr;
		delete[] data;
		data = tmp;
	}
}

//��������� �������� �������� �� ������� �����
template <typename T>
bool Stack<T>::pop(T& item)
{
	if (top == 0)
		return false;
	item = data[--top];
	return true;
}

//�������� �� �������
template <typename T>
bool Stack<T>::is_full() const
{
	return(top == size);
}

//�������� �� �������
template <typename T>
bool Stack<T>::is_empty() const
{
	return(top == 0);
}