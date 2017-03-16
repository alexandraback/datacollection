/*
#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:16777216")
#endif
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <time.h>
#include <vector>
// #include <sys/time.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i, n)
#define fj(n) fo(j, n)
#define fk(n) fo(k, n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))
//#define lgLowestBit(x) __builtin_ctz(x)
//#define bitCount(x) __builtin_popcount(x)
//#define foreach(it, a) for(__typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
//#define me (*this)
//#define PQ(t) priority_queue< t, vector< t >, greater< t > >
//#define CLR(a, v) memset(a, v, sizeof(a))
//#define UNIQUE(a) srt(a), a.resize(unique(all(a))-a.begin())
//#define RAND (((double)rand()/RAND_MAX) + ((double)rand()/RAND_MAX/RAND_MAX))
//#define assert(cond,msg) if(!(cond)){ fprintf(stderr, "assert failed at line %d: %s\n", __LINE__, msg); exit(1); }
/*
char systemBuffer[1<<10];
#define execute(...) {\
  sprintf(systemBuffer, __VA_ARGS__); \
  system(systemBuffer); \
}

#ifdef LOCAL
  #define debug(msg, ...) fprintf(stderr, msg, __VA_ARGS__)
#else
  #define debug(msg, ...)
#endif
*/

typedef long long ll;
typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector< vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< ll > vll;
typedef vector< bool > vb;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f){ return (t>f) ? (t=f, 1) : 0; }
template<class T> int chmax(T &t, T f){ return (t<f) ? (t=f, 1) : 0; }

/* 
struct timeval startTime, finishTime;
double timeElapsed(){
  gettimeofday(&finishTime, NULL);
  int top = finishTime.tv_sec-startTime.tv_sec-(startTime.tv_usec > finishTime.tv_usec);
  int bot = finishTime.tv_usec-startTime.tv_usec;
  if(bot < 0)
    bot += 1e6;
  return top+bot/1e6;
}
*/
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"),-1);
}



ii operator-(ii a, ii b) { return ii(a.x - b.x, a.y - b.y); }
ll operator^(ii a, ii b) { return ll(a.x) * b.y - ll(a.y) * b.x; }
ll ccw(const ii& a, const ii& b, const ii& c) {
  ii ac = a - c;
  ii bc = b - c;
  return ll(ac.x) * bc.y - ll(ac.y) * bc.x;
}
bool left(ii a, ii b, ii c) {
  return ((a-b) ^ (c-b)) > 0;
}
bool right(ii a, ii b, ii c) {
  return ((a-b) ^ (c-b)) < 0;
}

void myCode() {

  int ttt = getint();
  fo (tt, ttt) {
    int n = getint();
    vii a;
    fi(n) {
      int x = getint(), y = getint();
      a.pb(ii(x, y));
    }

    printf("Case #%d:\n", tt + 1);
    fi(n) {
      vector< pair<double, ii> > b;
      list<ii> l, r, gl, gr;
      fj(n) if (i != j) {
        b.push_back(mp(atan2(a[j].y - a[i].y, a[j].x - a[i].x), a[j]));
      }
      srt(b);
      fj(sz(b))
        if (b[j].y.y == a[i].y) {
          if (b[j].y.x < a[i].x)
            gr.pb(b[j].y);
          else
            gl.pb(b[j].y);
        } else {
          if (b[j].y.y < a[i].y) {
            l.pb(b[j].y);
          } else {
            r.pb(b[j].y);
          }
        }

      int ret = n - 1;
      fj(sz(b)) {
        fk(3) {
          ii p = b[j].y;
          while (!l.empty() && ccw(p, a[i], l.front()) >= 0) {
            gr.push_back(l.front());
            l.pop_front();
          }
          while (!gr.empty() && ccw(p, a[i], gr.front()) != 0) {
            r.push_back(gr.front());
            gr.pop_front();
          }
          while (!r.empty() && ccw(p, a[i], r.front()) <= 0) {
            gl.push_back(r.front());
            r.pop_front();
          }
          while (!gl.empty() && ccw(p, a[i], gl.front()) != 0) {
            l.push_back(gl.front());
            gl.pop_front();
          }
        }
        ret = min(ret, min(sz(l), sz(r)));
      }
      printf("%d\n", ret);
    }
  }
}

int main() {
/*
  // seed the random number generator with microseconds
  gettimeofday(&startTime, NULL);
  srand(startTime.tv_usec);
*/
  myCode();
  return 0;
}










