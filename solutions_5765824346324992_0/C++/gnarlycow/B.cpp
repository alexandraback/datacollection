#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int m[1001];

int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    int nc;
    cin >> nc;
    for(int cid=1; cid<=nc; ++cid) {
        int b;
        long long n;
        cin >> b >> n;
        for(int i=0; i<b; ++i) cin >> m[i];

        int lcm = m[0];
        for(int i=1; i<b; ++i) lcm = lcm / gcd(lcm, m[i]) * m[i];

        int total = 0;
        for(int i=0; i<b; ++i) total += lcm / m[i];

        n %= total;
        if(n == 0) n = total;

        int ans = -1;
        int cur[5] = {0, 0, 0, 0, 0};
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

