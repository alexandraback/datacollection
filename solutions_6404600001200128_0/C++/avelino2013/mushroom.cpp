#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N];

int main() {
    int n, t, T=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        int v1=0, v2=0, diff=0;
        for(int i=1; i<n; i++) {
            if(a[i]<a[i-1]) v1+=a[i-1]-a[i];
            diff=max(diff, a[i-1]-a[i]);
        }
        for(int i=1; i<n; i++) v2+=min(diff, a[i-1]);
        printf("Case #%d: %d %d\n", T++, v1, v2);
    }
    return 0;
}
