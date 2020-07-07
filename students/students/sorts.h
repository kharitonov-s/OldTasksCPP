#ifndef SORTS
#define SORTS

#include "sorts.h"
#include <iostream>

using namespace std;

//������� ��� ��������� ����
//�������� ����������
template <typename T>
bool Greater(T a, T b)
{
	return a > b;
}

//������� ��� ��������� ����
//�������� ����������
template <typename T>
bool GreaterOrEqual(T a, T b)
{
	return a >= b;
}

//������� ��� ������ ����������
//���� ����������
template <typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//����� �������
template <typename T>
void printa(T *arr, int N)
{
	for (int i = 0;i<N;++i)
		cout << arr[i] << " ";
	cout << endl << endl;
}

//����������� ����������
//������ ��������������� ������ �������
//�������� ��������, ���� ������ ������ �������
template <typename T>
void bubble_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 1;i<N;++i)
		for (int j = 0;j<N - i;++j)
			if (comp(arr[j], arr[j + 1]) == true)
				Swap(arr[j], arr[j + 1]);
}

//���������� �������
//���� ������������ ������� � ���������
//� ����� ����������������� �����
template <typename T>
void selection_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	for (int i = 0;i<N - 1;++i)
	{
		int idx = 0;
		for (int j = 1; j<N - i; ++j)
		{
			//���������� ������ �������������
			if (comp(arr[j], arr[idx]) == true)
				idx = j;
		}
		//��������� � �����
		Swap(arr[N - i - 1], arr[idx]);
	}
}

//���������� ���������
template <typename T>
void insertion_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//i -- ������ ���������� �������� � ��������������� �����
	for (int i = 0;i<N - 1;++i)
	{
		//���������� �������� ������� ��������
		//� ����������������� ����� (�������� �������)
		T key = arr[i + 1];
		//���� �� ��������������� �����
		int j = i;
		for (;j >= 0;--j)
		{
			//���� ������� ������� ������ ���������,
			//�������� ������� ������
			if (comp(arr[j], key) == true)
				arr[j + 1] = arr[j];
			//����� ��������� ����
			else
				break;
		}
		//��������� �������� �������
		//� �������������� �����
		arr[j + 1] = key;
	}
}

//���������� �����
//������������������ ���������� -- �� �. �����:
//1, 13, 40, 121, ... (s[i] = 3*s[i-1] + 1)
template <typename T>
void Shell_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//��������� ������������ ��������,
	//������� ������ ������� �������
	int s = 1;
	for (;s<N / 3;s = 3 * s + 1);

	//����, ����������� ������ ���������
	for (int h = s;h >= 1; h /= 3)
	{
		//����, �������� �������, �� ��������
		//������������� ���������
		for (int i = 0; i < h;++i)
			//���������� ��������� ���������������������
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

//������������� ����������
template <typename T>
void Heap_sort(T *arr, int N, bool(*comp)(T, T) = Greater)
{
	//1. ���������� ��������
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

	  //2.���������� �� ���� ��������
	for (int i = 0;i<N;++i)
	{
		Swap(arr[0], arr[N - 1 - i]);
		//���������� ������� ������ ��������
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

//������� ����������
template <typename T>
void QSort(T *arr, int lb, int rb, int ncalls = 0, bool(*comp)(T, T) = GreaterOrEqual)
{
	//���� ��������
	//������ ������� ���������������������
	int N = rb - lb + 1;
	//���� 1 ��� ������, �� ����������� ������
	if (N <= 1)
		return;
	//���� ��� ��������, �� ������ �� �������,
	//���� ������ ������ �������
	if (N == 2)
	{
		if (comp(arr[lb], arr[rb]))
			Swap(arr[lb], arr[rb]);
		return;
	}

	//�����������:
	//���� ������ ������� ������ 50,
	//���������� ���������� ���������
	const int Nmin = 50;
	if (N < Nmin)
	{
		insertion_sort(arr + lb, N,comp);
		return;
	}

	//����������� ������� ��������
	//ncalls - ����� �������� ������������ ������
	const int Nmaxcalls = 100;
	if (ncalls > Nmaxcalls)
	{
		insertion_sort(arr + lb, N,comp);
		return;
	}

	//������ �������� ��������
	int p = lb + N / 2;
	//�������� �������� ��������
	T key = arr[p];

	//���������� ������������ �������� ��������
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

	//��������
	QSort(arr, lb, left - 1, ncalls + 1,comp);
	QSort(arr, left + 1, rb, ncalls + 1,comp);
}


#endif // SORTS
