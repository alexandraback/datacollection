/* 2015.4.18 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

int m[10005];

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;
		fscanf(fin, "%d", &N);

		int maxd = 0;
		int r1 = 0;
		int r2 = 0;

		for (int i = 0; i < N; i++)
			fscanf(fin, "%d", m + i);

		for (int i = 0; i < N - 1; i++)
		{
			int delta = m[i] - m[i + 1];
			if (delta > 0)
			{
				r1 += delta;
				if (maxd < delta)
					maxd = delta;
			}
		}
		for (int i = 0; i < N - 1; i++)
		{
			r2 += std::min(maxd, m[i]);
		}

		fprintf(fout, "Case #%d: %d %d\n", c_n, r1, r2);
		printf("Case #%d: %d %d\n", c_n, r1, r2);
	}
	return -0;
}
