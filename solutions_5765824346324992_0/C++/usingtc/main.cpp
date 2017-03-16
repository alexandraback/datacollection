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

const int maxN = 1024;

int B, N;
long long M[maxN];

long long run(int x, long long val) {
    if( val < 0 ) return 0;
    long long l = 0, r = N, t = 0;
    while( l <= r ) {
        long long mid = (l + r) >> 1;
        long long ret = mid * M[x];
        if( ret <= val )
            t = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return (t + 1);
}

long long gao(int x, long long val) {
    long long res = 0;
    for(int i = 0; i <= x; i ++)
        res += run(i, val);
    for(int i = x + 1; i < B; i ++)
        res += run(i, val - 1);
    return res;
}

int check(int x) {
    long long l = 0, r = N;
    while( l <= r ) {
        long long mid = (l + r) >> 1;
        long long ret = gao(x, mid * M[x]);
        if( ret == (long long)N )
            return 1;
        if( ret < (long long)N )
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

int calc() {
    if( N <= B )
        return N;
    for(int x = 0; x < B; x ++) {
        if( check(x) ) {
            return (1 + x);
        }
    }
    return -1;
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int nt, idx = 0;
    scanf("%d", &nt);
    for(; nt > 0; nt --) {
        scanf("%d %d", &B, &N);
        for(int i = 0; i < B; i ++) scanf("%I64d", &M[i]);
        printf("Case #%d: %d\n", ++idx, calc());
    }
    return 0;
}
