#include <iostream>
#include "Header.h"

using namespace std;

int main()
{

	AVLBinaryTree<int> tree;

	for (int i = 0;i < 7;++i)
		tree.add_item(i);

	tree.traverse();




	system("pause");
	return 0;
}