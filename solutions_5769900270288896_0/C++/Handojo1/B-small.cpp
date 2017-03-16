#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int T,r,c,n;
bool isi[20][20];

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d %d %d",&r,&c,&n);
        int mini = 2*r*c-r-c;
        for (int i=0;i<(1<<(r*c));++i) {
            if (__builtin_popcount(i) != n) continue;
            memset(isi,0,sizeof(isi));
            for (int j=0;j<r*c;++j) {
                if (i & (1<<j)) isi[j / c][j % c] = true;
            }

            int total = 0;
            for (int i=0;i<r;++i) {
                for (int j=0;j<c;++j) {
                    if (j && isi[i][j] && isi[i][j-1]) ++total;
                    if (i && isi[i][j] && isi[i-1][j]) ++total;
                }
            }
            
            mini = min(total,mini);
        }
        
        printf("Case #%d: %d\n",l,mini);
    }
    return 0;
}
