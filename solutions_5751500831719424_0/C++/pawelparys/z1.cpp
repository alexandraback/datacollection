#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)
#define INIT(i,v) __typeof(v) i = (v)
#define FOREACH(i,v) for(INIT(i, (v).begin()); i!=(v).end(); ++i)
#define MP make_pair
#define PB push_back
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;
 
template<class T>
inline int size(const T&t){return t.size();}

#define INF 1000000000
 
//////////////////////////////////////////

int N;

char znaki[100][105];
int ilosci[100][105];
int ile[100];

char inp[105];

void dziel(int nr) {
  int len = 0;
  char pr = 0;
  for (char *x = inp; *x; ++x)
    if (*x==pr)
      ++ilosci[nr][len-1];
    else {
      znaki[nr][len] = pr = *x;
      ilosci[nr][len++] = 1;
    }
  ile[nr] = len;
}

int licz() {
  FOR(a, 1, N-1) {
    if (ile[a]!=ile[0])
      return -1;
    REP(b, ile[a])
      if (znaki[a][b]!=znaki[0][b])
        return -1;
  }
  int wyn = 0;
  REP(x, ile[0]) {
    int best = INF;
    FOR(i, 1, 100) {
      int zm = 0;
      REP(a, N)
        zm += abs(i-ilosci[a][x]);
      if (zm>best)
        break;
      best = zm;
    }
    wyn += best;
  }
  return wyn;
}

int main() {
  int TT;
  scanf("%d", &TT);
  REP(tt, TT) {
    scanf("%d", &N);
    REP(a, N) {
      scanf("%s", inp);
      dziel(a);
    }
    printf("Case #%d: ", tt+1);
    int wyn = licz();
    if (wyn>=0)
      printf("%d\n", wyn);
    else
      printf("Fegla Won\n");
  }
}


