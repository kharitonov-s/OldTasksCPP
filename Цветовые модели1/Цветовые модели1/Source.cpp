#include "tga1.h"
#include <iostream>
using namespace std;

void line(int x1, int y1, int x2, int y2, TGAColor color) {

	TGAImage image(100, 100, TGAImage::RGB);
	const TGAColor white = TGAColor(255, 255, 255, 255);
	const TGAColor red = TGAColor(255, 0, 0, 255);

	int dx = x2 - x1;
	int dy = y2 - y1;
	int d = 2 * dy - dx;
	int x = x1;
	int y = y1;
	if (x<x2) {
		while (x < x2)
		{
			image.set(x, y, color);
			if (d<0) { d += 2 * dy; }
			else {
				d += 2 * (dy - dx);
				++y;
			}
			if (y2<y1) { --y; }
			++x;
		}
	}
	if (x>x2) {
		while (x > x2) {
			image.set(x, y, color);
			if (d<0) { d += 2 * dy; }
			else {
				d += 2 * (dy - dx);
				++y;
			}
			if (y2<y1) { --y; }
			--x;
		}
	}
	if ((x1 == x2) && (y1<y2)) {

		while (y < y2) {
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
		while (y < y1) {
			image.set(x, y, color);
			++y;
		}
	}

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
}
void Circle_Pixel(int x0, int y0, int x, int y, TGAColor color)
{
	TGAImage image(100, 100, TGAImage::RGB);
	const TGAColor white = TGAColor(255, 255, 255, 255);
	const TGAColor red = TGAColor(255, 0, 0, 255);

	image.set(x0 + x, y0 + y, color);
	image.set(x0 + y, y0 + x, color);
	image.set(x0 + y, y0 -x, color);
	image.set(x0 + x, y0 - y, color);
	image.set(x0 - x, y0 - y, color);
	image.set(x0 - y, y0 - x, color);
	image.set(x0 - y, y0 + x, color);
	image.set(x0 - x, y0 + y, color);
}

void circle(int x0,int y0,int R, TGAColor color) {

	TGAImage image(100, 100, TGAImage::RGB);
	const TGAColor white = TGAColor(255, 255, 255, 255);
	const TGAColor red = TGAColor(255, 0, 0, 255);

	int d = 3 - 2 * R;
	int x = x0;
	int y = y0 + R;

	while (x < x0 + R / sqrt(2))
	{
		Circle_Pixel(x, y, x, y, color);
		if (d < 0) { d += 4 * x + 6;}
		else
		{
			d += 4 * (x - y) + 10;
			--y;
		}
		++x;
	}
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
}

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);



int main(int argc, char** argv) {

	//TGAImage image(100, 100, TGAImage::RGB);

	int x1, y1, x2, y2, R;

	//cin >> x1 >> y1 >> x2 >> y2;
	//line(x1, y1, x2, y2, white);

	cin >> x1>> y1>> R;
	circle(x1, y1, R,red);


	//image.set(52, 41, red);
	//image.set(x,y, red);
	//image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	//image.write_tga_file("output.tga");

	return 0;



}