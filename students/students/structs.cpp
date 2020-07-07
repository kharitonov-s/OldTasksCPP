#include "structs.h"
#include <cmath>
#include <iostream>
#include <cstring>

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

void edit_student(char* FirstName, char* LastName, unsigned short group, unsigned short year, Student& st)
{
	//Копируем имя
	int FirstNameLength = strlen(FirstName);
	if (st.FirstName == nullptr)
	{
		st.FirstName = new char[FirstNameLength + 1];
		strcpy_s(st.FirstName, FirstNameLength + 1, FirstName);
	}
	else
	{
		delete[] st.FirstName;
		st.FirstName = new char[FirstNameLength + 1];
		strcpy_s(st.FirstName, FirstNameLength + 1, FirstName);
	}

	//Копируем фамилию
	int LastNameLength = strlen(LastName);
	if (st.LastName == nullptr)
	{
		st.LastName = new char[LastNameLength + 1];
		strcpy_s(st.LastName, LastNameLength + 1, LastName);
	}
	else
	{
		delete[] st.LastName;
		st.LastName = new char[LastNameLength + 1];
		strcpy_s(st.LastName, LastNameLength + 1, LastName);
	}
	
	st.group = group;
	st.year = year;
}

void print_student(Student st)
{
	cout << st.LastName << " " << st.FirstName << " ";
	cout << st.group << " " << st.year << endl;
}

bool groupCmp(Student A, Student B)
{
	return A.group > B.group;
}

bool LastNameCmp(Student A, Student B)
{
	return strcmp(A.LastName, B.LastName) > 0;
}