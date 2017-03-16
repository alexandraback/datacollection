#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <cctype>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <climits>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

int setb(int n,int pos)
{
    return n=n | (1 << pos);
}

int resb(int n,int pos)
{
    return n=n & ~(1 << pos);
}

bool check(int n,int pos)
{
    return (bool)(n & (1 << pos));
}

LL r,c,nn;

LL go(LL mask,LL taken)
{
    LL i,j,k = 0,cnt = 0,ara[20][20];
    //if(mask == 495)printf("ldfdfdsfdsfglh\n");
    if(taken != nn)return INF;
    rep(i,r)
    {
        rep(j,c)
        {
            ara[i][j] = check(mask,k++);
            if(ara[i][j])
            {
                if(i-1 > 0 && ara[i-1][j])cnt++;
                if(j-1 > 0 && ara[i][j-1])cnt++;
            }
        }
    }
    //if(mask == 495)printf("%lld  lglh\n",cnt);
    return cnt;
}

LL visit[(1 << 16) + 10],dp[(1 << 16) + 10],CS;

LL fun(LL pos,LL mask,LL taken)
{
    if(pos == r*c)return go(mask,taken);

    if(visit[mask] == CS)return dp[mask];
    LL mn = INF,i,my;
    my = fun(pos+1,setb(mask,pos),taken+1);
    mn = min(mn,my);
    my = fun(pos+1,mask,taken);
    mn = min(mn,my);

    visit[mask] = CS;
    return dp[mask] = mn;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("outBBsmall.txt","w",stdout);
    LL t,T;
    sl(T);
    rep(t,T)
    {
        slll(r,c,nn);
        CS++;
        LL ans = fun(0,0,0);
        printf("Case #%lld: %lld\n",t,ans);
    }
    return 0;
}


