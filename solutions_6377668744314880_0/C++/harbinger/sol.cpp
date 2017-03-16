
// Author: Tiago Togores

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define CLR(a, x) memset(a, x, sizeof a)
#define REP(i, n) for (auto i = 0; i < (n); i++)
#define FORT(it, l) for (auto it = (l).begin(); it != (l).end(); it++)
#define SCW(n) while ((cin >> (n)) && (n))
#define SCR(n) for (cin >> (n); (n)--;)
#define READLINE(line) cin.getline((line), sizeof (line))
#define VALID(i, j, n, m) (0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))
#define PI M_PI
#define EPSILON 1e-9
#define INF 1000000000
#define MOD 1000000007
#define endl '\n'
//NOTE: append ll to name if using long long
#define BITCOUNT __builtin_popcount
#define BITLEAD0 __builtin_clz
#define BITTRAIL0 __builtin_ctz
#define BITPARITY __builtin_parity

typedef unsigned int uint;
typedef long long int int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

///////////////////////////////

 
typedef double coord_t;    
typedef double coord2_t;  
 
struct point {
  coord_t x, y;
 
  bool operator <(const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
  bool operator ==(const point &p) const {
    return x == p.x && y == p.y;
  }
};
 
coord2_t cross(const point &O, const point &A, const point &B)
{
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
vector<point> convex_hull(vector<point> P)
{
  int n = P.size(), k = 0;
  vector<point> H(2*n);
 
  // Sort points lexicographically
  sort(P.begin(), P.end());
 
  // Build lower hull
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
 
  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
 
  H.resize(k);
  return H;
}

void solve()
{
	int n;
	cin >> n;
	vector<point> v;
	REP (i, n) {
		point p;
		cin >> p.x >> p.y;	
		v.PB(p);
	}
	vector<int> ans(n, n - 1);
	vector<point> t;
  int limit = (1 << n) - 1;
	for (int s = 1; s <= limit; s++) {
		t.clear();
		REP (i, n)
			if ((s >> i) & 1)
				t.push_back(v[i]);
		auto a = convex_hull(t);
    // for (auto&x : a)
    //   cout << "* " << x.x << " " << x.y << endl;;
    int m = BITCOUNT(s);
    REP (i, SZ(a) - 1) {
      // cout << "* " << a[i].x << " " << a[i].y << endl;;
      REP (j, n) {
          if (v[j] == a[i]) {
            // cout << j << " * " << a[i].x << " " << a[i].y << endl;;
            ans[j] = min(ans[j], n - m);
            break; 
          }
      }
    }
	}
	REP (i, n)
		cout << ans[i] << endl;
}

int main()
{ _
	int t, tc = 1;
	SCR(t) {
		cout << "Case #" << tc++ << ":" << endl;
		solve();
	}
	return 0;
}
