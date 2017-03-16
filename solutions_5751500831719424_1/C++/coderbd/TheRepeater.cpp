#include <cstdio>
#include <cstring>

using namespace std;

char s[105][105], ss[105][105];
int c[105][105];

inline int abs(int a) {
	return a < 0 ? -a : a;
}

inline int min(int a, int b) {
	return a < b ? a : b;
}

void solve(int case_no) {
	int n, p, ans = 0;
	bool flag = true;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		int len = strlen(s[i]);
		ss[i][p=0] = s[i][0];
		c[i][p] = 1;
		for (int j = 1; j <= len; j++)
			if (s[i][j] != s[i][j-1]) {
				ss[i][++p] = s[i][j];
				c[i][p] = 1;
			}
			else
				c[i][p]++;
	}

	for (int i = 1; i < n; i++)
		if (strcmp(ss[i], ss[0])) {
			flag = false;
			break;
		}


	if (flag) {
		for (int i = 0; i < p; i++) {
			int mn = 0x7fffffff;
			for (int k = 1; k <= 105; k++) {
				int cnt = 0;
				for (int j = 0; j < n; j++)
					cnt += abs(c[j][i] - k);
				mn = min(mn, cnt);
			}
			ans += mn;
		}
		printf("Case #%d: %d\n", case_no, ans);

	}
	else
		printf("Case #%d: Fegla Won\n", case_no);
}

int main() {
	int t;

	scanf("%d", &t);
	for (int case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}