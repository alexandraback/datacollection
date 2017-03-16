#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,t,m,a[2333333],n;

int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
for(int t=1;t<=T;t++){
    scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int maxv=0,ans1=0,ans2=0;
    for(int i=2;i<=n;i++)if(a[i]<a[i-1])ans1+=a[i-1]-a[i];
    for(int i=2;i<=n;i++)if(a[i]<a[i-1])maxv=max(maxv,a[i-1]-a[i]);
    for(int i=1;i<=n-1;i++)ans2+=min(a[i],maxv);
    printf("Case #%d: %d %d\n",t,ans1,ans2);
}
    return 0;
}
