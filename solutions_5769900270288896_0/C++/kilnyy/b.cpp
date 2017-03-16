#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,n) for(int i=1;i<=(n);i++)
#define FORD(i,n) for(int i=(n);i>=1;i--)

#define SZ(x) ((int)x.size())
#define CC(a,x) memset(a,x,sizeof(a))
#define TWO(x) ((LL)1<<(x))

using namespace std;

int T;
int n, m, c;

bool check(int u, int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && (u & (1 << (i * m + j)));
}

void solve() {
    scanf("%d%d%d", &n, &m, &c);
    int ans = 100000;
    REP(u, 1<<(n*m)) {
        int cur = 0;
        int cnt = 0;
        REP(i, n) {
            REP(j, m) {
                if (check(u, i, j)) {
                    cnt++;
                    if (check(u, i+1, j)) cur ++;
                    if (check(u, i, j+1)) cur ++;
                }
            }
        }
        if (cnt == c) {
            ans = min(ans, cur);
        }
    }
    printf("%d", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}
