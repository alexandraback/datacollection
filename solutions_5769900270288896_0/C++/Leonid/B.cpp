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
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
#endif
}

const int INF = 0x7FFFFFFF;
int bruteforce(int n, int m, int k) {
	int p = n * m;
	vector<int> v;
	for (int i = 0; i < p - k; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		v.push_back(1);
	}
	const int di[] = {-1, 1, 0, 0};
	const int dj[] = {0, 0, -1, 1};
	int r = INF;
	vector<int> best;
	do {
		int x = 0;
		for (int i = 0; i < p; i++) if (v[i] == 1) {
			int ii = i / m, jj = i % m;
			for (int k = 0; k < 4; k++) {
				int i2 = ii + di[k], j2 = jj + dj[k];
				if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m) {
					int j = i2 * m + j2;
					if (v[j] == 1) {
						x++;
					}
				}
			}			
		}
		if (r > x / 2) {
			r = x / 2;
			best = v;
		}
	} while (next_permutation(v.begin(), v.end()));
	return r;
}

void solve() {
	int n, m, k; scanf("%d %d %d ", &n, &m, &k);
	printf("%d\n", bruteforce(n, m, k));
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
