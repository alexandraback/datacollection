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

int a[1005];

int main(){
  SHOW_TIME
  SF(A-large.in);
  PF
  int T;
  S(T);
  while(T--){
    int n;
    S(n);
    FR(i,n)S(a[i]);
    int r1=0,r2=0;
    FR(i,n-1){
      r1+=max(0,a[i]-a[i+1]);
    }
    int rt=0;
    FR(i,n-1){
      rt=max(rt,a[i]-a[i+1]);
    }
    FR(i,n-1){
      r2+=min(a[i],rt);
    }
    printf("Case #%d: %d %d\n",++kase,r1,r2);
  }
}

/*********Risoft corporation all rights reserved*********/
/**************Template V2.16 build 20150415*************/
