#ifndef SEARCHES
#define SEARCHES

//Алгоритмы поиска
//Последовательный поиск
//Работает на любых последовательностях
template <typename T>
int sequential_search(T* arr, int N, T key)
{
	for (int i = 0;i<N;++i)
		if (arr[i] == key)
			return i;
	return -1;
}

//Следующие два алгоритма
//работают ТОЛЬКО на отсортированных
//последовательностях!

//Бинарный поиск
template <typename T>
int binary_search(T* arr, int N, T key, bool (&comp)(T,T))
{
	//Индекс крайнего левого элемента
	int lb = 0;
	//Индекс крайнего правого элемента
	int rb = N - 1;

	while (lb <= rb)
	{
		//Индекс элемента посередине
		int mean = lb + (rb - lb) / 2;
		//Если то, что мы ищем, меньше того, что
		//лежит в этом индексе, то будем искать в левой части массива
		if (comp(arr[mean],key))
			rb = mean - 1;
		//...а если больше, то слева
		else if (comp(key,arr[mean]))
			lb = mean + 1;
		else
			return mean;
	}
	return -1;
}

//Интерполяционный поиск
//Эффективен, если элементы в последовательности
//увеличиваются линейно.
//А вообще, если известен характер возрастания (функция),
//то линейную интерполяцию можно заменить на эту функцию.
template <typename T>
int interp_search(T *p, int n, T key) {
	int lb = 0, rb = n - 1;
	while (lb <= rb)
	{
		//Если правая и левая границы совпали,
		//то сравниваем с текущим элементом
		if (p[rb] == p[lb])
		{
			if (p[lb] == key)
				return lb;
			else
				return -1;
		}
		//Строим уравнение прямой, проходящей через первый
		//и последний элемент последовательности:
		//это зависимость y = k*x + b,
		//где y -- значение элемента, а x -- его индекс
		//Выражаем x = (y-b)/k, и подставляем вместо y наш key
		int index = lb + (rb - lb) / (p[rb] - p[lb])*(key - p[lb]);
		//Если вылетели за границы массива,
		//остановимся на них
		if (index > rb)
			index = rb;
		else if (index < lb)
			index = lb;
		//Дальше действуем так же, как в двоичном поиске
		if (key < p[index])
			rb = index - 1;
		else if (p[index] < key)
			lb = index + 1;
		else
			return index;
	}
	return -1;
}



#endif // SEARCHES

