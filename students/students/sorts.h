#ifndef SORTS
#define SORTS

#include "sorts.h"
#include <iostream>

using namespace std;

//Функция для сравнения двух
//числовых переменных
template <typename T>
bool Greater(T a, T b)
{
	return a > b;
}

//Функция для сравнения двух
//числовых переменных
template <typename T>
bool GreaterOrEqual(T a, T b)
{
	return a >= b;
}

//Функция для обмена значениями
//двух переменных
template <typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//Вывод массива
template <typename T>
void printa(T *arr, int N)
{
	for (int i = 0;i<N;++i)
		cout << arr[i] << " ";
	cout << endl << endl;
}

//Пузырьковая сортировка
//просто последовательно меняем местами
//соседние элементы, если первый больше второго
template <typename T>
void bubble_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 1;i<N;++i)
		for (int j = 0;j<N - i;++j)
			if (comp(arr[j], arr[j + 1]) == true)
				Swap(arr[j], arr[j + 1]);
}

//Сортировка выбором
//Ищем максимальный элемент и вставляем
//в конец неотсортированной части
template <typename T>
void selection_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 0;i<N - 1;++i)
	{
		int idx = 0;
		for (int j = 1; j<N - i; ++j)
		{
			//Запоминаем индекс максимального
			if (comp(arr[j], arr[idx]) == true)
				idx = j;
		}
		//Вставляем в конец
		Swap(arr[N - i - 1], arr[idx]);
	}
}

//Сортировка вставками
template <typename T>
void insertion_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//i -- индекс последнего элемента в отсортированной части
	for (int i = 0;i<N - 1;++i)
	{
		//Запоминаем значение первого элемента
		//в неотсортированной части (ключевой элемент)
		T key = arr[i + 1];
		//Цикл по отсортированной части
		int j = i;
		for (;j >= 0;--j)
		{
			//Если текущий элемент больше ключевого,
			//сдвигаем текущий вправо
			if (comp(arr[j], key) == true)
				arr[j + 1] = arr[j];
			//Иначе завершаем цикл
			else
				break;
		}
		//Вставляем ключевой элемент
		//в освободившееся место
		arr[j + 1] = key;
	}
}

//Сортировка Шелла
//Последовательность интервалов -- по Д. Кнуту:
//1, 13, 40, 121, ... (s[i] = 3*s[i-1] + 1)
template <typename T>
void Shell_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//Вычисляем максимальный интервал,
	//который меньше размера массива
	int s = 1;
	for (;s<N / 3;s = 3 * s + 1);

	//Цикл, уменьшающий размер интервала
	for (int h = s;h >= 1; h /= 3)
	{
		//Цикл, задающий элемент, от которого
		//отсчитываются интервалы
		for (int i = 0; i < h;++i)
			//Сортировка вставками подпоследовательности
			for (int j = i; j <N - h;j += h)
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
	}
}

//Пирамидальная сортировка
template <typename T>
void Heap_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//1. Построение пирамиды
	for (int k0 = N / 2 - 1; k0 >= 0; --k0)
	{
		int k = k0;
		while (2 * k + 1 < N)
		{
			if (2 * k + 2 < N)
			{
				int maxIdx = comp(arr[2 * k + 1], arr[2 * k + 2]) ? 2 * k + 1 : 2 * k + 2;
				if (comp(arr[maxIdx], arr[k]))
				{
					Swap(arr[maxIdx], arr[k]);
					k = maxIdx;
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
		} //while
	} //for

	  //2.Сортировка на базе пирамиды
	for (int i = 0;i<N;++i)
	{
		Swap(arr[0], arr[N - 1 - i]);
		//Просеиваем элемент сквозь пирамиду
		int k = 0;
		while (2 * k + 1 < N - i - 1)
		{
			if (2 * k + 2 < N - i - 1)
			{
				int maxIdx = comp(arr[2 * k + 1], arr[2 * k + 2]) ? 2 * k + 1 : 2 * k + 2;
				if (comp(arr[maxIdx], arr[k]))
				{
					Swap(arr[maxIdx], arr[k]);
					k = maxIdx;
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
		} //while
	} //for
}

//Быстрая сортировка
template <typename T>
void QSort(T *arr, int lb, int rb, int ncalls = 0, bool(*comp)(T, T) = GreaterOrEqual)
{
	//База рекурсии
	//Размер текущей подпоследовательности
	int N = rb - lb + 1;
	//Если 1 или меньше, то сортировать нечего
	if (N <= 1)
		return;
	//Если два элемента, то меняем их местами,
	//если первый больше второго
	if (N == 2)
	{
		if (comp(arr[lb], arr[rb]))
			Swap(arr[lb], arr[rb]);
		return;
	}

	//ОПТИМИЗАЦИИ:
	//Если размер массива меньше 50,
	//используем сортировку вставками
	const int Nmin = 50;
	if (N < Nmin)
	{
		insertion_sort(arr + lb, N,comp);
		return;
	}

	//Ограничение глубины рекурсии
	//ncalls - номер текущего рекурсивного вызова
	const int Nmaxcalls = 100;
	if (ncalls > Nmaxcalls)
	{
		insertion_sort(arr + lb, N,comp);
		return;
	}

	//Индекс опорного элемента
	int p = lb + N / 2;
	//Значение опорного элемента
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
	QSort(arr, lb, left - 1, ncalls + 1,comp);
	QSort(arr, left + 1, rb, ncalls + 1,comp);
}


#endif // SORTS
