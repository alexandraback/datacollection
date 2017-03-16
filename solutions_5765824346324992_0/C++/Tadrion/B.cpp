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
int T,N,B;
int M[1010];

int gcd(int a, int b) {
    if(b > a) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm() {
    int res = M[1];
    FOR(i,2,B) {
        int g = gcd(res,M[i]);
        res *= M[i];
        res /= g;
    }
    //printf("lcm:%d\n",res);
    return res;
}

int cnt() {
    int w = lcm();
    int c = 0;
    FOR(i,1,B) c += w/M[i];
    return c;
}

int ans() {
    int c = cnt();
    //return c;
    N%=c;
    if(N==0) N=c;
    set<pair<int,pair<int,int> > > s; //min, nr, czas;
    FOR(i,1,B) s.insert(MP(0,MP(i,M[i])));
    while(N>=2) {
        pair<int,pair<int,int> > b = *(s.begin());
        s.erase(b);
        s.insert(MP(b.ST+b.ND.ND,b.ND));
        N--;
    }
    return (*(s.begin())).ND.ST;

}

int main() {
  scanf("%d",&T);
  //printf("%d",T);
  FOR(TTT,1,T) {
    scanf("%d %d",&B,&N);

    FOR(i,1,B) {
        scanf("%d",&M[i]);
    }

    printf("Case #%d: %d\n",TTT,ans());
  }
  return 0;
}
