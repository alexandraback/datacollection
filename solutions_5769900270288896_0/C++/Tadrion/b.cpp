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

//http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer
inline int cntbits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int unhap(int k, int r, int c) {
    int cnt=0;
    FOR(i,0,r*c-1) {
        if((k>>i)&1) {
            if((i+1)%c > 0 && (k>>(i+1))&1) cnt++;
            if((i+c) < r*c && (k>>(i+c))&1) cnt++;
        }
    }
    return cnt;
}

int a[20][20][20];

int main() {
  scanf("%d",&T);

  FOR(i,1,16) FOR(j,1,16) FOR(k,1,16) a[i][j][k] = 1000;

  FOR(r,1,16)
    FOR(c,1,16) {
        if(r*c <= 16) {
            FOR(i,1,(1<<(r*c))) {
                a[r][c][cntbits(i)] = MIN(a[r][c][cntbits(i)],unhap(i,r,c));
            }
        }
    }

  FOR(TTT,1,T) {
    int R,C,N;
    int minn = 10000;
    scanf("%d %d %d",&R,&C,&N);
    if(N==0) minn = 0;
    /*FOR(i,1,(1<<(R*C))) {
        if(cntbits(i) == N) {
            minn = MIN(minn,unhap(i,R,C));
        }
    }*/
    printf("Case #%d: %d\n",TTT,a[R][C][N]);
  }
  return 0;
}
