#include <functional>
#include <algorithm>
#include <strstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int ppc(int x)
{
	int r = 0;
	while (x)
	{
		r += x % 2;
		x /= 2;
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0);

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int t;
	cin >> t;
	for (int tn = 1; tn <= t; ++tn)
	{
		int r, c, n;
		cin >> r >> c >> n;
		int m = r * c;
		int res = 1000000000;
		for (int mask = 0; mask < (1 << m); ++mask)
		{
			if (ppc(mask) != n)
				continue;
			int tmp = 0;
			for (int i = 0; i < m; ++i)
			{
				if (!(mask & (1 << i)))
					continue;
				int j = i + 1;
				if ( i % c != c - 1 && j < m && (mask & (1 << j)))
					++tmp;
				j = i + c;
				if (j < m && (mask & (1 << j)))
					++tmp;
			}
			res = min(res, tmp);
		}
		cout << "Case #" << tn << ": " << res << endl;
	}

	return 0;
}