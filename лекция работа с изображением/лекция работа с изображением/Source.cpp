#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"

using namespace std;

int main()
{
	ifstream in;
	in.open("kidnoise.bmp", ios::binary);
	if (!in.is_open())
	{
		cout << "File not opened!" << endl;
		system("pause");
		return 1;
	}

	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;
	 
	in.read((char*)&bmfh.bfType, sizeof(WORD)); // & - ���������� ����� ���� bfType, ����������� � ��������� bmfh //������� 2 ����� � bfType
	                                 // � ����� ���� ���������������� ��� ��������� �� char, � char* ������� 2 ����� (sizeof(WORD)==2 �����) ��� ��������� �� ����
	in.read((char*)&bmfh.bfSize, sizeof(DWORD));
	in.read((char*)&bmfh.bfReserved1, sizeof(WORD));
	in.read((char*)&bmfh.bfReserved2, sizeof(WORD));
	in.read((char*)&bmfh.bfOffbits, sizeof(DWORD)); //bfOffbits - �������� �� ������ ����� �� ����� ��� �������� �������

	cout.write((char*)&bmfh.bfType, sizeof(WORD));
	cout << endl;
	cout << "bfSize: " << bmfh.bfSize << endl;
	cout << "bfReserved1: " << bmfh.bfReserved1 << endl;
	cout << "bfReserved2: " << bmfh.bfReserved2 << endl;
	cout << "bfOffbits: " << bmfh.bfOffbits << endl;

	//��������� Info Header
	//(������ � ����� �����������)
	in.read((char*)&b.biSmihize, sizeof(DWORD));
	in.read((char*)&bmih.biWidth, sizeof(LONG));
	in.read((char*)&bmih.biHeight, sizeof(LONG));
	in.read((char*)&bmih.biPlanes, sizeof(WORD));
	in.read((char*)&bmih.biBitCount, sizeof(WORD));
	in.read((char*)&bmih.biCompression, sizeof(DWORD));
	in.read((char*)&bmih.biSizeImage, sizeof(DWORD));
	in.read((char*)&bmih.biXPelsPerMeter, sizeof(LONG));
	in.read((char*)&bmih.biYPelsPerMeter, sizeof(LONG));
	in.read((char*)&bmih.biClrUsed, sizeof(DWORD));
	in.read((char*)&bmih.biClrImportant, sizeof(DWORD));

	cout << "Width: " << bmih.biWidth << endl;
	cout << "Height: " << bmih.biHeight << endl;

	//����� ��������� ����� � ������� ��������
	//in.seekg(bmfh.bfOffbits);

	//������� ���������� ������ ��� ������ ����������� 
	//(��������� �� ������ ���������� ��� ����� �� ������� ���������� RGB �����������)
	//����� ����� ��������� ��������� �� ������
	BYTE ***pix_colors = new BYTE **[bmih.biHeight];
	BYTE buf[3];//buf - ������ ��������� ������� ����� ��������� �� �������� ���� 
	for (int i = 0;i < bmih.biHeight;++i)
	{
		//����� ����� ��������� ��������� �� �������� � �������
		pix_colors[i] = new BYTE *[bmih.biWidth];
		for (int j = 0;j < bmih.biWidth;++j)
		{
			//����� ����� ��������� RGB ����������
			pix_colors[i][j] = new BYTE[3];
			//��������� �� ����� 3 �����
			in.read((char*)pix_colors[i][j], 3);
		}

		if (3 * bmih.biWidth % 4 != 0) //���� ������� �� ������� ������ �� 4 �� ����� ����
			in.read((char*)buf, 4 - 3 * bmih.biWidth % 4);//��
	}

	for (int i = 1;i < bmih.biHeight - 1;++i)
		for (int j = 1;j < bmih.biWidth - 1;++j)
		//{
			//int sum_rgb = 0;
			for (int k = 0;k < 3;++k)
			{
				BYTE neighbors[9];
				neighbors[0] = pix_colors[i - 1][j - 1][k];
				neighbors[1] = pix_colors[i - 1][j][k];
				neighbors[2] = pix_colors[i - 1][j + 1][k];

				neighbors[3] = pix_colors[i][j - 1][k];
				neighbors[4] = pix_colors[i][j][k];
				neighbors[5] = pix_colors[i][j + 1][k];

				neighbors[6] = pix_colors[i + 1][j - 1][k];
				neighbors[7] = pix_colors[i + 1][j][k];
				neighbors[8] = pix_colors[i + 1][j + 1][k];

				//���������� ��������
				/*	int sum = 0;
					for (int s = 0;s < 9;++s)
						sum += neighbors[s];


					pix_colors[i][j][k] = sum / 9;*/

					//��������� ���������� �����������
				sort(neighbors, neighbors + 9);
				pix_colors[i][j][k] = neighbors[4];
			}
					//������� ����������� �������
					//if (k < 2)
						//pix_colors[i][j][k] = 0;

				//������� ����������� �����
				/*sum_rgb += pix_colors[i][j][k];
			}
			for (int k = 0;k < 3;++k)
				pix_colors[i][j][k] = sum_rgb / 3;
		}*/

	ofstream out("result.bmp", ios::binary); //�������� ��������������� �����
	if (!out.is_open())
	{
		cout << "Out file is not opened!" << endl;
		system("pause");
		return 1;
	}

	out.write((char*)&bmfh.bfType, sizeof(WORD)); 
	out.write((char*)&bmfh.bfSize, sizeof(DWORD));
	out.write((char*)&bmfh.bfReserved1, sizeof(WORD));
	out.write((char*)&bmfh.bfReserved2, sizeof(WORD));
	out.write((char*)&bmfh.bfOffbits, sizeof(DWORD));

	out.write((char*)&bmih.biSize, sizeof(DWORD));
	out.write((char*)&bmih.biWidth, sizeof(LONG));
	out.write((char*)&bmih.biHeight, sizeof(LONG));
	out.write((char*)&bmih.biPlanes, sizeof(WORD));
	out.write((char*)&bmih.biBitCount, sizeof(WORD));
	out.write((char*)&bmih.biCompression, sizeof(DWORD));
	out.write((char*)&bmih.biSizeImage, sizeof(DWORD));
	out.write((char*)&bmih.biXPelsPerMeter, sizeof(LONG));
	out.write((char*)&bmih.biYPelsPerMeter, sizeof(LONG));
	out.write((char*)&bmih.biClrUsed, sizeof(DWORD));
	out.write((char*)&bmih.biClrImportant, sizeof(DWORD));

	int padding = 4 - 3 * bmih.biWidth % 4;//
	BYTE *pad = new BYTE[padding];
	for (int i = 0;i < padding;++i)
		pad[i] = 0;

	for (int i = 0;i < bmih.biHeight;++i)
	{
		for (int j = 0;j < bmih.biWidth;++j)
			out.write((char*)pix_colors[i][j], 3);
		if (padding != 0)
			out.write((char*)pad, padding);
	}
	
	
	in.close();
	out.close();
	cout << "Finish" << endl;
	system("pause");
	return 0;
}