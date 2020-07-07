#include <iostream>;
using namespace std;

template <typename T>
struct Node

{
	T data;
	Node*next;
	Node*prev;
	Node(T d) { data = d;next = nullptr;prev = nullptr; }
};
template <typename T>
class List
{
private:
	// Указатель на первый элемент спиcка
	Node<T>* first;
	Node<T>* last;
	// Размер списка
	int size;
public:
	//Конструктор по умолчанию 
	List();
	// Деструктор 
	~List();
	//Добавление элемента в начало списка 
	void push_front(const T& data);
	//Добавление элемента в конец списка
	void push_back(const T& data);
	// Удаление элемента из начала списка
	bool pop_front(T& data);
	// Удаление элемента из конца списка 
	bool pop_back(T& data);


	template <typename T1>
	friend ostream& operator<<(ostream&, List<T1>&);

	class Iterator {

	private:
		Node<T>* p;
	public:
		Iterator(Node<T> *pp = nullptr) { p = pp; }
		// Перегрузка оператора разымеования
		T& operator*()const { return p->data; }
		// Перегрузка инкрементов ++x
		Iterator& operator++()
		{
			p = p->next;
			return *this;
		}
		Iterator& operator--()
		{
			p = p->prev;
			return *this;
		}
		//x++
		Iterator operator++(int)
		{
			Iterator it(p);
			p = p->next;
			return it;
		}
		Iterator operator--(int)
		{
			Iterator it(p);
			p = p->prev;
			return it;
		}

		//Перегрузка операция сравнения 
		bool operator !=(Iterator it)
		{
			return p != it.p;

		}
		bool operator ==(Iterator it)
		{
			return p == it.p;
		}

	};
	//Метод возвращающий итератор начала списка 
	Iterator begin();
	// Метод, возвращающий итератор конца списка
	Iterator end();
	// Метод, возвращающий итератор конца списка
	Iterator real_end();
	//Метод, удаляющий произвольный элемент списка 
	bool remove(Iterator it, T& data);


};


//Метод, удаляющий произвольный элемент списка 
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
	// Идем по списку через указатель
	while (tmp->next != nullptr)
	{
		// Создаем итератор следующего элемента 
		Iterator nextIt(tmp->next);
		// Если этот итератора-- тот,который нужно удалить
		if (nextIt == it)
		{
			// считываем данные
			data = *nextIt;
			//Перезначем адрес следующего элемента
			Node<T>* nextElem = tmp->next;
			tmp->next = nextElem->next;
			tmp->next->prev = tmp;
			// Удаляем нужный элемент 
			delete nextElem;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}


// Метод, возвращающий итератор начала списка
template <typename T>
typename List<T>::Iterator List<T>::begin()
{
	Iterator it(first);
	return it;
}

// Метод, возвращающий итератор конца списка
template <typename T>
typename List<T>::Iterator List<T>::end()
{

	return Iterator();


}
// Метод, возвращающий итератор конца списка
template <typename T>
typename List<T>::Iterator List<T>::real_end()
{
	Node<T>* last = first;
	// Если список пустой, вернем пустой итератор 
	if (last == nullptr)
		return Iterator();
	// Идем до конца списка
	while (last->next != nullptr)
		last = last->next;
	// Возвращаем итератор конца списка
	return Iterator(last);
}


//template <typename T>
//ostream& operator<<(ostream& out, List<T>& list)
//{
	//if (list.size == 0)
	//{
		//out << "Empty list!" << endl;
		//return out;
	//}

	//typename List<T>::Iterator it = list.begin();
	//for (; it != list.end();++it)
		//out << *it << endl;
	//return out;
//}

template <typename T>
ostream& operator<<(ostream& out, List<T>& list)
{
	if (list.size == 0)
	{
		out << "Empty list!" << endl;
		return out;
	}

	typename List<T>::Iterator it = list.real_end();
	for (; it != list.begin();--it)
		out << *it << endl;
	out << *it << endl;
	return out;
}


//Конструктор 
template <typename T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}


// Деструктор 
template <typename T>
List<T>::~List()
{
	Node<T>* tmp;
	// перебираем весь список, удаляя все узлы 
	while (first != nullptr)
	{
		tmp = first;
		first = first->next;
		delete tmp;
	}
}
// Добавление элемента в конец списка 
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
	last = first;
	while (last->next != nullptr)
		last = last->next;
	// Связываем его с новым узлом 
	last->next = newNode;
	newNode->prev = last;
	// Увеличиваем размер на 1
	++size;
}
// Добавления элемента в начало списка 
template<typename T>
void List<T>::push_front(const T &data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->next = first;
	first->prev = newNode;
	first = newNode;
	++size;
}
// Удаление элемента из начала списка
template <typename T>
bool List<T>::pop_front(T &data)
{
	if (size == 0)
		return false;
	if (first->next == nullptr)
		cout << "nullptr!" << endl;
	Node<T>* tmp = first;
	data = first->data;
	first = first->next;
	first->next->prev = nullptr;
	--size;
	delete tmp;
	return true;

}
//Удаление элемента из конца списка 
template<typename T>
bool List<T>::pop_back(T &data)
{
	if (size == 0)
		return false;
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
}

