#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "RUS");
	cout << "Hello World!" << endl << endl;

	//����� ���������� ����������
	cout << "number of args: " << argc << endl;

	//����� ����� ����������
	for (int i = 0;i<argc;++i)
		cout << argv[i] << endl;

	//���� ��������� ����,
	//�� ������� ������ �� ���
	//� ����� ������������ ��� �����
	if (argc > 1)
	{
		int n = atoi(argv[1]);
		cout << n + 1 << endl;
	}

	system("pause");
	return 0;
}
