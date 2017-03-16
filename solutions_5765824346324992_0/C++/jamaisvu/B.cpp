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

int arr[12345]; int n,P;


ll ok( ll a){
  ll made = 0;
  REP(i,n){
    made+= a / (ll)arr[i];
    if (a % (ll)arr[i] > 0)made++;
  }
  if (made < P) return made;
  else return -1;
}


int solve(){

  RII(n,P);
  REP(i,n)RI(arr[i]);

 // if (P < n)return P;

  ll p,u = 100000000000002L, d = 0;

    while(u > d+1){ //pozor otestuj na ok(0) = true.
      p = (u+d) / 2;
      if ( ok(p) >= 0  ) d = p;//(2) u = p;
      else u = p;//(2) d = p;
    }

    ll made = ok(d);
    //DEB(d);

    REP(i,n){
      if (d % (ll)arr[i] == 0){
        made++;
        if (made == P)return i+1;
      }
    }
    DEB(1111111);
    return -1;
}

int main() {

  DRI(cs);
  FOR(ic,1,cs){

    int num = solve();
    printf("Case #%d: %d\n",ic,num);
  }
  return 0;
}
