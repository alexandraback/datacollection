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

int a[N];
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,ca=0,n,m;
    
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        int s=a[0],ans=0;
        for(i=1;i<n;i++){
            if(a[i]==s)continue;
            if(a[i]>s)s=a[i];
            else ans+=s-a[i],s=a[i];
        }
       printf("%d ",ans);
       int ok=1,mx=0;s=a[0];
       for(i=1;i<n;i++){
            if(a[i-1]>a[i])mx=max(mx,a[i-1]-a[i]),ok=0;
            s=max(s,a[i]);
       }
       if(ok)puts("0");
       else{
            int l=mx,r=s;ans=inf;
            while(l<=r){
                m=(l+r)>>1;
                s=a[0];int res=0;
                for(i=1;i<n;i++){
                    if(s>=m)res+=m,s-=m;
                    else res+=s,s=0;
                    if(s>a[i]){
                        l=m+1;
                        break;
                    }
                    s=a[i];
                }
                if(i==n)ans=min(res,ans),r=m-1;
            }
            printf("%d\n",ans);
       }
    }
    return 0;
}