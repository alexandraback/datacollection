#include <stdio.h>
#include <string.h>

char s[100][101];
int a[100];
int b[100];

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s[i]);
		}
		memset(a,0,sizeof(a));
		int r = 0;
		while (s[0][a[0]]) {
			char c = s[0][a[0]];
			int ma = 0, mi = 1000;
			for (int i = 0; i < n; ++i) {
				b[i]=0;
				while (s[i][a[i]] == c){
					++b[i];
					++a[i];
				}
				if (b[i]==0){
					r = -1;
					break;
				}
				if (ma < b[i]) ma=b[i];
				if (mi > b[i]) mi = b[i];
			}
			if (r < 0) break;
			int rr = 10000;
			for (int i = mi; i <= ma; ++i) {
				int rrr = 0;
				for (int j = 0; j < n; ++j) {
					rrr += abs(i-b[j]);
				}
				if (rrr < rr)rr = rrr;
			}
			r+=rr;
		}
		for (int i = 0; i < n; ++i) if(s[i][a[i]])r=-1;
		if (r < 0) printf("Case #%d: Fegla Won\n", tt);
		else printf("Case #%d: %d\n",tt, r);
	}
}
