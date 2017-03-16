#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void mofile(), input(), solve(), output(int i), sort(int l, int r);
string s[101];
int test, check=0, n, a[101], res = 0;

void mofile()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d\n", &test);
}

int main()
{
	mofile();
	for (int i = 1; i <= test; i++)
	{
		check = 0; res = 0;
		input(); 
		solve(); 
		output(i);
	}
}

void input()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
}

void solve()
{
	int j, t, u = 0, sl[101][101];
	char h;
	string hold, ex;

	for (int i = 1; i <= n; i++)
	{
		u = 0;
		j = 0; t = s[i].length() - 1; h = s[i][0]; hold = ""; sl[i][u] = 1;
		if (i == 1)
		{
			ex += h;
		}
		else
		{
			hold += h;
		}
		while (j+1 <= t)
		{
			j++;
			if (h == s[i][j])
			{
				sl[i][u]++;
			}
			else
			{
				h = s[i][j]; u++; sl[i][u] = 1;
				if (i == 1)
				{
					ex += h;
				}
				else
				{
					hold += h;
				}
			}
		}
		if ((ex != hold) && (i!=1))
		{
			check = 1; 
			return;
		}
	}
	t = ex.length();
	for (int i = 0; i <= t-1; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[j] = sl[j][i];
		}
		sort(1, n);
		u = a[(n + 1) / 2];
		for (int j = 1; j <= n; j++)
		{
			res += abs(a[j] - u);
		}
	}
}

void sort(int l, int r)
{
	int mid = a[(l + r) / 2], i=l, j=r;
	do
	{
		while (a[i] < mid){ i++; }
		while (a[j] > mid){ j--; }
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (i < r){ sort(i, r); }
	if (j > l){ sort(l, j); }
}

void output(int t)
{
	if (check == 1)
	{
		printf("Case #%d: %s\n",t,"Fegla Won");
	}
	else
	{
		printf("Case #%d: %d\n",t, res);
	}
}