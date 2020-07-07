#include<iostream>
#include"Header.h"

using namespace std;

int main()
{
	cout << "Manual work with list" << endl;
	//Первый узел списка (характеризует список в целом!!!)
	//(пока что список состоит из одного элемента)
	Node<int> first(0);
	//Указатель на предыдущий элемент списка
	//на данный момент это сам first
	Node<int>* prev = &first;
	//Создаем 3 узла в цикле
	for (int i = 1;i < 4;++i)
	{
		//Создаем новый узел динамически
		Node<int>* tmp = new Node<int>(i);
		//Связываем предыдущий узел с новым созданным
		prev->next = tmp;
		//Смещаем предыдущий элемент на новый созданный
		prev = tmp;

	}

	prev = &first;
	cout << prev->data << "\t";
	for (int i = 1;i < 4;++i)
	{
		prev = prev->next;
		if (prev != nullptr)
			cout << prev->data << "\t";
	}
	cout << endl;

	cout << "Working with list through the countainter class" << endl;
	List<int>* intList = new List<int>;
	cout << *intList;
	intList->push_back(1);
	intList->push_back(2);
	intList->push_front(3);
	cout << *intList;

	List<int>::Iterator it = intList->begin();
	int data;
	//intList->remove(it,data);
	//intList = pop_front;
	cout << *intList;

	
	delete intList;
	system("pause");
	return 0;
}
