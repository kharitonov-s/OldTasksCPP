#pragma once
//stack - специальная струкутура данных. мы можем получать элемент из стэка, при этом в стэке элемент удаляется

#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
	T* data;//массив с данными
	int top;//индекс последнего добавленнного элемента
	int size;//размер стэка
	static int incr;//кол-во элементов, на которое мы увеличем стек когда он полон
public:
	Stack(int s = 10);
	~Stack();
	void push(const T&); //функция добавляет элемент на вершину стэка
	bool pop(T&); //функция: получить элемент с вершины стэка

	bool is_full() const;//проверка полноты стэка
	bool is_empty() const;//проверка пустоты стэка
	
	//Перегрузка оператора вывода
	template<typename T>
	friend ostream& operator<<(ostream&, const Stack<T> &st);
};
//Перегрузка оператора вывода
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

//Конструктор
//все методы шаблона класса являются шаблонами функции 
template <typename T>
Stack<T>::Stack(int s)
{
	size = (s > 0) ? s : 10;//проверка целостности
	data = new T[size];
	top = 0;
}

//Деструктор
template <typename T>
Stack<T>::~Stack()
{
	if (data != nullptr)
		delete[] data;
}

//Добавление элемента
template <typename T>
void Stack<T>::push(const T& item)
{
	//если индекс вершины стека меньше размера стека 
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

//Получение значения элемента на вершине стека
template <typename T>
bool Stack<T>::pop(T& item)
{
	if (top == 0)
		return false;
	item = data[--top];
	return true;
}

//Проверка на полноту
template <typename T>
bool Stack<T>::is_full() const
{
	return(top == size);
}

//Проверка на пустоту
template <typename T>
bool Stack<T>::is_empty() const
{
	return(top == 0);
}