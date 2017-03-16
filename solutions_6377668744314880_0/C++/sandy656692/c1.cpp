#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int N = 3010;
const double pi = 3.14159265358979323846264338327950288419716939937510582;
const double eps = 0;

int a[N], b[N];

struct rec {
	long long x, y;
	int xx;
} R[N * 2], tmp;

bool cw(rec ra, rec rb) {
	return ra.x * rb.y - ra.y * rb.x >= 0;
}

bool operator < (const rec &ra, const rec &rb) {
	if (ra.xx != rb.xx) return ra.xx < rb.xx;
	return cw(ra, rb);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ++ttt) {
		int n;
		scanf("%d", &n);
		printf("Case #%d:\n", ttt);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			//if (ttt == 33) printf("%d %d\n", a[i], b[i]);
		}
		for (int i = 0; i < n; ++i) {
			int m = 0;
			for (int j = 0; j < n; ++j) {
				tmp.x = a[j] - a[i];
				tmp.y = b[j] - b[i];
				if (tmp.x >= 0 && tmp.y >= 0) tmp.xx = 1;
				else if (tmp.x <= 0 && tmp.y >= 0) tmp.xx = 2;
				else if (tmp.x <= 0 && tmp.y <= 0) tmp.xx = 3;
				else tmp.xx = 4;
				if (i == j) continue;
				R[m++] = tmp;
			}
			sort(R, R + m);
			for (int j = 0; j < m; ++j) {
				R[j + m] = R[j];
			}
			int now = 0;
			int ans = 0;
			for (int j = 0; j < n - 1; ++j) {
				while (now < j + n - 1 && cw(R[j], R[now])) ++now;
				ans = max(ans, now - j);
			}
			printf("%d\n", n - 1 - ans);
		}
	}
	return 0;
}
