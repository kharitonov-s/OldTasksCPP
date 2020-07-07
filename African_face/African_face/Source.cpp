/*#include "tga.h"
#include<fstream>
#include<vector> 
#include<iostream> 
using namespace std;

TGAImage image(3000, 3000, TGAImage::RGB);
ifstream versh("versh.txt");
ifstream line("lines.txt");
ofstream output("output.txt");

struct vershina {
	double x;
	double y;
	double z;
	char n;
};

struct triangle {
	double a;
	double s;
	double d;
	char f;
};
void drawline2(int x1, int y1, int x2, int y2)
{
	TGAColor white = TGAColor(255, 255, 255, 255);
	TGAColor red = TGAColor(255, 0, 0, 255);
	TGAColor color = white;

    int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int signX = x1 < x2 ? 1 : -1;
	int signY = y1 < y2 ? 1 : -1;
	//
	int d = dx - dy;
	//
	image.set(x2, y2, color);
	while (x1 != x2 || y1 != y2) {
		image.set(x1, y1,color);
		int d2 = d * 2;
		//
		if (d2 > -dy) {
			d -= dy;
			x1 += signX;
		}
		if (d2 < dx) {
			d += dx;
			y1 += signY;
		}
	}

}
void drawline(double x1, double y1, double x2, double y2) {


	TGAColor white = TGAColor(255, 255, 255, 255);
	TGAColor red = TGAColor(255, 0, 0, 255);
	TGAColor color = white;
	double dx = x2 - x1;
	double dy = y2 - y1;
	double d = 2 * dy - dx;
	double x = x1;
	double y = y1;

	if (x<x2) {
		while (x<x2)
		{
			image.set(x, y, color);
			if (d<0) 
			{	d += 2 * dy;
				if (y1 > y2) { y+=dy/dx; }
			}
			else {
				d += 2 * (dy - dx);
				++y;
			}
			//if (y1 > y2) { }
			++x;
			
		}

	}
	if (x>x2) {

		while (x>x2) {
			image.set(x, y, color);
			if (d<0) { d += 2 * dx; }
			else 
			{
				d += -2*(dy - dx);
				++y;
				
				
			}
			
			
			
			--x;
		} 
	}
	if ((x1 == x2) && (y1<y2)) {

		while (y<y2) {
			image.set(x, y, color);
			if (d<0) { d += 2 * dy; }
			else {
				d += 2 * (dy - dx);
				++y;
			}
		}
	}

	if ((y2<y1) && (x1 == x2)) {
		y = y2;
		while (y<y1) {
			image.set(x, y, color);
			++y;
		}
	}


}


vector<vershina>A;
vector<triangle>B;
int main() 
{
	for (int i = 0; i < 1259; i++) 
	{
		vershina temp;
		versh >> temp.x;
		versh >> temp.y;
		versh >> temp.z;
		versh >> temp.n;
		A.push_back(temp);
		A[i].x += 1;
		A[i].y += 1;
		A[i].z += 1;
		A[i].x = A[i].x * 1000;
		A[i].y = A[i].y * 1000;
		A[i].z = A[i].z * 1000;
		A[i].x = (int)A[i].x;
		A[i].y = (int)A[i].y;
		A[i].z = (int)A[i].z;
	}
	
	for (int k = 0; k < 7476; k++)
	{
		triangle temp2;
		line >> temp2.a;
		line >> temp2.f;
		line >> temp2.s;
		line >> temp2.f;
		line >> temp2.d;
		
		if (((k+1)%3==0)) 
		{
			line >> temp2.f;
		}
		B.push_back(temp2);
	}

	for (int u = 0;u < 7476;)
	{
		drawline2(A[B[u].a - 1].x, A[B[u].a - 1].y, A[B[u + 1].a - 1].x, A[B[u + 1].a - 1].y);
		drawline2(A[B[u].a - 1].x, A[B[u].a - 1].y, A[B[u + 2].a - 1].x, A[B[u + 2].a - 1].y);
		drawline2(A[B[u + 1].a - 1].x, A[B[u + 1].a - 1].y, A[B[u + 2].a - 1].x, A[B[u + 2].a - 1].y);
		u = u + 3;
	}



	//output << A[1257].x << " " << A[1257].y << " " << A[1257].z << endl;
	output << A[0].x << " " << A[0].y << " " << A[0].z << endl;
	output << A[3].x << " " << A[3].y << " " << A[3].z << endl;
	output << B[1].a << " " << B[1].s << " " << B[1].d << endl;
	output << B[3].a << " " << B[3].s << " " << B[3].d << endl;
	output << B[2491*3].a << " " << B[2491*3].s << " " << B[2491*3].d << endl;
	output << A[B[0].a - 1].x << " " << A[B[0].a - 1].y << "   " << A[B[0 + 1].a - 1].x << " " << A[B[0 + 1].a - 1].y << endl;
	output << A[B[0].a - 1].x << " " << A[B[0].a - 1].y << "   " << A[B[0 + 2].a - 1].x << " " << A[B[0 + 2].a - 1].y << endl;
	output << A[B[0 + 1].a - 1].x << " " << A[B[0 + 1].a - 1].y << "   " << A[B[0 + 2].a - 1].x << " " << A[B[0 + 2].a - 1].y << endl;

	//drawline(A[B[0].a - 1].x, A[B[0].a - 1].y, A[B[0 + 1].a - 1].x, A[B[0 + 1].a - 1].y);
	//drawline(A[B[0].a - 1].x, A[B[0].a - 1].y, A[B[0 + 2].a - 1].x, A[B[0 + 2].a - 1].y);
	//drawline(A[B[0 + 1].a - 1].x, A[B[0 + 1].a - 1].y, A[B[0 + 2].a - 1].x, A[B[0 + 2].a - 1].y);

	//drawline2(1134, 852, 1131, 867);//x1>x2 y1>y2
	//drawline2(1134, 852, 1147, 864);//x1>x2 y1>y2
	//drawline2(1131, 867, 1147, 864);//x1>x2 y1<y2

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	
	return 0;
}*/



