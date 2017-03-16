
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

int T;
ll B, N;
ll M[100100];
int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  cin >> T;
  rep1(test,T)
  {
    cin >> B >> N;
    rep1(i,B) cin >> M[i];
    cout << "Case #" << test << ": ";
    if (N <= B)
    {
      cout << N << endl;
      continue;
    }
    ll bad = 0;
    ll good = 1e15;
    while (bad + 1 < good)
    {
      ll m = (good + bad) / 2;
      ll tot = 0;
      rep1(i,B) 
      {
        tot += m / M[i];
        if (m % M[i] > 0)
          tot ++;
      }
      if (tot >= N)
        good = m;
      else
        bad = m;
    }
//    db(good);
    // good is the earliest minute when at least n customners entered store
    ll tot = 0;
    rep1(i,B) 
    {
      tot += (good-1) / M[i];
      if ((good-1) % M[i] > 0)
        tot ++;
    }
    // in the first good-1 min, 
    // there are tot many customers
    ll ans = -1;
    rep1(i,B)
    {
      if ((good-1) % M[i] == 0)
      {
        tot ++;
        if (tot == N)
        {
          ans = i;
          break;
        }
      }
    }
//    db(tot);
    if (ans == -1) 
    {
      db(tot);
      db(N);
      exit(0);
    }
    assert(ans != -1);
    cout << ans << endl;
  }
}
