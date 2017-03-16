// @author kelvin
// #includes {{{
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;
// }}}
// #defines {{{
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define POP() pop_back()
#define F first
#define S second
#define PR printf
void RI() {}
template<typename... T>
void RI(int& head,T&... tail) {
    scanf("%d",&head);
    RI(tail...);
}
void PRI(int x) {
    printf("%d\n",x);
}
template<typename... Args>
void PRI(int head,Args... tail) {
    printf("%d ",head);
    PRI(tail...);
}
#define RF(x) scanf("%lf",&(x))
#define RS(x) scanf("%s",x)
#define DPRI(x) fprintf(stderr,"<"#x"=%d>\n",x)
#define DPRII(x,y) fprintf(stderr,"<"#x"=%d, "#y"=%d>\n",x,y)
#define DPRIII(x,y,z) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d>\n",x,y,z)
#define DPRIIII(x,y,z,w) fprintf(stderr,"<"#x"=%d, "#y"=%d, "#z"=%d "#w"=%d>\n",x,y,z,w)
#define DPRF(x) fprintf(stderr,"<"#x"=%lf>\n",x)
#define DPRS(x) fprintf(stderr,"<"#x"=%s>\n",x)
#define DPRMSG(x) fprintf(stderr,#x"\n")
#define DPRPII(x) fprintf(stderr,"<"#x"=(%d,%d)>\n",x.F,x.S)
typedef pair<int,int> pii;
// }}}
// #functions {{{
pii operator+(const pii &a,const pii &b) { return MP(a.F+b.F,a.S+b.S); }
pii operator-(const pii &a,const pii &b) { return MP(a.F-b.F,a.S-b.S); }
pii& operator+=(pii &a,const pii &b) { a.F+=b.F; a.S+=b.S; return a; }
pii& operator-=(pii &a,const pii &b) { a.F-=b.F; a.S-=b.S; return a; }
template <class T,class U>
bool cmp_second(const pair<T,U> &a,const pair<T,U> &b) { return a.second<b.second; }
template <class T>
T gcd(T a,T b) { a=abs(a); b=abs(b); while(b) { T t=b; b=a%b; a=t; } return a; }
template <class T>
pair<T,T> ext_gcd(T a,T b) {
   T a0=1,a1=0,b0=0,b1=1;
   if(a<0) { a=-a; a0=-1; }
   if(b<0) { b=-b; b1=-1; }
   while(b) {
      T t,q=a/b;
      t=b; b=a-b*q; a=t;
      t=b0; b0=a0-b0*q; a0=t;
      t=b1; b1=a1-b1*q; a1=t;
   }
   return MP(a0,a1);
}
inline int sg(int x) { return x?(x>0?1:-1):0; }
inline string concatenate_strings(vector<string> ss) {
   string s;
   for(int i=0;i<ss.size();i++)
      s+=ss[i];
   return s;
}
template <class T>
inline vector<T> read_from_string(string s) {
   vector<T> ret; stringstream ss(s,stringstream::in);
   while(1) { T x; ss>>x; ret.push_back(x); if(ss.eof()) break; }
   return ret;
}
// }}}

#define MAXN 3050

class Coor {
    public:
        int x,y;
        Coor():x(0),y(0) { }
        Coor& operator-=(const Coor& b) {
            x-=b.x;
            y-=b.y;
            return *this;;
        }
        Coor operator-(const Coor &b) const {
            return Coor(*this)-=b;
        }
};
inline long long dot(Coor a,Coor b) { return (long long)a.x*b.x+(long long)a.y*b.y; }
inline long long dot(Coor o,Coor a,Coor b) { return dot(a-o,b-o); }
inline long long cross(Coor a,Coor b) { return (long long)a.x*b.y-(long long)a.y*b.x; }
inline long long cross(Coor o,Coor a,Coor b) { return cross(a-o,b-o); }

int n;
Coor pt[MAXN];
int sol[MAXN];

Coor o;
Coor qt[MAXN*2];

inline int quad(Coor p) {
    if(p.x>0&&p.y>=0) return 1;
    if(p.x<=0&&p.y>0) return 2;
    if(p.x<0&&p.y<=0) return 3;
    if(p.x>=0&&p.y<0) return 4;
    return 0;
}

bool cmp(Coor a,Coor b) {
    int qa=quad(a-o);
    int qb=quad(b-o);
    if(qa!=qb) return qa<qb;
    return cross(o,a,b)>0;
}

inline int sub() {
    sort(qt,qt+n-1,cmp);
    for(int i=0;i<n-1;i++)
        qt[i+n-1]=qt[i];
    int maxp=0;
    for(int i=0,j=0;i<n-1;i++) {
        while(j<i+n-1&&cross(o,qt[i],qt[j])>=0) j++;
        maxp=max(j-i,maxp);
    }
    return n-1-maxp;
}

void solve() {
    for(int i=0;i<n;i++) {
        o=pt[i];
        int t=0;
        for(int j=0;j<n;j++)
            if(i!=j) qt[t++]=pt[j];
        sol[i]=sub();
    }
}

int main(void)
{
    int t;
    RI(t);
    for(int cas=1; cas<=t; cas++) {
        RI(n);
        for(int i=0;i<n;i++)
            RI(pt[i].x,pt[i].y);
        solve();
        printf("Case #%d:\n",cas);
        for(int i=0;i<n;i++)
            printf("%d\n",sol[i]);
    }
    return 0;
}

// vim: fdm=marker:commentstring=//\ %s:nowrap:autoread
