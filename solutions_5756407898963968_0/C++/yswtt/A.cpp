#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt)
	{
		int r1, r2;
		int a[4][4];
		int b[4];
		int c[4];
		int res = 0;
		int n;
		
		cin >> r1;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> a[i][j];
		r1--;
		for (int i = 0; i < 4; ++i)
			b[i] = a[r1][i];
			
		cin >> r2;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> a[i][j];
		r2--;
		for (int i = 0; i < 4; ++i)
			c[i] = a[r2][i];
		
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if (b[i] == c[j])
				{
					res++;
					n = b[i];
				}
		
		cout << "Case #" << tt << ": ";
		if (res == 0)
			cout << "Volunteer cheated!" << endl;
		else if (res == 1)
			cout << n << endl;
		else if (res > 1)
			cout << "Bad magician!" << endl;
	}
	return 0;
}
