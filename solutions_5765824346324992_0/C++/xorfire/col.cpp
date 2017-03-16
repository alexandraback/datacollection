#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

const int N = 1234;
int a[N], b[N];

int go(int n, int M)
{
	if (M <= n) return M;

	int lo = 0, hi = (int)1e15;
	while (lo < hi)
	{
		int mi = (lo + hi + 1) / 2;
		int num = 0;
		for (int i = 1; i <= n; i++)
			num += mi / a[i];
		if (num >= M - n) hi = mi - 1;
		else lo = mi;
	}

	int num = 0;
	for (int i = 1; i <= n; i++)
		num += lo / a[i];
	M -= num + n;
	for (int i = 1; i <= n; i++)
		b[i] = a[i] - lo % a[i];

	while (M--)
	{
		int x = 1234567;
		for (int i = 1; i <= n; i++)
			x = min(x, b[i]);

		if (x == 0)
		{
			for (int i = 1; i <= n; i++)
				if (b[i] == 0)
				{
					b[i] = a[i];
					if (M == 0) return i;
					break;
				}
		}
		else
		{
			for (int i = 1; i <= n; i++)
				if (b[i] == x) b[i] = 0;
				else b[i] -= x;
			for (int i = 1; i <= n; i++)
				if (b[i] == 0)
				{
					b[i] = a[i];
					if (M == 0) return i;
					break;
				}
		}
	}
	assert(false);
	return 0;
}

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";

		int n, M; cin >> n >> M;
		for (int i = 1; i <= n; i++) cin >> a[i];

		cout << "Case #" << tt << ": " << go(n, M) << "\n";
	}
	return 0;
}