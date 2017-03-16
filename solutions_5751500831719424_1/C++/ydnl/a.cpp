#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-11
#define oo 1LL<<53
#define LL long long

using namespace std;

LL T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an;
char a[110][110], c[110][110];
LL b[110];
LL d[110];

int main(){
	scanf("%lld", &T);
	for (LL rr = 1; rr <= T; rr++){
		printf("Case #%lld: ", rr);
		scanf("%lld", &m);
		for (LL i=0; i<m; i++){
			scanf("%s", a[i]);
			strcpy(c[i], a[i]);
		}
		for (LL i=0; i<m; i++){
			memset(d, 0, sizeof(d));
			for (LL j=1; c[i][j]; j++)
				if (c[i][j] == c[i][j-1])
					d[j] = 1;
			cnt = 0;
			for (LL j=0; c[i][j]; j++)
				if (d[j] == 0){
					c[i][cnt] = c[i][j];
					cnt++;
				}
			c[i][cnt] = '\0';
		}
		bool OK = true;
		for (LL i=1; i<m; i++)
			if (strcmp(c[i], c[0]) != 0){
				OK = false;
				break;
			}
		if (!OK){
			puts("Fegla Won");
			continue;
		}
		for (LL i=0; i<m; i++)
			b[i] = 0;
		LL ans = 0;
		while (a[0][b[0]]){
			for (LL i=0; i<m; i++){
				LL q = 1;
				while (a[i][b[i]] == a[i][b[i]+1])
					b[i]++, q++;
				d[i] = q;
			}
			sort(d, d+m);
			mi = oo;
			for (LL i=d[0]; i<=d[m-1]; i++){
				cnt = 0;
				for (LL j=0; j<m; j++)
					cnt += abs(d[j] - i);
				if (cnt < mi)
					mi = cnt;
			}
			for (LL i=0; i<m; i++)
				b[i]++;
			ans += mi;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
