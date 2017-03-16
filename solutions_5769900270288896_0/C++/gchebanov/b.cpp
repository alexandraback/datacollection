#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define ford1(i, n) for(int i = (int)(n); i>=1; --i)
#define fored(i, a, b) for(int i = (int)(b); i >= (int)(a); --i)
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<ld> vld;

template<class T> T sqr(const T& a) { return a * a; }
template<class T> bool uax(T&a, const T& b) { if( a < b ) { a = b; return true; } return false; }
template<class T> bool uin(T&a, const T& b) { if( a > b ) { a = b; return true; } return false; }

#ifdef HOME
#define dbg(v) do {cerr << v << '\n';}while(0)
#else
#define dbg(v) do {;}while(0)
#endif

const int inf = 1e9 + 100500;

map<pii, vi> ans;

int Z[20][20];

vi solve(int r, int c) {
  int l = r * c;
  vi ans(l + 1, inf);
  for (int mask = 0; mask < (1 << l); ++mask) {
    forn(i, r) forn(j, c) Z[i][j] = (mask>>(i*c+j))&1;
    int cnt = 0, val = 0;
    forn(i, r) forn(j, c) cnt += Z[i][j];
    forn(i, r-1) forn(j, c) val += Z[i][j] && Z[i+1][j];
    forn(i, r) forn(j, c-1) val += Z[i][j] && Z[i][j+1];
    uin(ans[cnt], val);
  }
  return ans;
}

void solve() {
  int r,c,n;
  cin >> r >> c >> n;
  if ( r > c ) swap(r, c);
  if (!ans.count(mp(r,c)))
    ans[mp(r,c)] = solve(r,c);
  cout << ans[mp(r,c)][n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed; cout.precision(15);
  cerr << fixed; cerr.precision(15);
#ifdef HOME
  //freopen("input.txt", "r", stdin);
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-s0.out", "w", stdout);
#endif
  int T;
  cin >> T;
  fore(t, 1, T) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

