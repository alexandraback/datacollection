#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int n, p[30];
void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", p + i);
	vector<pair<int, int> > v;
	int sum = accumulate(p, p + n, 0);
	for (int i = 0; i < n; ++i)
		v.push_back(make_pair(p[i], i));
	while (sum > 0) {
		sort(v.begin(), v.end(), greater<pair<int, int> >());
		if (v[0].first >= 2 && v[1].first <= (sum - 2) / 2) {
			printf(" %c%c", v[0].second + 'A', v[0].second + 'A');;
			v[0].first -= 2, sum -= 2;
		} else if (v[0].first >= 1 && v[1].first <= (sum - 1) / 2) {
			printf(" %c", v[0].second + 'A');
			v[0].first -= 1, sum -= 1;
		} else {
			printf(" %c%c", v[0].second + 'A', v[1].second + 'A');
			v[0].first -= 1, v[1].first -= 1;
			sum -= 2;
		}
	}
	printf("\n");
}
int main() {
	// freopen("in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		printf("Case #%d:", _);
		solve();
	}
	return 0;
}
