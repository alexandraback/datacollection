#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifdef LOCAL
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

template<class edge> struct Graph {
    vector<vector<edge> > adj;
    Graph(int n) {adj.clear(); adj.resize(n + 5);}
    Graph() {adj.clear(); }
    void resize(int n) {adj.resize(n + 5); }
    void add(int s, edge e){adj[s].push_back(e);}
    void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
    vector<edge>& operator [](int t) {return adj[t];}
};

const int N = 2e2;

string S[N];
int w[N];

int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("A-large.in" , "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int T, n;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> S[i];

        int ans = 0;
        for (; ; ) {
            int cnt = 0;
            char x = 0;
            for (int i = 1; i <= n; ++i) {
                if (S[i] == "") {
                    ++cnt;
                    continue;
                }
                if (x == 0) x = S[i][0];
                else if (x != S[i][0]) {
                    ans = -1;
                    break;
                }
                int t = 0;
                for (; t < SZ(S[i]) && S[i][t] == S[i][0]; ++t)
                    ;
                w[i] = t;
                S[i] = S[i].substr(t);
            }
            if (cnt != 0 || ans < 0) {
                if (cnt != n) ans = -1;
                break;
            }
            
            int mx = 0;
            for (int i = 1; i <= n; ++i)
                chkmax(mx, w[i]);

            int cur = oo;
            for (int m = 1; m <= mx; ++m) {
                int t = 0;
                for (int i = 1; i <= n; ++i)
                    t += abs(w[i] - m);
                chkmin(cur, t);
            }
            ans += cur;
        }
        
        if (ans < 0) {
            cout << "Case #" << tc << ": Fegla Won" << endl;
        } else {
            cout << "Case #" << tc << ": " << ans << endl;
        }
    }

    return 0; 
}
