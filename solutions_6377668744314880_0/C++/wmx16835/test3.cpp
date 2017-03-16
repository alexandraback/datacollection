/**************Powered by Graphene Richards**************/
//{

#define FLOAT_PRECISION    "%.2f"
#define INT_64_MOD          "%I64d"
#define UNSIGNED_64_MOD     "%I64u"

//#pragma comment(linker,"/STACK:102400000,102400000")
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<complex>
#include<vector>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#define FAST_RW ios_base::sync_with_stdio(0),cin.tie(0);
#define IT(x) __typeof((x).begin())
#define DIT(x) __typeof((x).rbegin())
#define FS(i,a) for(ll i=0;a[i];i++)
#define FE(x,ctn) for(IT(ctn)x=(ctn).begin(),_en=(ctn).end();x!=_en;x++)
#define EF(x,ctn) for(DIT(ctn)x=(ctn).rbegin(),_en=(ctn).rend();x!=_en;x++)
#define FR(i,en) for(ll i=0,_en=(en);i<_en;i++)
#define FOR(i,en) for(ll i=1,_en=(en);i<=_en;i++)
#define RF(i,en) for(ll i=(en)-1;i>=0;i--)
#define ROF(i,en) for(ll i=(en);i>0;i--)
#define FFR(i,x,y) for(ll i=(x),_en=(y);i<=_en;i++)
#define RFF(i,x,y) for(ll i=(x),_en=(y);i>=_en;i--)
#define ll long long
#define ull unsigned long long
#define ui unsigned
#define lf long double
#define pc putchar
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define lb(x) (x&(-x))
#define sqr(x) (x)*(x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define clr(x) memset((x),0,sizeof(x))
#define ms(x,v) memset((x),(v),sizeof(x))
#define mc(x,y) memcpy((x),(y),sizeof(y))
#define NL puts("");
#define fin(x,c) ((c).find(x)!=(c).end())
using namespace std;

template<class T1,class T2,class T3>
bool _IN(T1 x,T2 y,T3 z){return x<=y&&x>=z||x<=z&&x>=y;}

ull gcd(ull a,ull b){if(!b)return a;while(b^=a^=b^=a%=b);return a;}

extern const ll mod;
ll ksm(ll a,ll b){
  ll res=1;
  a%=mod;
  for(;b;b>>=1){
    if(b&1)res=res*a%mod;
    a=a*a%mod;
  }
  return res;
}

#ifdef wmx16835
#include"wmx16835.h"
#else
#define LOG
#define TEL
#define PF
#define SF(...)
#define test(...) 0
#define TEST(...) 0
#define TRY(...)
#define PP
#define SHOW_TIME
#endif

bool S(char*a)  {return scanf("%s",a)==1;}
bool S(int&a)   {return scanf("%d",&a)==1;}
bool S(bool&a)  {return scanf("%d",&a)==1;}
bool S(ui&a)    {return scanf("%u",&a)==1;}
bool S(float&a) {return scanf("%f",&a)==1;}
bool S(double&a){return scanf("%lf",&a)==1;}
bool S(ll&a)    {return scanf(INT_64_MOD,&a)==1;}
bool S(ull&a)   {return scanf(UNSIGNED_64_MOD,&a)==1;}
bool S(lf&a)    {double res;if(scanf("%lf",&res)==-1)return 0;a=res;return 1;}
bool S(char&a)  {char res[2];if(scanf("%1s",res)==-1)return 0;a=*res;return 1;}
bool SL(char*a) {a[0]=0;while(gets(a)&&!a[0]);return a[0];}

void _P(const int&x)   {printf("%d",x);}
void _P(const bool&x)  {printf("%d",x);}
void _P(const ui&x)    {printf("%u",x);}
void _P(const char&x)  {printf("%c",x);}
void _P(const char*x)  {printf("%s",x);}
void _P(const string&x){printf("%s",x.c_str());}
void _P(const ll&x)    {printf(INT_64_MOD,x);}
void _P(const ull&x)   {printf(UNSIGNED_64_MOD,x);}
void _P(const float&x) {printf(FLOAT_PRECISION,x);}
void _P(const double&x){printf(FLOAT_PRECISION,x);}
void _P(const lf&x)    {printf(FLOAT_PRECISION,(double)x);}

