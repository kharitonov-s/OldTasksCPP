#include <iostream>
#include <ctime>
#include "sorts.h"
#include "SEARCHES.h"
#include "structs.h"

using namespace std;

int main()
{
	srand(time(NULL));
	//Количество элементов в последовательности
	int N = 10;
	/*int *arr = new int[N];
	for (int i = 0;i<N;++i)
		arr[i] = rand() % N;*/
	//    double *arr = new double[N];
	//    for (int i=0;i<N;++i)
	//        arr[i] = rand()/RAND_MAX;

	Point *arrP = new Point[N];
	for (int i = 0;i < N;++i)
		rand_point(arrP[i]);

	print_point_array(arrP, N);

	//printa(arr,N);
	clock_t start = clock();
	//bubble_sort(arr,N);
	//selection_sort(arr,N);
	//insertion_sort(arr,N);
	//Shell_sort(arr,N);
	//Heap_sort(arr,N);
	QSort(arrP, 0, N - 1,0,distCmpless);
	clock_t end = clock();
	//printa(arr,N);

	cout << "Sorting time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	cout << endl;
	print_point_array(arrP, N);

	/*int keyElem = N - 10;
	start = clock();
	//int index = sequential_search(arr,N,keyElem);
	//int index = binary_search(arr,N,keyElem);
	int index = interp_search(arr, N, keyElem);
	end = clock();
	cout << "KeyElem is: " << keyElem << endl;
	cout << "KeyElem index is: " << index << endl;
	cout << "Searching time is: " << (double)(end - start) / CLOCKS_PER_SEC << endl; */


	//delete[] arr;
	delete[] arrP;
	system("pause");
	return 0;
}