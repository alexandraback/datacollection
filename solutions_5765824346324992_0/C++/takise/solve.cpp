#include <bits/stdc++.h>
#define pb push_back
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define ALL(x) x.begin(), x.end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

typedef long double ld;
const int INF = 1 << 29;

// cond: a>b
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int B, N;
int m[1000];

int main(void) {
  int TestCase, TC = 0;
  cin >> TestCase;
  while(TestCase != TC) {
    cout << "Case #" << ++TC << ": ";
    cin >> B >> N;
    REP(i, B) cin >> m[i];
    ll l = 1;
    REP(i, B) l = lcm(l, m[i]);
    vector<pii> v;
    REP(i, B) {
      ll cnt = l / m[i];
      REP(j, cnt) v.push_back(pii(j * m[i], i));
    }
    sort(ALL(v));
    N = (N - 1) % v.size();
    cout << v[N].second + 1 << endl;
  }
  return 0;
}
