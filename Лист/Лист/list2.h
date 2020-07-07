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
	// ��������� �� ������ ������� ���c��
	Node<T>* first;
	Node<T>* last;
	// ������ ������
	int size;
public:
	//����������� �� ��������� 
	List();
	// ���������� 
	~List();
	//���������� �������� � ������ ������ 
	void push_front(const T& data);
	//���������� �������� � ����� ������
	void push_back(const T& data);
	// �������� �������� �� ������ ������
	bool pop_front(T& data);
	// �������� �������� �� ����� ������ 
	bool pop_back(T& data);


	template <typename T1>
	friend ostream& operator<<(ostream&, List<T1>&);

	class Iterator {

	private:
		Node<T>* p;
	public:
		Iterator(Node<T> *pp = nullptr) { p = pp; }
		// ���������� ��������� ������������
		T& operator*()const { return p->data; }
		// ���������� ����������� ++x
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

		//���������� �������� ��������� 
		bool operator !=(Iterator it)
		{
			return p != it.p;

		}
		bool operator ==(Iterator it)
		{
			return p == it.p;
		}

	};
	//����� ������������ �������� ������ ������ 
	Iterator begin();
	// �����, ������������ �������� ����� ������
	Iterator end();
	// �����, ������������ �������� ����� ������
	Iterator real_end();
	//�����, ��������� ������������ ������� ������ 
	bool remove(Iterator it, T& data);


};


//�����, ��������� ������������ ������� ������ 
template <typename T>
bool List<T>::remove(typename List<T>::Iterator it, T& data)
{
	Iterator curr = begin();
	if (curr == it)
	{
		return pop_front(data);
	}
	//��������� �� ������ ������� ������
	Node<T>* tmp = first;
	// ���� �� ������ ����� ���������
	while (tmp->next != nullptr)
	{
		// ������� �������� ���������� �������� 
		Iterator nextIt(tmp->next);
		// ���� ���� ���������-- ���,������� ����� �������
		if (nextIt == it)
		{
			// ��������� ������
			data = *nextIt;
			//���������� ����� ���������� ��������
			Node<T>* nextElem = tmp->next;
			tmp->next = nextElem->next;
			tmp->next->prev = tmp;
			// ������� ������ ������� 
			delete nextElem;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}


// �����, ������������ �������� ������ ������
template <typename T>
typename List<T>::Iterator List<T>::begin()
{
	Iterator it(first);
	return it;
}

// �����, ������������ �������� ����� ������
template <typename T>
typename List<T>::Iterator List<T>::end()
{

	return Iterator();


}
// �����, ������������ �������� ����� ������
template <typename T>
typename List<T>::Iterator List<T>::real_end()
{
	Node<T>* last = first;
	// ���� ������ ������, ������ ������ �������� 
	if (last == nullptr)
		return Iterator();
	// ���� �� ����� ������
	while (last->next != nullptr)
		last = last->next;
	// ���������� �������� ����� ������
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


//����������� 
template <typename T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}


// ���������� 
template <typename T>
List<T>::~List()
{
	Node<T>* tmp;
	// ���������� ���� ������, ������ ��� ���� 
	while (first != nullptr)
	{
		tmp = first;
		first = first->next;
		delete tmp;
	}
}
// ���������� �������� � ����� ������ 
template <typename T>
void List<T>::push_back(const T &data)
{
	Node<T>* newNode = new Node<T>(data);
	//���� ������ ���������� ������
	if (size == 0)
	{
		first = newNode;
		size = 1;
		return;
	}
	//���� ��������� ������� � ������
	last = first;
	while (last->next != nullptr)
		last = last->next;
	// ��������� ��� � ����� ����� 
	last->next = newNode;
	newNode->prev = last;
	// ����������� ������ �� 1
	++size;
}
// ���������� �������� � ������ ������ 
template<typename T>
void List<T>::push_front(const T &data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->next = first;
	first->prev = newNode;
	first = newNode;
	++size;
}
// �������� �������� �� ������ ������
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
//�������� �������� �� ����� ������ 
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

