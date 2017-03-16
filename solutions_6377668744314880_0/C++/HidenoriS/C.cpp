
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

int T, N;
ll X[3333];
ll Y[3333];
int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  cin >> T;
  rep1(test,T)
  {
    cin >> N;
    rep1(i,N) cin >> X[i] >> Y[i];
    cout << "Case #" << test << ":" << endl;
    rep1(i,N)
    {
      ll best = INF;
      rep1(j,N) if (i != j)
      {
        ll cntplus = 0;
        ll cntminus = 0;
        rep1(k,N) if (i != k && j != k)
        {
          ll dx1 = X[i]-X[j];
          ll dx2 = X[k]-X[j];
          ll dy1 = Y[i]-Y[j];
          ll dy2 = Y[k]-Y[j];
          ll cp = dx1*dy2 - dx2*dy1;
          if (cp < 0) cntminus++;
          if (cp > 0) cntplus++;
        }
        best = min(best,cntplus);
        best = min(best,cntminus);
      }
      if (N <= 2) best = 0;
      assert(best<INF);
      cout << best << endl;
    }
  }
}
