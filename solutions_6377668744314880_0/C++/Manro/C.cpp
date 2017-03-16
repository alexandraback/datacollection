#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define DBG(x) cout << ">>> " << #x << " : " << x << endl
#define PB push_back
#define REP(i,b) for ( int i = 0; i < (b); ++i )
#define FOR(i,a,b) for ( int i = (a); i <= (b); ++i )
#define FORD(i,a,b) for ( int i = (a); i >= (b); --i )
#define RI(a) scanf( "%d", &a )
#define RII(a,b) scanf( "%d%d", &a, &b )
#define RIII(a,b,c) scanf( "%d%d%d", &a, &b, &c )
#define RIIII(a,b,c,d) scanf( "%d%d%d%d", &a, &b, &c, &d )
#define DRI(a) int a; RI(a)
#define DRII(a,b) int a, b; RII(a,b)
#define DRIII(a,b,c) int a, b, c; RIII(a,b,c)
#define DRIIII(a,b,c,d) int a, b, c, d; RIIII(a,b,c,d)
const int INF = 1e9+7;

struct Vec
{
  ll x, y;
  Vec( ll _x = 0, ll _y = 0 ) : x(_x), y(_y) {}
  bool operator<(const Vec & v) const { return x < v.x || (x == v.x && y < v.y); }
  Vec operator-(const Vec & v) const { return Vec(x-v.x, y-v.y); }
  //void operator/=(ll n) { x /= n; y/=n; }
  //double size() const { return sqrt(x*x+y*y); }
};

double cross(const Vec & v1, const Vec & v2)
{
  return v1.x * v2.y - v1.y * v2.x;
}

double direction(const Vec & v1, const Vec & v2, const Vec & point)
{
  return cross(point-v1, v2-v1);
}

void convex_hull( vector<Vec> & points, vector<Vec> & hull )
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


int n;
int res[20];
map<Vec,int> order;
vector<Vec>  points;

int main( ) {
  DRI( caseCnt );
  FOR( caseNr, 1, caseCnt ) {
    RI( n );
    points.resize( n );
    REP( i, n ) {
      scanf( "%lld%lld", &points[i].x, &points[i].y );
      order[ points[i] ] = i;
    }
    // DBG( "points" );
    //   for ( const auto & x : points ) {
    //     cout << "[" << x.x << ";" << x.y << "]" << endl;
    //   }
    REP( i, n )
      res[i] = INT_MAX;
    printf( "Case #%d:\n", caseNr );
    REP( s, 1 << n ) {
      int cnt = 0;
      for ( int i = 1; i < (1 << n); i <<= 1 )
        if ( !(s & i) )
          ++cnt;
      vector<Vec> pts, hull;
      REP( i, n )
        if ( s & ( 1 << i ) )
          pts.PB( points[i] );
      // DBG( "pts" );
      // for ( const auto & x : pts ) {
      //   cout << "[" << x.x << ";" << x.y << "]" << endl;
      // }
      convex_hull( pts, hull );
      // DBG( s );
      // DBG( cnt );
      for ( const auto & x : hull ) {
        // cout << "[" << x.x << ";" << x.y << "]" << endl;
        res[ order[ x ] ] = min( res[ order[ x ] ], cnt );
      }
    }
    REP( i, n )
      printf( "%d\n", res[i] );
  }
  return 0;
}