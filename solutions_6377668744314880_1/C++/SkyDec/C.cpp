// Problem : gcj r1 C
// Author : Leo Yu

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
#include <cstring>

using namespace std;
typedef long long LL;

#define link Link
#define next Next
#define elif else if

inline int read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}

const double Pi = 3.1415926535897932384626433832795;
int x[1000006], y[1000006];
double a[1000006];

int main()
{
	
	int T;
	cin >> T;
	for (int _ = 1; _ <= T; ++ _)
	{
		printf("Case #%d:\n", _);
		int N = read();
		for (int i = 1; i <= N; ++ i)
		{
			x[i] = read(), y[i] = read();
		}
		for (int i = 1; i <=  N; ++ i)
		{
			int n = 0;
			for (int j = 1; j <= N; ++ j)	if (i != j)
			{
				a[++ n] = atan2(y[j] - y[i], x[j] - x[i]);
			}
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= n; ++ i)
				a[i + n] = a[i] + 2 * Pi;
			int j = 1;
			int ans = n;
			for (int i = 1; i <= n; ++ i)
			{
				j = max(j, i);
				while (a[j + 1] < a[i] + Pi - 1e-9)
					++ j;
				ans = min(ans, j - i);
			}
			cout << ans << endl;
		}
	}

	return 0;
}