#include "tga.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <limits>


using namespace std;

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor black = TGAColor(0, 0, 0, 0);
const int depth = 255;
const int width = 400;
const int height = 400;
const int viewport1 = 0;
const int viewport2 = 0;
const int viewport3 = 1;

int *zbuf = NULL;

const int eye1 = 1;
const int eye2 = 1;
const int eye3 = 4;

const int centre1 = 0;
const int centre2 = 0;
const int centre3 = 0;

const int up1 = 0;
const int up2 = 1;
const int up3 = 0;
struct Point
{
	double x;
	double y;
};

struct Point2
{
	double x;
	double y;
	double z;
	double w;
};

struct Point3
{
	double x;
	double y;
	double z;
};

double** lookat(int eye1, int eye2, int eye3, int  centre1, int centre2, int centre3, int up1, int up2, int up3)
{
	double  z1 = eye1 - centre1;
	double  z2 = eye2 - centre2;
	double  z3 = eye3 - centre3;
	z1 = z1 / sqrt(z1*z1 + z2*z2 + z3*z3);
	z2 = z2 / sqrt(z1*z1 + z2*z2 + z3*z3);
	z3 = z3 / sqrt(z1*z1 + z2*z2 + z3*z3);

	double x1 = up2*z3 - up3*z2;
	double x2 = up3*z1 - up1*z3;
	double x3 = up1*z2 - up2*z1;
	//v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x
	x1 = x1 / sqrt(x1*x1 + x2*x2 + x3*x3);
	x2 = x2 / sqrt(x1*x1 + x2*x2 + x3*x3);
	x3 = x3 / sqrt(x1*x1 + x2*x2 + x3*x3);

	double y1 = z2*x3 - z3*x2;
	double y2 = z3*x1 - z1*x3;
	double y3 = z1*x2 - z2*x1;
	//v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x
	y1 = y1 / sqrt(y1*y1 + y2*y2 + y3*y3);
	y2 = y2 / sqrt(y1*y1 + y2*y2 + y3*y3);
	y3 = y3 / sqrt(y1*y1 + y2*y2 + y3*y3);

	double *x = new double[3];
	x[0] = x1;
	x[1] = x2;
	x[2] = x3;
	double *y = new double[3];
	y[0] = y1;
	y[1] = y2;
	y[2] = y3;
	double *z = new double[3];
	z[0] = z1;
	z[1] = z2;
	z[2] = z3;
	double *center = new double[3];
	center[0] = centre1;
	center[1] = centre2;
	center[2] = centre3;
	double  **Minv = new double*[4];
	for (int count = 0; count < 4; count++)
		Minv[count] = new double[4];

	double  **Tr = new double*[4];
	for (int count = 0; count < 4; count++)
		Tr[count] = new double[4];

	for (int i = 0; i<4;i++)
		for (int j = 0;j<4;j++)
			Tr[i][j] = (i == j ? 1.f : 0.f);
	for (int i = 0; i<4;i++)
		for (int j = 0;j<4;j++)
			Minv[i][j] = (i == j ? 1.f : 0.f);

	for (int i = 0; i<3; i++) {
		Minv[0][i] = x[i];
		Minv[1][i] = y[i];
		Minv[2][i] = z[i];
		Tr[i][3] = -center[i];
	}

	double  **ModelView = new double*[4];
	for (int count = 0; count < 4; count++)
		ModelView[count] = new double[4];


	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			ModelView[i][j] = 0.f;
			for (int k = 0; k<4; k++) {
				ModelView[i][j] += Minv[i][k] * Tr[k][j];
			}
		}
	}

	return ModelView;



}

