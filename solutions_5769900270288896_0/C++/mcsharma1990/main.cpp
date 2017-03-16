
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

int a[16][16];
int R, C;
int solve() {
    int ans = 0;
    rep(i, R) {
        rep(j, C-1) {
            ans += a[i][j] && a[i][j+1];
        }
    }
    rep(i, C) {
        rep(j, R-1) {
            ans += a[j][i] && a[j+1][i];
        }
    }
    return ans;
}
int main () {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);
    int T = SS;
    rep(t, T) {
        R = SS;
        C = SS;
        int N = SS;
        int ans = inf;
        fill(a, 0);
        rep(i, 1<<(R*C)) {
            if (__builtin_popcount(i) == N) {
                rep(j, R*C) {
                    if (i&(1<<j)) {
                        a[j/C][j%C] = 1;
                    } else {
                        a[j/C][j%C] = 0;
                    }
                }
                ans = min(ans, solve());
            }
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
}
