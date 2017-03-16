#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int test, t;
int a[20][20];
int b[20];
int d;
int rs;

int find(int x, int y, int kq, int k)
{
	if(k == n)
	{
		rs = min(rs, kq);
		//cout << kq << " ";
		return 0;
	}
	if (y > c) {
		find(x + 1, 1, kq, k);
		return 0;
	}
	if (x > r) return 0;

	for (int i = 0; i <= 1; i++){
		a[x][y] = i;
		int kqq = kq;
		if (i == 1){
			if (a[x - 1][y] == 1) kqq++;
			if (a[x][y - 1] == 1) kqq++;
			find(x, y + 1, kqq, k + 1);
		} else find(x, y + 1, kqq, k);
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> test;
	for(int t = 1; t <= test; t++)
	{
		cin >> r >> c >> n;
		for(int i = 0; i < 20; i++)
			for(int j = 0; j < 20; j++)
				a[i][j] = 0;
		//cout << r << c << n;
		rs = 100000;
		find(1, 1, 0, 0);
		cout << "Case #" << t << ": " << rs << "\n";
	}
	return 0;
}