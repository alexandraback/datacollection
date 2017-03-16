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

using point = complex<double>;
const int N = 3030;

int n;
point p[N];

void prepare()
{

}

void input()
{
    cin >> n;
    rep(i, n) {
        double x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }
}

const double eps = 1e-8;
double inner(const point& a, const point& b) { return real(conj(a) * b); }
double cross(const point& a, const point& b) { return imag(conj(a) * b); }
bool upper(const point& a) { return imag(a) > eps or (imag(a) > -eps and real(a) > eps); }

int solve(int origin)
{
    vector<point> v;
    rep(i, n) if (i != origin) {
        v.eb(p[i] - p[origin]);
    }
    sort(begin(v), end(v), [](const point& a, const point& b) -> bool {
            if (upper(a) != upper(b)) return upper(a);
            return cross(a, b) > eps;
        });
    int ans = n - 1;
    int j = 1;
    rep(i, n-1) {
        while (j-i<n-1 and (cross(v[i], v[j % (n-1)]) > eps or (cross(v[i], v[j % (n-1)]) > -eps and inner(v[i], v[j % (n-1)]) > eps))) {
            ++j;
        }
        ans = min(ans, (j-i-1)%(n-2));
    }
    return ans;
}

void solve()
{
    if (n <= 3) {
        rep(i, n) cout << 0 << endl;
        return;
    }
    rep(i, n) cout << solve(i) << endl;
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
        cout << "Case #" << i << ":\n";
        solve();
    }
}
