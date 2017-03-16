#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <bitset>

using namespace std;

#define ll long long

const int N = 1000011;

bool a[20][20];

int n, m;
int mmin;


void doit(int ii, int hh, int kk) {
	if (ii == n) {
		if (kk > 0)
			return;
		int ans = 0;
		for (int i = 0; i < n; i++) 
			for (int h = 0; h < m; h++) 
				if (a[i][h]) {
					if (i + 1 < n && a[i + 1][h]) {
						ans++;
					}
					if (h + 1 < m && a[i][h + 1]) {
						ans++;
					}
				}
		if (ans < mmin) {
			mmin = ans;
			// for (int i = 0; i < n; i++) {
			// 	for (int h = 0; h < m; h++) {
			// 		cout << (a[i][h] ? "#" : ".");
			// 	}
			// 	cout << endl;
			// }
		}
		mmin = min(ans, mmin);
		return;
	}
	int j1 = ii, j2 = hh + 1;
	if (j2 == m) {
		j1++;
		j2 = 0;
	}
	if (kk > 0) {
		a[ii][hh] = true;
		doit(j1, j2, kk - 1);
		a[ii][hh] = false;
	} 
	doit(j1, j2, kk);
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	int t;
	scanf("%d", &t);
	bitset<20> bt = 0;
	for (int jj = 0; jj < t; jj++) {
		int k;
		mmin = 100000;
		scanf("%d%d%d", &n, &m, &k);
		doit(0, 0, k);
		printf("Case #%d: %d\n", jj + 1, mmin);
	}

	return 0;
}