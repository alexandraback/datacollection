#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;


typedef long long LL;


LL binsearch(LL n, LL b, vector < LL > &mi) {
    LL l = -1;
    LL r = (LL) 1e18;
    for (; r - l > 1; ) {
        LL m = (r + l) / 2;
        LL barb = 0;
        for (LL i = 0; i < b; ++i) {
            barb += m / mi[i] + 1;
        }
        if (barb >= n) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}


int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    LL t;
    cin >> t;
    for (LL q = 1; q <= t; ++q) {
        LL b, n;
        cin >> b >> n;
        vector < LL > mi (b);
        for (LL i = 0; i < b; ++i) {
            cin >> mi[i];
        }

        LL mt = binsearch(n, b, mi);
        //cout << mt << endl;
        LL as = 0;
        for (LL i = n - 1; i > 0 && binsearch(i, b, mi) == mt; --i) {
            ++as;
        }
        LL ans = 0;
        for (LL i = 0; i < b; ++i) {
            if (mt % mi[i] == 0) {
                if (as == 0) {
                    ans = i + 1;
                    break;
                }
                --as;
            }
        }
        cout << "Case #" << q << ": " << ans << endl;
    }
    return 0;
}