double ** viewport(int w, int h)
{
	double  **m = new double*[4];
	for (int count = 0; count < 4; count++)
		m[count] = new double[4];

	for (int i = 0; i<4;i++)
		for (int j = 0;j<4;j++)
			m[i][j] = (i == j ? 1.f : 0.f);
	/*
	m[0][3] = x+w/2.f;
	m[1][3] = y+h/2.f;
	m[2][3] = depth/2.f;

	m[0][0] = w/2.f;
	m[1][1] = h/2.f;
	m[2][2] = depth/2.f;
	*/
	m[0][0] = w;
	m[1][1] = w;
	m[2][2] = w;
	m[0][3] = h;
	m[1][3] = h;
	m[2][3] = h;
	return m;
}

double ** projection(int eye1, int eye2, int eye3, int  centre1, int centre2, int centre3)
{
	double  **m = new double*[4];
	for (int count = 0; count < 4; count++)
		m[count] = new double[4];

	for (int i = 0; i<4;i++)
		for (int j = 0;j<4;j++)
			m[i][j] = (i == j ? 1.f : 0.f);
	double  z1 = eye1 - centre1;
	double  z2 = eye2 - centre2;
	double  z3 = eye3 - centre3;
	double n = sqrt(z1*z1 + z2*z2 + z3*z3);
	m[3][2] = -1.f / n;
	return m;
}
//закраска
void superzakraska(double x0, double y0, double x1, double y1, double x2, double y2, TGAImage &image, TGAColor color)
{

	y0 = int(y0 + 0.5);
	x0 = int(x0 + 0.5);
	y1 = int(y1 + 0.5);
	x1 = int(x1 + 0.5);
	x2 = int(x2 + 0.5);
	y2 = int(y2 + 0.5);



	if (y0 > y1) { float t = y0; y0 = y1; y1 = t; t = x0; x0 = x1; x1 = t; }
	if (y0 > y2) { float t = y0; y0 = y2; y2 = t; t = x0; x0 = x2; x2 = t; }
	if (y1 > y2) { float t = y1; y1 = y2; y2 = t;  t = x1; x1 = x2; x2 = t; }
	int total_height = y2 - y0;

	for (int i = 0; i < total_height; i++)
	{
		bool second_half = i > y1 - y0 || y1 == y0;
		int segment_height = second_half ? y2 - y1 : y1 - y0;
		float alpha = (float)i / total_height;
		float beta = (float)(i - (second_half ? y1 - y0 : 0)) / segment_height;
		double ax, ay, az, bx, by, bz;
		ax = x0 + (x2 - x0)*alpha;
		ay = y0 + (y2 - y0)*alpha;
		bx = second_half ? x1 + (x2 - x1)*beta : x0 + (x1 - x0)*beta;
		by = second_half ? y1 + (y2 - y1)*beta : y0 + (y1 - y0)*beta;
		if (ax > bx) { double  t = ax; ax = bx; bx = t; t = ay; ay = by; by = t; }
		for (int j = ax; j <= bx; j++)
		{
			image.set(j, y0 + i, color);
		}
	}

}

