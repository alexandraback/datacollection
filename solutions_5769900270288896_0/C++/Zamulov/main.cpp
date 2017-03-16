#pragma comment(linker, "/STACK:6400000000000")

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <stack>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-12;
const int INF = (int)(2e9 + 0.5);
const int MAXN = 20;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int t, ans, n, r, c, a[MAXN][MAXN];

int main() {
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    scanf("%d", &t);
    for(int q = 1; q <= t; ++q) {
        scanf("%d%d%d", &r, &c, &n);
        int all = r * c;
        ans = INF;
        for(int i = 0; i < MAXN; ++i) {
            for(int j = 0; j < MAXN; ++j) {
                a[i][j] = 0;
            }
        }
        for(int mask = 0; mask < (1 << all); ++mask) {
            if(__builtin_popcount(mask) == n) {
                int now = 0;
                for(int i = 1; i <= r; ++i) {
                    for(int j = 1; j <= c; ++j) {
                        a[i][j] = 0;
                    }
                }
                for(int i = 1; i <= r; ++i) {
                    for(int j = 1; j <= c; ++j) {
                        a[i][j] = mask & (1 << now);
                        ++now;
                    }
                }
                int nowans = 0;
                for(int i = 1; i <= r; ++i) {
                    for(int j = 1; j <= c; ++j) {
                        if(a[i][j]) {
                            for(int k = 0; k < 4; ++k) {
                                int ii = i + dy[k];
                                int jj = j + dx[k];
                                if(a[ii][jj])
                                    ++nowans;
                            }
                        }
                    }
                }
                ans = min(ans, nowans >> 1);
            }
        }
        printf("Case #%d: %d\n", q, ans);
    }
    return 0;
}
