#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 1010;
int m[maxn];
long long a[maxn];
int b, n;
set<pair<int, int> >S;

long long check(long long time) {
	long long tmp = 0;
	for (int i = 1; i <= b; i++)
		tmp += time / m[i] + 1;
	return tmp ;
}
int main()
{
	//freopen("B.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int cas;
	cin >> cas;
	for (int t = 1; t <= cas; t++) {
		printf("Case #%d: ", t);

		cin >> b >> n;
		for (int i = 1; i <= b; i++) {
			cin >> m[i];
		}
		long long hi = 1000000000000000LL;
		long long lo = 0;
		while (lo < hi) {
			long long mid = (lo + hi) >> 1;
			if (n <= check(mid))
				hi = mid;
			else
				lo = mid + 1;
		}
		//cout << lo << ' ' << check(lo) << ' ';
		//	cout << lo << ' ';
		int cnt = check(lo) - n;
		for (int i = b; i >= 1; i--) {
			if (lo % m[i] == 0 && cnt-- == 0)
				printf("%d\n", i);
		}
		//memset(vis, 0, sizeof(vis));

		//printf("%d\n", ans);
	}
	return 0;
}