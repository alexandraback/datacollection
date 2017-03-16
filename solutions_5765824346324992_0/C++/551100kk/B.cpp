#include<bits/stdc++.h>
using namespace std;
long long int s[1005],L,R,M;
int main(){
    int C=0,t,n,m,i,j,x,y;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%lld",&s[i]);
        }
        L=-1,R=1000000000000000;
        while(L+1!=R){
            M=(L+R)/2;
            long long int tmp=0;
            for(i=0;i<n;i++){
                tmp+=M/s[i]+1;
            }
            if(tmp>=m) R=M;
            else L=M;
        }
        long long int tmp=0;
        for(i=0;i<n;i++){
            tmp+=(R-1)/s[i]+1;
        }
        long long int res=m-tmp,add=0,ans;
        for(i=0;i<n;i++){
            if(R%s[i]==0){
                add++;
                if(add==res){
                    ans=i;
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n",++C,ans+1);
    }
}
