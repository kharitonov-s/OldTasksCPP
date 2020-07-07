#include "list.h"
#include <iostream>
using namespace std;

template <typename T, typename Key>
class Hashtable
{
private:
	int size;
	List<T>* hashArray; //массив указателей на списки
	int(*hashfunc) (Key keyval);
	Key(*keyfunc) (const T& data);
public:
	Hashtable<T,Key>(int t_size, int(*hf) (Key), Key(*kf) (const T&));
	~Hashtable<T,Key>();
	void insert(const T& data);
	bool remove(const T& data);
	bool find(const T& data, T& result) const;
	void print() const;
};

//Конструктор 
template <typename T, typename Key>
Hashtable<T,Key>::Hashtable<T,Key>(int t_size, int(*hf)(Key), Key(*kf) (const T &))
{
	size = t_size;
	hashArray = new List<T>[size];
	hashfunc = hf;
	keyfunc = kf;
}

//Дуструктор
template <typename T, typename Key>
Hashtable<T,Key>::~Hashtable<T,Key>()
{
	delete[] hashArray;
}

//Вставка элемента
template <typename T, typename Key>
void Hashtable<T,Key>::insert(const T &data)
{
	Key keyval = keyfunc(data);
	int hashIndex = hashfunc(keyval);
	hashArray[hashIndex].push_front(data);
}

//Поиск элемента
template <typename T, typename Key>
bool Hashtable<T,Key>::find(const T &data, T &result) const
{
	Key keyval = keyfunc(data);
	int hashIndex = hashfunc(keyval);
	List<T>::Iterator it = hashArray[hashIndex].find(data);
	if (it != nullptr)
	{
		result = *it;
		return true;
	}
	return false;
}

//Вывод таблицы
template <typename T, typename Key>
void Hashtable<T,Key>::print() const
{
	if (size == 0) cout << "Empty table" << endl;
	List<T>::Iterator it;
	for (int i = 0;i < size;++i)
	{
		cout << i << "\t: ";
		it = hashArray[i].begin();
		while (it != hashArray[i].end())
		{
			cout << *it << "\t";
			++it;
		}
		cout << endl;
	}
}

