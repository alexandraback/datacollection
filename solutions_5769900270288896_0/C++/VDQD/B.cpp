#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int m, n, k;

int solve(){
    scanf("%d%d%d", &m, &n, &k);
    int z = m * n, res = m*n*4;
    for (int s = 0; s < (1<<z); s++){
        int occ = 0, all = 0, s1, s2, ni, nj;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                s1 = i*n + j;
                if ((s>>s1)&1){
                    occ++;
                    for (int zz = 0; zz < 4; zz++){
                        ni = i + dx[zz]; nj = j + dy[zz];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n){
                            s2 = ni*n + nj;
                            all += ((s>>s2)&1);
                        }
                    }
                }
            }
        //printf("%d, %d, %d\n", s, occ, all);
        if (occ == k) res = min(res, all/2);
    }
    return res;
}

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
    	printf("Case #%d: %d\n", ++cases, solve());
    }
	return 0;
}