template<class T1,class T2>
bool S(T1&a,T2&b){return S(a)+S(b)==2;}
template<class T1,class T2,class T3>
bool S(T1&a,T2&b,T3&c){return S(a)+S(b)+S(c)==3;}
template<class T1,class T2,class T3,class T4>
bool S(T1&a,T2&b,T3&c,T4&d){return S(a)+S(b)+S(c)+S(d)==4;}
template<class T1,class T2,class T3,class T4,class T5>
bool S(T1&a,T2&b,T3&c,T4&d,T5&e){return S(a)+S(b)+S(c)+S(d)+S(e)==5;}

template<class T1>
void P(const T1&a){_P(a);pc(' ');}
template<class T1,class T2>
void P(const T1&a,const T2&b){_P(a);pc(' ');_P(b);pc(' ');}
template<class T1>
void PN(const T1&a){_P(a);NL}
template<class T1,class T2>
void PN(const T1&a,const T2&b){_P(a);pc(' ');_P(b);NL}
template<class T1,class T2,class T3>
void PN(const T1&a,const T2&b,const T3&c){_P(a);pc(' ');_P(b);pc(' ');_P(c);NL}
template<class T1,class T2,class T3,class T4>
void PN(const T1&a,const T2&b,const T3&c,const T4&d){_P(a);pc(' ');_P(b);pc(' ');_P(c);pc(' ');_P(d);NL}
template<class T1,class T2,class T3,class T4,class T5>
void PN(const T1&a,const T2&b,const T3&c,const T4&d,const T5&e){_P(a);pc(' ');_P(b);pc(' ');_P(c);pc(' ');_P(d);pc(' ');_P(e);NL}

template<class T>
void PA(T*a,int n){
  bool f=1;
  FR(i,n){
    if(f)f=0;
    else pc(' ');
    _P(a[i]);
  }
  NL
}

template<class T>
void PA(const T&x){
  bool f=1;
  FE(it,x){
    if(f)f=0;
    else pc(' ');
    _P(*it);
  }
  NL
}

int kase;
const double pi=4*atan(1);
const double ep=1e-9;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3fll;
const ll mod=1000000007;
//}

struct point { ll x, y;
  void in(){
    S(x,y);
  }
  bool operator==(const point&r)const{
    return x==r.x&&y==r.y;
  }
  bool operator!=(const point&r)const{
    return x!=r.x||y!=r.y;
  }
};
bool mult(point sp, point ep, point op){
return (sp.x - op.x) * (ep.y - op.y)
>= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r){
return l.y < r.y || (l.y == r.y && l.x < r.x);
}
ll graham(point pnt[], ll n, point res[]){
ll i, len, k = 0, top = 1;
sort(pnt, pnt + n);
if (n == 0) return 0; res[0] = pnt[0];
if (n == 1) return 1; res[1] = pnt[1];
if (n == 2) return 2; res[2] = pnt[2];
for (i = 2; i < n; i++) {
while (top && mult(pnt[i], res[top], res[top-1]))
top--;
res[++top] = pnt[i];
}
len = top; res[++top] = pnt[n - 2];
for (i = n - 3; i >= 0; i--) {
while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
res[++top] = pnt[i];
}
  vector<point>xx;
  FR(i,top){
    point a=res[i],b=res[(i+1)%top];
    FR(j,n){
      if((pnt[j].x-a.x)*(b.y-a.y)==(pnt[j].y-a.y)*(b.x-a.x)&&pnt[j]!=a&&pnt[j]!=b)xx.pb(pnt[j]);
    }
  }
  FR(i,xx.size())res[top++]=xx[i];

return top; // 返回凸包中点的个数
}

ll res[20];
point a[20],b[20],c[20];

int main(){
  SHOW_TIME
  SF(C-small-attempt1.in);
  PF
  ll T;
  S(T);
  while(T--){
    ll n;
    S(n);
    ms(res,0x3f);
    FR(i,n)a[i].in();
    for(ll i=0;i<1<<n;i++){
      ll cn=0;
      for(ll j=0;j<n;j++){
        if(i>>j&1){
          b[cn++]=a[j];
        }
      }
      ll dn=graham(b,cn,c);
      FR(j,n){
        FR(k,dn){
          if(c[k]==a[j]){
            res[j]=min(res[j],n-cn);
          }
        }
      }
    }
    printf("Case #%d:\n",++kase);
    FR(i,n)PN(res[i]);
  }
}

/*********Risoft corporation all rights reserved*********/
/**************Template V2.16 build 20150415*************/
