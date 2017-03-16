#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i,n)
#define fj(n) fo(j,n)
#define fk(n) fo(k,n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f) { return (t>f) ? (t=f,1) : 0; }
template<class T> int chmax(T &t, T f) { return (t<f) ? (t=f,1) : 0; }

inline int getint() {
  int a;
  return scanf("%d",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

void myCode() {
  int ttt = getint();
  fo(tt,ttt) {
    int b = getint(), n = getint();
    vi m(b);
    fi(b)
      m[i] = getint();

    // binary search for the first minute where I can get my hair cut
    // lo <= ans < hi
    ll lo = -1;
    ll hi = INF; hi *= INF;
    while (hi - lo > 1) {
      ll mid = lo + (hi-lo)/2;
      ll served = 0;
      fi(b)
        served += mid/m[i] + 1;
      if (served < n)
        lo = mid;
      else
        hi = mid;
    }
//    fprintf(stderr,"can get haircut after %d min\n",hi);
    int ans = 0;
    fi(b)
      n -= (hi-1)/m[i]+1;
    fi(b)
      if (hi%m[i] == 0) {
        if (--n == 0) {
          ans = i+1;
          break;
        }
      }
    printf("Case #%d: %d\n",tt+1,ans);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
