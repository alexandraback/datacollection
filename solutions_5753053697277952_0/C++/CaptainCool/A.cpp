#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<functional>
#include<iostream>
#include<istream>
#include<iterator>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
#define LL              long long
#define ULL             unsigned long long
#define FOR(i, a, b)    for(int i = a; i < b; i++)
#define REV(i, a, b)    for(int i = a - 1; i >= b; i--)
#define VI              vector<int>
#define PB              push_back
#define ALL(v)          v.begin(), v.end()
#define MII             map<int, int>
#define MSI             map<string, int>
#define PII             pair<int, int>
#define MP              make_pair
#define X               first
#define Y               second
#define SET(a, v)       memset(a, v, sizeof a)
// return the index (match ? first match : immediate greater)
#define lbA(a, n, x)    lower_bound(a, a + n, x) - a
#define lbV(v, x)       lower_bound(ALL(v), x) - v.begin()
// return the index (match ? last match + 1 : immediate greater)
#define ubA(a, n, x)    upper_bound(a, a + n, x) - a
#define ubV(v, x)       upper_bound(ALL(v), x) - v.begin()

template <class T> inline T bigmod(T b, T p, T M) {
    LL ret = 1;
    for (; p > 0; p >>= 1) {
        if (p & 1) ret = (ret * b) % M;
        b = (b * b) % M;
    }
    return (T)ret;
}

const double            PI = acos(-1.0), EPS = 1e-7;
const LL                INF = (LL)1e18 + 7;
const int               N = 2e5 + 5, M = 1e9 + 7;

struct data {
    int cnt;
    char id;
    bool friend operator < (data a, data b) {
        if (a.cnt != b.cnt) return a.cnt < b.cnt;
        return a.id > b.id;
    }
};

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int tc;
    cin >> tc;
    FOR(cs, 1, tc + 1) {
        priority_queue<data>pq;
        int n, t = 0;
        cin >> n;
        FOR(i, 0, n) {
            data x;
            cin >> x.cnt;
            x.id = char(i + 'A');
            pq.push(x);
            t += x.cnt;
        }
        vector<string>ans;
        while (t) {
            data p = pq.top();
            pq.pop();
            data q = pq.top();
            pq.pop();
            string s = "";
            p.cnt--, t--;
            s += p.id;
            if (2 * q.cnt > t) {
                q.cnt--, t--;
                s += q.id;
            }
            pq.push(p);
            pq.push(q);
            ans.PB(s);
        }
        cout << "Case #" << cs << ": " << ans[0];
        FOR(i, 1, ans.size()) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}
