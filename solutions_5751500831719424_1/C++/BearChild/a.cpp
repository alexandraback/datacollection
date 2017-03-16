#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int N = 105;

int n, l[N][N];
char s[N][N], t[N][N];

void cat (int x) {
	int len = strlen(s[x]);
	int c = 1;
	t[x][0] = s[x][0];
	l[0][x]++;
	for (int i = 1; i < len; i++) {
		t[x][c] = s[x][i];
		if (t[x][c] != t[x][c-1])
			c++;
		l[c-1][x]++;
	}
	t[x][c] = '\0';
}

void init () {
	scanf("%d", &n);
	memset(l, 0, sizeof(l));
	for (int i = 0; i < n; i++) {
		scanf("%s",  s[i]);
		cat(i);
	}
}

bool judge () {

	for (int i = 1; i < n; i++) {
		if (strcmp(t[0], t[i]))
			return true;
	}
	return false;
}

int solve () {
	int ans = 0;
	int len = strlen(t[0]);
	for (int i = 0; i < len; i++) {
		sort(l[i], l[i]+n);
		int tmp = l[i][n/2];
		for (int j = 0; j < n; j++)
			ans += abs(l[i][j] - tmp);
	}
	return ans;
}

int main () {
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++) {
		init ();
		printf("Case #%d: ", i); 
		if (judge())
			printf("Fegla Won\n");
		else
			printf("%d\n", solve());
	}
	return 0;
}
