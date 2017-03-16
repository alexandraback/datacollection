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
int arr[N];

int main( ) {
  DRI( caseCnt );
  FOR( caseNr, 1, caseCnt ) {
    DRII( b, n );
    REP( i, b )
      RI( arr[i] );
    int mini = *min_element( arr, arr + b );
    ll low = 1, high = (ll) n * mini;
    while ( low != high ) {
      ll mid = ( low + high ) / 2;
      ll cnt = 0;
      REP( i, b )
        cnt += ( mid + arr[i] - 1 ) / arr[i];
      if ( cnt < n )
        low = mid + 1;
      else
        high = mid;
    }
    --low;
    // uz hotovi
    REP( i, b )
      n -= ( low + arr[i] - 1 ) / arr[i];
    // DBG( n );
    // DBG( low );
    // nacnuty, ktery nezacali ted
    for ( ; ; ++low ) {
      REP( j, b ) {
        if ( low % arr[j] == 0 ) {
          if ( --n <= 0 ) {
            printf( "Case #%d: %d\n", caseNr, j + 1 );
            goto next;
          }
        }
      }
    }
    next:;
    /*int res;
    // secti uz zapocaty
    DBG( n );
    REP( i, b ) {
      // uz hotovi
      n -= low / arr[i];
      // nacnuty
      if ( ( low - 1 ) % arr[i] )
        --n;
    }
    DBG( n );
    REP( i, b ) {
      if ( ( low - 1) / arr[i] * arr[i] == low - 1 ) {
        if ( --n <= 0 ) {
          res = i + 1;
          break;
        }
      }
    }*/
    // printf( "Case #%d: %d\n", caseNr, res );
  }
  return 0;
}