#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
 
using namespace std;
 
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define UNIQUE(x) x.erase(unique(ALL(x)),x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

////////////////////////////////////////////////////////////

int brute(int X, int Y, int N) {
  int res = 9999;
  REP(msk, 1<<(X*Y)) {
    int cnt = 0;
    REP(i, X*Y) if (msk & (1<<i)) cnt++;
    if (cnt != N) continue;
    int tmp = 0;
    REP(y,Y) REP(x,X) REP(d,4) {
      int ny=y+dy[d], nx=x+dx[d];
      if (ny<0 || ny>=Y || nx<0 || nx>=X) continue;
      int i = y*X+x;
      int j = ny*X+nx;
      if ((msk & (1<<i)) && (msk & (1<<j))) tmp++;
    }
    res = min(res,tmp);
  }
  return res/2;
}


int smart(int X, int Y, int N) {
  vector<set<pair<int,int>>> cell(5);
  int res = 0;
  REP(y,Y) REP(x,X) {
    int cnt = 0;
    REP(d,4) {
      int ny=y+dy[d], nx=x+dx[d];
      if (nx>=0 && nx<X && ny>=0 && ny<Y) cnt++;
    }
    cell[cnt].insert(make_pair(x,y));
    res += cnt;
  }
  res /= 2;
  REP(n,X*Y-N) {
    REPD(cnt,5) {
      if (!cell[cnt].empty()) {
	res -= cnt;
	pair<int,int> p = *cell[cnt].begin();
	cell[cnt].erase(p);

	REP(d,4) {
	  pair<int,int> q = make_pair(p.first + dx[d], p.second + dy[d]);
	  REP(i,5) {
	    if (cell[i].find(q) != cell[i].end()) {
	      cell[i].erase(q);
	      if (i>0) cell[i-1].insert(q);
	    }
	  }
	}
	break;
      }
    }
  }
  return res;
}

void solve () {
  int X,Y,N;
  cin >> X >> Y >> N;
  cout << brute(X,Y,N);
}

int main () {

  int runs;
  cin >> runs;

  for (int run=1; run<=runs; run++) {
    cout << "Case #" << run << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
