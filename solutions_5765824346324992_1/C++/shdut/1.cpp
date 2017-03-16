#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define ull long long
#define inf 1000000007
#define mod 1000000007
#define DBG(x) cerr<<#x<<"="<<x<<"\n";
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define N 10005

int m,n,a[1010];
bool cal(ll t){
    ll ans=0;
    for(int i=0;i<m;i++){
        ans+=(t+a[i]-1)/a[i];
    }
    if(ans>=n)return 1;
    return 0;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,ca=0;
    
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)scanf("%d",&a[i]);
        ll l=0,r=(1e14)+1;
        while(l<=r){
            ll t=(l+r)/2;
            if(cal(t))r=t-1;
            else l=t+1;
        }
        //DBG(r)
        ll t=r;int ans=-1;
        //DBG(t)
        for(i=0;i<m;i++){
            if(n<=1){
                ans=i+1;break;
            }
            n-=(t+a[i]-1)/a[i];
        }
        //DBG(n)
        if(ans!=-1){
            printf("%d\n",ans);
            continue;
        }
        for(i=0;i<m;i++){
            if(t%a[i]==0){
                if(n==1){
                    ans=i+1;break;
                }
                n--;
            }
        }
        if(ans==-1){
            //DBG("err")
            DBG(ca)
        }
       // assert(n>=0&&n<m);
       printf("%d\n",ans);
    }
    return 0;
}