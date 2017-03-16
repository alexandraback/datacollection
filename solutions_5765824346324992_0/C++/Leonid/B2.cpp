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
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small-attempt1.out", "wt", stdout);
#endif
}

long long bruteforce(const vector<int>& v, int n) {
	int lcm = 1;
	for (int i = 0; i < v.size(); i++) {
		lcm *= v[i];
	}
	int cyclen = 0;
	for (int i = 0; i < v.size(); i++) {
		cyclen += lcm / v[i];
	}
	n = (n % cyclen == 0) ? cyclen : n % cyclen;

	int t = 0;
	for (; n; t++) {
		for (int i = 0; i < v.size(); i++) {
			if (t % v[i] == 0) {
				n--;
				if (n == 0) {
					return i + 1;
				}
			}
		}
	}
	return 1;
}

void solve() {
	int b, n; scanf("%d %d ", &b, &n);
	vector<int> v(b);
	for (int i = 0; i < b; i++) {
		scanf("%d ", &v[i]);
	}
	cout << bruteforce(v, n) << endl;
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
