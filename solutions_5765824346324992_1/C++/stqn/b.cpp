#include <bits/stdc++.h>
using namespace std;
#define ulong uint64_t
#define mt make_tuple
#define eb emplace_back
#define all(u) begin(u),end(u)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
template<class C>void uniq(C&c){c.erase(unique(all(c)),end(c));}
template<class T>bool chmin(T&a,const T&b){return a>b&&(a=b,1);}
template<class T>bool chmax(T&a,const T&b){return a<b&&(a=b,1);}

const int N = 1024;
const long inf = 1e16;

long n, k, a[N];

void prepare()
{

}

void input()
{
    cin >> n >> k;
    rep(i, n) cin >> a[i];
}

long attempt(long t)
{
    if (t < 0) return 0;
    long ret = 0;
    rep(i, n) {
        ret = min(ret + t / a[i] + 1, inf);
    }
    return ret;
}

long solve()
{
    long l = -1, r = inf;
    while (l < r - 1) {
        const long m = (l + r) / 2;
        if (attempt(m) < k) l = m;
        else r = m;
    }
    vector<int> cands;
    rep(i, n) {
        if (r % a[i] == 0) cands.push_back(i);
    }
    return cands[k - attempt(l) - 1];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    prepare();

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        input();
        cout << "Case #" << i << ": " << solve() + 1 << endl;
    }
}
