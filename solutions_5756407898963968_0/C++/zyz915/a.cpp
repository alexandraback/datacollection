#include <cstdio>
#include <cstring>

int main(int argc, char **argv) {
	int cas, T;
	int cnt[17];
	int i, j, k, x, l;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int cc = 0, ret = 0;
		memset(cnt, 0, sizeof(cnt));
		for (k = 0; k < 2; k++) {
			scanf("%d", &l);
			for (i = 1; i <= 4; i++)
				for (j = 1; j <= 4; j++) {
					scanf("%d", &x);
					if (i == l)
						cnt[x] += 1;
				}
			for (i = 1; i <= 16; i++)
				if (cnt[i] == 2) {
					cc += 1;
					ret = i;
				}
		}
		printf("Case #%d: ", cas);
		if (cc == 0)
			printf("Volunteer cheated!\n");
		else if (cc == 1)
			printf("%d\n", ret);
		else
			printf("Bad magician!\n");
	}
	return 0;
}
