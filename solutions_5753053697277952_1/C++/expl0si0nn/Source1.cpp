#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define mp make_pair
#define TASKNAME "monument"


const int inf = 2 * 1e9;
const int mod = 1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	while (s) {
		int mx = -1;
		int mxn = -1;
		int mxn2 = -1;
		for (int i = 0; i < n; i++) {
			if (mx < a[i]) {
				mx = a[i];
				mxn = i;
				mxn2 = -1;
			}
			else if (mx == a[i]) {
				if (mxn2 == -1)
					mxn2 = i;
				else mxn2 = inf;
			}
		}
		if (mxn2 != -1 && mxn2 != inf)
			cout << (char)('A' + mxn) << (char)('A' + mxn2) << " ";
		else cout << (char)('A' + mxn) << " ";
		a[mxn]--;
		if (mxn2 != -1 && mxn2 != inf) {
			a[mxn2]--;
			s--;
		}
		s--;
	}
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//assert(freopen(TASKNAME".in", "r", stdin));
	//assert(freopen(TASKNAME".out", "w", stdout));
#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cerr << "Test #" << t + 1 << " in progress\n";
		cout << "Case #" << t + 1 << ": ";
		solve();
		cout << endl;
		cerr << "Test #" << t + 1 << " done\n";
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}