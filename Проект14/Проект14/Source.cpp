#include <iostream>
#include <cmath>	//z(x) = ch(1 + ?(1 + x)) cos ?(1 + x ? x^2), x = 0.1(0.01)0.2;
#include <iomanip>
using namespace std;				// e = 10^(-4)

double e1;  //u=sqrt(1+x)      u'=1/(2sqrt(x+1))
double e2;	//v=sqrt(1+x+x^2)  v'=(2*x+1)/(2*sqrt(x^2+x+1))
double e3=pow(10,-4)/3; 
//f3=ch(1+u)*cos(v) (f3)/du = sinh(u+1)cos(v) f3/dv = -cosh(u+1)sin(v)

double sinx(double x)
{
	double n = x;
	double sum = 0.0;
	int i = 1;

	while (fabs(n) > pow(10,-4))
	{
		sum += n;
		n *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	}
	return sum;
}
double cosx(double x,double eps)
{
	double n = 1.0;
	double sum = 0.0;
	int i = 1;

	while (abs(n) > eps)
	{
		sum += n;
		n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
		i++;
	} 

	return sum;
}
double hyperbolcos(double x,double eps)
{
	double n = 1.0;
	double sum = 0.0;
	int i = 1;

	while (abs(n) > eps)
	{
		sum += n;
		n *= x*x / ((2 * i - 1)*(2 * i));
		i++;
	}
	return sum;
}
double sqrtGeron(double A, double eps)
{
	double prev=1;
	double next=A;
	//const double eps = exp(-10);
	while (abs(prev-next)>eps)
	{
		prev = next;
		next = (prev + A / prev)/2;
	}
	return next;
}
double multifunc(double v,double u)
{
	double n = 1.0;
	double sum = 0.0;
	int i = 1;

	while (abs(n) > pow(10, -4)/3)
	{
		sum += n;
		n *= (u*u / ((2 * i - 1)*(2 * i)))*(-1.0 *v * v / ((2 * i - 1) * (2 * i)));
		i++;
	}

	return sum;
}

int main()
{
	cout << "                                                                        Value table" << endl;
	cout << endl;
	
	double umin = sqrt(1 + 0.1);
	double umax = sqrt(1 + 0.2);
	double vmin = sqrt(1 + 0.1 + pow(0.1, 2));
	double vmax = sqrt(1 + 0.2 + pow(0.2, 2));

	double c1 = abs(sinh(umax + 1)*cos(vmax)); //df(u,v)/du 
	double c2 = abs(-cosh(umin + 1)*sin(vmin)); //df(U,v)/dv

	e1 = pow(10, -4) / (3 * c1); //for sqrtGerom(1+x)
	e2 = pow(10, -4) / (3 * c2); //for sqrtGeron(1+x+x^2)
	e3 = pow(10, -4) / 3;

	double x1 = 0.1;
	for (int n = 1;n != 12;++n)
	{
		cout.width(2);
		cout << n << "  X=" <<setw(4)<< x1 << "  Value: " <<setw(9)<< cos(sqrt(1 + x1 - pow(x1, 2)))*cosh(1 + sqrt(1 + x1));
		
		cout <<setw(40)<< "  Value with inaccuaracy: " << setw(9) << cosx(sqrtGeron(1 + x1 - pow(x1, 2), e2), e3)*hyperbolcos(1 + sqrtGeron(1 + x1, e1), e3);
		cout << "        Delta:  "  << abs(cos(sqrt(1 + x1 - pow(x1, 2)))*cosh(1 + sqrt(1 + x1)) - cosx(sqrtGeron(1 + x1 - pow(x1, 2), e2), e3)*hyperbolcos(1 + sqrtGeron(1 + x1, e1), e3))<<endl;
		x1 = x1 + 0.01;
	}
	cout << endl;


	double x2 = 0.1;
	for (int n = 1;n != 12;++n)
	{
		cout.width(2);
		if (abs(cos(sqrt(1 + x1 - pow(x1, 2)))*cosh(1 + sqrt(1 + x1)) - cosx(sqrtGeron(1 + x1 - pow(x1, 2), e2), e3)*hyperbolcos(1 + sqrtGeron(1 + x1, e1), e3)) <= e3)
		{
			cout << n << "  X=" << setw(4) << x2 << " Check f(u,v): " << setw(9) << abs(cos(sqrt(1 + x2 - pow(x2, 2)))*cosh(1 + sqrt(1 + x2)) - cosx(sqrtGeron(1 + x2 + pow(x2, 2), e2), e3)*hyperbolcos(1 + sqrtGeron(1 + x2, e1), e3)) << " <= " << setw(9) << e3 << " True!";
		}
		else
			cout << "Error!" << endl;
		
		if (abs(sqrtGeron(1 + x2, e1) - sqrt(1 + x2)) <= e1)
		{
			cout  << "     Check sqrt(1+x): " << setw(9) << abs(sqrtGeron(1 + x2, e1) - sqrt(1 + x2)) << " <= " << setw(9) << e1 << " True!" ;
		}
		else
			cout << "                    Error!";

		if (abs(sqrtGeron(1 + x2 - pow(x2,2),e2) - sqrt(1 + x2 - pow(x2,2))) <= e2)
		{
			cout << "     Check sqrt(1+x+x^2): " << setw(9) << abs(sqrtGeron(1 + x2 - pow(x2, 2), e2) - sqrt(1 + x2 - pow(x2, 2))) << " <= " << setw(9) << e2 << " True!" << endl;
		}
		else
			cout << "Error!" << endl;
		x2 = x2 + 0.01;
	}

	
	system("pause");
	return 0;
}


