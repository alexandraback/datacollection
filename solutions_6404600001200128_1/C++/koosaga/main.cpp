#include <cstdio>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    int a[1005];
    scanf("%d",&n);
    int ret = 0, rat = 0;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(i){
            ret += max(a[i-1] - a[i],0);
            rat = max(a[i-1] - a[i],rat);
        }
    }
    printf("%d",ret);
    int piv = 0;
    for (int i=1; i<n; i++) {
        piv += min(rat,a[i-1]);
    }
    printf(" %d\n",piv);
}

int main(){
    int t;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output","w",stdout);
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        printf("Case #%d: ",i);
        solve();
    }
}