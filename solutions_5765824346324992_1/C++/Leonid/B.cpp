#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
#endif
}

pair<long long, long long> barbersRange(const vector<int>& v, long long t) {
	long long n = 0;
	int nbarb = 0;
	for (int i = 0; i < v.size(); i++) {
		n += t / v[i];
		if (t % v[i] == 0) {
			nbarb++;
		} else {
			n++;
		}
	}
	return pair<long long, long long>(n, n + nbarb);
}

void answer(const vector<int>& v, int started, int n, long long t) {
	int ans = -1;
	for (int i = 0; i < v.size(); i++) {
		if (t % v[i] == 0) {
			started++;
			if (started == n) {
				ans = i + 1;
				break;
			}
		}
	}
	printf("%d\n", ans);
}

void solve() {
	int b, n; scanf("%d %d ", &b, &n);
	vector<int> v(b);
	for (int i = 0; i < b; i++) {
		scanf("%d ", &v[i]);
	}
	
	long long mn = 0, mx = (1LL << 60);
	bool found = false;
	while (mn < mx) {		
		long long t = (mn + mx - 1) / 2;
		pair<long long, long long> barb = barbersRange(v, t);
		if (barb.second < n) {
			mn = t + 1;
		} else if (barb.first >= n) {
			mx = t - 1;
		} else {
			answer(v, barb.first, n, t);
			found = true;
			break;
		}
	}
	if (!found) {
		pair<long long, long long> barb = barbersRange(v, mn);
		answer(v, barb.first, n, mn);
	}
}

int main() {
	openFiles();
	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}

	return 0;
}
