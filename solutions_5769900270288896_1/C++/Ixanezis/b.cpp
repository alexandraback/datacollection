#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10;
int len[(1 << N) + 5];
int nei[(1 << N) + 5];

int bitcount(int x) {
    int ret = 0;
    for (; x; x>>=1)
        ret += x & 1;
    return ret;
}

int neicount(int x) {
    int ret = 0;
    for (int i=0; i<=N; ++i) {
        if ((x & (1 << i)) && (x & (1 << (i+1))))
            ++ret;
    }
    return ret;
}

int neicount(int a, int b) {
    int ret = 0;
    for (int i=0; i<=N; ++i) {
        if ((a & (1 << i)) && (b & (1 << i)))
            ++ret;
    }
    return ret;
}

const int INF = 0x7f7f7f7f;

int solve(int r, int c, int n) {
    if (r < c) swap(c, r);
    //cerr << "solving " << r << ' ' << c << ' ' << n << endl;
    int dp[2][(1 << N) + 5][N*N + 1];
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

int solve2(int r, int c, const int n) {
    //cerr << "solving " << r << ' ' << c << ' ' << n << endl;
    if (r < c) swap(r, c);
    if (c == 1) {
        int ans = 0;
        int lft = n;

        lft -= (r + 1) / 2;
        if (lft <= 0) return ans;

        if (r % 2 == 0) {
            ++ans;
            --lft;
        }

        if (lft <= 0) return ans;
        ans += lft * 2;
        return ans;
    }

    int mn = INF;
    for (int start=0; start<=1; ++start) {
        //cerr << "start = " << start << endl;
        int ans = 0;
        int lft = n;

        int sm = start;
        int triples = 0;
        for (int i=0; i<r; ++i) {
            if (i == 0 || i == r-1) {
                triples += (c - sm - 1) / 2;
            } else {
                if (sm == 1)
                    ++triples;
                if ((c - sm) % 2 == 0)
                    ++triples;
            }
            lft -= (c - sm + 1) / 2;
            sm ^= 1;
        }

        if (lft <= 0) {
            mn = 0;
        } else {
            int corners = 0;
            if (r % 2 == 0 || c % 2 == 0) {
                corners = 2;
            } else if (start == 0) {
                corners = 0;
            } else if (start == 1) {
                corners = 4;
            } else {
                throw logic_error("oh no no no");
            }

            while (lft && corners) {
                ans += 2;
                --lft;
                --corners;
            }

            while (lft && triples) {
                ans += 3;
                --lft;
                --triples;
            }

            ans += lft*4;
            
            mn = min(mn, ans);
        }
    }

    return mn;
}

int main() {
    for (int i=0; i<(1<<N); ++i) {
        len[i] = bitcount(i);
        nei[i] = neicount(i);
    }

    /*
    for (int e=0; e<1111; ++e) {
        int r = (rand() % N) + 1;
        int c = (rand() % N) + 1;
        int n = rand() % (r*c+1);
        cerr << "Test " << e << ": " << r << ' ' << c << ' ' << n << endl;

        int ans1 = solve(r, c, n);
        int ans2 = solve2(r, c, n);
        if (ans1 != ans2) {
            cerr << "oh no no no " << r << ' ' << c << ' ' << n << endl;
            exit(1);
        }
    }
    return 0;
    */

    int t; cin >> t;
    for (int e=1; e<=t; ++e) {
        int r,c,n; cin >> r >> c >> n;
        //int ans1 = solve(r, c, n);
        int ans2 = solve2(r, c, n);
        //if (ans1 != ans2) {
            //cerr << "oh no no no " << r << ' ' << c << ' ' << n << endl;
        //}
        cout << "Case #" << e << ": " << ans2 << endl;
    }

    return 0;
}



