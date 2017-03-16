#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int R, C, n, unhappy;

int calc1()
{
	int internal = 0;
	if (R >= 3 && C >= 3) internal = ((R - 2) * (C - 2) + 1) / 2;

	int holes = R * C - n;
	if (holes <= internal)
	{
		return unhappy - 4 * holes;
	}
	unhappy -= 4 * internal;
	holes -= internal;

	int corners = 2;
	if (R % 2 == 1 && C % 2 == 1) corners += 2;
	int borders = (R * C + 1) / 2 - internal - corners;

	if (holes <= borders)
	{
		return unhappy - 3 * holes;
	}
	unhappy -= 3 * borders;
	holes -= borders;

	assert(holes < corners);
	unhappy -= 2 * holes;

	return unhappy;	
}

int calc2()
{
	int left = n - (R * C + 1) / 2;

	int borders = 2 * (R + C) - 4;

	for(int i = 0; i < R; i++)
	{
		if (i % 2 == 0) borders--;
		if ((i + C - 1) % 2 == 0) borders--;
	}

	for(int i = 1; i < C - 1; i++)
	{
		if (i % 2 == 0) borders--;
		if ((i + R - 1) % 2 == 0) borders--;
	}
	if (left <= borders) return left * 3;
	return 1000000000;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d %d %d", &R, &C, &n);

		if (n <= (R * C + 1) / 2)
		{
			puts("0");
			continue;
		}

		unhappy = 0;
		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
			{
				int walls = 4;
				if (i == 0) walls--;
				if (i == R - 1) walls--;
				if (j == 0) walls--;
				if (j == C - 1) walls--;
				unhappy += walls;
			}
		unhappy /= 2;

		if (R == 1)
		{
			int holes = C - n;
			printf("%d\n", unhappy - 2 * holes);
			continue;
		}

		if (C == 1)
		{
			int holes = R - n;
			printf("%d\n", unhappy - 2 * holes);
			continue;
		}
		
		printf("%d\n", min(calc1(), calc2()));
	}
	return 0;
}