#include <cstdio>

int T, x, t, bp, bp2, b[1 << 16];

int main() {
	for (int i = 0; i < 16; ++i)
		b[1 << i] = i + 1;
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		bp = bp2 = 0;
		scanf("%d", &x); --x;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				scanf("%d", &t); --t;
				if (i == x) bp |= (1 << t);
			}
		scanf("%d", &x); --x;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				scanf("%d", &t); --t;
				if (i == x) bp2 |= (1 << t);
			}
		bp &= bp2;
		printf("Case %d: ", r);
		if (bp) {
			if (bp&bp-1) puts("Bad magician!");
			else printf("%d\n", b[bp]);
		} else puts("Volunteer cheated!");
	}
	return 0;
}
