#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

void solve();
int main()
{
	int t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
}

int findmin(int a[],int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}
unsigned gcd(unsigned x, unsigned y){
	unsigned wk;
	if (x<y){ wk = x; x = y; y = wk; }
	while (y){
		wk = x%y;
		x = y;
		y = wk;
	}
	return x;
}
int gcd_a(int n, int a[])
{
	if (n == 1) return a[0];
	if (n == 2) return gcd(a[0], a[1]);
	int h = n / 2;
	return gcd(gcd_a(h, &a[h - 1]), gcd_a(n - h, &a[h]));
}
int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}
int lcm_a(int n, int a[])
{
	int l = a[0];
	for (int i = 1; i < n; i++)
		l = lcm(l, a[i]);
	return l;
}
void solve()
{
	int M[1000], S[1000], c = 1, b, n;
	scanf("%d %d", &b, &n);
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &M[i]);
		S[i] = 0;
	}
	unsigned nLcm = lcm_a(b, M);
	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		sum += nLcm / M[i];
	}
	n %= sum;
	if (!n)
		n = sum;
	c = 0;
	/*if (c == n)
	{
		printf("1");
		return;
	}*/
	while (1)
	{	
		int min = findmin(S, b);
		for (int i = 0; i < b; i++)
		{
			S[i] = S[i] - min;
			if (S[i] == 0)
			{
				c++;
				if (c == n)
				{
					printf("%d", i + 1);
					return;
				}
				S[i] = M[i];
			}
		}
	}
}