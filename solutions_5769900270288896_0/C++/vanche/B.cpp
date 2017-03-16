#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int tc, tcn, r, c,n,re,d[16][16];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

void solve(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d %d %d", &r, &c, &n);
		re = r*c * 4;
		for (int i = 0; i < (1 << (r*c)); i++){
			int t = 0;
			for (int j = 1; j <= i; j <<=1){
				if (i&j)
					t++;
			}
			if (t != n)
				continue;
			memset(d, 0, sizeof(d));
			for (int j = 1,k= 0; j <= i; j <<= 1,k++){
				if (i&j)
					d[k / c][k%c] = 1;
			}
			
			t = 0;
			for (int j = 0; j < r; j++){
				for (int k = 0; k < c; k++){
					for (int x = 0; x < 2; x++){
						if (j + dx[x] >= 0 && j + dx[x] < r &&
							k + dy[x] >= 0 && k + dy[x] < c &&
							(d[j + dx[x]][k + dy[x]] & d[j][k]))
							t++;
					}
				}
			}

			re = min(re, t);
		}
		printf("Case #%d: %d\n", ++tcn, re);
	}
}

int main(void){
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}