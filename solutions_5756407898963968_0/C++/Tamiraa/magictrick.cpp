#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int cnt[16];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		printf("Case #%d: ", tt);
		memset(cnt, 0, sizeof cnt);
		int k; scanf("%d", &k); k--;
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) {
				int kk;
				scanf("%d", &kk); kk--;
				if (k == i)
					cnt[kk]++;
			}
		scanf("%d", &k); k--;
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) {
				int kk;
				scanf("%d", &kk); kk--;
				if (k == i)
					cnt[kk]++;
			}
		int howmany = 0, ret;
		for (int i = 0; i < 16; i++)
			if (cnt[i] == 2) {
				howmany++;
				ret = i;
			}
		if (howmany == 1)
			printf("%d\n", ret+1);
		else if (howmany > 1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
	return 0;
}