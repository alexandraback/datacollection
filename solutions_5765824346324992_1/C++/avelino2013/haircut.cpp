#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;
int a[N], n, k;
ll s;

int valid(ll v) {
    s=0;
    for(int i=0; i<n; i++) {
        s+=(v/a[i]+1);
        if(s>=k) return 1;
    }
    return 0;
}

int main() {
    int t, T=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        ll lo=0, mid, hi=2e14;
        while(lo<hi) {
            mid=(lo+hi)/2;
            if(valid(mid)) hi=mid;
            else lo=mid+1;
        }
        valid(lo-1);
        int ans=1;
        for(int i=0; i<n; i++) if(lo%a[i]==0) {
            s++;
            if(s==k) {
                ans=i+1;
                break;
            }
        }
        assert(s==k);
        printf("Case #%d: %d\n", T++, ans);
    }
    return 0;
}
