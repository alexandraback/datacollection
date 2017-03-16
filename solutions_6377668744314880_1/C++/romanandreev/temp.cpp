#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
struct pnt {
  ll x, y;
  pnt() {
  }
  pnt(ll _x, ll _y):x(_x), y(_y) {
  }
};
pnt operator + (pnt a, pnt b) {
  return pnt(a.x + b.x, a.y + b.y);
}
pnt operator - (pnt a, pnt b) {
  return pnt(a.x - b.x, a.y - b.y);
}
ll sp(pnt a, pnt b) {
  return a.x * b.x + a.y * b.y;
}
ll vp(pnt a, pnt b) {
  return a.x * b.y - a.y * b.x;
}
int pls(pnt a) {
  if (a.y > 0 || (a.y == 0 && a.x > 0)) {
    return 0;
  } else {
    return 1;
  }
}
bool operator < (pnt a, pnt b) {
  if (pls(a) != pls(b)) {
    return pls(a) < pls(b);
  }
  if (vp(a, b) != 0) {
    return vp(a, b) > 0;
  }
  return sp(a, a) < sp(b, b);
}
int n;
pnt p[10000];
int ans[10000];
void solve() {
  cin>>n;
  for (int i = 0; i < n; i++) {
    cin>>p[i].x>>p[i].y;
    ans[i] = n - 1;
  }
//  cerr<<n<<endl;
  for (int i = 0; i < n; i++) {
    vector<pnt> ls;
    for (int j = 0; j < n; j++) if (i != j) {
      ls.pb(p[j] - p[i]);
    }
    sort(all(ls));
    if (sz(ls) == 0) {
      ans[i] = 0;
      continue;
    }
    int k = sz(ls);
    for (int j = 0; j < k; j++) {
      ls.pb(ls[j]);
    }
    int it = 0;
    for (int j = 0; j < k; j++) {
      while (vp(ls[j], ls[it]) >= 0 && it < j + k) {
        it++;
      }
      ans[i] = min(ans[i], k - (it - j));
    }
    reverse(all(ls));
    it = 0;
    for (int j = 0; j < k; j++) {
      while (vp(ls[j], ls[it]) <= 0 && it < j + k) {
        it++;
      }
      ans[i] = min(ans[i], k - (it - j));
    }
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }
}
int main(){
  assert(freopen(problem_name".out","wt",stdout));
  assert(freopen(problem_name".in","rt",stdin));
  int T;
  scanf("%d", &T);
  for (int ti = 1; ti <= T; ti++) {
    printf("Case #%d: ", ti);
    solve();
  }
  return 0;
}
