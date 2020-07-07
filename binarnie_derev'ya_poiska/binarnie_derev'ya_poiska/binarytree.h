 #pragma once
#include <iostream>
#include <cstring>
using namespace std;

//���������, ����������� ���� ������
template <typename T>
struct TreeNode
{
	//������
	T data;
	//��������� �� ������ � ������� ��������
	TreeNode *left, *right;
	//�����������
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
	//������ ������
	int size;
	//������ ������
	TreeNode<T>* root;
	//�������� ���������
	void delete_subtree(TreeNode<T>* subroot);
	//������� ��������� � ���������
	void add_item_subtree(TreeNode<T>* subroot, const T&);
	//����� ���������
	void traverse_subtree(TreeNode<T>* subroot) const;
	//����� � ���������
	bool find_subtree(TreeNode<T>* subroot, T key, T& res) const;
public:
	BinaryTree();
	~BinaryTree();
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


//�����������
template <typename T>
BinaryTree<T>::BinaryTree()
{
	//������� ������ ������
	root = nullptr;
	size = 0;
}

//����������
template <typename T>
BinaryTree<T>::~BinaryTree()
{
	if (size == 0) return;
	delete_subtree(root);
}

//�������� ���������
template <typename T>
void BinaryTree<T>::delete_subtree(TreeNode<T> *subroot)
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
void BinaryTree<T>::add_item(const T & item)
{
	//���� ������ ������, ������� ������
	if (root == nullptr)
	{
		root = new TreeNode<T>(item);
		++size;
		return;
	}
	//���� ������ ��������
	add_item_subtree(root, item);
	++size;
}

//������� �������� � ���������
template <typename T>
void BinaryTree<T>::add_item_subtree(TreeNode<T> *subroot, const T& item)
{
	//������� ����� �������� � ����� ���������
	if (item < subroot->data)
	{
		//���� ����� ��� ��������, ������� ����� ����
		if (subroot->left == nullptr)
		{
			subroot->left = new TreeNode<T>(item);
			return;
		}
		//���� ������� ����, �������� ��������
		add_item_subtree(subroot->left, item);
	}
	else
	{
		//���� ������ ��� ��������, ������� ����� ����
		if (subroot->right == nullptr)
		{
			subroot->right = new TreeNode<T>(item);
			return;
		}
		//���� ������� ����, �������� ��������
		add_item_subtree(subroot->right, item);
	}
}

//����� ������
template <typename T>
void BinaryTree<T>::traverse() const 
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
void BinaryTree<T>::traverse_subtree(TreeNode<T>* subroot) const
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
bool BinaryTree<T>::find(T key, T &res) const
{
	if (root == nullptr)
	{
		return false;
	}
	return find_subtree(root, key, res);
}

//����� ��������� � ���������
template <typename T>
bool BinaryTree<T>::find_subtree(TreeNode<T> *subroot, T key, T &res) const
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


