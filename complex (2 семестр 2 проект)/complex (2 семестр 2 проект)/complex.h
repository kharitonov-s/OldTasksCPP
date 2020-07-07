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
	//Перегрузка операции сложения
	Complex operator+(Complex);
	Complex operator*(Complex);
	Complex& operator+=(Complex);
	//перегрузка побитовых операций
	//остались &,|,!
	Complex operator^(int);
	//перегрузка операции сравнения
	//(остались >,<,>=,<=,!=) реалицуются по аналогии
	bool operator==(Complex);
	//перегрузка операторов вывода и ввода
	//остался >> (таким же образом, только ostream на istream поменять)
	friend ostream& operator<<(ostream&, Complex);

	//Функция-друг, имеющая доступ к защищенным полям в классе
	friend void getReal(Complex x);

	//что еще можно перегружать:
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
	//Конструкторы
	ComplexPolynom(int n=0, double* arr=nullptr);
	//Деструктор
	~ComplexPolynom();
	//Перегрузка оператора индексации
	double& operator[](int index);
	//Перегрузка оператора вызова функции
	Complex operator()(Complex);
	//Перегрузка операции присваивания
	ComplexPolynom& operator=(ComplexPolynom&);

	int getDegree();

private:
	//Степень полинома
	int degree;
	//Массив коэффициентов
	double* coeffs;

};