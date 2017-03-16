#include <iostream>
#include <stdio.h>
using namespace std;

int T;
int a[4][4];
int b[4][4];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int fr;
		cin >> fr; --fr;
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				cin >> a[j][k];
		int sr;
		cin >> sr; --sr;
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				cin >> b[j][k];
		int cnt = 0, y;
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				if (a[fr][j] == b[sr][k])
					++cnt, y = a[fr][j];
		if (cnt == 0)
			cout << "Case #" << i << ": Volunteer cheated!" << endl;
		else if (cnt == 1)
			cout << "Case #" << i << ": " << y << endl;
		else
			cout << "Case #" << i << ": Bad magician!" << endl;
		cout.flush();
	}

	return 0;
}