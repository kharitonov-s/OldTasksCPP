#include <iostream>
#include "Header.h"
using namespace std;

void objectInfo(Shape* sh)
{
	sh->draw();
	TwoDShape* sh_two;
	ThreeDShape* sh_three;
	//�������� ������������� ���������� �������� ������ � ���������� ���� �����-����������
	sh_two = dynamic_cast<TwoDShape*>(sh);
	if (sh_two != nullptr)
	{
		cout << "Area: " << sh_two->area() << endl;
	}
	else
	{
		sh_three = dynamic_cast<ThreeDShape*>(sh);
		cout << "Volume: " << sh_three->volume() << endl;
	}
}

int main()
{
	Circle crc(3.0);
	crc.draw();
	cout << crc.radius() << " " << crc.area() << endl;
	objectInfo(&crc);
	Cube cb(5.5);
	objectInfo(&cb);

	//� ������, ���� ���������� ���� ������-���������� 
	//��������� ��� ������ ��������� �� ������� �����
	//������� �����������, � ����� �������,
	//�� ���������� ������ ���������� �������� ������.
	//����� ����� ��������, ���������� �������� ������ ����� �������� ��� virtual

	//  Shape* triangle = new Triangle;
	//  delete triangle;

	system("pause");
	return 0;
}