#ifndef SEARCHES
#define SEARCHES

//��������� ������
//���������������� �����
//�������� �� ����� �������������������
template <typename T>
int sequential_search(T* arr, int N, T key)
{
	for (int i = 0;i<N;++i)
		if (arr[i] == key)
			return i;
	return -1;
}

//��������� ��� ���������
//�������� ������ �� ���������������
//�������������������!

//�������� �����
template <typename T>
int binary_search(T* arr, int N, T key, bool (&comp)(T,T))
{
	//������ �������� ������ ��������
	int lb = 0;
	//������ �������� ������� ��������
	int rb = N - 1;

	while (lb <= rb)
	{
		//������ �������� ����������
		int mean = lb + (rb - lb) / 2;
		//���� ��, ��� �� ����, ������ ����, ���
		//����� � ���� �������, �� ����� ������ � ����� ����� �������
		if (comp(arr[mean],key))
			rb = mean - 1;
		//...� ���� ������, �� �����
		else if (comp(key,arr[mean]))
			lb = mean + 1;
		else
			return mean;
	}
	return -1;
}

//���������������� �����
//����������, ���� �������� � ������������������
//������������� �������.
//� ������, ���� �������� �������� ����������� (�������),
//�� �������� ������������ ����� �������� �� ��� �������.
template <typename T>
int interp_search(T *p, int n, T key) {
	int lb = 0, rb = n - 1;
	while (lb <= rb)
	{
		//���� ������ � ����� ������� �������,
		//�� ���������� � ������� ���������
		if (p[rb] == p[lb])
		{
			if (p[lb] == key)
				return lb;
			else
				return -1;
		}
		//������ ��������� ������, ���������� ����� ������
		//� ��������� ������� ������������������:
		//��� ����������� y = k*x + b,
		//��� y -- �������� ��������, � x -- ��� ������
		//�������� x = (y-b)/k, � ����������� ������ y ��� key
		int index = lb + (rb - lb) / (p[rb] - p[lb])*(key - p[lb]);
		//���� �������� �� ������� �������,
		//����������� �� ���
		if (index > rb)
			index = rb;
		else if (index < lb)
			index = lb;
		//������ ��������� ��� ��, ��� � �������� ������
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

