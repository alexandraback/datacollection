/*
by:http://blog.csdn.net/acmmmm
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <time.h>
#include <string>
#include <queue>
template <class T>
inline bool rd(T &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template <class T>
inline void pt(T x) {
	if (x <0) {
		putchar('-');
		x = -x;
	}
	if (x>9) pt(x / 10);
	putchar(x % 10 + '0');
}
using namespace std;
typedef long long ll;
int a[1111], n;
int main()
{
	freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
	int T, Cas = 1;
	rd(T);
	while (T--)
	{
		rd(n);
		int ans = -INT_MAX;
		for (int i = 0; i < n; i++)
		{
			rd(a[i]);
			if (i)
				ans = max(ans, a[i - 1] - a[i]);
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i<n; i++)
		if (a[i - 1]>a[i])
			ans1 += a[i - 1] - a[i];
		for (int i = 0; i < n - 1; i++)
		if (a[i] < ans)
			ans2 += a[i];
		else
			ans2 += ans;
		printf("Case #%d: %d %d\n", Cas++, ans1, ans2);
	}
	return 0;
}
