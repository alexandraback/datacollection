/*********************************
                                *
                               *
                              *
                             *
                            *
                           *
                          *
                         *
                        *
                       *
                      *
                     *
                    *
                   *
                  *
                 *
                *
               *
              *
             *
            *
           *
          *
         *
        *
       *
      *
     *
    * ***   ***   ***    ***
   * *   *  *  *  *  *  *   *
  *  *   *  ***   ***   *   *
 *    ***   *  *  *  *   ***
**********************************/



#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9
#define Afridi 0

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
#define NL printf("\n")
#define SP printf(" ")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 10000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL n,b,ara[Max],ANS;

struct node
{
    LL l,h;
};

void Find(LL x)
{
    bool work[1005];
    mem(work,0);
    LL i,tot = 0,w = 0;
    rep(i,b)
    {
        LL my = x/ara[i];
        if(x % ara[i])
        {
            my++;
            w++;
            work[i] = 1;
        }
        tot += my;
    }
    LL pos = n - tot,cnt = 0;
    rep(i,b)
    {
        if(work[i] == 0)cnt++;
        if(cnt == pos)
        {
            ANS = i;
            break;
        }
    }
}

node go(LL x)
{
    LL i,tot = 0,w = 0;
    rep(i,b)
    {
        LL my = x/ara[i];
        if(x % ara[i])
        {
            my++;
            w++;
        }
        tot += my;
    }
    node tmp;
    tmp.l = tot;
    tmp.h = tot + b - w;
    return tmp;
}

void bin()
{
    LL low = 0,high = 1e15,mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        node my = go(mid);
        if(my.l < n && n <= my.h)
        {
            Find(mid);
            break;
        }
        if(my.l >= n)
        {
            high = mid-1;
        }
        else low = mid+1;
    }
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("Bsmallout.txt","w",stdout);
    LL t,T,i;
    sl(T);
    rep(t,T)
    {
        sll(b,n);
        rep(i,b)sl(ara[i]);
        bin();
        printf("Case #%lld: %lld\n",t,ANS);
    }
    return Afridi;
}
