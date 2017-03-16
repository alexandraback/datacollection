

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

#define pb push_back


static void solve();

int main() {
	freopen("A.in.txt","r",stdin);
	freopen("A.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static void solve() {
	int n, mm;
	cin >> n;
	vector<int> m;
	for (int i = 0; i < n; i++) {
		cin >> mm;
		m.pb(mm);
	}
	
	int sum = 0;
	int max = 0;
	for (int i = 1; i < n; i++) {
		int delta = m[i-1] - m[i];
		if (delta > 0) {
			sum += delta;
			max = std::max(max, delta);
		}
	}
	int sum2 = 0;
	for (int i = 1; i < n; i++) {
		sum2 += std::min(m[i-1], max);
	}
	cout << sum << " " << sum2;
}

#endif

