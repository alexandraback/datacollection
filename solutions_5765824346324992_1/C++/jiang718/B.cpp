#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <limits.h>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <assert.h>
#include <cstring>
using namespace std;
#define rep(i, n) for (int (i) = 0, j123 = n; (i) < j123; (i) ++)
#define rep1(i, n) for (int (i) = 1, j123 = n; (i) <= j123; (i) ++)
#define db(x) {cout << #x << " = " << (x) << endl;}
#define dba(a, x, y) {cout << #a << " :";for(int i123=(x);i123<=(y);i123++) cout<<setw(4)<<(a)[i123];cout<<endl;}
#define clr(x) memset(x,0,sizeof(x));
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const ld pi = acos(-1);
// const int MOD = ;
//find smallest T such that at time T, sum(ceil[T/Mk]) >= N, mark those k, such that T/Mk != (T-1)Mk
//answer: q[N - v - 1]
//right-max: Max(Mk) * N 
ll N;
int T, B;
ll m[2000];
ll mm;

inline ll getceil(ll a, ll b) {
  ll v = a / b;
  if (a % b) v += 1;
  return v;
}

inline ll ok(ll mid) {
  ll v = 0;
  rep(i, B) {
    v += getceil(mid, m[i]);
  }
  return v >= N;
}

inline ll findAns() {
  ll bad = 0; 
  ll good = mm * N; 
  ll mid;
  while (bad + 1 < good) {
    mid = (bad + good) / 2;
    if (ok(mid)) { 
      good = mid;
    } else {
      bad = mid; 
    }
  }
  ll c1, c2;
  ll v = 0;
  vector<int> q;
  //db(good);
  rep(i, B) {
    c1 = getceil(good, m[i]);
    c2 = getceil(good - 1, m[i]);
    v += c2;
    if (c1 != c2) {
      q.pb(i + 1);
    }
  }
  //db(N);
  //db(v);
  //dba(q, 0, sz(q) - 1);
  return q[N-v-1];
}

int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  cin >> T;
  rep1(cc, T) {
    cin >> B >> N;
    mm = -1;
    rep(i, B) {
      cin >> m[i];
      if (m[i] > mm) mm = m[i];
    }
    cout << "Case #" << cc << ": " << findAns() << endl;
  }
}
