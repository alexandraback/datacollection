#include    <bits/stdc++.h>
#define     SF              scanf
#define     PF              printf
#define     S1(a)           SF("%d",&a);
#define     S2(a,b)         SF("%d%d",&a,&b);
#define     S3(a,b,c)       SF("%d%d%d",&a,&b,&c);
#define     S4(a,b,c,d)     SF("%d%d%d%d",&a,&b,&c,&d);
#define     S5(a,b,c,d,e)   SF("%d%d%d%d%d",&a,&b,&c,&d,&e);
#define     P1(a)           PF("%d ",a);
#define     P2(a,b)         PF("%d %d ",a,b);
#define     P3(a,b,c)       PF("%d %d %d ",a,b,c);
#define     P4(a,b,c,d)     PF("%d %d %d %d ",a,b,c,d);
#define     P5(a,b,c,d,e)   PF("%d %d %d %d %d ",a,b,c,d,e);
#define     SL1(a)          SF("%lld",&a);
#define     SL2(a,b)        SF("%lld%lld",&a,&b);
#define     SL3(a,b,c)      SF("%lld%lld%lld",&a,&b,&c);
#define     SL4(a,b,c,d)    SF("%lld%lld%lld%lld",&a,&b,&c,&d);
#define     SL5(a,b,c,d,e)  SF("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
#define     PL1(a)          PF("%lld ",a);
#define     PL2(a,b)        PF("%lld %lld ",a,b);
#define     PL3(a,b,c)      PF("%lld %lld %lld ",a,b,c);
#define     PL4(a,b,c,d)    PF("%lld %lld %lld %lld ",a,b,c,d);
#define     PL5(a,b,c,d,e)  PF("%lld %lld %lld %lld %lld ",a,b,c,d,e);
#define     CHK(a)          cerr << #a << "=" << a << " ";
#define     C1(a)           cerr << "{ "; CHK(a) cerr << "} ";
#define     C2(a,b)         cerr << "{ "; CHK(a) CHK(b) cerr << "} ";
#define     C3(a,b,c)       cerr << "{ "; CHK(a) CHK(b) CHK(c) cerr << "} ";
#define     C4(a,b,c,d)     cerr << "{ "; CHK(a) CHK(b) CHK(c) CHK(d) cerr << "} ";
#define     C5(a,b,c,d,e)   cerr << "{ "; CHK(a) CHK(b) CHK(c) CHK(d) CHK(e) cerr << "} ";
#define     EL              PF("\n");
#define     LINE            PF("--------------------\n");
#define     STR(a)          #a
#define     MSET(a,b)       memset(a,b,sizeof(a));
#define     LL              long long
#define     BO              bool operator
#define     MP              make_pair
#define     IB              push_back
#define     IF              push_front
#define     DB              pop_back()
#define     DF              pop_front()
#define     LB              lower_bound
#define     UB              upper_bound
#define     PII             pair<int,int>
#define     PLL             pair<LL,LL>
#define     MAXPQ(T)        priority_queue <T>
#define     MINPQ(T)        priority_queue <T,vector<T>,greater<T>>
#define     FRI(a)          freopen(a,"r",stdin);
#define     FRO(a)          freopen(a,"w",stdout);
#define     _1              first
#define     _2              second
#define     MOD             1000000009
#define     INF             2000000000
#define     PI              3.141592653589793
template<typename A, typename B> inline bool mins(A &x,B y){return (x>y)?(x=y,1):0;}
template<typename A, typename B> inline bool maxs(A &x,B y){return (x<y)?(x=y,1):0;}
using namespace std;

int t,r,c,n,x,y,ans,a[20][20],j,k;

int main(){
    FRI("B-small-attempt1.in")
    //FRI("B-large.in")
    FRO("out2.txt")
    S1(t)
    for(int tc=1;tc<=t;tc++){
        S3(r,c,n)
        ans=INF;
        for(int i=0;i<=(1<<(r*c))-1;i++){
            x=0;
            y=i;
            while(y>0){
                if(y%2==1){
                    x++;
                }
                y/=2;
            }
            if(x==n){//C1(x);
                y=i;
                for(j=1;j<=r;j++){
                    for(k=1;k<=c;k++){
                        a[j][k]=y%2;
                        y/=2;
                    }
                }
                x=0;
                for(j=1;j<=r;j++){
                    for(k=1;k<=c;k++){
                        if(a[j][k]==1){
                            if(a[j+1][k]==1 and j!=r){
                                x++;
                            }
                            if(a[j][k+1]==1 and k!=c){
                                x++;
                            }
                        }
                    }
                }
                if(i==32447){
                    C1(x);
                }
                ans=min(ans,x);
            }
        }
        PF("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
