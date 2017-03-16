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
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
#endif
}

void solve() {
	int n; scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &v[i]);
	}
	int s1 = 0, s2 = 0;
	int maxdiff = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			s1 += v[i - 1] - v[i];
			maxdiff = max(v[i - 1] - v[i], maxdiff);
		}
	}
	int mush = v[0];
	for (int i = 1; i < n; i++) {
		s2 += min(mush, maxdiff);
		mush = v[i];
	}
	
	printf("%d %d\n", s1, s2);
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
