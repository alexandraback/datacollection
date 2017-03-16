#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve() {
	int H, W, T;
	cin >> H >> W >> T;
	int n = H*W;
	int res = 10000;
	rep(i,0,(1 << n)) {
		if ((int)bitset<32>(i).count() != T) continue;
		int noise = 0;
		rep(a,0,H) {
			rep(b,0,W) {
#define H(a, b) (i & (1 << ((a) * W + (b))))
				if (!(H(a, b))) continue;
				if (a > 0 && H(a-1, b)) noise++;
				if (b > 0 && H(a, b-1)) noise++;
			}
		}
		res = min(res, noise);
	}
	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
