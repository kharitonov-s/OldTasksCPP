typedef unsigned short WORD; //typedef дает новое имя какому-либо типу (здесь - short)
typedef unsigned long DWORD; //для линукса (int DWORD)
typedef long LONG; //для линукса int LONG
typedef unsigned char BYTE;

struct BITMAPFILEHEADER
{
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffbits;
};

struct BITMAPINFOHEADER 
{
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
};


