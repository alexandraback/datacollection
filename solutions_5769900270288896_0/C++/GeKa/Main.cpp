#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <memory.h>


using namespace std;

int R, C, N;

pair<int, int> f(int a)
{
	int cnt = 0;
	int unh = 0;
	for (int i = 0; i < R * C; i++)
		if (a & (1 << i))
			cnt++;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			if (j + 1 < C)
			{
				if  ( a & (1 << (C * i + j)))
					if ( a & (1 << (C * i + j+1)))
						unh++;
			}
			if (i + 1 < R)
			{
				if  ( a & (1 << (C * i + j)))
					if ( a & (1 << (C * (i+1) + j)))
						unh++;
			}
		}
		return make_pair(cnt, unh);
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T;t++)
	{		
		cin >> R >> C >> N;
		int NN = 1 << (R*C);
		int res = 1000000000;
		for (int i = 0; i < NN; i++)
		{
			auto p = f(i);
			if (p.first == N)
				res = min(res, p.second);
		}
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}