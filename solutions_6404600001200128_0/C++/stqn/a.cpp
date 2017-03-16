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

long n, a[N];

void prepare()
{

}

void input()
{
    cin >> n;
    rep(i, n) cin >> a[i];
    a[n] = 0;
}

long solve1()
{
    long ret = 0;
    rep(i, n-1) {
        if (a[i] > a[i+1]) ret += a[i] - a[i+1];
    }
    return ret;
}

long solve2()
{
    long rate = 0;
    rep(i, n-1) rate = max<long>(rate, a[i] - a[i+1]);
    long ret = 0;
    rep(i, n-1) {
        ret += min(rate, a[i]);
    }
    return ret;
}

void solve()
{
    cout << solve1() << ' ' << solve2() << endl;
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
        cout << "Case #" << i << ": ";
        solve();
    }
}
