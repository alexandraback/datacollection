#include <cstdio>
#include <algorithm>

using namespace std;

int unhappiness(int r, int c, int mask) {
	int ret = 0;
	for(int i = 0; i < r * c; i ++) {
		if(mask & (1 << i)) {
			int x = i / c;
			int y = i % c;
			if(x + 1 < r) {
				int val = (x + 1) * c + y;
				if(mask & (1 << val))
					ret ++;
			}
			if(y + 1 < c) {
				int val = (x) * c + (y + 1);
				if(mask & (1 << val))
					ret ++;
			}
		}
	}
	return ret;
}

int main() {
	int T;
	scanf(" %d", &T);
	for(int t = 0; t < T; t ++) {
		int r, c, n;
		scanf(" %d %d %d", &r, &c, &n);
		int ans = 4 * r * c;
		for(int i = 0; i < 1 << (r * c); i ++) {
			if(__builtin_popcount(i) == n)
				ans = min(unhappiness(r, c, i), ans);
		}
		printf("Case #%d: %d\n", t + 1, ans);
	}
	return 0;
}
