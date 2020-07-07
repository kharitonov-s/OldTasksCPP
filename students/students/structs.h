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

struct Student
{
	char* FirstName;
	char* LastName;
	unsigned short group;
	unsigned short year;
	Student()
	{
		FirstName = nullptr;
		LastName = nullptr;
		group = 0;
		year = 0;
	}
};

void edit_student(char*, char*, unsigned short, unsigned short, Student&);
void print_student(Student);

bool groupCmp(Student A, Student B);
bool LastNameCmp(Student A, Student B);

