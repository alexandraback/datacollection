#include<stdio.h>
#include<string.h>
#include<algorithm>
#define R 20
#define INF 1000000000
using namespace std;

bool occ[R][R];

int main(){
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int r, c, n;
        scanf("%d%d%d", &r, &c, &n);
        int ans = INF;
        for(int i=0; i<1<<r*c; i++){
            int cnt = 0;
            for(int j=0; j<r*c; j++) cnt += (i>>j&1);
            if(cnt != n) continue;
            memset(occ, false, sizeof(occ));
            for(int j=0; j<r*c; j++) occ[j/c][j%c] = (i>>j&1);
            int temp = 0;
            for(int j=0; j<r; j++) for(int k=0; k<c; k++){
                temp += occ[j][k] && occ[j][k+1];
                temp += occ[j][k] && occ[j+1][k];
            }
            ans = min(ans, temp);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
