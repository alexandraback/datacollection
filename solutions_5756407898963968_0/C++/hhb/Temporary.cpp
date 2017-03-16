#include <stdio.h>

int read() {
	int l;
	scanf("%d", &l);
	for (int i = 0; i < (l - 1) * 4; i++) scanf("%*d");
	int r = 0;
	for (int i = 0; i < 4; i++) {
		int v;
		scanf("%d", &v);
		r |= 1 << v;
	}
	for (int i = l * 4; i < 4 * 4; i++) scanf("%*d");
	return r;
}

int bitcnt(int d) {
	int c = 0;
	while (d) {
		d >>= 1;
		c++;
	}
	return c - 1;
}

void solve() {
	int d = read() & read();
	if (d == 0) {
		puts("Volunteer cheated!");
	} else if ((d&-d) == d) {
		printf("%d\n", bitcnt(d));
	} else {
		puts("Bad magician!");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		solve();
	}
}