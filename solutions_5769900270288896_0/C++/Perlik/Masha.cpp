#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#pragma comment(linker, "/STACK:268435456")

using namespace std;
typedef long long ll;

const int INF = 1e9;

int calc(const vector<vector<char> >& a) {
	int ans = 0;
	int n = a.size(), m = a[0].size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (!a[i][j])
				continue;
			if (i + 1 < n && a[i + 1][j])
				++ans;
			if (j + 1 < m && a[i][j + 1])
				++ans;
		}
	return ans;
}

int rec(int y, int x, int cur, int r, int c, int n, vector<vector<char> >& a) {
	if (cur > n)
		return INF;
	if (x == c) {
		x = 0;
		++y;
	}
	if (y == r) {
		if (cur < n)
			return INF;
		else
			return calc(a);
	}
	int ans = rec(y, x + 1, cur, r, c, n, a);
	a[y][x] = 1;
	ans = min(ans, rec(y, x + 1, cur + 1, r, c, n, a));
	a[y][x] = 0;
	return ans;
}

int solve(int r, int c, int n) {
	vector<vector<char> > a(r, vector<char>(c));
	return rec(0, 0, 0, r, c, n, a);
}

int main() {
	ios_base::sync_with_stdio(false);	
	int t;		
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;		
	for (int i = 1; i <= t; ++i) {
		int n, r, c;
		cin >> r >> c >> n;
		cout << "Case #" << i << ": " << solve(r, c, n) << "\n";
	}
	return 0;
}