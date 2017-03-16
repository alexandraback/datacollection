
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
int N;
ll A[1010];
int main()
{
  ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0);
  cin >> T;
  rep1(test,T)
  {
    cin >> N;
    rep1(i,N) cin >> A[i];
    cout << "Case #" << test << ": ";
    ll tot = 0;
    for (int i = 1; i+1 <= N; i++)
      if (A[i] > A[i+1])
        tot += A[i] - A[i+1];
    cout << tot << ' ';
    tot = 0;
    ll mx = 0;
    for (int i = 1; i+1 <= N; i++)
      if (A[i] > A[i+1])
        mx = max(mx, A[i]-A[i+1]);
    
    for (int i = 1; i+1 <= N; i++)
      tot += min(mx, A[i]);
    cout << tot << endl;
  }
}
