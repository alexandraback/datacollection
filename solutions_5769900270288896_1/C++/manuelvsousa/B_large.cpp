#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int cnt[1 << 18];
int R, C, N;

int calc(int i)
{
	int resposta = 0;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				resposta++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				resposta++;
		}
	}
	return resposta;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> N;

		int max = R * C * N * 100;
		for (int i = 1; i < (1 << (R * C)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == N) max = min(max, calc(i));
		}
		printf("Case #%d: %d\n", t, max);
	}
}
