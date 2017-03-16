#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool okBits(int m, int n, int a) {
	int cnt = 0;
	while (m > 0) {
		cnt += a & 1;
		m--;
		a >>=1;
	}
	return cnt == n;
}

inline int getBit(int a, int r, int c, int i, int j) {
	int n = i * c + j;
	return (a >> n) & 1;
}

long long calc(int r, int c, int n, int a) {
	int pen = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (i < r - 1) {
				if (getBit(a, r, c, i, j) == 1 && getBit(a, r, c, i, j) == getBit(a, r, c, i + 1, j))
					pen += 1;
			}
			if (j < c - 1) {
				if (getBit(a, r, c, i, j) == 1 && getBit(a, r, c, i, j) == getBit(a, r, c, i, j + 1))
					pen += 1;
			}
		}
	return pen;
}

long long f(int r, int c, int n) {
	int m = r * c;
	int ans = 200000;
	for (int i = 0; i < 1<<m; i++) {
		if (! okBits(m, n, i))
			continue;
		int pre = calc(r, c, n, i);
		if (pre < ans) {
			ans = pre;
		}
	}
	return ans;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int t;
	cin >>t;
	for (int q = 1; q <= t; q++) {
		int r, c, n;
		cin >>r>>c>>n;
		cout <<"Case #"<<q<<": "<<f(r, c, n)<<'\n';
	}
}