#pragma once
#include <iostream>
using namespace std;
//Шаблон структуры узла списка
template <typename T>
struct Node
{
	T data;
	Node* next;
	Node(T d) { data = d; next = nullptr; }
};

template <typename T>
class List
{
private:

	//Указатель на первый элемент списка
	Node<T>* first;

	int size;//Рамзер списка
public:
	//конструктор по умолчанию
	List();
	//Деструктор
	~List();
	//Добавление элемента в начало списка
	void push_front(const T& data);
	//Добавление элемента в конец списка
	void push_back(const T& data);
	//Удаление элемента из начала списка
	bool pop_front(T& data);
	//Удаление элемента из конца списка 
	bool pop_back(T& data);
	


	template<typename T1>
	friend ostream& operator<<(ostream&, List<T1>);

	class Iterator {
	private:
		//Указатель на элемент списка
		Node<T>* p;
	public:
		Iterator(Node<T> *pp = nullptr) { p = pp; }
		//Перегрузка оператора разыменования 
		T& operator*() const { return p->data; }
		//Перегрузка инкрементов
		//++х
		Iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		//x++
		Iterator operator++(int)
		{
			Iterator it(p);
			p = p->next;
			return it;
		}
		//Перегрущка операции сравнения
		bool operator!=(Iterator it)
		{
			return p != it.p;
		}
		bool operator==(Iterator it)
		{
			return p == it.p;
		}
	};
	//Метод возвращающий итератор начала списка
	Iterator begin();
	//Метода возвращающий итератор конца списка
	Iterator end();

	//Метод удаляющий произвольный элемент списка 
	bool remove(Iterator it, T& data);
	//Поиск элемента
	Iterator find(T elem);
};

//Метод удаляющий произвольный элемент списка 
template <typename T>
bool List<T>::remove(typename List<T>::Iterator it, T& data)
{
	Iterator curr = begin();
	if (curr == it)
	{
		return pop_front(data);
	}
	//Указатель на первый элемент списка
	Node<T>* tmp = first;
	//Идем по списку через указатели 
	while (tmp->next != nullptr)
	{
		//Создаем итератор следующего элемента за текущим
		Iterator nextIt(tmp->next);
		//Если этот итератор -- тот, который нужно удалить 
		if (nextIt == it)
		{
			//считываем данные 
			data = *nextIt;
			//Удаляем след элемент
			delete tmp->next;
			//Переназначаем адрес след элемента 
			Node<T>* nextElem = tmp->next;
			tmp->next = nextElem->next;
			//Удаляем нужный элемент
			delete nextElem;

			return true;
		}
		//Переход на следующий элемент
		tmp = tmp->next;
	}
	//Есди дошли до сюда, значит,
	//элемент не найден
	return false;
}


//Метод возвращающий итератор начала списка
template <typename T>
typename List<T>::Iterator List<T>::begin()
{
	Iterator it(first);
	return it;
}

//Метод возвращающий итератор конца списка
template <typename T>
typename List<T>::Iterator List<T>::end()
{
	//Node<T>* last = first;
	////Если список пустой, вернем пустой итератор 
	//if (last == nullptr) return Iterator();
	////Идем до конца списка
	//while (last->next != nullptr)
	//	last = last->next;
	////Возвращаем итератор конца списка
	//return Iterator(last->next);
	return Iterator();
}


template<typename T>
ostream& operator<<(ostream& out, List<T> list)
{
	if (list.size == 0)
	{
		out << "Empty list!" << endl;
		return out;
	}
	//Node<T>* tmp = list.first;
	//out << tmp->data << endl;
	//while (tmp->next != nullptr)
	//{
	//	tmp = tmp->next;
	//	out << tmp->data << endl;
	//}
	typename List<T>::Iterator it = list.begin();
	for (;it != list.end();++it)
		out << *it << endl;

	return out;

}

//Конструктор
template<typename T>
List<T>::List()
{
	first = nullptr;
	size = 0;
}
//Деструктор
template <typename T>
List<T>::~List()
{
	Node<T>* tmp;
	//Перебираем весь список, удаляя все узлы
	while (first != nullptr)
	{
		tmp = first;
		first = first->next;
		delete tmp;
	}
}

//Добавление элемента в конец списка
template <typename T>
void List<T>::push_back(const T &data)
{
	Node<T>* newNode = new Node<T>(data);
	//Если список изначально пустой
	if (size == 0)
	{
		first = newNode;
		size = 1;
		return;
	}
	//Ищем последний элемент в списке
	Node<T>* last = first;
	while (last->next != nullptr)
		last = last->next;
	//Связываем его с новым узлом
	last->next = newNode;
	//Увеличиваем размер на единицу
	++size;
}

//Добавление элемента в начало списка
template <typename T>
void List<T>::push_front(const T &data)
{
	//
	Node<T>* newNode = new Node<T>(data);
	newNode->next = first;//следующий после newNode принимает значение first
	first = newNode; //а в first записываем новый элемент
	++size;
}
//Удаление элемента из начала списка
template <typename T>
bool List<T>::pop_front(T &data)
{
	if (size == 0)
		return false;
	Node<T>* tmp = first;
	data = first->data;
	first = first->next;
	--size;
	delete tmp;
	return true;
}

//Удаление элемента из конца списка
template <typename T>
bool List<T>::pop_back(T &data)
{
	if (size == 0)
		return false;
	//Ищем последний элемент в списке
	Node<T>* last = first;
	if (size > 1)
	{
		while (last->next->next != nullptr)
		{
			last = last->next;
		}
		data = last->next->data;
		delete last->next;
		last->next = nullptr;
		--size;
	}
	else
	{
		data = first->data;
		delete first;
		first = nullptr;
		size = 0;
	}
	return true;
}

template <typename T>
typename List<T>::Iterator List<T>::find(T key)
{
	if (size == 0) retirn Iterator();
	Node<T>* tmp = first;
	while (tmp != nullptr) {
		if (tmp->data == key)
			return Iterator(tmp);
		tmp = tmp->next;
	}
	return Iterator();
}