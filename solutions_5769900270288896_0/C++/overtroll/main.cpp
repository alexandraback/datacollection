#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int tt;

void pt(int ans)
{
	cout << "Case #" << tt << ": " << ans << endl;
}

int a[5];
int b[5];

int r, c, n, nd;

int gta()
{
	int l = nd, an = 0;
	for (int i = 4; i >= 0; i--)
	{
		if (a[i] >= l) return an + l * i;
		l -= a[i], an += a[i] * i;
	}
	return 0;
}

int gtb()
{
	int l = nd, an = 0;
	for (int i = 4; i >= 0; i--)
	{
		if (b[i] >= l) return an + l * i;
		l -= b[i], an += b[i] * i;
	}
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	cin >> tests;	
	for (tt = 1; tt <= tests; tt++)
	{
		cin >> r >> c >> n;
		if ((r * c + 1) / 2 >= n)
		{
			pt(0);
			continue;
		}
		int walls = r * c * 2 - r - c;
		nd = r * c - n;
		for (int i = 0; i < 5; i++) a[i] = b[i] = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				int an = 4;
				if (i == 0) an--;
				if (i + 1 == r) an--;
				if (j == 0) an--;
				if (j + 1 == c) an--;
				if ((i + j) % 2 == 0) a[an]++;
				else b[an]++;
			}
		}
		int ga = gta();
		int gb = gtb();
		pt (walls - max(ga, gb));
	}
	return 0;
}