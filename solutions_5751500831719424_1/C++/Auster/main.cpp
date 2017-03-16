#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int T, n;

char s[1 << 7][1 << 7];
char ss[1 << 7][1 << 7];

vector<int> len[1 << 7];

int dp[1 << 7];

int go(int pos)
{
	if (pos == len[0].size())
		return 0;
	int & res = dp[pos];
	if (res != -1)
		return res;
	res = (int)1e9;
	for(int i = 1; i <= 111; ++i)
	{
		int add = 0;
		for(int j = 0; j < n; ++j)
			add += abs(len[j][pos] - i);
		res = min(res, add + go(pos + 1));
	}
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 0; I < T; ++I)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		printf("Case #%d: ", I + 1);
		for(int i = 0; i < n; ++i)
		{
			int N = 0;
			for(int j = 0; s[i][j]; ++j)
				if (N == 0 || (ss[i][N - 1] != s[i][j]))
					ss[i][N++] = s[i][j];
			ss[i][N] = 0;
		}
		bool bad = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if (strcmp(ss[i], ss[j]) != 0)
					bad = 1;
		if (bad)
		{
			printf("Fegla Won\n");
			continue;
		}

		for(int i = 0; i < n; ++i)
		{
			len[i].clear();
			int cnt = 1;
			for(int j = 1; s[i][j]; ++j)
			{
				if (s[i][j] != s[i][j - 1])
				{
					len[i].push_back(cnt);
					cnt = 1;
					continue;
				}
				else
					++cnt;
			}
			len[i].push_back(cnt);
		}
		memset(dp, -1, sizeof(dp));

		printf("%d\n", go(0));
	}
	return 0;
}