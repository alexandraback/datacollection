#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

void solve() {
	int n;
	cin >> n;
	vector<int> mush(n);
	for (auto &v: mush) {
		cin >> v;
	}
	int y = 0, z = 0;
	int maxd = 0;
	for (int i = 1; i < n; ++i) {
		int d = max(0, mush[i - 1] - mush[i]);
		y += d;
		maxd = max(maxd, d);
	}
	for (int i = 1; i < n; ++i) {
		z += min(mush[i - 1], maxd);
	}
	cout << y << " " << z;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

