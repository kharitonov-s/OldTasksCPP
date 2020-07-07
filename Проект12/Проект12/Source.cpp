#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

double F(double x) {
	return (x*x - sin(x));
}

//Пассивный поиск

void passive(double(*F)(double x), double k = 0.05, double a = 0, double b = 3.14159265 / 2)
{
	bool t = 0;
	int count = 0;
	double x = a;
	while ((F(x) > F(x + k)) && (x<b))
	{
		count++;
		x += k;
		t = 1;
	}
	if (t = 1)  std::cout << "count =      " << count << "\n x=      " << x << std::endl;
	else std::cout << "error\n";
}

//Метод дихотомии

void dichotomy(double(*F)(double x), double d = 0.01, double a = 0, double b = 3.14159265, double eps = 0.01)
{

	double a1 = a;
	double b1 = b;
	int count = 0;
	while ((b1 - a1) / 2 > eps)
	{
		double c1 = (a1 + b1) / 2 - d / 2;
		double d1 = (a1 + b1) / 2 + d / 2;
		if (F(c1) <= F(d1)) b1 = d1;
		else a1 = c1;
		count++;
	}
	std::cout << "count =      " << count << "\n x=      " << a1 + (b1 - a1) / 2 << std::endl;
}

//метод золотого сечения
void goldensect(double(*F)(double x), double d = 0.01, double a = 0, double b = 3.14159265, double eps = 0.01)
{
	double a1 = a;
	double b1 = b;
	int count = 0;
	double c1, d1;
	c1 = ((3 - sqrt(5)) / 2)*(b1 - a1) + a1;
	d1 = ((sqrt(5) - 1) / 2)*(b1 - a1) + a1;
	while ((b1 - a1) / 2 > eps)
	{

		if (F(c1) <= F(d1)) {
			b1 = d1;
			d1 = c1;
			c1 = ((3 - sqrt(5)) / 2)*(b1 - a1) + a1;
		}
		else {
			a1 = c1;
			c1 = d1;
			d1 = ((sqrt(5) - 1) / 2)*(b1 - a1) + a1;
		}
		if (F(c1) < F(d1))b1 = d1;
		else a1 = c1;
		count++;
	}
	std::cout << "count =      " << count << "\n x=      " << a1 + (b1 - a1) / 2 << std::endl;

}

double tan(double(*F)(double x), double x)
{
	double eps = 0.0001;
	return (F(x + eps) - F(x)) / eps;
}

double tan2(double(*F)(double x), double x)
{
	double eps = 0.0001;
	return ((F(x + eps) - 2 * F(x) + F(x - eps)) / pow(eps, 2));
}

//метод секущих
void sek(double(*F)(double x), double d = 0.05, double a = 0, double b = 3.14159265, double eps = 0.05)
{
	double a1 = a;
	double b1 = b;
	int count = 0;
	double x1 = a;
	double x2 = a;
	double x3 = a;
	x2 = x1 - tan(F, x1) / tan2(F, x1);
	while ((abs(tan(F, x1)) > eps))
	{

		x3 = x2 - tan(F, x2)*((x2 - x1) / (tan(F, x2) - tan(F, x1)));
		x1 = x2;
		x2 = x3;
		std::cout <<
			"x =    " << x2 << std::endl <<
			"x' =   " << tan(F, x2) << std::endl;
		count++;

	}
	std::cout << "count =      " << count + 1 << "\n x=      " << x1 << std::endl;
}

//МНОГОМЕРНАЯ
//
//
//
//
//
//
//

double F2(double x1, double x2)
{
	return (x1*x1 + pow(2.71828182,(x1*x1 + x2*x2)) + 4 * x1 + 3 * x2);
}

struct gradient
{
	double i, j;
	void init(double(*F)(double x1, double x2), double x1, double x2, double eps = 0.00000001)
	{
		i = (F(x1 + eps, x2) - F(x1, x2)) / eps;
		j = (F(x1, x2 + eps) - F(x1, x2)) / eps;
	}
	double abs()
	{
		return sqrt(i*i + j*j);
	}
};

//Покоординатный спуск