//zbuffer
void zbuffer(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, int *zbuf, TGAImage &image, TGAColor color)
{

	double ax, ay, az, bx, by, bz, px, py, pz;;

	/*
	x0 = int(x0 + 0.5);
	y0 = int(y0 + 0.5);
	z0 = int(z0 + 0.5);

	x1 = int(x1 + 0.5);
	y1 = int(y1 + 0.5);
	z1 = int(z1 + 0.5);

	x2 = int(x2 + 0.5);
	y2 = int(y2 + 0.5);
	z2 = int(z2 + 0.5);

	*/
	x0 = int((x0 + 1) * 400 / 2.);
	y0 = int((y0 + 1) * 400 / 2.);
	z0 = int((z0 + 1) * 400 / 2.);

	x1 = int((x1 + 1) * 400 / 2.);
	y1 = int((y1 + 1) * 400 / 2.);
	z1 = int((z1 + 1) * 400 / 2.);

	x2 = int((x2 + 1) * 400 / 2.);
	y2 = int((y2 + 1) * 400 / 2.);
	z2 = int((z2 + 1) * 400 / 2.);

	if (y0 == y1 && y0 == y2) return;
	if (y0 > y1) { double t = y0; y0 = y1; y1 = t; t = x0; x0 = x1; x1 = t; t = z0; z0 = z1; z1 = t; }
	if (y0 > y2) { double t = y0; y0 = y2; y2 = t; t = x0; x0 = x2; x2 = t; t = z0; z0 = z2; z2 = t; }
	if (y1 > y2) { double t = y1; y1 = y2; y2 = t;  t = x1; x1 = x2; x2 = t; t = z1; z1 = z2; z2 = t; }
	int total_height = y2 - y0;

	for (int i = 0; i < total_height; i++)
	{
		bool second_half = i > y1 - y0 || y1 == y0;
		int segment_height = second_half ? y2 - y1 : y1 - y0;
		double alpha = (double)i / total_height;
		double beta = (double)(i - (second_half ? y1 - y0 : 0)) / segment_height;
		ax = x0 + (x2 - x0)*alpha;
		ay = y0 + (y2 - y0)*alpha;
		az = z0 + (z2 - z0)*alpha;
		bx = second_half ? x1 + (x2 - x1)*beta : x0 + (x1 - x0)*beta;
		by = second_half ? y1 + (y2 - y1)*beta : y0 + (y1 - y0)*beta;
		bz = second_half ? z1 + (z2 - z1)*beta : z0 + (z1 - z0)*beta;
		if (ax > bx) { double  t = ax; ax = bx; bx = t; t = ay; ay = by; by = t; t = az; az = bz; bz = t; }
		for (int j = ax; j <= bx; j++)
		{
			double phi = bx == ax ? 1. : (double)(j - ax) / (double)(bx - ax);
			px = ax + (bx - ax)*phi;
			py = ay + (by - ay)*phi;
			pz = az + (bz - az)*phi;
			int idx = px + py * 400;
			if (zbuf[idx]<pz)
			{
				zbuf[idx] = pz;
				image.set(px, py, color);
			}
		}
	}

}

