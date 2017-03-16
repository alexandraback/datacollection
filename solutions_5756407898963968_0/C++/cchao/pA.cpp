#include <cstdio>


int n, a[4][4], m, b[4][4];
int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n); --n;
		for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) scanf("%d", &a[i][j]);
		scanf("%d", &m); --m;
		for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) scanf("%d", &b[i][j]);
		int cnt = 0, ans = 0;
		for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) if(a[n][i] == b[m][j]) { cnt++; ans = a[n][i]; }
		printf("Case #%d: ", kase);
		if(cnt == 1) printf("%d\n", ans);
		else puts(cnt? "Bad magician!" : "Volunteer cheated!");
	}
	return 0;
}