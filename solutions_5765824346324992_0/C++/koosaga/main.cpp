#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1005];
int t;

bool trial(long long T){
    long long r = 0;
    for (int i=0; i<n; i++) {
        r += T / a[i] + 1;
        if(r > 1e18) return 1;
    }
    return r >= t;
}

void solve(){
    scanf("%d %d",&n,&t);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    long long s = 0, e = 1e16;
    while (s != e) {
        long long m = (s+e)/2;
        if(trial(m)) e = m;
        else s = m+1;
    }
    long long r = 0;
    for (int i=0; i<n; i++) {
        r += s / a[i] + 1;
    }
    for (int i=n-1; i>=0; i--) {
        if(s % a[i] == 0) r--;
        if(r == t-1){
            printf("%d\n",i+1);
            return;
        }
    }
}

int main(){
    int t;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("ret","w",stdout);
    scanf("%d",&t);
    for (int i=1; i<=t; i++){
        printf("Case #%d: ",i);
        solve();
    }
}