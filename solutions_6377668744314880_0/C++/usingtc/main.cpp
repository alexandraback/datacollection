#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << (x) << endl
#define dbg2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define dbg3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl

template<class T> inline T cabs(T x) { return x > 0 ? x : (-x); }
template<class T> inline T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }

#define out(x) cout << (x) << endl
#define out2(x,y) cout << (x) << " " << (y) << endl
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl

const int maxN = 3000 + 10;

int N;
long long x[maxN], y[maxN];
int dp[maxN][maxN];

inline long long mul(long long &ax, long long &ay, long long &bx, long long &by) {
    return ax * by - ay * bx;
}

inline int multi(int &p, int &q, int &r) {
    static long long pqx, pqy, qrx, qry;
    pqx = x[q] - x[p]; pqy = y[q] - y[p];
    qrx = x[r] - x[q]; qry = y[r] - y[q];
    static long long res;
    res = mul(pqx, pqy, qrx, qry);
    if( res > 0 ) return 1;
    if( res < 0 ) return -1;
    return 0;
}

int calc(int &p, int &q) {
    int a = 0, b = 0;
    for(int r = 0, t; r < N; r ++) {
        t = multi(p, q, r);
        if( t > 0 )
            a ++;
        if( t < 0 )
            b ++;
    }
    return min(a, b);
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int nt, idx = 0;
    scanf("%d", &nt);
    for(; nt > 0; nt --) {
        scanf("%d", &N);
        for(int i = 0; i < N; i ++)
            scanf("%I64d %I64d", &x[i], &y[i]);
        printf("Case #%d:\n", ++idx);
        for(int i = 0, j; i < N; i ++) {
            dp[i][i] = maxN;
            for(j = i + 1; j < N; j ++) {
                dp[i][j] = dp[j][i] = calc(i, j);
            }
        }
        for(int i = 0, j, k; i < N; i ++) {
            k = maxN;
            for(j = 0; j < N; j ++) {
                if( dp[i][j] < k ) {
                    k = dp[i][j];
                }
            }
            if( k == maxN ) k = 0;
            printf("%d\n", k);
        }
    }
    return 0;
}
