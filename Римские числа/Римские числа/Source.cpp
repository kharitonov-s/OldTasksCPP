#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
	int n, k, t, d, m, g, f;
	char c[1000];

	ofstream out;
	out.open("out.txt", ios::app);
	if (!out.is_open())
	{
		cout << "Error!" << endl;
		return 1;
	}
	ifstream in;
	in.open("in.txt");
	if (!in.is_open()) {
		cout << "error" << endl;
		return 1;
	}
	while (!in.eof())
	{
		in.getline(c, 10000);
		n = strlen(c);
		for (int i = 0;i < n;++i) {
			if (((i + 10) <= n) && ((int(c[i]) >= 48) && (int(c[i]) <= 57)) && ((int(c[i + 1]) >= 48) && (int(c[i + 1]) <= 57)) && ((c[i + 2]) == '.') && ((int(c[i + 3]) >= 48) && (int(c[i + 3]) <= 57)) && ((int(c[i + 4]) >= 48) && (int(c[i + 4]) <= 57)) && ((c[i + 5]) == '.') && ((int(c[i + 6]) >= 48) && (int(c[i + 6]) <= 57)) && ((int(c[i + 7]) >= 48) && (int(c[i + 7]) <= 57)) && ((int(c[i + 8]) >= 48) && (int(c[i + 8]) <= 57)) && ((int(c[i + 9]) >= 48) && (int(c[i + 9]) <= 57)) && ((10 * (int(c[i]) - 48) + (int(c[i + 1]) - 48)) <= 31) && ((10 * (int(c[i + 3]) - 48) + (int(c[i + 4]) - 48)) <= 12))
			{

				t = i;
				i = i + 9;

				d = (int(c[t]) - 48) * 10 + (int(c[t + 1]) - 48);
				cout << d << endl;
				if ((d / 10) == 1)
					out << 'X';
				if ((d / 10) == 2)
					out << "XX";
				if ((d / 10) == 3)
					out << "XXX";
				if (d % 10 == 1)
					out << 'I';
				if (d % 10 == 2)
					out << "II";
				if (d % 10 == 3)
					out << "III";
				if (d % 10 == 4)
					out << "IV";
				if (d % 10 == 5)
					out << 'V';
				if (d % 10 == 6)
					out << "VI";
				if (d % 10 == 7)
					out << "VII";
				if (d % 10 == 8)
					out << "VIII";
				if (d % 10 == 9)
					out << "IX";
				out << c[t + 2];
				m = (int(c[t + 3]) - 48) * 10 + (int(c[t + 4]) - 48);
				cout << m << endl;
				if ((m / 10) == 1)
					out << 'X';
				if (m % 10 == 1)
					out << 'I';
				if (m % 10 == 2)
					out << "II";
				if (m % 10 == 3)
					out << "III";
				if (m % 10 == 4)
					out << "IV";
				if (m % 10 == 5)
					out << 'V';
				if (m % 10 == 6)
					out << "VI";
				if (m % 10 == 7)
					out << "VII";
				if (m % 10 == 8)
					out << "VIII";
				if (m % 10 == 9)
					out << "IX";
				out << c[t + 5];
				g = (int(c[t + 6]) - 48) * 1000 + (int(c[t + 7]) - 48) * 100 + (int(c[t + 8] - 48)) * 10 + (int(c[t + 9]) - 48);
				cout << g << endl;
				cout << ((g % 1000) / 100) << endl;
				if ((g / 1000) == 1)
					out << 'M';
				if ((g / 1000) == 2)
					out << "MM";
				if ((g % 1000) == 3)
					out << "MMM";
				if (((g % 1000) / 100) == 1)
					out << 'C';
				if (((g % 1000) / 100) == 2)
					out << "CC";
				if (((g % 1000) / 100) == 3)
					out << "CCC";
				if (((g % 1000) / 100) == 4)
					out << "CD";
				if (((g % 1000) / 100) == 5)
					out << 'D';
				if (((g % 1000) / 100) == 6)
					out << "DC";
				if (((g % 1000) / 100) == 7)
					out << "DCC";
				if (((g % 1000) / 100) == 8)
					out << "DCCC";
				if (((g % 1000) / 100) == 9)
					out << "CM";
				cout << ((g % 100) / 10) << endl;
				if (((g % 100) / 10) == 1)
					out << 'X';
				if (((g % 100) / 10) == 2)
					out << "XX";
				if (((g % 100) / 10) == 3)
					out << "XXX";
				if (((g % 100) / 10) == 4)
					out << "XL";
				if (((g % 100) / 10) == 5)
					out << 'L';
				if (((g % 100) / 10) == 6)
					out << "LX";
				if (((g % 100) / 10) == 7)
					out << "LXX";
				if (((g % 100) / 10) == 8)
					out << "LXXX";
				if (((g % 100) / 10) == 9)
					out << "XC";
				cout << g % 10 << endl;
				if (g % 10 == 1)
					out << 'I';
				if (g % 10 == 2)
					out << "II";
				if (g % 10 == 3)
					out << "III";
				if (g % 10 == 4)
					out << "IV";
				if (g % 10 == 5)
					out << 'V';
				if (g % 10 == 6)
					out << "VI";
				if (g % 10 == 7)
					out << "VII";
				if (g % 10 == 8)
					out << "VIII";
				if (g % 10 == 9)
					out << "IX";
				f = 1;
			}
			else out << c[i];
		}
		if (f == 0) {
			out << endl;
			out << "oshibka";
		}

		cout << endl;
		out << endl;
	}
	out.close();
	in.close();
	system("pause");
	return 0;
}