#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <string>
#include <cstring>
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.out", "w", stdout);
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e6+10;

int r, c, n;
int mrk[17][17];

int main()
{
	rf; wf;
	
	int test;
	scanf("%d", &test);

	rep(tt, 1, test)
	{
		cin >> r >> c >> n;
		memset(mrk, 0, sizeof mrk);

		rep(i, 0, r*c-1)
		{
			rep(j, i+1, r*c-1)
			{
				if((i+1 == j and (i/c) == (j/c)) or i+c == j)
					mrk[i][j] = 1;
			}
		}

		int ans = 1e9, rc = r*c;
		rep(i, 0, (1<<rc)-1)
		{
			if(__builtin_popcount(i) != n) continue;

			vector<int> bits;
			rep(j, 0, rc-1)
			{
				int tmp = 1<<j;
				if((tmp&i)) bits.push_back(j);
			}

			int tans = 0;
			rep(j, 0, bits.size()-2) rep(k, j+1, bits.size()-1)
				tans += mrk[bits[j]][bits[k]];
			ans = min(ans, tans);
		}

		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}