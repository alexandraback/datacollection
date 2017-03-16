#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef long long ll;
using namespace std;

ll ba[1005];
ll ban[1005];

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}


int main(){
    freopen("B-small-attempt1 (1).in","r",stdin);
    freopen("outputB1.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int co=1;co<=t;co++){
        ll b,n;
        scanf("%lld %lld",&b,&n);
        ll gad = 1;

        for(int g=0;g<b;g++){
            scanf("%lld",&ba[g]);
            gad = gad * ba[g] / gcd(gad,ba[g]);
        }
        //cout<<gad<<endl;
        ll tnum=0;
        ll ans=100005;
        ll td=100005;
        ll gcda;
        gcda = ba[0];

        for(int g=0;g<b;g++){
            ban[g] = gad/ba[g];
            tnum += ban[g];
            gcda = gcd(ba[g],gcda);
        }
        n = n%tnum;
        if(n==0){
            for(int g=0;g<b;g++){
                if(ba[g]<=td){
                    ans = g;
                    td = ba[g];
                }
            }
        }
        else{
            ll t=0;
            while(n>=0){
                for(int g=0;g<b;g++){
                    if(t==0 || t%ba[g]==0){
                        n--;
                        if(n==0){
                            ans = g;
                            break;
                        }
                    }
                }
                t+=gcda;
            }

        }
        printf("Case #%d: %lld\n",co,ans+1);
    }

}
