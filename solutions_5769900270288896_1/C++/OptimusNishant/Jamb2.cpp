#include<bits/stdc++.h>
using namespace std;
int arr[300000];
int j, C, N;
int func(int i)
{
	int ans = 0;
	for (int r = 0; r < j; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				ans++;
		}
	}
	return ans;
}

int main() 
{
	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++)
	{
		cin >> j >> C >> N;
 
		int sol = j * C * N * 100;
		for (int i = 1; i < (1 << (j * C)); i++)
		{
			arr[i] = arr[i - (i & -i)] + 1;
			if (arr[i] == N) sol = min(sol, func(i));
		}
		printf("Case #%d: %d\n", cs, sol);
	}
}

