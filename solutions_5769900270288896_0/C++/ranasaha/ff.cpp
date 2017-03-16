#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
#else
#include "header.h"
#include "debug.h"
#endif
#define sz(s) int((s).size())
#define clr(a) memset(a,0,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int(i)=0; (i)<(n);++(i))
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef pair <int,int> pii;
typedef long long LL;
template <class T> inline T gcd(T a,T b){return (!b? a : gcd(b,a%b));}
template <class T> inline T ABS(T x){return ((x)>0?(x):(-(x)));}
const int N = 20;

bool mat [N][N];
int r, c, k;

inline void mark (int n) {
  int rr = n / c;
  int cc = n % c;
  mat [rr][cc] = 1;
  //show3 (n, rr, cc);
}

inline int get () {
  int ret = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (j > 0) {
        if (mat [i][j] == 1 && mat [i][j - 1] == 1) {
          ++ret;
        }
      }
      if (i > 0) {
        if (mat [i][j] == 1 && mat [i - 1][j] == 1) {
          ++ret;
        }
      }
    }
  }
  return ret;
}

inline void show_mat () {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << mat [i][j] << " \n" [j == c - 1];
    }
  }
  cout << '\n';
}

inline int solve (int mask) {
  int nn = r * c;
  for (int bit = 0; bit < nn; ++bit) {
    if (((1 << bit) & mask) > 0) {
      //show (bit);
      mark (bit);
    }
  }
  //show_mat ();
  return get ();
}

int main () {
  #ifndef ONLINE_JUDGE
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
  #endif
  cin.sync_with_stdio (0); cin.tie (0);
  int tt;
  cin >> tt;
  for (int tc = 1; tc <= tt; ++tc) {
    cout << "Case #" << tc << ": "; 
    cin >> r >> c >> k;
    int n = r * c;
    int nn = 1 << n;
    int ans = 999999999;
    for (int mask = 0; mask < nn; ++mask) {
      int cnt = 0;
      for (int bit = 0; bit < n; ++bit) {
        if (((1 << bit) & mask) > 0) {
          ++cnt;
        }
      }
      if (cnt == k) {
        //show (mask);
        clr (mat);
        ans = min (ans, solve (mask));
      }
    }
    cout << ans << '\n';
  }
}
