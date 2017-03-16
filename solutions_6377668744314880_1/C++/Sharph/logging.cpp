#include <iostream>
#include <vector>
#include <complex>
#include <cassert>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long int Z;
typedef complex<Z> C;
#define X real()
#define Y imag()

// 10
// 23
int quadrant(C p) {
	if(p.Y >= 0) {
		return p.X < 0 ? 1 : 0;
	} else {
		return p.X < 0 ? 2 : 3;
	}
}

bool ccw(C a, C b, C c) {
	return ((c - a) * conj(b - a)).imag() > 0;
}

int lol(vector<C> p) {
	int n = p.size();
	if(n <= 3) return 0;
	
	sort(p.begin(), p.end(), [&](C a, C b) {
		int qa = quadrant(a);
		int qb = quadrant(b);
		if(qa == qb) {
			return ccw(0, a, b);
		} else {
			return qa < qb;
		}
	});
	
	int l = -1;
	int ret = INT_MAX;
	for(int i = 0; i < n; ++i) {
		l = max(l, 1);
		while(ccw(0, p[i], p[(i + l) % n])) ++l;
		assert(l <= n);
		ret = min(ret, l);
		--l;
	}
	assert(ret != INT_MAX);
	assert(ret != 0);
	return ret - 1;
}

int main() {
	cin.sync_with_stdio(false);
	
	int tests;
	cin >> tests;
	for(int test = 0; test < tests; ++test) {
		int n;
		cin >> n;
		
		vector<C> p(n);
		for(int i = 0; i < n; ++i) {
			Z x, y;
			cin >> x >> y;
			p[i] = C(x, y);
		}
		
		cout << "Case #" << test + 1 << ":\n";
		for(int cv = 0; cv < n; ++cv) {
			vector<C> ar;
			for(int i = 0; i < n; ++i) {
				if(i != cv) {
					ar.push_back(p[i] - p[cv]);
					assert(ar.back() != C(0));
				}
			}
			assert((int)ar.size() == n - 1);
			
			cout << lol(move(ar)) << '\n';
		}
	}
	
	return 0;
}
