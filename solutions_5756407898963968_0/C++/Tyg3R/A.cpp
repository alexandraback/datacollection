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

bool mp[20];

int main ()
{
  DRI(T);
  FOR(t,1,T+1) {
  	MM(mp,true);
  	DRI(a);
  	FOR(i,1,5) {
  		FOR(j,0,4) {
  			DRI(n);
  			if(i != a) mp[n] = false;
  		}
  	}
  	RI(a);
  	FOR(i,1,5) {
  		FOR(j,0,4) {
  			DRI(n);
  			if(i != a) mp[n] = false;
  		}
  	}
  	vector<int> res;
  	FOR(i,1,17) if(mp[i] == true) res.PB(i);
  	if(res.size() == 0) printf("Case #%d: Volunteer cheated!\n", t);
  	else if(res.size() == 1) printf("Case #%d: %d\n", t, res[0]);
  	else printf("Case #%d: Bad magician!\n", t);
  }
  return 0;
}










