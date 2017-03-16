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
#define Max 100000
#define INF INT_MAX

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL n,ara[Max];

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("Asmallout.txt","w",stdout);
    LL t,T,i;
    sl(T);
    rep(t,T)
    {
        sl(n);
        rep(i,n)sl(ara[i]);
        LL prev = 0,a = 0;
        rep(i,n)
        {
            if(ara[i] < prev)
            {
                a += (prev - ara[i]);
            }
            prev = ara[i];
        }
        LL b = 0,mx = 0;
        rep(i,n-1)
        {
            mx = max(mx,ara[i] - ara[i+1]);
        }
        rep(i,n-1)
        {
            b += min(mx,ara[i]);
        }
        printf("Case #%lld: %lld %lld\n",t,a,b);
    }
    return Afridi;
}
