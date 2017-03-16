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

const int N = 1005;
int n;
int arr[N];

int satisfiable( int d ) {
  int s = arr[0];
  int res = 0;
  FOR( i, 1, n - 1 ) {
    res += max( 0, s - d );
    s    = max( 0, s - d );
    if ( arr[i] < s )
      return INT_MAX;
    s = max( s, arr[i] );
  }
  return res;
}

int main( ) {
  DRI( caseCnt );
  FOR( caseNr, 1, caseCnt ) {
    RI( n );
    REP( i, n )
      RI( arr[i] );
    int res1 = 0, res2 = 0, d = 0;
    FOR( i, 1, n - 1 )
      if ( arr[i] < arr[i-1] )
        res1 += arr[i-1] - arr[i];
    REP( i, n - 1 )
      d = max( d, arr[i] - arr[i+1] );
    REP( i, n - 1 ) {
      res2 += min( d, arr[i] );
    }
    /*FOR( i, 1, n - 1 ) {
      if ( arr[i] < arr[i-1] )
        d = max( d, arr[i-1] - arr[i] );
      else if ( arr[i-1] < arr[i] )
        d = max( d, arr[i-1] );
    }
    FOR( i, 1, n - 1 ) {
      res2 += min( d, arr[i-1] );
    }*/
    printf( "Case #%d: %d %d\n", caseNr, res1, res2 );
  }

  return 0;
}