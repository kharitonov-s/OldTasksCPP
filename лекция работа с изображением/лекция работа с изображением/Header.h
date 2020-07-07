typedef unsigned short WORD; //typedef ���� ����� ��� ������-���� ���� (����� - short)
typedef unsigned long DWORD; //��� ������� (int DWORD)
typedef long LONG; //��� ������� int LONG
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


