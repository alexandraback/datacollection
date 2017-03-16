#include <algorithm>
#include <cmath>
#include <climits>
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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define DEBUG(x) cout << ">>> " << #x << " : " << x << endl
#define MP make_pair
#define PB push_back
#define REP(i,b) for ( int i = 0; i < int(b); ++i )
#define FOR(i,a,b) for ( int i = int(a); i <= int(b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= int(b); --i )
#define RI(a) scanf("%d", &a)
#define RII(a,b) scanf("%d%d", &a, &b)
#define RIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define RIIII(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
#define MM(x,b) memset( x, b, sizeof( x ) )
const int INF = 1<<29;
typedef long long ll;
typedef pair<char,int> ci;

vector< queue<ci> > words;

int main( ) {
  int caseCnt, n;
  string line;
  cin >> caseCnt;
  FOR( caseNr, 1, caseCnt ) {
    cout << "Case #" << caseNr << ": ";
    words.clear( );
    cin >> n;
    REP( i, n ) {
      queue<ci> q;
      cin >> line;
      for ( int j = 0; j < (int) line.size( ); ++j ) {
        int k;
        for ( k = j + 1; k < (int) line.size( ) && line[k] == line[j]; ++k );
        q.push( MP( line[j], k - j ) );
        j = k - 1;
      }
      words.PB( q );
    }
    ll moves = 0;
    while ( !words[0].empty( ) ) {
      int  mini = INT_MAX, maxi = INT_MIN;
      int  score, minscore;
      char c = words[0].front( ).first;
      REP( i, n ) {
        if ( words[i].empty( ) || words[i].front( ).first != c )
          goto fail;
        mini = min( mini, words[i].front( ).second );
        maxi = max( maxi, words[i].front( ).second );
      }
      minscore = INT_MAX;
      FOR( len, mini, maxi ) {
        score = 0;
        REP( i, n )
          score += abs( words[i].front( ).second - len );
        minscore = min( score, minscore );
      }
      REP( i, n )
        words[i].pop( );
      moves += minscore;
    }
    REP( i, n )
      if ( !words[i].empty( ) )
        goto fail;
    cout << moves << endl;
    continue;
    fail:
    cout << "Fegla Won" << endl;
  }

  return 0;
}
