 #pragma once
#include <iostream>
#include <cstring>
using namespace std;

//Структура, описывающая узлы дерева
template <typename T>
struct TreeNode
{
	//Данные
	T data;
	//Указатели на левого и правого потомков
	TreeNode *left, *right;
	//Конструктор
	TreeNode(T item)
	{
		data = item;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class BinaryTree
{
private:
	//Размер дерева
	int size;
	//Корень дерева
	TreeNode<T>* root;
	//Удаление поддерева
	void delete_subtree(TreeNode<T>* subroot);
	//Вставка элементов в поддерево
	void add_item_subtree(TreeNode<T>* subroot, const T&);
	//Обход поддерева
	void traverse_subtree(TreeNode<T>* subroot) const;
	//Поиск в поддереве
	bool find_subtree(TreeNode<T>* subroot, T key, T& res) const;
public:
	BinaryTree();
	~BinaryTree();
	//Вставка нового элемента
	void add_item(const T&);
	//Обход дерева
	void traverse() const;
	//Поиск
	bool find(T key, T& res) const;

};

struct word
{
	char eng[32];
	char rus[32];
	word(char eng_word[]="", char rus_word[]="")
	{
		strcpy_s(eng,strlen(eng_word)+1, eng_word);
		strcpy_s(rus, strlen(rus_word)+1, rus_word);
	}
	word& operator=(const word& w)
	{
		strcpy_s(eng, strlen(w.eng),w.eng);
		strcpy_s(rus, strlen(w.rus),w.rus);
		return *this;
	}
};

bool operator<(const word& w1, const word& w2)
{
	if (strcmp(w1.eng, w2.eng) == -1)
		return true;
	else
		return false;
}

bool operator==(const word& w1, const word& w2)
{
	if (strcmp(w1.eng, w2.eng) == 0)
		return true;
	else
		return false;
}

class Dictionary
{
private:
	BinaryTree<word> tree;
public:
	Dictionary() {}
	~Dictionary() {}
	void add_word(const word&);
	bool translate(char* eng, char* rus);
};

void Dictionary::add_word(const word & item)
{
	tree.add_item(item);
}

bool Dictionary::translate(char *eng, char *rus)
{
	word key(eng), trans;
	bool res = tree.find(key, trans);
	if (res == true)
	{
		strcpy_s(rus, strlen(trans.rus)+1, trans.rus);
	}
	return res;
}


//Конструктор
template <typename T>
BinaryTree<T>::BinaryTree()
{
	//Создаем пустое дерево
	root = nullptr;
	size = 0;
}

//Деструктор
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	if (size == 0) return;
	delete_subtree(root);
}

//Удаление поддерева
template <typename T>
void BinaryTree<T>::delete_subtree(TreeNode<T> *subroot)
{
	//Удаление левого поддерева 
	if (subroot->left != nullptr)
		delete_subtree(subroot->left);
	//Удаление проавого поддерева 
	if (subroot->right != nullptr)
		delete_subtree(subroot->right);

	delete subroot;
}

//Вставка элемента 
template <typename T>
void BinaryTree<T>::add_item(const T & item)
{
	//Если дерево пустое, создаем корень
	if (root == nullptr)
	{
		root = new TreeNode<T>(item);
		++size;
		return;
	}
	//Если дерево непустое
	add_item_subtree(root, item);
	++size;
}

//Вставка элемента в поддерево
template <typename T>
void BinaryTree<T>::add_item_subtree(TreeNode<T> *subroot, const T& item)
{
	//Элемент нужно добавить в левое поддерево
	if (item < subroot->data)
	{
		//Если слева нет потомков, создаем новый узел
		if (subroot->left == nullptr)
		{
			subroot->left = new TreeNode<T>(item);
			return;
		}
		//Если потомки есть, вызываем рекурсию
		add_item_subtree(subroot->left, item);
	}
	else
	{
		//Если справа нет потомков, создаем новый узел
		if (subroot->right == nullptr)
		{
			subroot->right = new TreeNode<T>(item);
			return;
		}
		//Если потомки есть, вызываем рекурсию
		add_item_subtree(subroot->right, item);
	}
}

//Обход дерева
template <typename T>
void BinaryTree<T>::traverse() const 
{
	//Если дерево пустое
	if (root == nullptr)
	{
		cout << "Empty tree!" << endl;
		return;
	}
	//Если непустое вызываем рекурсию
	traverse_subtree(root);
}

//Обход поддерева
template <typename T>
void BinaryTree<T>::traverse_subtree(TreeNode<T>* subroot) const
{
	//Вывод левого поддерева
	if (subroot->left != nullptr)
		traverse_subtree(subroot->left);
	//Вывод текущего элемента
	cout << subroot->data << endl;
	//Вывод правого поддерева
	if (subroot->right != nullptr)
		traverse_subtree(subroot->right);
}

//Поиск элемента
template <typename T>
bool BinaryTree<T>::find(T key, T &res) const
{
	if (root == nullptr)
	{
		return false;
	}
	return find_subtree(root, key, res);
}

//Поиск элементов в поддереве
template <typename T>
bool BinaryTree<T>::find_subtree(TreeNode<T> *subroot, T key, T &res) const
{
	//если нашли элемент, возвращаем его 
	if (key == subroot->data)
	{
		res = subroot->data;
		return true;
	}
	//Если ключ меньше текущего элемента, ищем в левом поддереве
	if (key < subroot->data)
	{
		if (subroot->left == nullptr)
			return false;
		find_subtree(subroot->left, key, res);
	}
	else
	{
		//Если ключ больше текущего элемента, ищем в правом поддереве
		if (subroot->right == nullptr)
			return false;
		find_subtree(subroot->right, key, res);
	}
}


