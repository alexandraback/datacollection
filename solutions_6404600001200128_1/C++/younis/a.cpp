#include<cstdio>
int m[10001];
int main(){
    freopen("D://1A/A-large.in","r",stdin);
    freopen("D://1A/x.out","w",stdout);
    int t;scanf("%d",&t);
    int n,i;
    int ans1,ans2,rat;
    for(int cas=1;cas<=t;cas++){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&m[i]);
        ans1=ans2=rat=0;
        for(i=1;i<n;i++)
            if(m[i]<m[i-1]){
                ans1+=m[i-1]-m[i];
                if(m[i-1]-m[i]>rat)rat=m[i-1]-m[i];
            }
        for(i=0;i<n-1;i++){
            if(m[i]>rat)ans2+=rat;
            else ans2+=m[i];
        }
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}
