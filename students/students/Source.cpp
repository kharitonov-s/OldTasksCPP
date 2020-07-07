#include <iostream>
#include "sorts.h"
#include "SEARCHES.h"
#include "structs.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int N = 4;
	Student* st = new Student[N];
	edit_student("Vasily", "Pupkin", 105, 1997,st[0]);
	edit_student("Sergey", "Simakov", 105, 1998, st[2]);
	edit_student("Evgeny", "Catana", 666, 0, st[3]);
	edit_student("Anton", "Borontsov", 105, 1997, st[1]);

	for (int i = 0;i < N;++i)
	{
		print_student(st[i]);
	}
	cout << endl;

	insertion_sort(st, N,LastNameCmp);

	for (int i = 0;i < N;++i)
		print_student(st[i]);

	Student keySt;
	keySt.LastName = "Simakov";
	int ind = binary_search(st, N, keySt,LastNameCmp);

	cout << endl;
	print_student(st[ind]);
	

	system("pause");
	return 0;
}