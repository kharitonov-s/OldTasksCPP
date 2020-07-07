#pragma once

struct Point
{
	double x;
	double y;
	Point()
	{
		x = 0;
		y = 0;
	}
};

void rand_point(Point&);
void print_point(Point);
void print_point_array(Point*,int);

bool distCmp(Point, Point);
bool distCmpless(Point, Point);