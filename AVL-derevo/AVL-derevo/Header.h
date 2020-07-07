#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//���������, ����������� ���� ������
template <typename T>
struct AVLTreeNode
{
	enum balance { d2left = -2, dleft, bal, dright, d2right };
	balance status;
	//������
	T data;
	//��������� �� ������ � ������� ��������
	AVLTreeNode *left, *right;
	//�����������
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
	//������ ������
	int size;
	//������ ������
	int height;
	//������ ������
	AVLTreeNode<T>* root;
	//�������� ���������
	void delete_subtree(AVLTreeNode<T>* subroot);
	//������� ��������� � ���������
	AVLTreeNode<T>* add_item_subtree(AVLTreeNode<T>* subroot, const T&);
	//����� ���������
	void traverse_subtree(AVLTreeNode<T>* subroot) const;
	//����� � ���������
	bool find_subtree(AVLTreeNode<T>* subroot, T key, T& res) const;
	//������ ��� ������������
	//���������� ������ ������
	int height_subtree(AVLTreeNode<T>* subroot) const;
	AVLTreeNode<T>* single_rotate_left(AVLTreeNode<T>*);
	AVLTreeNode<T>* single_rotate_right(AVLTreeNode<T>*);
	void set_status(AVLTreeNode<T>* subroot);
	
public:
	AVLBinaryTree();
	~AVLBinaryTree();
	//������� ������ ��������
	void add_item(const T&);
	//����� ������
	void traverse() const;
	//�����
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


//�����������
template <typename T>
AVLBinaryTree<T>::AVLBinaryTree()
{
	//������� ������ ������
	root = nullptr;
	size = 0;
	height = -1;
}

//����������
template <typename T>
AVLBinaryTree<T>::~AVLBinaryTree()
{
	if (size == 0) return;
	delete_subtree(root);
}

//�������� ���������
template <typename T>
void AVLBinaryTree<T>::delete_subtree(AVLTreeNode<T> *subroot)
{
	//�������� ������ ��������� 
	if (subroot->left != nullptr)
		delete_subtree(subroot->left);
	//�������� �������� ��������� 
	if (subroot->right != nullptr)
		delete_subtree(subroot->right);

	delete subroot;
}

//������� �������� 
template <typename T>
void AVLBinaryTree<T>::add_item(const T & item)
{
	//���� ������ ������, ������� ������
	if (root == nullptr)
	{
		root = new AVLTreeNode<T>(item);
		++size;
		++height;
		return;
	}
	//���� ������ ��������
	root = add_item_subtree(root, item);

}

//������� �������� � ���������
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::add_item_subtree(AVLTreeNode<T> *subroot, const T& item)
{
	//������� ����� �������� � ����� ���������
	if (item < subroot->data)
	{
		//���� ����� ��� ��������, ������� ����� ����
		if (subroot->left == nullptr)
		{
			subroot->left = new AVLTreeNode<T>(item);
			++size;
			
		}
		else 
		//���� ������� ����, �������� ��������
		subroot->left = add_item_subtree(subroot->left, item);
	}
	else
	{
		//���� ������ ��� ��������, ������� ����� ����
		if (subroot->right == nullptr)
		{
			subroot->right = new AVLTreeNode<T>(item);
			++size;
			
		}
		else 
		//���� ������� ����, �������� ��������
		subroot->right = add_item_subtree(subroot->right, item);
	}
	//������������� ������ ������������ �������� ����
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

//�������� ������� ������������
template <typename T>
void AVLBinaryTree<T>::set_status(AVLTreeNode<T> *subroot)
{
	subroot->status = (AVLTreeNode<T>::balance) (height_subtree(subroot->right) - height_subtree(subroot->left));
}

//����� ������
template <typename T>
void AVLBinaryTree<T>::traverse() const
{
	//���� ������ ������
	if (root == nullptr)
	{
		cout << "Empty tree!" << endl;
		return;
	}
	//���� �������� �������� ��������
	traverse_subtree(root);
}

//����� ���������
template <typename T>
void AVLBinaryTree<T>::traverse_subtree(AVLTreeNode<T>* subroot) const
{
	//����� ������ ���������
	if (subroot->left != nullptr)
		traverse_subtree(subroot->left);
	//����� �������� ��������
	cout << subroot->data << endl;
	//����� ������� ���������
	if (subroot->right != nullptr)
		traverse_subtree(subroot->right);
}

//����� ��������
template <typename T>
bool AVLBinaryTree<T>::find(T key, T &res) const
{
	if (root == nullptr)
	{
		return false;
	}
	return find_subtree(root, key, res);
}

//����� ��������� � ���������
template <typename T>
bool AVLBinaryTree<T>::find_subtree(AVLTreeNode<T> *subroot, T key, T &res) const
{
	//���� ����� �������, ���������� ��� 
	if (key == subroot->data)
	{
		res = subroot->data;
		return true;
	}
	//���� ���� ������ �������� ��������, ���� � ����� ���������
	if (key < subroot->data)
	{
		if (subroot->left == nullptr)
			return false;
		find_subtree(subroot->left, key, res);
	}
	else
	{
		//���� ���� ������ �������� ��������, ���� � ������ ���������
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


//������� ������ �������
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::single_rotate_right(AVLTreeNode<T> *subroot)
{
	AVLTreeNode<T>* Left = subroot->left;
	subroot->left = Left->right;
	Left->right = subroot;
	return Left;
}

//������� ����� �������
template <typename T>
AVLTreeNode<T>* AVLBinaryTree<T>::single_rotate_left(AVLTreeNode<T> *subroot)
{
	AVLTreeNode<T>* Right= subroot->right;
	subroot->right = Right->left;
	Right->left = subroot;
	return Right;
}
