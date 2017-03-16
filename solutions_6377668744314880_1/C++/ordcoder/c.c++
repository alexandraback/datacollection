#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

typedef array<int64_t, 2> xy;
vector<xy> tree;

bool half(const xy &a) {
	return a[1] > 0 || (a[1] == 0 && a[0] > 0);
}

int64_t vmul(const xy &a, const xy &b) {
	return a[0] * b[1] - a[1] * b[0];
}

struct Anglecmp {
	bool operator()(const xy &a, const xy &b) const {
		bool ha = half(a), hb = half(b);
		if (ha != hb)
			return ha < hb;
		return vmul(a, b) > 0;
	}
};

void solve() {
	int n;
	cin >> n;
	tree.resize(n);
	for (auto &t: tree) for (auto &v: t) cin >> v;
	vector<array<int64_t, 2>> rot;
	for (int i = 0; i < n; ++i) {
		rot.clear();
		for (int j = 0; j < n; ++j) if (i != j) {
			rot.emplace_back();
			rot.back()[0] = tree[j][0] - tree[i][0];
			rot.back()[1] = tree[j][1] - tree[i][1];
		}
		sort(all(rot), Anglecmp{});
		rot.resize(2 * (n - 1));
		copy(begin(rot), begin(rot) + (n - 1), begin(rot) + (n - 1));
		int op = 0;
		int ans = n - 1;
		for (int j = 0; j < n - 1; ++j) {
			while (op < j + n - 1) {
				if (vmul(rot[j], rot[op]) < 0)
					break;
				++op;
			}
			ans = min(ans, n - 1 - (op - j));
		}
		cout << "\n" << ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

