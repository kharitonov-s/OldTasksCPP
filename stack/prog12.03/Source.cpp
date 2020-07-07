#include <iostream>
#include "stack.h"
#include <cstring>
using namespace std;

int calculate(char *str)
{
	int n = strlen(str);
	Stack<int> st(32);
	for (int i = 0;i < n;++i)
	{
		if (isdigit(str[i]))
			st.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '*') //если символ является операцией...
		{
			int num1, num2;
			if (!st.pop(num1)) //...вынимаем два последних числа...
			{
				cout << "Error!" << endl;
				return 0;
			}
			if (!st.pop(num2))
			{
				cout << "Error!" << endl;
				return 0;
			}
			if (str[i] == '+') //...и проводим с ними ту операцию
				st.push(num1 + num2);
			else
				st.push(num1*num2);
		}
	}
	int res;
	if (st.pop(res))//результат вычисления должен оказаться на вершине стэка
		return res;
	else
	{
		cout << "Error!" << endl;
		return 0;
	}
}

int main()
{
	Stack<int> st;
	cout << st;
	st.push(100);
	st.push(500);
	cout << st;
	
	int item = 0;
	if (st.pop(item))
		cout << item << endl;
	char str[64] = "7 5 9 + *";
	int n = strlen(str);
	cout << calculate(str) << endl;
	
	system("pause");
	return 0;
}