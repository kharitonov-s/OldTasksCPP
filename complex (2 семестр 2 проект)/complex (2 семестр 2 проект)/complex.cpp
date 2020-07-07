#include "complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double r, double i)
{
	re = r;
	im = i;
}

double Complex::real() const
{
	return re;
}

double Complex::imag() const
{
	return im;
}

void Complex::print() const
{
	cout << re << "+" << im << "i" << endl;
}

Complex Complex::operator+(Complex c2)
{
	Complex res(re+c2.real(),im+c2.imag());
	return res;
}

Complex Complex::operator*(Complex c2)
{
	double r = re*c2.real() - im*c2.imag();
	double i = re*c2.imag() + im*c2.real();
	Complex res(r,i);
	return res;
}

Complex& Complex::operator+=(Complex c2)
{
	re += c2.real();
	im += c2.imag();

	return *this;
}

Complex Complex::operator^(int power)
{
	if (power == 0)
		return Complex(1, 0);

	Complex res=*this;
	for (int i = 1;i < power;++i)
		res = res*(*this);
	return res;
}

//с1==с2 <=> с1.operator==(c2)
bool Complex::operator==(Complex c2)
{
	if ((re == c2.real(), im == c2.imag()))
		return true;
	else
		return false;

}
//cout<<c1; <=> operator<<(cout,c1);
ostream& operator<<(ostream& out, Complex c1)
{
	c1.print();
	return out;
}

void getReal(Complex x)
{
	cout << x.re << endl;
}

ComplexPolynom::ComplexPolynom(int n, double* arr)
{
	coeffs = new double[n];
	degree = n-1;
	if (arr != nullptr)
	{
		for (int i = 0;i <= degree;++i)
			coeffs[i] = arr[i];
	}
	else
	{
		for (int i = 0;i <= degree;++i)
			coeffs[i] = 1;
	}
}

ComplexPolynom::~ComplexPolynom()
{
	if (coeffs != nullptr)
		delete[] coeffs;
}

//Перегрузка оператора индексации
double& ComplexPolynom::operator[](int index)
{
	if (index<0 || index>degree)
		throw range_error("Index out of range");
	return coeffs[index];
}

//Перегрузка оператора вызова функции
Complex ComplexPolynom::operator()(Complex z)
{
	Complex Pz;

	for (int i = 0;i <= degree;++i)
	{
		Complex ci(coeffs[i], 0);
		Pz += ci * (z ^ (degree - i));
	}

	return Pz;
}

int ComplexPolynom::getDegree()
{
	return degree;
}

//Перегрузка операции присваивания
ComplexPolynom& ComplexPolynom::operator=(ComplexPolynom& P)
{
	if (coeffs != nullptr)
		delete[] coeffs;
	if (this == &P)
		return *this;

	degree = P.getDegree();
	coeffs = new double[degree+1];
	for (int i = 0;i <= degree;++i)
		coeffs[i] = P[i];
	return *this;
}
