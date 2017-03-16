#include <stdio.h>

int v[1000], n;
long long count(long long tempo) {
	if (tempo < 0)	return 0;
	int i;
	long long ans = 0;
	for (i = 0; i < n; i++) {
		ans += tempo/v[i] + 1;
	}
	return ans;
}

int find(long long tempo, int pos) {
	int i;
	for (i = 0; i < n && pos; i++) {
		if (tempo%v[i])	continue;
		pos--;
	}
	return i;
}

int main (void) {
	int t, c, k, i;
	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		scanf ("%d%d", &n, &k);
		for (i = 0; i < n; i++) {
			scanf ("%d", &v[i]);
		}
		long long beg = 0, end = 100000000000000LL, h;
		while (beg <= end) {
			h = (beg + end)/2;
			if (count(h) >= k)	end = h-1;
			else	beg = h+1;
		}
		if (count(h) < k)	h++;
		int bef = (int) count(h-1);
		int m = k-bef;
//		printf ("m eh %d h eh %lld\n", m, h);
		printf ("Case #%d: %d\n", c, find(h, m));
	}
}
