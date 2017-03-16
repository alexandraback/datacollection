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
int a[N];

#undef int
int main()
{
#define int long long
	int t; cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cerr << "Executing Case #" << tt << "\n";

		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int ret1 = 0;
		for (int i = 1; i < n; i++)
			ret1 += max(0ll, a[i - 1] - a[i]);

		int rate = 0;
		for (int i = 1; i < n; i++)
			rate = max(rate, a[i - 1] - a[i]);

		int ret2 = 0, cur = a[0];
		for (int i = 1; i < n; i++)
		{
			double eat = min(cur, rate);
			ret2 += eat;
			cur -= eat;
			cur = a[i];
		}

		cout << "Case #" << tt << ": ";
		cout << ret1 << " " << ret2 << "\n";
	}
	return 0;
}