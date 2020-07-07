#include <iostream>
#include <ctime>

using namespace std;

template <typename T> //так задается любой тип даннных
bool Greater(T a, T b)
{
	return a > b;
}

template <typename T> //так задается любой тип даннных
bool GreaterOrEqual(T a, T b)
{
	return a >= b;
}

template <typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
void printa(T *arr, int N)
{
	for (int i = 0;i < N;++i)
		cout << arr[i] << " ";
	cout << endl << endl;
}

//Пузырьковая сортировка
template <typename T>
void bubble_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 1;i < N;++i)
		for (int j = 0;j < N - i;++j)
			if (comp(arr[j], arr[j + 1]) == true)
				Swap(arr[j], arr[j + 1]);
}

//Сортировка выбором
template <typename T>
void selection_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 0;i < N-1;++i)
	{
		int idx = 0;
		for (int j = 1;j < N - i;++j)
		{
			if (comp(arr[j], arr[idx]) == true)
				idx = j;
		}
	
			Swap(arr[N - i - 1], arr[idx]);
	}
}

//Сортировка вставками
template <typename T>
void insertion_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 0;i < N - 1;++i)
	{
		T key = arr[i + 1];
		int j = i;
		for (;j >= 0;--j)
		{
			if (comp(arr[j], key) == true)
				arr[j + 1] = arr[j];
			else
				break;
		}

			arr[j + 1] = key;
	}
}

//Сортировка Шелла (Дональд Шелл)
template <typename T>
void Shell_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	int s = 1;
	for (;s < N / 3;s = 3 * s + 1);

	for (int h = s;h >= 1;h /= 3)
	{
		for (int i = 0;i < h;++i)
			for (int j = i;j < N - h;j += h)
			{
				T key = arr[j + h];
				int k = j;
				for (;k >= 0;k -= h)
				{
					if (comp(arr[k], key) == true)
						arr[k + h] = arr[k];
					else
						break;
				}

					arr[k + h] = key;
			}
		//cout << endl;
		//printa(arr, N);
	}
}

template <typename T>
void Heap_sort(T*arr, int N, bool(*comp)(T, T) = Greater)
{
	//1.построение пирамиды 
	for (int k0 = N / 2 - 1;k0 >= 0;--k0)
	{
		int k = k0;
		while (2 * k + 1 < N)
		{
			if (2 * k + 2 < N)
			{
				int maxidx = comp(arr[2 * k + 1], arr[2 * k + 2]) ? 2 * k + 1 : 2 * k + 2;// сокращенный if находим max 
				if (comp(arr[maxidx], arr[k]))
				{
					Swap(arr[maxidx], arr[k]);
					k = maxidx;
				}
				else
					break;

			}
			else
			{
				if (comp(arr[2 * k + 1], arr[k]))
					Swap(arr[k], arr[2 * k + 1]);
				break;
			}
		}//while 
	}//for 

	 //2 Сортировка на базе пирамиды 
	for (int i = 0;i < N;++i)
	{
		Swap(arr[0], arr[N - 1 - i]);
		//проводим элемент сквозь пирамиду 
		int k = 0;
		while (2 * k + 1 < N - i - 1)
		{
			if (2 * k + 2 < N - i - 1)
			{
				int maxidx = comp(arr[2 * k + 1], arr[2 * k + 2]) ? 2 * k + 1 : 2 * k + 2;// сокращенный if находим max 
				if (comp(arr[maxidx], arr[k]))
				{
					Swap(arr[maxidx], arr[k]);
					k = maxidx;
				}
				else
					break;

			}
			else
			{
				if (comp(arr[2 * k + 1], arr[k]))
					Swap(arr[k], arr[2 * k + 1]);
				break;
			}
		}
	}
}

template <typename T>
void Qsort(T *arr, int lb, int rb, int ncalls, bool(*comp)(T, T) = GreaterOrEqual)
{
	//База рекурсии
	int N = rb - lb + 1;
	if (N <= 1)
		return;
	if (N == 2)
	{
		if (comp(arr[lb], arr[rb]))
			Swap(arr[lb], arr[rb]);
		return;
	}

	//Если размер массива меньше 50
	//используем сортировку вставками
	const int Nmin = 50;
	if (N < Nmin)
	{
		insertion_sort(arr + lb, N);
		return;
	}

	//Ограничение глубины рекурсии
	const int Nmaxcalls = 100;
	if (ncalls > Nmaxcalls)
	{
		insertion_sort(arr + lb, N);
		return;
	}

	int p = lb + N / 2;
	T key = arr[p];

	//Разделение относительно опорного элемента
	int left = lb;
	int right = rb;
	
	while (left < right)
	{
		while (comp(key, arr[left]) && left < p)
			++left;
		while (comp(arr[right], key) && p < right)
			--right;
		if (left >= right) 
			break;
		Swap(arr[left], arr[right]);
		if (left == p)
			p = right;
		else if (right == p)
			p = left;
	}
	//Рекурсия
	Qsort(arr, lb, left - 1,ncalls+1);
	Qsort(arr, left + 1, rb,ncalls+1);
}

//Алгоритмы поиска
//Последовательный поиск
template <typename T>
int sequential_search(T* arr, int N, T key)
{
	for (int i = 0;i < N;++i)
		if (arr[i] == key)
			return i;
	return -1;
}

//Бинарный поиск
template <typename T>
int binary_search(T* arr, int N, T key)
{
	int lb = 0;
	int rb = N - 1;

	while (lb <= rb)
	{
		int mean = lb + (rb - lb) / 2;
		if (key < arr[mean])
			rb = mean - 1;
		else if (key>arr[mean])
			lb = mean + 1;
		else
			return mean;
	}
	return -1;
}

//Интерполяционный поиск

int main()
{
	srand(time(NULL));
	int N = 10000;
	int *arr = new int[N];
	for (int i = 0;i < N;++i)
     	arr[i] = rand() % 21 - 10;
	printa(arr, N);

	clock_t start = clock();
	//bubble_sort(arr, N);
	//selection_sort(arr, N);
	//insertion_sort(arr, N);
	//Shell_sort(arr, N);
	//Heap_sort(arr, N);
	Qsort(arr, 0, N - 1,0);
	clock_t end = clock();
	printa(arr, N);
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;;

	system("pause");
	return 0;
}