#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    DRIII(R,C,N);
    int cells = R*C;
    int best = 1000;
    FORDE(house,(1<<cells)-1,0) {
      int n = 0;
      FOR(i,0,cells) if(house & (1 << i)) n++;
      if(n != N) continue;
      int unh = 0;
      FOR(r,0,R) {
        FOR(c,0,C) {
          int msk = (1 << (r*C+c));
          int mskL = (1 << (r*C+c-1));
          int mskU = (1 << ((r-1)*C+c));
          if(c > 0 && (house & msk) && (house & mskL)) unh++;
          if(r > 0 && (house & msk) && (house & mskU)) unh++;
        }
      }
      best = min(best, unh);
    }
    printf("Case #%d: %d\n", t+1, best);
  }
  return 0;
}
