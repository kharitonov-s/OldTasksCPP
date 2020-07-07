#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

//Функция для вывода матрицы
void printm(double** mat, int n)
{
	for (int i = 0;i<n;++i)
	{
		for (int j = 0;j<n;++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


//Рекурсивная функция для вычисления
//определителя произвольного порядка
//методом разложения по столбцу
double det(double** matrx, int n)
{
	if (n == 1)
	{
		return matrx[0][0];
	}

	double sum = 0;
	double **minor;

	int decr = 0;

	//Цикл для выбора ведущего элемента
	//В 0-м столбце
	for (int i = 0;i<n;++i)
	{
		//Для каждого элемента в столбце
		//нужно сформировать соответствующий минор
		minor = new double*[n - 1];
		//Цикл по всем строчкам
		for (int j = 0;j<n;++j)
		{
			//Если текущая строчка -- это строчка,
			//которая содержит ведущий элемент,
			//то делаем decr = 1, и переходим на следующую
			//(перескакиваем на следующую строчку)
			if (j == i)
			{
				decr = 1;
				continue;
			}

			//Создаем массив для строк в миноре
			//если перескочили через строчку,
			//то индекс для добавления в минор
			//нужно уменьшить на единицу,
			//так как его размер = n-1
			minor[j - decr] = new double[n - 1];
			//Цикл для добавления строки в минор поэлементно
			//начинается с 1, так как 0-й столбец вычеркиваем
			for (int k = 1;k<n;++k)
			{
				//Нумерация в миноре начинается с нуля,
				//Поэтому k-1
				//j-decr -- уменьшаем индекс на единицу,
				//если перескочили через строку
				minor[j - decr][k - 1] = matrx[j][k];
			}
		}
		//Для следующей итерации обнуляем decr
		decr = 0;
		//Добавляем слагаемое к сумме по определению
		//det(minor,n-1) -- рекурсивное вычисление
		//определителя минора
		sum += matrx[i][0] * pow(-1, i + 0)*det(minor, n - 1);

		for (int j = 0;j<n - 1;++j)
			delete[] minor[j];
		delete[] minor;
	}

	return sum;
}

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Hello World!" << endl;
	cin >> n;

	//Создание квадратной матрицы
	//Размера nxn, заполнение
	//случайными числами
	//от 1 до 9
	double **matrx = new double*[n];
	for (int i = 0;i<n;++i)
	{
		matrx[i] = new double[n];
		for (int j = 0;j<n;++j)
			matrx[i][j] = rand() % 9 + 1;
	}

	//Вывод матрицы
	printm(matrx, n);

	//Расчет и вывод определителя
	cout << det(matrx, n) << endl;

	system("pause");
	return 0;
}