#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct data {
	int t, num;
	bool operator < (const data x) const {
		if (t == x.t) return num < x.num;
		return t < x.t;
	}
};

int n, b, ans;
data a[1100];

long long calc(long long x) {
	long long ret = 0;
	for (int i = 0; i < b; i++) {
		++ret;
		ret += x / a[i].t;
	}
	return ret;
}

void solve() {
	long long l = 0, r = a[b-1].t, mid, w, q, tmp;
	r *= n;
	while (l <= r) {
		mid = (l + r) / 2;
		tmp = calc(mid);
		if (tmp < n) {
			l = mid + 1;
		} else {
			r = mid - 1;
			w = mid; q = tmp;
		}
	}
	tmp = w % a[0].t;
	for (int i = 1; i < b; i++) {
		if ((w % a[i].t) < tmp) tmp = w % a[i].t;
	}
	q -= n - 1;
	for (int i = b - 1; i >= 0; i--) {
		if ((w % a[i].t) != tmp) continue;
		if (--q) continue;
		ans = i;
		break;
	}
}

void init() {
	scanf("%d%d", &b, &n);
	for (int i = 0; i < b; i++) {
		a[i].num = i + 1;
		scanf("%d", &a[i].t);
	}
	//sort(a, a + b);
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int cas; scanf("%d", &cas);
	for (int t = 1; t <= cas; t++) {
		init();
		solve();
		printf("Case #%d: %d\n", t, a[ans].num);
	}
	return 0;
}
