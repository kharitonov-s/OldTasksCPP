#include <iostream>
#include <cstring>
#include "binarytree.h"

using namespace std;

int main()
{
	//BinaryTree<int>* tree = new BinaryTree<int>;
	//tree->add_item(10);
	//tree->add_item(8);
	//tree->add_item(12);
	//tree->traverse();
	//cout << endl;
	//tree->add_item(7);
	//tree->add_item(9);
	//tree->traverse();

	//int nine = 0;
	//if (tree->find(9, nine))
	//	cout << "Nine: " << nine << endl;
	//else
		//cout << "Nein neun!!!" << endl;

	//delete tree;

	setlocale(LC_ALL, "Russian");

	Dictionary dict;
	dict.add_word(word("nine", "הוגÿעü"));
	dict.add_word(word("eight", "גמסולü"));
	dict.add_word(word("seven", "סולü"));
	char eng[32] = "nine";
	char rus[32];
	if (dict.translate(eng, rus))
	{
		cout<< "Translation "<< eng <<" : ";
		cout << rus << endl;
	}
	else
		cout << "No translation" << eng << endl;
	system("pause");
	return 0;
}
