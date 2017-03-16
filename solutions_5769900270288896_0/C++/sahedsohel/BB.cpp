/***************************************
    codeforces = topcoder = sahedsohel
    IIT,Jahangirnagar University(42)
****************************************/
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define inf (INT_MAX/10)
#define linf (LLONG_MAX/10LL)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define pb push_back
#define pp pop_back()
#define aov(a) a.begin(),a.end()
#define mpr make_pair
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair< int , int >
#define pll pair< ll , ll >
#define pcs(a) printf("Case %d: ", a)
#define nl puts("")
#define dbg(x) cout<<#x<<" : "<<x<<endl

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);}return (T)ret;}

int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
int toLlint(string s){long long int sm;stringstream ss(s);ss>>sm;return sm;}


///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction
///const double eps=1e-6;
///int dx[]={0,1,0,-1};
///int dy[]={1,0,-1,0}; //4 Direction

/*****************************************************************/
///////////////////////   GET SET GO    ///////////////////////////
/*****************************************************************/

#define M 1000006
#define MX 100005
#define MD 1000000007LL

int r,c,n,cs;

int p[16][(1<<16)][20];
int bl[16][(1<<16)][20];

int dp(int i,int msk,int x)
{
    if(x==0)
        return 0;
    if(i==-1)
        return inf;

    int &pr=p[i][msk][x];
    if(bl[i][msk][x]==cs)
        return pr;
    bl[i][msk][x]=cs;
    pr=inf;

    int mx,j,q,s,l,k;
    bool ls;
    mx=(1<<c);
    for(j=0;j<mx;j++)
    {
//        if(k<=x)
//        {
            q=0;
            s=0;
            l=0;
            k=0;
            if( (msk&(1<<l))&&(j&(1<<l)) )
                s++;
            ls=((j&(1<<l))>0);
            k+=ls;
            fl(1,l,c)
            {
                if( (msk&(1<<l))&&(j&(1<<l)) )
                    s++;
                if( ls&&(j&(1<<l)) )
                    s++;
                ls=((j&(1<<l))>0);
                k+=ls;
            }
            if(k<=x)
            pr=min(pr, dp(i-1,j,x-k)+s );
//        }
    }
    return pr;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,i,j,k;
    cs=1;

    sc(t);
    while(t--)
    {
        sc3(r,c,n);
        printf("Case #%d: %d\n",cs++,dp(r-1,0,n));
    }

    return 0;
}



