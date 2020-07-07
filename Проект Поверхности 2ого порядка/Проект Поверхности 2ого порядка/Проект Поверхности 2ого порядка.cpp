#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
ifstream input("input.txt");
vector<vector<float>>small_matrix(vector<vector<float>>M, int a, int b)          // ������������ ������� � �������
{
	M.erase(M.begin() + a);
	for (int i = 0; i < M.size(); i++)
		M[i].erase(M[i].begin() + b);
	return(M);
}

float det(vector<vector<float>>xk)	//������� ���������� ������������
{
	vector<vector<float>>temp_matrix;
	int count = xk.size();

	float temp = 0;
	int k = 1;
	if (count<1) {
		cout << "not run";
		return 0;
	}
	else if (count == 1)
		temp = xk[0][0];
	else if (count == 2)
		temp = xk[0][0] * xk[1][1] - xk[1][0] * xk[0][1];
	else
	{
		for (int i = 0; i<count; i++)
		{
			temp_matrix = small_matrix(xk, i, 0);

			temp = temp + k*xk[i][0] * det(temp_matrix);
			k = -k;
		}
	}
	return temp;
}

vector<vector<float>> GetMatrix()      // ���������� ������� �� �����
	{
	vector<vector<float>>matrix;
	int n = 4;
	matrix.resize(n);
	for (int i = 0; i < n; i++) {
		matrix[i].resize(n);
		for (int j = 0; j < n; j++) {
			input >> matrix[i][j];
		}
	}
	return matrix;
}

vector<float>cube(float a, float b, float c, float d)
{
	vector<float>ansver;
	for (int i = -10000; i < 10000; i++) {
		if (a*i*i*i + b*i*i + c*i + d == 0) {
			ansver.push_back(i);
		}
	}
	if (ansver.size() != 3)
		ansver.push_back(ansver[0]);
	return ansver;
}

vector<float>Find_Type(vector<float>La, float D, float d, float k1, float k2, float t1, float t2)  // ������� ��� �����������
{
	setlocale(LC_CTYPE, "rus");
	sort(La.begin(), La.end());
	if (d == 0) {
		if (D == 0) {
			if (t2 > 0) {
				if (t1*k2 < 0) {
					cout << "������������� �������" << endl;
				}
				if (t1*k2>0) {
					cout << "������ ������������� �������" << endl;
				}
				if (k2 == 0) {
					cout << "���� ������ �������������� ����������" << endl;
				}
			}
			if (t2 < 0) {
				if (k2 == 0) {
					cout << "���� �������������� ����������" << endl;
				}
				if (k2 != 0) {
					cout << "��������������� �������" << endl;
				}
			}
			if (t2 == 0) {
				if (k2 != 0) {
					cout << "�������������� �������" << endl;
				}
				if (k2 == 0) {
					if (k1 < 0) {
						cout << "���� ������������ ����������" << endl;
					}
					if (k1 > 0) {
						cout << "���� ������ ������������ ����������" << endl;
					}
					if (k1 == 0) {
						cout << "���� ����������� ����������" << endl;
					}
				}
			}
		}
		else {
			if (D<0) {
				cout << "������������� ����������" << endl;
			}
			if (D>0) {
				cout << "��������������� ����������" << endl;
			}
		}
	}
	else {
		if (t2 > 0 && t1*d > 0) {
			if (D > 0) {
				cout << "������ ���������" << endl;
			}
			if (D == 0) {
				cout << "������ �����" << endl;
			}
			if (D < 0) {
				cout << "���������" << endl;
			}
		}
		else {
			if (La[1]>0) {
				La.push_back(La[0]);
				La.erase(La.begin());
			}
			if (D > 0) {
				cout << "������������� �����������" << endl;
			}
			if (D < 0) {
				cout << "������������ �����������" << endl;
			}
			if (D == 0) {
				cout << "�����" << endl;
			}
		}
	}
	return La;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "������� ����� �������" << endl;
	int a, b;
	cin >> a;
	for (int i = 0; i < 16 * (a - 1); i++) {
		input >> b;
	}

	vector<vector<float>>P; // ������������ �������
	vector<vector<float>>A; // ������������ �����
	P = GetMatrix();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			cout << P[i][j] << " ";
		}
		cout << endl;
	}
	A = small_matrix(P, 3, 3);
	float t1 = P[0][0] + P[1][1] + P[2][2];
	float t2 = det(small_matrix(A, 0, 0)) + det(small_matrix(A, 1, 1)) + det(small_matrix(A, 2, 2));
	float k1 = (P[0][0] * P[3][3] - P[3][0] * P[3][0]) + (P[1][1] * P[3][3] - P[3][3] * P[3][1]) + (P[2][2] * P[3][3] - P[3][2] * P[3][2]);
	float k2 = det(small_matrix(P, 2, 2)) + det(small_matrix(P, 1, 1)) + det(small_matrix(P, 0, 0));
	float d = det(A), D = det(P);
	cout << "�������� ����������:" << endl;
	cout << "J1 = " << t1 << endl;
	cout << "J2 = " << t2 << endl;
	cout << "J3 = " << d << endl;
	cout << "J4 = " << D << endl;
	vector<float>La = cube(-1, t1, -t2, d); // ����� ������������������� ����������

	if (d != 0) {
		cout << "��� ��� ����������� �������� �����������, � ��������� ����� ��� \nL1*x^(-2) + L2*y^(-2) + L3*z^(-2)+J4/J3 = 0" << endl;
		La = Find_Type(La, D, d, k1, k2, t1, t2);
		cout << "������������ ���������: " << endl << La[0] << "*x(-2) + " << La[1] << "*y(-2) + " << La[2] << "*z(-2)+" << D / d << " = 0" << endl;
	}
	else if (D != 0) {
		cout << "����������� �������������" << endl;
		La = Find_Type(La, D, d, k1, k2, t1, t2);
		cout << "������������ ���������:" << endl;
		cout << La[1] << "*x^(-2) + " << La[2] << "*y^(-2) + 2*" << sqrt(D / t2 * (-1)) << " = 0" << endl;
	}
	else
		if (t2 != 0) {
			cout << "��� ��� J3=J4=0, �� �������� �������������:" << endl;
			if (La[0] == 0)
				La.erase(La.begin());
			else
				if (La[1] == 0)
					La.erase(La.begin() + 1);
				else
					if (La[2] == 0)
						La.erase(La.begin() + 2);
			cout << "J'3=" << k2 << endl;
			cout << "�������� ��������� ����������� � ����:" << endl;
			cout << La[0] << "*x^(-2) + " << La[1] << "*y^(-2) + " << k2 / t2 << " = 0" << endl;
			La = Find_Type(La, D, d, k1, k2, t1, t2);
		}
		else {
			cout << "��� ��� J2=J3=J4=0 �������� �������������:" << endl;
			cout << "J'3=" << k2 << endl;
			if (La[0] == 0)
				La.erase(La.begin());
			else
				if (La[1] == 0)
					La.erase(La.begin() + 1);
				else
					if (La[2] == 0)
						La.erase(La.begin() + 2);
			cout << "������� � ������������ ������� ��������� ��������� ����������� ����� ���:" << endl;
			cout << La[0] << "*x^(-2) + 2*" << sqrt(k2 / t1*(-1)) << "*y = 0" << endl;
			La = Find_Type(La, D, d, k1, k2, t1, t2);
		}
		system("pause");
}
