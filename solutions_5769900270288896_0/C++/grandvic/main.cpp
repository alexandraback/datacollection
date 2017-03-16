#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

//#pragma comment(linker, "/STACK:16777216")

using namespace std;

int X, Y, N;

int getHapyness(const vector<vector<int> > & a)
{
	int happy = 0;
	for (int x = 0; x < X; ++x)
	{
		for (int y = 1; y < Y; ++y)
		{
			if (a[x][y] && a[x][y - 1])
			{
				++happy;
			}
		}
	}
	for (int x = 1; x < X; ++x)
	{
		for (int y = 0; y < Y; ++y)
		{
			if (a[x][y] && a[x - 1][y])
			{
				++happy;
			}
		}
	}
	return happy;
}

void solve()
{
	cin >> X >> Y >> N;
	int cells = (X * Y);
	int maxMask = 1 << cells;
	int bestHapyness = 2000000000;

	vector<vector<int> > a(X, vector<int>(Y));
	for (int mask = 0; mask < maxMask; ++mask)
	{
		int m = mask, cnt = 0;
		for (int x = 0; x < X; ++x)
		{
			for (int y = 0; y < Y; ++y)
			{
				if (m & 1)
				{
					++cnt;
					a[x][y] = 1;
				}
				else
				{
					a[x][y] = 0;
				}
				m >>= 1;
			}
		}
		if (cnt == N)
		{
			bestHapyness = min(getHapyness(a), bestHapyness);
		}
	}
	cout << bestHapyness << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("d:/input.txt", "rt", stdin);
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		std::cout << "Case #" << t << ": ";
		solve();
	}
	return 0;
}
