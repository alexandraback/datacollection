#include <bits/stdc++.h>
using namespace std;

int a[22][22];

int main() {
    int t, T=1, n, r, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &r, &c, &n);
        int ans=1e9;
        for(int i=0; i<(1<<(r*c)); i++) if(__builtin_popcount(i)==n) {
            memset(a, 0, sizeof(a));
            for(int j=0; j<r*c; j++) if(i&(1<<j)) a[j/c][j%c]=1;
            int cnt=0;
            for(int j=0; j<r; j++) for(int k=0; k<c; k++) if(a[j][k]) {
                if(k && a[j][k-1]) cnt++;
                if(j && a[j-1][k]) cnt++;
            }
            ans=min(ans, cnt);
        }
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
