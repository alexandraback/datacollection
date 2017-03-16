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
int n;
ii a[1234];


int main() {
  // freopen("A.in","r",stdin);
  //  freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
  //	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
  //	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	  freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);

  DRI(cs);
  FOR(ci,1,cs){
    RI(n);
    int sum = 0;
    REP(i,n){ DRI(x); a[i] = MP(x,i); sum+=x; }
    sort(a,a+n);

    printf("Case #%d:",ci);

    while(1){
      if(sum == 3){ printf(" %c",  (char)a[n-1].ss + 'A' ); a[n-1].ff--; sum--;  }
      else if(a[n-1].ff + a[n-2].ff == 0)break;
      else if(a[n-1].ff > a[n-2].ff ) { printf(" %c",  (char)a[n-1].ss + 'A' ); a[n-1].ff--; sum--;}
      else { printf(" %c%c",  (char)a[n-1].ss + 'A', (char)a[n-2].ss + 'A' ); a[n-1].ff--; a[n-2].ff--; sum-=2; }

      sort(a,a+n);

    }
    printf("\n");




  }
  return 0;
}