void coordinateDescentMethod(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.01, double d = 0.0001)
{
	cout << "COORDINATE DESCENT" << endl;

	unsigned counter = 0;
	double   x1, y1;
	gradient g;


	x1 = x0;
	y1 = y0;

	g.init(F, x1, y1);



	double start_time = clock() / (double)CLOCKS_PER_SEC;
	do
	{
		x0 = x1;
		y0 = y1;


		if (F(x1, y1) > F(x1 + d, y1))
			while (F(x1, y1) > F(x1 + d, y1))
			{
				x1 = x1 + d;
			}
		else
			while (F(x1, y1) > F(x1 - d, y1))
			{
				x1 = x1 - d;
			}
		if (F(x1, y1) > F(x1, y1 + d))
			while (F(x1, y1) > F(x1, y1 + d))
			{
				y1 = y1 + d;
			}
		else
			while (F(x1, y1) > F(x1, y1 - d))
			{
				y1 = y1 - d;
			}

		g.init(F, x1, y1);
		counter++;
	} while (g.abs() > eps);
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << endl << endl;

}

//градиентный метод с дроблением шага
void gradientWithSplittingStep(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.000001, double d = 0.000001)
{
	cout << "GRADIENT WITH SPLITTING STEP" << endl << endl;

	unsigned counter = 0;
	double   x01, y01, x1, y1;

	x01 = x0;
	y01 = y0;

	x1 = x0;
	y1 = y0;


	double   step = alpha;
	gradient g;
	g.init(F, x0, y0);

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	while (g.abs() > d)
	{
		while (true)
		{
			x01 = x1 - step * g.i;
			y01 = y1 - step * g.j;
			if (F(x01, y01) - F(x1, y1) <= (-1.) * step * eps * pow(g.abs(), 2))
			{
				x1 = x01;
				y1 = y01;

				break;
			}
			else step = step * 0.1;
		}
		g.init(F, x1, y1);
		counter++;
	}
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	cout << "Step = " << step << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << endl << endl;
}

//градиентный метод с постоянным шагом

void gradientWithFixedStep(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.01, double d = 0.001)
{
	cout << "GRADIENT WITH FIXED STEP" << endl << endl;

	unsigned counter = 0;
	double   x1, y1;

	x1 = x0;
	y1 = y0;


	double   step = alpha;
	gradient g;
	g.init(F, x0, y0);

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	while (g.abs() > d)
	{
		x1 = x1 - step * g.i;
		y1 = y1 - step * g.j;
		g.init(F, x1, y1);

		counter++;
	}
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	cout << "Step = " << step << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << endl << endl;
}

//вспомогательная для мнгс(принимает на вход функцию и точку, возвращает оптимальное a, чтобы вычислить точку)
double alpha_k(double(*F)(double x1, double x2), double x1, double x2)
{
	gradient g;
	g.init(F, x1, x2);

	double a = 0;
	double d = 0.0000005;

	if (F(x1 - a * g.i, x2 - a * g.j) > F(x1 - (a + d) * g.i, x2 - (a + d) * g.j))
		while (F(x1 - a * g.i, x2 - a * g.j) > F(x1 - (a + d) * g.i, x2 - (a + d) * g.j))
			a += d;
	else
		while (F(x1 - a * g.i, x2 - a * g.j) > F(x1 - (a - d) * g.i, x2 - (a - d) * g.j))
			a -= d;
	return a;
}

//МНГС
void fastestGradientDescentMethod(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.01, double d = 0.000001)
{
	cout << "FASTEST GRADIENT DESCENT" << endl << endl;

	unsigned counter = 0;
	double   x1, y1;

	x1 = x0;
	y1 = y0;

	double   step = alpha;
	gradient g;
	g.init(F, x0, y0);

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	while (g.abs() > eps)
	{
		step = alpha_k(F, x1, y1);
		x1 = x1 - step * g.i;
		y1 = y1 - step * g.j;
		g.init(F, x1, y1);

		counter++;
	}
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	//cout << "Step = " << step << endl;
	cout << g.abs() << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << endl << endl;
}

//вспомогательная для ускоренного

double p(double(*F)(double x1, double x2), double x1, double x2, double v1, double v2)
{
	double a = 10;
	double d = 0.05;

	if (F(x1 - v1, x2 - v2) > F(x1 - (a + d) * v1, x2 - (a + d) * v2))
		while (F(x1 - v1, x2 - v2) > F(x1 - (a + d) * v1, x2 - (a + d) * v2))
			a += d;
	else
		while (F(x1 - a * v1, x2 - a * v2) > F(x1 - (a - d) * v1, x2 - (a - d) * v2))
			a -= d;

	return a;
}

