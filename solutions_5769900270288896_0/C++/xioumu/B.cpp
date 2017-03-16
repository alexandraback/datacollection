/*
 * Author:  xioumu
 * Created Time:  2015/5/3 1:32:28
 * File Name: B.cpp
 * solve: B.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double eps = 1e-8;
const int maxn = 16 + 10;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

int r, c, n, m;
int two(int x) {
    return 1 << x;
}

int getCount(int x) {
    int res = 0;
    while (x != 0) {
        if (x & 1)
            res++;
        x >>= 1;
    }
    return res;
}

int ok(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

int getAns(int mark) {
    int x[maxn][maxn];
    int res = 0;
    clr(x);
    rep (i, r) rep (j, c) {
        int v = i * c + j; 
        if (mark & two(v))
            x[i][j] = 1;
    }
    rep (i, r) rep (j, c) {
        if (x[i][j]) {
            if (ok(i - 1, j) && x[i - 1][j])
                res++;
            if (ok(i, j - 1) && x[i][j - 1])
                res++;
        }
    }
    return res;
}

int main() {
    int T, ca = 1;
    freopen("B.out", "w", stdout);
    scanf("%d", &T); 
    while (T--) {
        scanf("%d%d%d", &r, &c, &n);
        int ans = maxint;
        m = r * c;
        rep (i, two(m)) {
            //printf("%d %d\n", i, getCount(i));
            if (getCount(i) != n) continue;
            int res = getAns(i);
            ans = min(res, ans);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
