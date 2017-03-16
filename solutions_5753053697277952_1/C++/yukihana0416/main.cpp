#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define I64d_OJ

#ifdef I64d_OJ
#define LL __int64
#endif // I64d_OJ
#ifndef I64d_OJ
#define LL long long
#endif // I64d_OJ

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define MK(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;
typedef vector<int> vi;

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T >
inline void swapt(T &a,T &b) {T c=a;a=b;b=c;}
template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T >
inline T maxt(T a,T b) {if(a<b) return b; else return a;}
template< typename T >
inline T mint(T a,T b) {if(a<b) return a; else return b;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) 0x3f3f3f3f3f3f3f3f;
const int SINF=(uint) ~0U>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e2+20;
const int maxm=(int) 1000+15;

LL gcd(LL a,LL b) {LL t; while(b) t=a%b, a=b, b=t; return absx(a);}
inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int cnt[26];

void work()
{
    int tc; read(tc);
    int T_T=0;
    while(tc--)
    {
        memset(cnt,0,sizeof(cnt));
        int n; read(n);
        for(int i=0;i<n;i++) read(cnt[i]);

        printf("Case #%d: ",++T_T);
        bool flag=1;
        while(flag)
        {
            int tt=0;
            for(int i=0;i<26;i++) tt+=cnt[i];
            if(tt==0) break;
            else if(tt==1)
            {
                int mx=0;
                for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
                printf(" %c",'A'+mx);
                break;
            }

            int mx=0;
            for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
            cnt[mx]--;
            tt--;
//            for(int i=0;i<26;i++) tt+=cnt[i]; cout <<" tt : " <<tt <<" " ;
            if(tt>2 || tt==1)
            {
//                cout <<"!" <<endl;
                int a=mx;
                for(int i=0;i<26;i++) if(cnt[i]>cnt[mx]) mx=i;
                cnt[mx]--;
                printf(" %c%c",'A'+mx,'A'+a);
            }
            else
            {
                printf(" %c",'A'+mx);
            }
        }
        puts("");
    }
}


//--------------end--------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
//freopen("in.txt","r",stdin);
freopen("A-large.in","r",stdin);
freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
