#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define MM(arr, num) memset((arr), (num), sizeof((arr)))
#define DEB(x) cerr << ">>> " << (#x) << " -> " << (x) << endl;
#define DEBA(x,n) cerr << (#x) << " "; deba((x),(n));
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
struct Vec
{
  ll x, y;
  Vec(ll _x=0, ll _y=0): x(_x), y(_y) {}

  bool operator<(const Vec & v) const { return x < v.x || (x == v.x && y < v.y); }
  bool operator==(const Vec & v) const { return (x == v.x && y == v.y); }
  Vec operator-(const Vec & v) const { return Vec(x-v.x, y-v.y); }
  //void operator/=(double n) { x /= n; y/=n; }
  //double size() const { return sqrt(x*x+y*y); }
};

ll cross(const Vec & v1, const Vec & v2)
{
  return v1.x * v2.y - v1.y * v2.x;
}

ll direction(const Vec & v1, const Vec & v2, const Vec & point)
{
  return cross(point-v1, v2-v1);
}

void convex_hull(vector<Vec> & points, vector<Vec> & hull)
{
  sort(points.begin(), points.end());
  vector<Vec> top, bot;
  REP(i, points.size())
  {
    while (top.size() >= 2 && direction(top[top.size()-2], points[i], top[top.size()-1]) < 0)
      top.pop_back();  // vymaz (b, b-1)  kym vector (b, b-2) je na lavo od vektoru ( b, b-1 );
    top.push_back(points[i]);

    while (bot.size() >= 2 && direction(bot[bot.size()-2], points[i], bot[bot.size()-1]) > 0)
      bot.pop_back();  // vymaz (b, b-1)  kym vector (b, b-2) je na pravo od vektoru ( b, b-1 );
    bot.push_back(points[i]);
  }
  reverse(bot.begin(), bot.end());
  hull = top;
  if (bot.size() > 2)
    hull.insert(hull.end(), bot.begin()+1, bot.end()-1);
  // ukladanie bodov v protismere hodinovych ruc.  od najlavejsieho bodu.
}

void solve(){

  int n;
  RI(n);
  int arr[18];
  REP(i,n+2)arr[i] = 154;

  vector<Vec> points(n), hull;
  REP(i, n) scanf("%lld%lld", &points[i].x, &points[i].y);

  REP(i,1<<n){
    vector<Vec> v;
    int cnt = 0;
    REP(j,n){

      if ((i>>j) & 1){
        cnt++;
        v.PB(points[j]);
      }
    }
    int num = n-cnt;

      convex_hull(v, hull);
      REP(k,hull.size()){

        REP(j,points.size() ){
            if ( ((i>>j) & 1) && hull[k] == points[j]){arr[j] = min(arr[j],num );  }
        }
      }
  }

  REP(i,n){
    printf("%d\n", arr[i]);

  }


}







int main() {

  DRI(cs);
  FOR(ic,1,cs){


    printf("Case #%d:\n",ic);
    solve();
  }
  return 0;
}
