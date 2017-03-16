#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cases, n, m;
int cnt[200][200];
char st[200], order[200];


void mark() {
	int len = strlen(st);
	m = 0;
	for (int i = 0; i < len; ++i)
		if (i == 0) order[m++] = st[i];
		else
			if (st[i] != st[i - 1]) order[m++] = st[i];
	order[m] = '\0';
}

bool check() {
	int len = strlen(st);
	int j = 0;
	for (int i = 0; i < len; ++i)
		if (i == 0) {
			if (st[i] != order[j++]) return false;
		}
		else {
			if (st[i] != st[i - 1])
				if (st[i] != order[j++]) return false;
		}
	return (j == m);
}

void count(int now) {
	int len = strlen(st);
	int j = 0;
	for (int i = 0; i < len; ++i)
		if (st[i] == order[j]) ++cnt[j][now];
		else cnt[++j][now] = 1;
}

int main() {

	scanf("%d", &cases);
	
	for (int casei = 1; casei <= cases; ++casei) {
		
		
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			scanf(" %s", st);
			if (ans == -2) continue;
			
			if (i == 0) mark();
			else
				if (!check()) {
					ans = -2;
					continue;
				}
			
			count(i);
		}
		
		if (ans == -2) {
			printf("Case #%d: Fegla Won\n", casei);
			continue;
		}
		
		ans = 0;
		for (int i = strlen(order) - 1; i >= 0; --i) {
			sort(cnt[i], cnt[i] + n);
			int t = cnt[i][n / 2];
			
			for (int j = 0; j < n; ++j) ans += abs(cnt[i][j] - t);
		}
		
		printf("Case #%d: %d\n", casei, ans);
	}
	
	return 0;
}