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
ll n;
int b;
ll t[10000];
void solve() {
  cin>>b>>n;
  for (int i = 0; i < b; i++) {
    cin>>t[i];
  }
  ll L = 0;
  ll R = n * t[0];
  while (L < R) {
    ll M = (L + R) / 2;
    ll sum = 0;
    for (int i = 0; i < b; i++) {
      sum += M / t[i] + 1;
    }
    if (sum >= n) {
      R = M;
    } else {
      L = M + 1;
    }
  }
  {    
    ll sum = 0;
    for (int i = 0; i < b; i++) {
      sum += L / t[i] + 1;      
    }
    ll cc = sum - n;
    for (int i = b - 1; i >= 0; i--) {
      sum += L / t[i] + 1;      
      if (L % t[i] == 0) {
        if (cc == 0) {
          printf("%d\n", i + 1);
          return;
        }
        cc--;
      }
    }
    assert(false);
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