//zbuffer тонировка
void zbuffertoni(double x0, double y0, double z0, double  vt01, double vt02, double vn01, double vn02, double vn03, double x1, double y1, double z1, double vt11, double vt12, double vn11, double vn12, double vn13, double x2, double y2, double z2, double vt21, double vt22, double vn21, double vn22, double vn23, int *zbuf, TGAImage &image, TGAImage &image2, double intensity)
{

	double ax, ay, az, bx, by, bz, px, py, pz, vta1, vta2, vna1, vna2, vna3, vtb1, vtb2, vtp1, vtp2, vnb1, vnb2, vnb3, vnp1, vnp2, vnp3;



	if (y0 == y1 && y0 == y2) return;
	if (y0 > y1) { double t = y0; y0 = y1; y1 = t; t = x0; x0 = x1; x1 = t; t = z0; z0 = z1; z1 = t;t = vt01; vt01 = vt11; vt11 = t;t = vt02; vt02 = vt12; vt12 = t;t = vn01; vn01 = vn11; vn11 = t; t = vn02; vn02 = vn12; vn12 = t;t = vn03; vn03 = vn13; vn13 = t; }
	if (y0 > y2) { double t = y0; y0 = y2; y2 = t; t = x0; x0 = x2; x2 = t; t = z0; z0 = z2; z2 = t;t = vt01; vt01 = vt21; vt21 = t;t = vt02; vt02 = vt22; vt22 = t;t = vn01; vn01 = vn21; vn21 = t; t = vn02; vn02 = vn22; vn22 = t; t = vn03; vn03 = vn23; vn23 = t; }
	if (y1 > y2) {
		double t = y1; y1 = y2; y2 = t;  t = x1; x1 = x2; x2 = t; t = z1; z1 = z2; z2 = t; t = vt11; vt11 = vt21; vt21 = t;t = vt12; vt12 = vt22; vt22 = t;t = vn11; vn11 = vn21; vn21 = t; t = vn12; vn12 = vn22; vn22 = t; t = vn13; vn13 = vn23; vn23 = t;
	}

	/*
	x0 = int((x0 + 1) * 400 / 2.);
	y0 = int((y0 + 1) * 400 / 2.);
	z0 = int((z0 + 1) * 400 / 2.);

	x1 = int((x1 + 1) * 400 / 2.);
	y1 = int((y1 + 1) * 400 / 2.);
	z1 = int((z1 + 1) * 400 / 2.);

	x2 = int((x2 + 1) * 400 / 2.);
	y2 = int((y2 + 1) * 400 / 2.);
	z2 = int((z2 + 1) * 400 / 2.);

	*/
	int total_height = y2 - y0;
	for (int i = 0; i < total_height; i++)
	{
		bool second_half = i > y1 - y0 || y1 == y0;
		int segment_height = second_half ? y2 - y1 : y1 - y0;
		double alpha = (double)i / total_height;
		double beta = (double)(i - (second_half ? y1 - y0 : 0)) / segment_height;
		ax = x0 + (x2 - x0)*alpha;
		ay = y0 + (y2 - y0)*alpha;
		az = z0 + (z2 - z0)*alpha;
		vta1 = vt01 + (vt21 - vt01)*alpha;
		vta2 = vt02 + (vt22 - vt02)*alpha;
		vna1 = vn01 + (vn21 - vn01)*alpha;
		vna2 = vn02 + (vn22 - vn02)*alpha;
		vna3 = vn03 + (vn23 - vn03)*alpha;
		bx = second_half ? x1 + (x2 - x1)*beta : x0 + (x1 - x0)*beta;
		by = second_half ? y1 + (y2 - y1)*beta : y0 + (y1 - y0)*beta;
		bz = second_half ? z1 + (z2 - z1)*beta : z0 + (z1 - z0)*beta;
		vtb1 = second_half ? vt11 + (vt21 - vt11)*beta : vt01 + (vt11 - vt01)*beta;
		vtb2 = second_half ? vt12 + (vt22 - vt12)*beta : vt02 + (vt12 - vt02)*beta;
		vnb1 = second_half ? vn11 + (vn21 - vn11)*beta : vn01 + (vn11 - vn01)*beta;
		vnb2 = second_half ? vn12 + (vn22 - vn12)*beta : vn02 + (vn12 - vn02)*beta;
		vnb3 = second_half ? vn13 + (vn23 - vn13)*beta : vn03 + (vn13 - vn03)*beta;
		if (ax > bx) {
			double  t = ax; ax = bx; bx = t; t = ay; ay = by; by = t; t = az; az = bz; bz = t;
			t = vta1; vta1 = vtb1; vtb1 = t;t = vta2; vta2 = vtb2; vtb2 = t;t = vna1; vna1 = vnb1; vnb1 = t; t = vna2; vna2 = vnb2; vnb2 = t;t = vna3; vna3 = vnb3; vnb3 = t;
		}
		for (int j = ax; j <= bx; j++)
		{
			double phi = bx == ax ? 1. : (double)(j - ax) / (double)(bx - ax);
			px = ax + (bx - ax)*phi;
			py = ay + (by - ay)*phi;
			pz = az + (bz - az)*phi;

			vtp1 = vta1 + (vtb1 - vta1)*phi;
			vtp2 = vta2 + (vtb2 - vta2)*phi;

			vnp1 = vna1 + (vnb1 - vna1)*phi;
			vnp2 = vna2 + (vnb2 - vna2)*phi;
			vnp3 = vna3 + (vnb3 - vna3)*phi;
			int idx = px + py * 400;
			//intensity = vnp3;
			if (px >= 400 || py >= 400 || px<0 || py<0) continue;
			if (zbuf[idx]<pz)
			{
				zbuf[idx] = pz;
				TGAColor ff = image2.get(vtp1, vtp2);

				image.set(px, py, TGAColor(ff.r, ff.g, ff.b, 255));
			}
		}
	}

}

