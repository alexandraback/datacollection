#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

int bitcnt(int n){
    int res = 0;
    while(n) {
        if (n%2) ++res;
        n /= 2;
    }
    return res;
}

int get(int C, int r, int c, int i)
{
    int idx = r * C + c;
    return (i & (1 << idx));
}

int solve(void) {
    int N, R, C;
    cin >> R >> C >> N;
    
    int mn = 100000;
    REP(i, (1 << (R*C))) {
        if (bitcnt(i) != N) continue;

        int local = 0;
        REP(r, R) {
            REP(c, C-1) {
                if (get(C, r, c, i) * get(C, r, c+1, i)) ++local;
            }
        }
        REP(c, C) {
            REP(r, R-1) {
                if (get(C, r, c, i) * get(C, r+1, c, i)) ++local;
            }
        }
        mn = min(local, mn);
    }
    return mn;
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for (int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test + 1) << ": ";
        cout << solve();
        cout << endl;
    }

    return 0;
}