//ускореный градиентный метод p-го порядка

void acceleratedGradient(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.01, double d = 0.000001)
{
	cout << "ACCELERATED GRADIENT" << endl << endl;

	unsigned counter = 0;
	double   x1, y1;

	x1 = x0;
	y1 = y0;

	double   step = alpha;
	double   step2;
	gradient g;
	g.init(F, x0, y0);

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	do
	{
		int qwe = 0;

		x0 = x1;
		y0 = y1;
		while (qwe < 3 & g.abs() > eps)
		{
			step = alpha_k(F, x1, y1);

			x1 = x1 - step * g.i;
			y1 = y1 - step * g.j;

			g.init(F, x1, y1);
			counter++;
			qwe++;
		}
		if (g.abs() <= eps)break;
		step2 = p(F, x0, y0, x1 - x0, y1 - y0);
		x1 = x0 - step2 * (x1 - x0);
		y1 = y0 - step2 * (y1 - y0);
		g.init(F, x1, y1);

		counter++;
		//cout << g.abs() << endl;

	} while (g.abs() > eps);
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << ")" << endl << endl;
}

//Овражный метод

void ravineMethod(double(*F)(double x1, double x2), double alpha = 0.00000000000000001, double x0 = 1., double y0 = 1., double eps = 0.00100000, double d = 0.0000000000000001)
{
	cout << "RAVINE" << endl << endl;

	unsigned counter = 0;
	double   x01, y01, x1, y1;

	x1 = x0;
	y1 = y0;

	x01 = x1 + d;
	y01 = y1 + d;

	double   step = alpha;
	double   step2 = alpha;
	gradient g, g2;
	g.init(F, x0, y0);
	g2.init(F, x01, y01);

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	while (g.abs() > eps)
	{
		//cout << "step1" << endl;
		int qwe = 0;
		while (qwe < 3 & g.abs() > d)
		{
			step = alpha_k(F, x1, y1);
			x1 = x1 - step * g.i;
			y1 = y1 - step * g.j;
			g.init(F, x1, y1);

			step2 = alpha_k(F, x01, y01);
			x01 = x01 - step2 * g2.i;
			y01 = y01 - step2 * g2.j;
			g2.init(F, x01, y01);
			qwe++;
			counter++;
		}

		step = p(F, x0, y0, x01 - x1, y01 - y1);
		if (g.abs() <= eps)break;
		x1 = x1 - step * (x01 - x1);
		y1 = y1 - step * (y01 - y1);
		g.init(F, x1, y1);
		counter++;
	}
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << ")" << endl << endl;
}

//флетчера - ривза
void conjugateDirections(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1., double y0 = 1., double eps = 0.1, double d = 0.000001)
{
	cout << "CONJUGATE DIRECTIONS (FLETCHER - REEVES)" << endl << endl;

	unsigned counter = 0;
	double   d01, d02, d11, d12;
	double   x1, y1;
	double   step = alpha;
	double   beta;
	gradient g, g2;

	x1 = x0;
	y1 = y0;
	g.init(F, x0, y0);
	g2.init(F, x0, y0);
	d01 = (-1.) * g.i;
	d02 = (-1.) * g.j;

	double start_time = clock() / (double)CLOCKS_PER_SEC;
	while (g.abs() > eps)
	{
		step = alpha_k(F, x1, y1);

		g2.init(F, x1, y1);
		x1 = x1 - step * g.i;
		y1 = y1 - step * g.j;
		g.init(F, x1, y1);

		beta = pow(g.abs(), 2) / pow(g2.abs(), 2);
		d11 = (-1.) * g.i + beta * d01;
		d12 = (-1.) * g.j + beta * d02;

		g2.init(F, x1, y1);
		x1 = x1 + step * d11;
		y1 = y1 + step * d12;
		g.init(F, x1, y1);

		d01 = d11;
		d02 = d12;

		counter++;
		if ((counter + 1) % 3 == 0)
			beta = 0;
	}
	double end_time = clock() / (double)CLOCKS_PER_SEC;

	cout << "Computation time: " << (end_time - start_time) << " seconds" << endl;
	cout << "Num of iterations = " << counter << endl;
	//cout << "Step = " << step << endl;
	cout << "Xmin = \t(" << x1 << "; " << y1 << "; " << ")" << endl << endl;
}

