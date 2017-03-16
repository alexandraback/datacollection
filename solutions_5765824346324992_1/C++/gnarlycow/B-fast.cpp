#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int m[1001];
int cur[1001];

int main() {
    int nc;
    cin >> nc;
    for(int cid=1; cid<=nc; ++cid) {
        int b;
        long long n;
        cin >> b >> n;
        for(int i=0; i<b; ++i) cin >> m[i];
        
        int maxm = 0;
        for(int i=0; i<b; ++i) maxm = max(maxm, m[i]);

        long long L = 0, R = 1000000000000000LL / maxm;
        while(L+1 < R) {
            long long mid = (L+R)/2;
            long long limit = mid * maxm;
            long long total = 0;
            for(int i=0; i<b; ++i) {
                total += limit / m[i];
            }
            if(total >= n) R = mid;
            else L = mid;
        }

        if(L > 1) --L;
        L *= maxm;

        memset(cur, 0, sizeof(cur));
        for(int i=0; i<b; ++i) cur[i] = -(L % m[i]);
        for(int i=0; i<b; ++i) n -= L/m[i];
/*
        cout << "n: " << n << " limit: " << L << endl;
        for(int i=0; i<b; ++i) cout << cur[i] << ' ';
        cout << endl;
        */

        int ans = -1;
        for(int i=0; i<n; ++i) {
            int minid = 0, mincur = cur[0];
            for(int j=1; j<b; ++j)
                if(cur[j] < mincur) {
                    minid = j;
                    mincur = cur[j];
                }
            cur[minid] += m[minid];
            if(i==n-1) ans = minid + 1;
        }

        printf("Case #%d: %d\n", cid, ans);
    }
    return 0;
}