//умножение матриц
double ** umnoj(double ** A, double ** B, int m, int n, int q)
{
	double  **ModelView = new double*[m];
	for (int count = 0; count < m; count++)
		ModelView[count] = new double[q];

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<q; j++) {
			ModelView[i][j] = 0.f;
			for (int k = 0; k<n; k++) {
				ModelView[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return ModelView;
}

//функция считает нормаль
Point3 CalcNormals(Point3 a, Point3 b, Point3 c)
{
	double wrki;
	Point3 v1, v2, n;
	double q1, q2, q3;
	q1 = (b.y - a.y)*(c.z - a.z) - (b.z - a.z)*(c.y - a.y);
	q2 = (b.z - a.z)*(c.x - a.x) - (b.x - a.x)*(c.z - a.z);
	q3 = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
	v1.x = a.x - b.x;
	v1.y = a.y - b.y;
	v1.z = a.z - b.z;

	v2.x = b.x - c.x;
	v2.y = b.y - c.y;
	v2.z = b.z - c.z;

	wrki = sqrt((v1.y*v2.z - v1.z * v2.y)*(v1.y*v2.z - v1.z * v2.y) + (v1.z * v2.x - v1.x * v2.z)*(v1.z * v2.x - v1.x * v2.z) + (v1.x * v2.y - v1.y * v2.x)*(v1.x * v2.y - v1.y * v2.x));
	n.x = (v1.y * v2.z - v1.z * v2.y) / wrki;
	n.y = (v1.z * v2.x - v1.x * v2.z) / wrki;
	n.z = (v1.x * v2.y - v1.y * v2.x) / wrki;
	return n;
}

int main(int argc, char** argv)
{
	TGAImage image(400, 400, TGAImage::RGB);
	TGAImage image2(1024, 1024, TGAImage::RGB);
	image2.read_tga_file("african_head_diffuse.tga");
	image2.flip_vertically();
	int m = 1;
	int nm = 0;
	zbuf = new int[400 * 400];
	for (int i = 0; i<400 * 400; i++)
		zbuf[i] = std::numeric_limits<int>::min();
	ifstream in("in.txt");
	if (!in.is_open())

	{
		cout << "Read file Error!" << endl;
		return 1;
	}

	int n = 1400;
	double   *vershx = new double[n];
	for (int i = 0; i < n; i++)
		vershx[i] = 0;

	double *vershy = new double[n];
	for (int i = 0; i < n; i++)
		vershy[i] = 0;

	double *vershz = new double[n];
	for (int i = 0; i < n; i++)
		vershz[i] = 0;




	double   *nvershx = new double[n];
	for (int i = 0; i < n; i++)
		nvershx[i] = 0;

	double *nvershy = new double[n];
	for (int i = 0; i < n; i++)
		nvershy[i] = 0;

	double *nvershz = new double[n];
	for (int i = 0; i < n; i++)
		nvershz[i] = 0;

	double *vtvershx = new double[n];
	for (int i = 0; i < n; i++)
		vtvershx[i] = 0;

	double *vtvershy = new double[n];
	for (int i = 0; i < n; i++)
		vtvershy[i] = 0;

	char str[255];

	int k, l = 0;
	int r = 0;
	int vn = 0;
	int vt = 0;
	int ftr1, ftr2, ftr3;

	int tr1, tr2, tr3;

	while (!in.eof())
	{
		in.getline(str, 255);
		if ((str[0] == 'v') && (str[1] == ' '))
		{
			k = 2;
			l = 0;
			char str2[255] = "";
			while (str[k] != ' ')
			{
				str2[l] = str[k];
				k += 1;
				l += 1;
			}
			double agl = atof(str2);
			vershx[r] = agl;


			char str3[255] = "";
			k += 1;
			l = 0;
			while (str[k] != ' ')
			{
				str3[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atof(str3);
			vershy[r] = agl;

			char str4[255] = "";
			k += 1;
			l = 0;
			while (k<strlen(str))
			{
				str4[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atof(str4);
			vershz[r] = agl;
			r += 1;


		}

		if ((str[0] == 'v') && (str[1] == 'n'))
		{
			k = 4;
			l = 0;
			char vstr2[255] = "";
			while (str[k] != ' ')
			{
				vstr2[l] = str[k];
				k += 1;
				l += 1;
			}
			double agl = atof(vstr2);
			nvershx[vn] = agl;


			char vstr3[255] = "";
			k += 1;
			l = 0;
			while (str[k] != ' ')
			{
				vstr3[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atof(vstr3);
			nvershy[vn] = agl;

			char vstr4[255] = "";
			k += 1;
			l = 0;
			while (k<strlen(str))
			{
				vstr4[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atof(vstr4);
			nvershz[vn] = agl;
			vn += 1;


		}
		if ((str[0] == 'v') && (str[1] == 't'))
		{
			k = 4;
			l = 0;
			char vstr2[255] = "";
			while (str[k] != ' ')
			{
				vstr2[l] = str[k];
				k += 1;
				l += 1;
			}
			double agl = atof(vstr2);
			vtvershx[vt] = agl;


			char vstr3[255] = "";
			k += 1;
			l = 0;
			while (str[k] != ' ')
			{
				vstr3[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atof(vstr3);
			vtvershy[vt] = agl;

			char vstr4[255] = "";
			k += 1;
			l = 0;
			while (k<strlen(str))
			{
				vstr4[l] = str[k];
				k += 1;
				l += 1;
			}
			vt += 1;


		}

		if (str[0] == 'f')
		{
			k = 2;
			l = 0;
			char str2[32] = "";
			while (str[k] != '/')
			{
				str2[l] = str[k];
				k += 1;
				l += 1;
			}
			double agl = atoi(str2);
			tr1 = agl;

			k += 1;
			l = 0;
			char str3[32] = "";
			while (str[k] != '/')
			{
				str3[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atoi(str3);
			ftr1 = agl;

			while (str[k] != ' ')
				k += 1;

			l = 0;
			char str33[32] = "";
			k += 1;
			while (str[k] != '/')
			{
				str33[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atoi(str33);
			tr2 = agl;

			k += 1;
			l = 0;
			char str44[32] = "";
			while (str[k] != '/')
			{
				str44[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atoi(str44);
			ftr2 = agl;

			while (str[k] != ' ')
				k += 1;

			l = 0;
			char str444[32] = "";
			k += 1;
			while (str[k] != '/')
			{
				str444[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atoi(str444);
			tr3 = agl;

			k += 1;
			l = 0;
			char str5[32] = "";
			while (str[k] != '/')
			{
				str5[l] = str[k];
				k += 1;
				l += 1;
			}
			agl = atoi(str5);
			ftr3 = agl;

			Point3 a;
			a.x = vershx[tr1 - 1];
			a.y = vershy[tr1 - 1];
			a.z = vershz[tr1 - 1];
			Point3 b;
			b.x = vershx[tr2 - 1];
			b.y = vershy[tr2 - 1];
			b.z = vershz[tr2 - 1];
			Point3 c;
			c.x = vershx[tr3 - 1];
			c.y = vershy[tr3 - 1];
			c.z = vershz[tr3 - 1];
			Point3 n;
			n = CalcNormals(a, b, c);
			float intensity = n.z*(-1);
			/*
			vershx[tr1-1]= int((vershx[tr1-1] + 1) * 400 / 2.);
			vershy[tr1-1]= int((vershy[tr1-1] + 1) * 400 / 2.);
			vershz[tr1-1]= int((vershz[tr1-1] + 1) * 400 / 2.);

			vershx[tr2-1]= int((vershx[tr2-1] + 1) * 400 / 2.);
			vershy[tr2-1]= int((vershy[tr2-1] + 1) * 400 / 2.);
			vershz[tr2-1]= int((vershz[tr2-1] + 1) * 400 / 2.);

			vershx[tr3-1]= int((vershx[tr3-1] + 1) * 400 / 2.);
			vershy[tr3-1]= int((vershy[tr3-1] + 1) * 400 / 2.);
			vershz[tr3-1]= int((vershz[tr3-1] + 1) * 400 / 2.);
			*/

			double  **v1 = new double*[4];
			for (int count = 0; count < 4; count++)
				v1[count] = new double[1];

			/*
			v1[0][0]=vershx[tr1-1];
			v1[1][0]=vershy[tr1-1];
			v1[2][0]=vershz[tr1-1];
			v1[3][0]=1;
			*/
			v1[0][0] = vershx[tr1 - 1];
			v1[1][0] = vershy[tr1 - 1];
			v1[2][0] = vershz[tr1 - 1];
			v1[3][0] = 1;
			double  **v2 = new double*[4];
			for (int count = 0; count < 4; count++)
				v2[count] = new double[1];
			v2[0][0] = vershx[tr2 - 1];
			v2[1][0] = vershy[tr2 - 1];
			v2[2][0] = vershz[tr2 - 1];
			v2[3][0] = 1;
			double  **v3 = new double*[4];
			for (int count = 0; count < 4; count++)
				v3[count] = new double[1];
			v3[0][0] = vershx[tr3 - 1];
			v3[1][0] = vershy[tr3 - 1];
			v3[2][0] = vershz[tr3 - 1];
			v3[3][0] = 1;
			double  **ViewPort1 = new double*[4];
			for (int count = 0; count < 4; count++)
				ViewPort1[count] = new double[4];
			ViewPort1 = viewport(width, height);

			/*
			double  ** ModelView = new double* [4];
			for (int count = 0; count < 4; count++)
			ModelView[count] = new double [4];
			ModelView=lookat(eye1,eye1,eye3,centre1,centre2,centre3,up1,up2,up3);

			double  ** Projection1 = new double* [4];
			for (int count = 0; count < 4; count++)
			Projection1[count] = new double [4];
			Projection1=projection(eye1,eye1,eye3,centre1,centre2,centre3);
			*/

			double  ** itog1 = new double*[4];
			for (int count = 0; count < 4; count++)
				itog1[count] = new double[1];

			double  ** itog2 = new double*[4];
			for (int count = 0; count < 4; count++)
				itog2[count] = new double[1];

			double  ** itog3 = new double*[4];
			for (int count = 0; count < 4; count++)
				itog3[count] = new double[1];


			// itog1=umnoj(umnoj(umnoj(ViewPort1,Projection1,4,4,4),ModelView,4,4,4),v1,4,4,1);
			//itog2=umnoj(umnoj(umnoj(ViewPort1,Projection1,4,4,4),ModelView,4,4,4),v2,4,4,1);
			//  itog3=umnoj(umnoj(umnoj(ViewPort1,Projection1,4,4,4),ModelView,4,4,4),v3,4,4,1);

			itog1 = umnoj(ViewPort1, v1, 4, 4, 1);
			itog2 = umnoj(ViewPort1, v2, 4, 4, 1);
			itog3 = umnoj(ViewPort1, v3, 4, 4, 1);
			vershx[tr1 - 1] = itog1[0][0] / 2.;
			vershy[tr1 - 1] = itog1[1][0] / 2.;
			vershz[tr1 - 1] = itog1[2][0] / 2.;

			vershx[tr2 - 1] = itog2[0][0] / 2.;
			vershy[tr2 - 1] = itog2[1][0] / 2.;
			vershz[tr2 - 1] = itog2[2][0] / 2.;

			vershx[tr3 - 1] = itog3[0][0] / 2.;
			vershy[tr3 - 1] = itog3[1][0] / 2.;
			vershz[tr3 - 1] = itog3[2][0] / 2.;

			cout << vershx[tr1 - 1] << " " << vershy[tr1 - 1] << " " << vershz[tr1 - 1];
			//zbuffer(vershx[tr1 - 1] * 200 + 200, vershy[tr1 - 1] * 200 + 200, vershz[tr1 - 1] * 200 + 200, vershx[tr2 - 1] * 200 + 200, vershy[tr2 - 1] * 200 + 200, vershz[tr2 - 1] * 200 + 200, vershx[tr3 - 1] * 200 + 200, vershy[tr3 - 1] * 200 + 200, vershz[tr3 - 1] * 200 + 200, zbuf, image, TGAColor(intensity * aa, intensity * bb, intensity * 255, 255));
			//if (n.z*(-1)<0)
			//{

			zbuffertoni(vershx[tr1 - 1], vershy[tr1 - 1], vershz[tr1 - 1], int(vtvershx[ftr1 - 1] * 1024), int(vtvershy[ftr1 - 1] * 1024), nvershx[tr1 - 1], nvershy[tr1 - 1], nvershz[tr1 - 1], vershx[tr2 - 1], vershy[tr2 - 1], vershz[tr2 - 1], int(vtvershx[ftr2 - 1] * 1024), int(vtvershy[ftr2 - 1] * 1024), nvershx[tr2 - 1], nvershy[tr2 - 1], nvershz[tr2 - 1], vershx[tr3 - 1], vershy[tr3 - 1], vershz[tr3 - 1], int(vtvershx[ftr3 - 1] * 1024), int(vtvershy[ftr3 - 1] * 1024), nvershx[tr3 - 1], nvershy[tr3 - 1], nvershz[tr3 - 1], zbuf, image, image2, intensity);

			//}

		}

	}
	image.flip_vertically();

	image.write_tga_file("output.tga");

	system("pause");
	return 0;

}

