#include<bits/stdc++.h>
using namespace std;
long long int s[1005];
int main(){
    int C=0,t,n,m,i,j,x,y;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);

    while(t--){
        long long int ans1=0,ans2=0,ma=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&s[i]);
            if(i) ma=max(ma,s[i-1]-s[i]);
        }
        for(i=0;i<n;i++){
            if(i && s[i]<s[i-1]) ans1+=s[i-1]-s[i];
            if(i<n-1) ans2+=min(s[i],ma);
        }
        printf("Case #%d: %lld %lld\n",++C,ans1,ans2);
    }
}
