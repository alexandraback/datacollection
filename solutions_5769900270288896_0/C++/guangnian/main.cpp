#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
const int N = (1<<20)-1;
const int M = 145;
const int MAX = 1000005;
#define inf (1<<30)
int vis[55][55];
int main()
{
    freopen("/Users/junchen/topcoder/tc/tc/B-small-attempt0.in", "r", stdin);
    freopen("/Users/junchen/topcoder/tc/tc/b.out", "w", stdout);
    int T, r, c, n;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        cin >> r >> c >> n;
        int N = r * c;
        int ans = 10000;
        for (int i = 0; i < (1 << N); i++) {
            memset(vis, 0, sizeof(vis));
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    vis[j/c][j%c] = 1;
                }
            }
            if (cnt != n)
                continue;
            int t = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 1; j < c; j++) {
                        if (vis[i][j] && vis[i][j-1])
                            t++;
                }
                
            }
            for (int i = 1; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (vis[i][j] && vis[i-1][j])
                        t++;
                }
            }
            ans= min(ans, t);
        }
        printf("Case #%d: %d\n", ca, ans);
    }

}