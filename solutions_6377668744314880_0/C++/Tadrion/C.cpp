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

inline LL det(LL x1,LL y1,
	      LL x2, LL y2) {
  return ((x1*y2)-(x2*y1));
}

inline bool isright(PII x1, PII x2, PII x3) {
  return ((det(x3.ST-x1.ST,x3.ND-x1.ND,x2.ST-x1.ST,x2.ND-x1.ND) <= 0) ? 1 : 0);
}

inline bool isbetween(PII x1, PII x2, PII x3) {
  return ((det(x3.ST-x1.ST,x3.ND-x1.ND,x2.ST-x1.ST,x2.ND-x1.ND) == 0) ? 1 : 0);
}

vector<PII> calchull(vector<PII> p) {
  if(SZ(p) <= 3) return p;
  vector<PII> upper,lower,hull;
   sort(p.begin(),p.end());
  int k = SZ(p);

  upper.PB(p[0]);
  upper.PB(p[1]);
  for(int i = 2; i < SZ(p); i++) {
    PII last = upper.back();
    upper.pop_back();
    PII beflast = upper.back();
    // printf("i:%d\n last:%d %d\n beflast:%d %d\n",i,last.ST,last.ND,beflast.ST,beflast.ND);
    while(SZ(upper) >= 1 &&
	  isright(beflast,last,p[i]))
      {
          //if(isbetween(beflast,last,p[i])) hull
	last = beflast;
	upper.pop_back();
	beflast = upper.back();
      }
    upper.PB(last);
    upper.PB(p[i]);
  }

  lower.PB(p[k-1]);
  lower.PB(p[k-2]);
  for(int i = k-3; i >= 0; i--) {
    PII last = lower.back();
    p.pop_back();
    PII beflast = lower.back();


    while(SZ(lower) >= 1 &&
	  isright(beflast,last,p[i])) {


      last = beflast;
      lower.pop_back();
      beflast = lower.back();
    }
    lower.PB(last);
    lower.PB(p[i]);
  }
  lower.pop_back();
  //lower.pop_front();

  for(int i = 0; i < SZ(upper); i++) {
    hull.PB(upper[i]);
  }
  for(int i = 1; i < SZ(lower); i++) {
    hull.PB(lower[i]);
  }
  return hull;
}

inline long double dist(PII x1, PII x2) {
  return sqrtl(((long double)(x1.ST-x2.ST)*
		(long double)(x1.ST-x2.ST) +
		(long double)(x1.ND-x2.ND)*
		(long double)(x1.ND-x2.ND)));
}

int N,T,a,b;
vector<PII> p;
int ans[20];
map<PII,int> m;
int main() {
  scanf("%d",&T);
  FOR(TTT,1,T) {
    m.clear();
    p.clear();
    scanf("%d",&N);
    FOR(i,1,N) ans[i] = 10000;
    FOR(i,1,N) {
        scanf("%d %d",&a,&b);
        p.PB(MP(a,b));
        m[MP(a,b)]=i;
    }

    FOR(k,1,(1<<N)-1) {
        vector<PII> test;
        for(int i = 0; i < N; i++) {
            if( (k >> i)&1 ) test.PB(p[i]);
        }
        vector<PII> hull = calchull(test);
        REP(i,SZ(hull)) {
            ans[m[hull[i]]] = MIN(ans[m[hull[i]]], N-SZ(test));
        }
        //printf("%d %d %d\n",k,SZ(hull),SZ(test));
        if(SZ(hull) >= 2) {
            REP(i,SZ(hull)) {
                PII x1 = hull[i];
                PII x2;
                if(i == SZ(hull)-1) x2=hull[0];
                else x2=hull[i+1];
                REP(j,SZ(test)) {
                    if(isbetween(x1,x2,test[j])) {
                        ans[m[test[j]]] = MIN(ans[m[test[j]]],N-SZ(test));
                    }
                }
            }
        }
    }

    printf("Case #%d:\n",TTT);
    FOR(i,1,N) printf("%d\n",ans[i]);
  }
  return 0;
}
