#pragma once
#include <iostream>
using namespace std;
//������� �����-��������
class A
{
private:
	int x;
protected:
	double y;
public:
	char z;
	void set_x(int x_val) { x = x_val; }
	int get_x() { return x; }
	A(int x_val = 0, double y_val = 0, char z_val = 0)
	{
		x = x_val;
		y = y_val;
		z = z_val;
	}
	virtual void print()
	{
		cout << x << " " << y << " " << z << " " << endl;
	}
	//c++11
	//��������� �����: ������� �� ����� ������ ����������
	virtual void final_method() final { cout << "Final" << endl; }
	virtual void override_method()
	{
		cout << "override" << endl;
	}

	//������ ����������� ������� (� ������� ��� ����������)
	//virtual void pure_virtual() = 0;
};

class B : public A //������� ��� ����� �, : ��� ������������ � �� ����
{
private:
	int bx;
public:
	B(int xv = 1, double yv = 1.0, char zv = '1', int bxv = 0) : A(xv, yv, zv)
	{
		bx = bxv;
		//������ ���������� � private ����� ������ ��������
		//x = xv; 
		//����� ���������� � public- � protected-�����
		z = 'c';
		y = 10;
	}
	void print()
	{
		cout << get_x() << " " << y << " " << z << " " << bx << endl;
	}
	void override_method() override
	{
		cout << "override B" << endl;
	}
	//void final_method()//������: ������ �������������� ��������� �����
	//{
	//	cout << "Final B" << endl;
	//}
	//void pure_virtual()
	//{
	//	cout << "Pure virtual method" << endl;
	//}
};

//protected-������������
 //private ��������� � private ��� ����������� ������� ��������
//protected ��������� � protected � � ���� ����� ����������
//public ��������� � protected
class C : protected A
{
public:
	C(int xv = 3, double yv = 3.0, char zv = '3') : A(xv, yv, zv)
	{

	}
	void set_z(char zv) { z = zv; }
	char get_z() { return z; }
	int get_xv() { return get_x(); }
};

//private-������������
//private ��������� � private ��� ����������� �������
//public,protected �������� � private � ������ ������ ����� ����������
class D : private A
{
public:
	D(int xv = 4, double yv = 4.0, char zv = '4') : A(xv, yv, zv)
	{

	}
	int get_xv() { return get_x(); }
	double get_y() { return y; }
};