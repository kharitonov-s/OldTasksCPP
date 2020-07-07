#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Структура, описывающая узлы дерева
template <typename T>
struct AVLTreeNode
{
	enum balance { d2left = -2, dleft, bal, dright, d2right };
	balance status;
	//Данные
	T data;
	//Указатели на левого и правого потомков
	AVLTreeNode *left, *right;
	//Конструктор
	AVLTreeNode(T item)
	{
		data = item;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T>
class AVLBinaryTree
{
private:
	//Размер дерева
	int size;
	//Высота дерева
	int height;
	//Корень дерева
	AVLTreeNode<T>* root;
	//Удаление поддерева
	void delete_subtree(AVLTreeNode<T>* subroot);
	//Вставка элементов в поддерево
	AVLTreeNode<T>* add_item_subtree(AVLTreeNode<T>* subroot, const T&);
	//Обход поддерева
	void traverse_subtree(AVLTreeNode<T>* subroot) const;
	//Поиск в поддереве
	bool find_subtree(AVLTreeNode<T>* subroot, T key, T& res) const;
	//Методы для балансировки
	//Вычисление высоты дерева
	int height_subtree(AVLTreeNode<T>* subroot) const;
	AVLTreeNode<T>* single_rotate_left(AVLTreeNode<T>*);
	AVLTreeNode<T>* single_rotate_right(AVLTreeNode<T>*);
	void set_status(AVLTreeNode<T>* subroot);
	
public:
	AVLBinaryTree();
	~AVLBinaryTree();
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
	word(char eng_word[] = "", char rus_word[] = "")
	{
		strcpy_s(eng, strlen(eng_word) + 1, eng_word);
		strcpy_s(rus, strlen(rus_word) + 1, rus_word);
	}
	word& operator=(const word& w)
	{
		strcpy_s(eng, strlen(w.eng), w.eng);
		strcpy_s(rus, strlen(w.rus), w.rus);
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
	AVLBinaryTree<word> tree;
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
		strcpy_s(rus, strlen(trans.rus) + 1, trans.rus);
	}
	return res;
}


//Конструктор
template <typename T>
AVLBinaryTree<T>::AVLBinaryTree()
{
	//Создаем пустое дерево
	root = nullptr;
	size = 0;
	height = -1;
}

//Деструктор
template <typename T>
AVLBinaryTree<T>::~AVLBinaryTree()
{
	if (size == 0) return;
	delete_subtree(root);
}

//Удаление поддерева
template <typename T>
void AVLBinaryTree<T>::delete_subtree(AVLTreeNode<T> *subroot)
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
void AVLBinaryTree<T>::add_item(const T & item)
{
	//Если дерево пустое, создаем корень
	if (root == nullptr)
	{
		root = new AVLTreeNode<T>(item);
		++size;
		++height;
		return;
	}
	//Если дерево непустое
	root = add_item_subtree(root, item);

}

//Вставка элемента в поддерево
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::add_item_subtree(AVLTreeNode<T> *subroot, const T& item)
{
	//Элемент нужно добавить в левое поддерево
	if (item < subroot->data)
	{
		//Если слева нет потомков, создаем новый узел
		if (subroot->left == nullptr)
		{
			subroot->left = new AVLTreeNode<T>(item);
			++size;
			
		}
		else 
		//Если потомки есть, вызываем рекурсию
		subroot->left = add_item_subtree(subroot->left, item);
	}
	else
	{
		//Если справа нет потомков, создаем новый узел
		if (subroot->right == nullptr)
		{
			subroot->right = new AVLTreeNode<T>(item);
			++size;
			
		}
		else 
		//Если потомки есть, вызываем рекурсию
		subroot->right = add_item_subtree(subroot->right, item);
	}
	//пересчитываем статус балансировки текущего узла
	set_status(subroot);
	if (subroot->status == AVLTreeNode<T>::d2left)
	{
		if (subroot->left->status == AVLTreeNode<T>::dleft)
		{
			subroot = single_rotate_right(subroot);
			set_status(subroot->right);
			set_status(subroot);
		}
		else //if (subroot->left->status == AVLTreeNode<T>::dright)
		{
			subroot->left = single_rotate_left(subroot->left);
			subroot = single_rotate_right(subroot);
			set_status(subroot->right);
			set_status(subroot->left);
			set_status(subroot);
		}
	}
	else if (subroot->status == AVLTreeNode<T>::d2right)
	{
		if (subroot->right->status == AVLTreeNode<T>::dright)
		{
			subroot = single_rotate_left(subroot);
			set_status(subroot->left);
			set_status(subroot);
		}
		else //if (subroot->left->status == AVLTreeNode<T>::dright)
		{
			subroot->right = single_rotate_right(subroot->right);
			subroot = single_rotate_left(subroot);
			set_status(subroot->left);
			set_status(subroot->right);
			set_status(subroot);
		}
	}
	return subroot;
}

//Пересчет статуса балансировки
template <typename T>
void AVLBinaryTree<T>::set_status(AVLTreeNode<T> *subroot)
{
	subroot->status = (AVLTreeNode<T>::balance) (height_subtree(subroot->right) - height_subtree(subroot->left));
}

//Обход дерева
template <typename T>
void AVLBinaryTree<T>::traverse() const
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
void AVLBinaryTree<T>::traverse_subtree(AVLTreeNode<T>* subroot) const
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
bool AVLBinaryTree<T>::find(T key, T &res) const
{
	if (root == nullptr)
	{
		return false;
	}
	return find_subtree(root, key, res);
}

//Поиск элементов в поддереве
template <typename T>
bool AVLBinaryTree<T>::find_subtree(AVLTreeNode<T> *subroot, T key, T &res) const
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

template <typename T>
int AVLBinaryTree<T>::height_subtree(AVLTreeNode<T>* subroot) const
{
	if (subroot == nullptr) return -1;
	if (subroot->left == nullptr && subroot->right == nullptr)
		return 0;
	int height_left, height_right;
	if (subroot->left == nullptr)
		height_left = -1;
	else
		height_left = height_subtree(subroot->left);

	if (subroot->right == nullptr)
		height_right = -1;
	else
		height_right = height_subtree(subroot->right);

	return 1 + max(height_left, height_right);
}


//Простой правый поворот
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::single_rotate_right(AVLTreeNode<T> *subroot)
{
	AVLTreeNode<T>* Left = subroot->left;
	subroot->left = Left->right;
	Left->right = subroot;
	return Left;
}

//Простой левый поворот
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::single_rotate_left(AVLTreeNode<T> *subroot)
{
	AVLTreeNode<T>* Right= subroot->right;
	subroot->right = Right->left;
	Right->left = subroot;
	return Right;
}
