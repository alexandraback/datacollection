#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 20
using namespace std;
int T, r, c, n;
bool vis[N];
int popcount (int cur) {
	int res = 0;
	while (cur) {
		if (cur & 1) {
			res ++;
		}
		cur /= 2;
	}
	return res;
}
int main() {
	freopen ("B-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	cin>>T;
	for (int cas = 1; cas <= T; ++cas) {
		cin>>r>>c>>n;
		int ans = 10000000;
		for (int i = 0; i < (1<<(r * c)); ++i) {
			if (popcount(i) == n) {
				for (int j = 0; j < r; ++j) {
					for (int k = 0; k < c; ++k) {
						if ((1<<(j * c + k)) & i) {
							vis[j * c + k] = true;
						} else {
							vis[j * c + k] = false;
						}
					}
				}
				int tot = 0;
				for (int k = 0; k < r - 1; ++k) {
					for (int j = 0; j <c; ++j) {
						if (vis[k * c + j] && vis[(k + 1) * c + j]) {
							tot++;
						}
					}
				}
				for (int j = 0; j < c - 1; ++j) {
					for (int k = 0; k < r; ++k) {
						if (vis[k * c + j] && vis[k * c + j + 1]) {
							tot++;
						}
					}
				}
		//		if (tot == 4) {cout<<i<<endl; for (int k = 0; k < r; ++k) {for (int j = 0; j < c; ++j) cout<<vis[k * c + j]<<" "; cout<<endl;} }
				ans = min(ans, tot);
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
