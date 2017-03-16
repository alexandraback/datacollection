//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T;
int N;
int a[100100];

int main() {
  scanf("%d",&T);
  FOR(TTT,1,T) {
    int x = 0;
    int y = 0;

    scanf("%d",&N);
    FOR(i,1,N) scanf("%d",&a[i]);

    FOR(i,2,N) x += MAX(0,a[i-1]-a[i]);

    int slope = 0;
    FOR(i,2,N) slope = MAX(slope,a[i-1]-a[i]);

    FOR(i,1,N-1) {
        if(a[i] >= slope) y += slope;
        else y += a[i];
    }

    printf("Case #%d: %d %d\n",TTT,x,y);
  }
  return 0;
}
