#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[1100];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;cin>>T;
    for (int tt=1;tt<=T;tt++){
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("Case #%d: ",tt);
        for (int i=2;i<=n;i++) if (a[i]<a[i-1])
            ans+=-a[i]+a[i-1];
        printf("%d ",ans);
        double rate=0;
        double ans2=0;
        for (int i=2;i<=n;i++) if (a[i]<a[i-1])
        rate=max(rate,(-a[i]+a[i-1])/10.0);
        for (int i=1;i<n;i++)
        ans2+=min(rate*10,a[i]*1.0);
        ans=ans2+0.0000000001;
        printf("%d\n",ans);
    }
}

