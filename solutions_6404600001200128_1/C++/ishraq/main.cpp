#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,1,T+1) {
        int n; scanf("%d", &n);
        vector<int> v(n);
        FO(i,0,n) scanf("%d", &v[i]);
        int r0 = 0;
        FO(i,0,n-1) {
            if (v[i+1] < v[i]) r0 += v[i]-v[i+1];
        }
        int q = 0;
        FO(i,0,n-1) {
            if (v[i+1] < v[i]) q = max(q, v[i]-v[i+1]);
        }
        int r1 = 0;
        FO(i,0,n-1) {
            r1 += min(q, v[i]);
        }
        printf("Case #%d: %d %d\n", Z, r0, r1);
    }
}

