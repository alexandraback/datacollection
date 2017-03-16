#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

int len[259];
int nei[259];

int bitcount(int x) {
    int ret = 0;
    for (; x; x>>=1)
        ret += x & 1;
    return ret;
}

int neicount(int x) {
    int ret = 0;
    for (int i=0; i<9; ++i) {
        if ((x & (1 << i)) && (x & (1 << (i+1))))
            ++ret;
    }
    return ret;
}

int neicount(int a, int b) {
    int ret = 0;
    for (int i=0; i<9; ++i) {
        if ((a & (1 << i)) && (b & (1 << i)))
            ++ret;
    }
    return ret;
}

const int INF = 0x7f7f7f7f;

int solve(int r, int c, int n) {
    if (r < c) swap(c, r);
    cerr << "solving " << r << ' ' << c << ' ' << n << endl;
    int dp[2][259][17];
    int cur = 1;
    int prv = 0;
    memset(dp, 0x7f, sizeof dp);
    dp[prv][0][0] = 0;

    for (int i=0; i<r; ++i) {
        //cerr << "i = " << i << endl;
        memset(dp[cur], 0x7f, sizeof dp[cur]);
        for (int prvmask=0; prvmask < (1 << c); ++prvmask) {
            //cerr << "prvmask = " << prvmask << endl;
            for (int putbefore=0; putbefore <= n; ++putbefore) {
                if (dp[prv][prvmask][putbefore] != INF) {
                    //cerr << "here" << endl;
                    for (int putmask=0; putmask < (1 << c); ++putmask) {
                        int putcur = putbefore + len[putmask];
                        if (putcur <= n) {
                            int cost = dp[prv][prvmask][putbefore];
                            cost += nei[putmask];
                            cost += neicount(prvmask, putmask);
                            dp[cur][putmask][putcur] = min(dp[cur][putmask][putcur], cost);
                        }
                    }
                }
            }
        }
        swap(cur, prv);
    }

    int mn = INF;
    for (int lastmask=0; lastmask < (1<<c); ++lastmask)
        mn = min(mn, dp[prv][lastmask][n]);
    return mn;
}

int main() {
    for (int i=0; i<(1<<8); ++i) {
        len[i] = bitcount(i);
        nei[i] = neicount(i);
    }
    cerr << "done" << endl;

    int t; cin >> t;
    for (int e=1; e<=t; ++e) {
        int r,c,n; cin >> r >> c >> n;
        cout << "Case #" << e << ": " << solve(r, c, n) << endl;
    }

    return 0;
}



