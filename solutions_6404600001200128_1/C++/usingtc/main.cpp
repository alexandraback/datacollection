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

int N;
int M[maxN];

int gao() {
    int res = 0;
    for(int i = 0; i + 1 < N; i ++) {
        if( M[i] > M[i + 1] ) {
            res += M[i] - M[i + 1];
        }
    }
    return res;
}

int calc(int v) {
    int res = 0;
    for(int i = 0; i + 1 < N; i ++) {
        int mi = min(M[i], v);
        res += mi;
        if( M[i] - mi > M[i + 1] )
            return -1;
    }
    return res;
}

int gao2() {
    int res = -1, mx = 0;
    for(int i = 0; i < N; i ++)
        mx = max(mx, M[i]);
    for(int i = 0; i <= mx; i ++) {
        int tmp = calc(i);
        if( tmp != -1 ) {
            if( res == -1 || res > tmp )
                res = tmp;
        }
    }
    return res;
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
            scanf("%d", &M[i]);
        printf("Case #%d: %d %d\n", ++idx, gao(), gao2());
    }
    return 0;
}
