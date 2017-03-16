#include<iostream>
#include<complex>
#include<vector>
#include<string>

#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<sstream>
#include<unistd.h>
#include<valarray>
#include<numeric>
#include<algorithm>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>

#include<fstream>
#include<time.h>
using namespace std;

#define NDEBUG
#include<assert.h>
#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MOD(A,B) (((A)%(B)+(B))%(B))
#define MP make_pair
#define FI first
#define SE second
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define RFOREACH(I,C) for(VAR(I,(C).rbegin());I!=(C).rend();I++)
#define ALL(X) (X).begin(),(X).end()
#define SRT(X) sort((X).begin(),(X).end())
#define PB push_back

typedef long double ld;
typedef long long ll;
const long double EPS=10e-12;
inline int isZero(long double x){if(x>=-EPS&&x<=EPS) return 1; else return 0;}
template<class T> inline T ABS(T x){return x<0?-x:x;}
template<class T> inline T sqr(T a){return a*a;}

typedef vector<int> VI;
struct Point{ld x,y,z;
  Point(ld wx=0,ld wy=0,ld wz=0){x=wx;y=wy;z=wz;}
  inline bool operator==(Point a){return isZero(a.x-x)&&isZero(a.y-y)&&isZero(a.z-z);}
  inline bool operator!=(Point a){return !(*this==a);}
  inline Point& operator=(Point a){x=a.x;y=a.y;z=a.z;return *this;}
  inline Point operator+(Point a){Point ret;ret.x=x+a.x;ret.y=y+a.y;ret.z=z+a.z;return ret;}
  inline Point operator-(Point a){Point ret;ret.x=x-a.x;ret.y=y-a.y;ret.z=z-a.z;return ret;}
  inline Point operator*(ld a){Point ret;ret.x=x*a;ret.y=y*a;ret.z=z*a;return ret;}
  inline Point operator/(ld a){Point ret;if(a){ret.x=x/a;ret.y=y/a;ret.z=z/a;}return ret;}
  inline ld operator*(Point a){ld ret=0;ret+=x*a.x;ret+=y*a.y;ret+=z*a.z;return ret;}
  inline bool operator>(ld q){if(x>q&&y>q&&z>q) return true; else return false;}
  inline bool operator<(ld q){if(x<q&&y<q&&z<q) return true; else return false;}
  inline bool operator>=(ld q){if(x>=q&&y>=q&&z>=q) return true; else return false;}
  inline bool operator<=(ld q){if(x<=q&&y<=q&&z<=q) return true; else return false;}
  inline ld norm1(){return ABS(x)+ABS(y)+ABS(z);}
  inline ld norm2(){return sqrtl(sqr(x)+sqr(y)+sqr(z));}
  inline ld normInf(){return MAX(ABS(x),MAX(ABS(y),ABS(z)));}
  inline bool colinear(Point a){ld n1=this->norm1(),n2=a.norm1();return(isZero(n1)||isZero(n2))?true:(((*this)/n1==a/n2)||((*this)/n1==a/(-n2)));}
  inline bool sense(Point a){return (*this)/(this->norm1())==a/(a.norm1());}
  inline bool antiSense(Point a){return (*this)/(this->norm1())==a/(-a.norm1());}
};
ostream& operator<<(ostream& a, Point p){a<<"("<<p.x<<", "<<p.y<<", "<<p.z<<")";return a;}
typedef vector<Point> VP;
inline bool OrdXY(Point *a, Point *b){return a->x==b->x?a->y<b->y:a->x<b->x;}
inline Point det(Point a, Point b, Point c){Point ret;b=b-a;c=c-a;ret.x=b.y*c.z-b.z*c.y;ret.y=b.z*c.x-b.x*c.z;ret.z=b.x*c.y-b.y*c.x;return ret;}
#define XCAL {while(SZ(w)>m&&det((*w[SZ(w)-2]),(*w[SZ(w)-1]),(*s[x])).z<0)w.pop_back();w.PB(s[x]);}
vector<Point*> convexHull(VP& p) {vector<Point*> s,w;FOREACH(it,p)s.PB(&*it);sort(ALL(s),OrdXY);int m=1;REP(x,SZ(s))XCAL m=SZ(w);FORD(x,SZ(s)-2,0)XCAL w.pop_back();return w;}
#define qdet(a, b, c) ((ll)(b.x-a.x)*(ll)(c.y-a.y)-(ll)(b.y-a.y)*(ll)(c.x-a.x))
template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}
int N;

struct cst_compare {
  bool operator() (const Point& a, const Point& b) const{
    return a.x==b.x?a.y<b.y:a.x<b.x;
  }
};

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    VI x=parsei(line);
    N=x[0];
    VP ps;
    REP(i,N){
      getline(cin, line);
      x=parsei(line);
      ps.PB(Point(x[0],x[1],0));
    }
    //vector<Point*> ch = convexHull(ps);
    //set<Point,cst_compare> sch;
    //FOREACH(I,ch) sch.insert(**I);
    cout<<"Case #"<<stringify(tt)<<":\n";
    REP(i,N){
      int ret=N;
      if(N<=3){
        ret=0;
      }else{
        REP(j,N) if(j!=i){
          int le=0, ri=0;
          REP(k,N)if(j!=k&&k!=i){
            ll r=qdet(ps[j],ps[i],ps[k]);
            if(r<0) le++; else if(r>0) ri++;
          }
          le=MIN(le,ri);
          ret=MIN(ret,le);
        }
      }
      cout<<stringify(ret)<<"\n";
    }
  }

  return 0;
}
