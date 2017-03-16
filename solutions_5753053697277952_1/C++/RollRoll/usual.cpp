#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (x); i++)
#define DEP(i,x) for(int i = (x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) ((int)v.size())
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
// ************************************************************************

int a[33];

void solve() {
    int n, tmp;
    scanf("%d", &n);
    priority_queue<PII, vector<PII>, less<PII> > pq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        pq.push(mp(tmp, i));
    }

    if (n == 2) {
        while (!pq.empty()) {
            PII top = pq.top(); pq.pop();
            if (--top.X > 0) pq.push(top);
            PII top2 = pq.top(); pq.pop();
            if (--top2.X > 0) pq.push(top2);

            printf(" %c%c", 'A' + top.Y, 'A' + top2.Y);
        }
        puts("");
        return;
    }

    while (!pq.empty()) {
        if (pq.size() == 2) {
            int a = pq.top().Y; pq.pop();
            int b = pq.top().Y; pq.pop();
            printf(" %c%c", 'A' + a, 'A' + b);
            break;
        }
        PII top = pq.top(); pq.pop();
        if (--top.X > 0) pq.push(top);
        printf(" %c", 'A' + top.Y);
    }
    puts("");
}

int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    // freopen("/Users/Lodour/Downloads/A-small-attempt0.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int t, cnt = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d:", ++cnt);
        // printf("%d\n", solve());
        solve();
    }

    return 0;
}

