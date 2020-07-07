#include<iostream> 
#include<cstring> 
using namespace std;
int main()
{
	int n, k = 0, max = 0, f = 0, t;
	char s[32];
	cin.getline(s, 32);
	n = strlen(s);

	for (int i = 0;i < n;++i)
	{
		if (s[i] == '1') {
			++k;
			if (f == 0)
				f = i;
		}
		else {
			if (k > max) {
				max = k;
				t = f;
			}
			k = 0;
			f = 0;
		}
	}
	for (int i = 0;i < n;++i)
		if (i != t) cout « " ";
		else {
			cout « "^" « endl;
			break;
		}
		if (max == 0)
			cout « "error" « endl;
		else cout « max «" "« t « endl;
		system("pause");
		return 0;
}