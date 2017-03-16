#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <climits>
#include <cmath>
#include <iomanip>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define endl '\n'
#define dbgv(arr) cout << #arr << ": "; for (int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " "; cout << endl;
#define dbge(el) cout << #el << ": " << el << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }

int solve2(int r, int c, int n) {
	int max0 = 0;
	if (r % 2 == 0 || c % 2 == 0) {
		max0 = r * c / 2;
	} else {
		max0 = (r * c) / 2 + 1;
	}

	if (n <= max0) 
		return 0;
	
	int total = r * c;
	int f[16][16];
	int best = 2000;

	for (int i = 0; i < (1 << total); i++) {
		int cnt = 0;
		for (int j = 0; j < total; j++) {
			int row = j / c;
			int col = j % c;
			if (i & (1 << j)) {
				f[row][col] = 1;
				cnt++;
			} else {
				f[row][col] = 0;
			}
		}

		if (cnt != n) continue;

		int res = 0;
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if (f[j][k] == 1) {
					if (j > 0 && f[j - 1][k] == 1) res++; 
					if (j < r - 1 && f[j + 1][k] == 1) res++;
					if (k > 0 && f[j][k - 1] == 1) res++;
					if (k < c - 1 && f[j][k + 1] == 1) res++;
				}
			}
		}

		if (res < best) {
			best = res;
		}
	}

	return best / 2;
}

int solve(int r, int c, int n) {
	int max0 = 0;
	if (r % 2 == 0 || c % 2 == 0) {
		max0 = r * c / 2;
	} else {
		max0 = (r * c) / 2 + 1;
	}

	if (n <= max0) return 0;
	n -= max0;
	int edge2 = 0;
	int edge3 = 0;
	if (r % 2 == 0) edge3 += r; else edge3 += 2 * (r / 2 + 1);
	if (c % 2 == 0) edge3 += c; else edge3 += 2 * (c / 2 + 1);
	
	if ((r % 2 == 0 || c % 2 == 0) && (r != 1 && c != 1)) {
		edge3 -= 2;
		edge2 = 2;
	}

	if (r == 1 || c == 1) {
		return 2 * n;
	}
	
	if (n <= edge2) {
		return n * 2;
	}

	int ans = edge2 * 2;
	n -= edge2;

	if (n <= edge3) {
		return ans + n * 3;
	} else {
		return ans + edge3 * 3 + (n - edge3) * 4;
	}
}

int main()
{
	freopen("input.in.txt", "r", stdin);
	freopen("output", "w", stdout);
	int t;
	cin >> t;
	for (int idx = 1; idx <= t; idx++) {
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << idx <<  ": " << solve2(r, c, n) << endl;
	}
	return 0;
}

