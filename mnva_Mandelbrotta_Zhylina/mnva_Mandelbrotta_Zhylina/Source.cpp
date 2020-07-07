#include "windows.h"
#include <conio.h>
#include <iostream>

using namespace std;

int depth = 2000;
const unsigned int d1 = 2000;
const unsigned int d2 = 2000;
int arr[d1][d2];

int main()
{
	float cr, ci, zr, zi, tmp;
	HWND wnd = GetConsoleWindow();
	HDC dc = GetDC(wnd);
	int k,n;

	COLORREF COLOR = RGB(50, 255, 255);

	for (n = 1; n<d1; n ++)
	{
		for (int i = -320;i<320;i++)
		{
			ci = ((float)i) / 200.0;
			for (int j = -380;j<160;j++)
			{
				cr = ((float)j) / 240.0;
				zi = zr = 0.0;
				for (k = 0;k<depth;k++)
				{
					tmp = zr*zr - zi*zi;
					zi = 2 * zr*zi + ci;
					zr = tmp + cr;
					if (zr*zr + zi*zi>1.0E16) break;
				}
				if (k<depth)
				arr[n][k]= SetPixel(dc, i + 240, j + 380, k*4);
				else SetPixel(dc, i + 240, j + 380, 10);
			}
		}
	}
	cout << arr[n][k];
	system("pause");
	return 0;
}
