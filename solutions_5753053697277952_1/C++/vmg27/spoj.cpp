#include    <bits/stdc++.h>

#define     M_PI            3.14159265358979323846
#define     mod             1000000007
#define     inf             1000000000000000000
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     ll              long long
#define     pii             pair<int,int>
#define     pli             pair<ll,int>
#define     pil             pair<int,ll>
#define     pll             pair<ll,ll>
#define     si(t)           scanf("%d",&t)
#define     sii(m,n)        scanf("%d %d",&m,&n);
#define     sl(t)           scanf("%lld",&t)
#define     rep(i,n)        for(int i=0;i<n;i++)
#define     REP(i,a,b)      for(int i=a;i<=b;i++)
#define     RREP(i,a,b)     for(int i=a;i>=b;i--)
#define     N               100005

using namespace std;

pii arr[30];

int chk(int n){
    if(arr[n-1].F == 1 && arr[n-2].F == 1 && (n-3>=0 && arr[n-3].F == 1) ) return 1;
    return 0;
}

int main(){
    int t; si(t);
    REP(T,1,t){
        int n; si(n);
        rep(i,n) si(arr[i].F);
        rep(i,n) arr[i].S = i;
        sort(arr,arr+n);
        printf("Case #%d: ",T);
        while(arr[n-1].F != 0){
            if(chk(n)){
                printf("%c ",arr[n-1].S+'A');
                arr[n-1].F = 0;
            }
            else{
                printf("%c%c ",arr[n-1].S+'A',arr[n-2].S+'A');
                arr[n-1].F--;
                arr[n-2].F--;
            }
            sort(arr,arr+n);
        }
        printf("\n");
    }
    return 0;   
}

