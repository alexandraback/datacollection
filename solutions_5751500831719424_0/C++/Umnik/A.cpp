#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int t;
int n;
string a[110];
string b[110];
int c[110][110];
int d[200];
int ans = 0;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int z = 1; z <= t; z++)
	{
		ans = 0;
		printf("Case #%d: ", z);
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			int m = a[i].length();
			b[i] = a[i][0];
			for (int j = 1; j < m; j++)
				if (a[i][j] != a[i][j - 1])
					b[i] += a[i][j];
		}
		bool good = 1;
		for (int i = 1; i < n; i++)
			good &= (b[i] == b[0]);
		if (!good)
		{
			printf("Fegla Won\n");
			continue;
		}
		int m = b[0].length();
		for (int i = 0; i < n; i++)
		{
			int idx = 0;
			int sz = 1;
			for (int j = 1; j < a[i].length(); j++)
			{
				if (a[i][j] == a[i][j - 1])
					sz++;
				else
				{
					c[i][idx] = sz;
					sz = 1;
					idx++;
				}
			}
			c[i][idx] = sz;
		}
	/*	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				printf("%d ", c[i][j]);
			printf("\n");
		}
	*/	for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				d[j] = c[j][i];
			sort(d, d + n);
			for (int j = 0; j < n / 2; j++)
				ans += d[n / 2] - d[j];
			for (int j = n / 2; j < n; j++)
				ans += d[j] - d[n / 2];
		}
		printf("%d\n", ans);
	}

	return 0;
}