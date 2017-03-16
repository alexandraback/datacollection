#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const long long inf = (long long)1e17;

int n, m, a[10000], pos[10000], lef[10000];

long long cal(long long t) {
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += t / a[i];
		if (t % a[i] != 0) ++ans;
	}
	return ans;
}

bool cmp(int a, int b) {
	if (lef[a] != lef[b]) return lef[a] < lef[b];
	return a < b;
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		long long l = 0, r = inf;
		while (l < r) {
			long long mid = (l + r) / 2;
			if (cal(mid) < m) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		if (l > 0) --l;
		for (int i = 0; i < n; ++i) {
			pos[i] = i;
			lef[i] = a[i] - l % a[i];
			if (lef[i] == a[i]) lef[i] = 0;
		}
		sort(pos, pos + n, cmp);
		int ans = pos[m - cal(l) - 1];
		printf("Case #%d: %d\n", o + 1, ans + 1);
	}
	return 0;
}