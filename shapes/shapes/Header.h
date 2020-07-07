#pragma once
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159

//Aбстрактный базовый класс, хранилище общих свойств для всех потомков всех уровней:
class Shape 
{
public:
	virtual void draw() const = 0;//чистая виртуальная функция для отрисовки (вывода на консоль)

};

//абстрактный базовый класс для двумерных фигур:
class TwoDShape : public Shape 
{
public:
	virtual double area() const = 0;//площадь
};

//абстрактный базовый класс для трехмерных фигур:
class ThreeDShape : public Shape 
{
public:
	virtual double volume() const = 0;//объем
};

class Circle : public TwoDShape
{
private:
	double r;
public:
	Circle(double rv = 1.0) { r = rv; }
	double radius() { return r; }
	void draw() const override
	{
		cout << "Circle with radius " << r << endl;
	}
	double area() const override
	{
		return PI*r*r;
	}
};

class Square : public TwoDShape
{
private:
	double side;
public:
	Square(double side_val = 0) { side = side_val; }
	double getSide() { return side; }
	void draw() const override
	{
		cout << "Square with side " << side << endl;
	}
	double area() const override
	{
		return side*side;
	}
};

class Triangle : public TwoDShape
{
private:
	double a, b, c;
public:
	Triangle(double av = 1.0, double bv = 1.0, double cv = 1.0)
	{
		a = av;
		b = bv;
		c = cv;
	}
	double getA() const { return a; }
	double getB() const { return b; }
	double getC() const { return c; }
	void draw() const override
	{
		cout << "Triangle: " << a << " " << b << " " << c << endl;
	}
	double area() const override
	{
		double pp = (a + b + c) / 2;
		return sqrt(pp*(pp - a)*(pp - b)*(pp - c));
	}
};

class Sphere : public ThreeDShape
{
private:
	double r;
public:
	Sphere(double rv = 1.0) { r - rv; }
	double radius() const { return r; }
	void draw() const override
	{
		cout << "Sphere with radius " << r << endl;
	}
	double volume() const override
	{
		return 4 * PI*r*r*r / 3;
	}
};
class Cube : public ThreeDShape
{
private:
	double side;
public:
	Cube(double side_val = 1.0) { side = side_val; }
	double getSide() const { return side; }
	void draw() const override
	{
		cout << "Cube with side " << side << endl;
	}
	double volume() const override
	{
		return side*side*side;
	}
};

class Tetrahedron : public ThreeDShape //тетраэдр
{
private:
	double side;
public:
	Tetrahedron(double side_val = 1.0) { side = side_val; }
	double getSide() const { return side; }
	void draw() const override
	{
		cout << "Tetrahedron with side " << side << endl;
	}
	double volume() const override
	{
		return sqrt(2.0) / 12 * side*side*side;
	}
};
