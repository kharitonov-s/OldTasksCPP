#pragma once
#include <iostream>
#include <exception>

using namespace std;

class Complex
{
public:
	Complex(double r = 0, double i = 0);

	double real() const;
	double imag() const;

	void print() const;
	//���������� �������� ��������
	Complex operator+(Complex);
	Complex operator*(Complex);
	Complex& operator+=(Complex);
	//���������� ��������� ��������
	//�������� &,|,!
	Complex operator^(int);
	//���������� �������� ���������
	//(�������� >,<,>=,<=,!=) ����������� �� ��������
	bool operator==(Complex);
	//���������� ���������� ������ � �����
	//������� >> (����� �� �������, ������ ostream �� istream ��������)
	friend ostream& operator<<(ostream&, Complex);

	//�������-����, ������� ������ � ���������� ����� � ������
	friend void getReal(Complex x);

	//��� ��� ����� �����������:
	//=
	//()
	//[]
	//?<>


private:
	double im;
	double re;
};

class ComplexPolynom
{
public:
	//������������
	ComplexPolynom(int n=0, double* arr=nullptr);
	//����������
	~ComplexPolynom();
	//���������� ��������� ����������
	double& operator[](int index);
	//���������� ��������� ������ �������
	Complex operator()(Complex);
	//���������� �������� ������������
	ComplexPolynom& operator=(ComplexPolynom&);

	int getDegree();

private:
	//������� ��������
	int degree;
	//������ �������������
	double* coeffs;

};