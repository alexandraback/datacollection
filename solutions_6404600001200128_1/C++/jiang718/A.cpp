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
int m[2000];

int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  int T, n;
  int mm;
  ll ans1, ans2;
  cin >> T;
  rep1(cc, T) {
    cin >> n;
    m[0] = 0;
    ans1 = 0;
    ans2 = 0;
    mm = 0;
    rep1(i, n) {
      cin >> m[i];
      if (m[i] < m[i - 1]) {
        ans1 += m[i - 1] - m[i];
      }
      if (m[i - 1] - m[i] > mm) {
        mm = m[i - 1] - m[i];
      }
    }
    rep1(i, n) {
      ans2 += min(mm, m[i - 1]); 
    }
    cout << "Case #" << cc << ": " << ans1 << " " << ans2 << endl;
  }
}
