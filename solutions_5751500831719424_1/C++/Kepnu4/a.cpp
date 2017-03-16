#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n, cnt[105][105];

string s[105];

void load() {
	scanf ("%d\n", &n);

	for (int i = 0;i < n;i++) {
		cin >> s[i];
	}
}

void solve(int test) {
	vector <char> a;
	memset (cnt, 0, sizeof (cnt));

	for (int i = 0;i < n;i++) {
		vector <char> cur;
		int sz = 0;
		for (int j = 0;j < (int)s[i].size();j++) {
			if (j == 0 || s[i][j] != s[i][j - 1]) {
				cur.push_back (s[i][j]);
				sz++;
			}
			cnt[i][sz - 1]++;
		}

		if ((int)a.size() == 0) a = cur;

		if (a != cur) {
			printf ("Case #%d: Fegla Won\n", test);
			return;
		}
	}

	int ans = 0;
	for (int i = 0;i < (int)a.size();i++) {
		int sum = 1000;
		for (int j = 1;j <= 100;j++) {
			int cur = 0;
			for (int k = 0;k < n;k++) {
				cur += abs (j - cnt[k][i]);
			}
			sum = min (sum, cur);
		}
		ans += sum;
	}

	printf ("Case #%d: %d\n", test, ans);
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}