double am(double(*F)(double x1, double x2), double x1, double x2, double a, double b, double c, double d)
{
	gradient g;
	g.init(F, x1, x2);
	double alpha = 0;
	double dett = 0.0005;
	while (F(x1 - alpha*(a*g.i + b*g.j), x2 - alpha*(c*g.i + d*g.j)) > F(x1 - (alpha + dett)*(a*g.i + b*g.j), x2 - (alpha + dett)*(c*g.i + d*g.j)))alpha += dett;
	return alpha;
}

//квази-ньютон

void KNuton(double(*F)(double x1, double x2), double alpha = 0.001, double x0 = 1, double y0 = 1, double eps = 0.00001, double dett = 0.00001)
{

	int count = 0;
	double x1, y1;
	x1 = x0;
	y1 = y0;
	double alf = alpha;
	gradient g, g0;
	g.init(F, x0, y0);
	g0.init(F, x0, y0);
	double a, b, c, d;
	a = 1;
	b = 0;
	c = 0;
	d = 1;
	//std::cout << a << b << c << d;
	//system("pause");
	while (g.abs() > eps)
	{
		a = 1;
		b = 0;
		c = 0;
		d = 1;
		x0 = x1; y0 = y1;
		alf = am(F, x1, y1, a, b, c, d);
		x1 = x1 - alf*(a*g.i + b*g.j);
		y1 = y1 - alf*(c*g.i + d*g.j);
		g.init(F, x1, y1);
		g0.init(F, x0, y0);
		count++;
		std::cout << "count =      " << count << "\n a=      " << alf << "\n x,y=      " << x1 << " " << y1 << std::endl;
		if (g.abs() < eps) break;
		double del1 = (x1 - x0) - (a*(g.i - g0.i) + b*(g.j - g0.j));
		double del2 = (y1 - y0) - (c*(g.i - g0.i) + d*(g.j - g0.j));
		double ddd = del1*(g.i - g0.i) + del2*(g.j - g0.j);
		a = a + del1*del1 / ddd;
		b = b + del1*del2 / ddd;
		c = c + del2*del1 / ddd;
		d = d + del2*del2 / ddd;
		x0 = x1; y0 = y1;
		alf = am(F, x1, y1, a, b, c, d);
		x1 = x1 - alf*(a*g.i + b*g.j);
		y1 = y1 - alf*(c*g.i + d*g.j);
		g.init(F, x1, y1);
		g.init(F, x0, y0);
		//std::cout << "\n x,y=      " << x1 << " " << y1 <<"        "<<g.abs()<< std::endl;
		count++;
		//system("pause");
		std::cout << "count =      " << count << "\n a=      " << alf << "\n x,y=      " << x1 << " " << y1 << std::endl;
	}
	std::cout << "count =      " << count << "\n a=      " << alf << "\n x,y=      " << x1 << " " << y1 << std::endl;
}

//ньютон
void Nuton(double(*F)(double x1, double x2), double alpha = 0.01, double x0 = 1, double y0 = 1, double eps = 0.0001, double dett = 0.0001)
{
	int count = 0;
	double x1, y1;
	x1 = x0;
	y1 = y0;
	double alf = alpha;
	gradient g;
	g.init(F, x0, y0);
	double a, b, c, d;
	a = 1.0;
	b = 0;
	c = 0;
	d = 1 / 9.0;
	//std::cout << a << b << c << d;
	//system("pause");
	while (g.abs() > eps)
	{
		alf = am(F, x1, y1, a, b, c, d);
		x1 = x1 - alf*(a*g.i + b*g.j);
		y1 = y1 - alf*(c*g.i + d*g.j);
		g.init(F2, x1, y1);
		count++;
	}
	std::cout << "count =      " << count << "\n a=      " << alf << "\n x,y=      " << x1 << " " << y1 << std::endl;
}






int main()
{
	//одномерная минимизация

	//passive(F);
	//dichotomy(F);
	//goldensect(F);
	//sek(F);

	//многомерная оптимизация

	//coordinateDescentMethod(F2);
	//gradientWithSplittingStep(F2);
	//gradientWithFixedStep(F2);
	//fastestGradientDescentMethod(F2);
	//acceleratedGradient(F2);
	//ravineMethod(F2);
	//conjugateDirections(F2);
	//KNuton(F2);
	//Nuton(F2);



	system("pause");
	return 0;
}