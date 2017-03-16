#include<cstdio>
#include<cstring>

int solve(int r, int c, int k) {
	if (r % 2 != 0 && c % 2 != 0) {
		int t = r * c / 2 + 1;
		if (k <= t) {
			return 0;
		}
		if (k <= t + 2) {
			return (k - t) * 3;
		}
		int ret = 6;
		t += 2;
		int tt = r * c - r / 2 * c / 2;
		if (k <= tt) {
			return 6 + (tt - t) * 2;
		}
		return (r - 1) * c + r * (c - 1) - (r * c - k) * 4;
	}
	if (r % 2 != 0 && c % 2 == 0) {
		int t = r;
		r = c;
		c = t;
	}
	if (r % 2 == 0 && c % 2 != 0) {
		int t = r * c / 2;
		if (k <= t) {
			return 0;
		}
		if (k <= t + 2) {
			return (k - t) * 2;
		}
		t += 2;
		int ret = 4;
		if (k <= t + 2) {
			return ret + (k - t) * 3;
		}
		ret += 6;
		int tt = r * c - r / 2 * c / 2;
		if (k <= tt) {
			return ret + (tt - t) * 2;
		}
		return (r - 1) * c + r * (c - 1) - (r * c - k) * 4;
	}
	if (r % 2 == 0 && c % 2 == 0) {
		int t = r * c / 2;
		if (k <= t) {
			return 0;
		}
		if (k <= t + 2) {
			return (k - t) * 2;
		}
		t += 2;
		int ret = 4;
		if (k <= t + 2) {
			return ret + (k - t) * 3;
		}
		ret += 6;
		int tt = r * c - r / 2 * c / 2;
		if (k <= tt) {
			return ret + (tt - t) * 2;
		}
		return (r - 1) * c + r * (c - 1) - (r * c - k) * 4;
	}
}

int main() {

	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		int r, c, k;
		scanf("%d%d%d", &r, &c, &k);
		printf("Case #%d: %d\n", ii, solve(r, c, k));
	}


	return 0;
}