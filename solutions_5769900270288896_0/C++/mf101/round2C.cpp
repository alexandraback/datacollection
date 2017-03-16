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

using namespace std;

#define mp make_pair

int grid(int mask, int R, int C)
{
	int G[20][20];
	for (int i = 0; i <= R; i++)
		for (int j = 0; j <= C; j++)
			G[i][j] = 0;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			G[i][j] = (mask & 1);
			mask >>= 1;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ans += (G[i-1][j] && G[i][j]) + (G[i][j-1] && G[i][j]);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	for (int cases = 1; cases <= TC; cases++)
	{
		int N, R, C;
		cin >> R >> C >> N;
		
		int ans = 10000;
		int m = R*C;
		for (int i = 0; i < (1 << m); i++)
		{
			int mask = i;
			if( __popcnt(mask) == N)
					ans = min(ans, grid(mask, R, C));
		}

		cout << "Case #" << cases << ": ";
		cout << ans << "\n";
	}
	
	return 0;
}