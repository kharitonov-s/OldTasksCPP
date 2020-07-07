#include "structs.h"
#include <cmath>
#include <iostream>

using namespace std;

void rand_point(Point &p)
{
	p.x = rand() % 21 - 10;
	p.y = rand() % 21 - 10;
}

void print_point(Point p)
{
	cout <<"\t"<< p.x << "\t" << p.y << endl;
}

void print_point_array(Point *p,int n)
{
	for (int i = 0;i < n;++i)
		print_point(p[i]);
}

bool distCmp(Point A, Point B)
{
	double distA = sqrt((A.x)*(A.x) + (A.y)*(A.y));
	double distB = sqrt((B.x)*(B.x) + (B.y)*(B.y));

	return distA > distB;
}

bool distCmpless(Point A, Point B)
{
	double distA = sqrt((A.x)*(A.x) + (A.y)*(A.y));
	double distB = sqrt((B.x)*(B.x) + (B.y)*(B.y));

	return distA < distB;
}