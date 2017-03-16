#include <cstdio>
#include <queue>
using namespace std;

int r,c,q;

int arr[16][16];

void solve(){
    scanf("%d %d %d",&r,&c,&q);
    int ret2 = 1e9;
    for (int i=0; i<(1<<(r*c)); i++) {
        int ret = 0;
        for (int j=0; j<r*c; j++) {
            if((i>>j)&1) ret++;
        }
        if(ret != q) continue;
        for (int j=0; j<r; j++) {
            for (int k=0; k<c; k++) {
                if(i&(1<<(j * c + k))) arr[j][k] = 1;
                else arr[j][k] = 0;
            }
        }
        int cnt = 0;
        for (int j=0; j<r; j++) {
            for (int k=0; k<c-1; k++) {
                if(arr[j][k] && arr[j][k+1]) cnt++;
            }
        }
        for (int j=0; j<r-1; j++) {
            for (int k=0; k<c; k++) {
                if(arr[j][k] && arr[j+1][k]) cnt++;
            }
        }
        ret2 = min(ret2,cnt);
    }
    printf("%d\n",ret2);
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ",i);
        solve();
    }
}