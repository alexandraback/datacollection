#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int cas,ans1,ans2;
int a[1005];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,n,ans1,ans2,d;
    scanf("%d",&T);
    while(T--){
        ans1=ans2=d=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1])
                ans1+=a[i]-a[i+1];
            d=max(d,a[i]-a[i+1]);
        }
        for(int i=0;i<n-1;i++){
            if(a[i]>=d)
                ans2+=d;
            else
                ans2+=a[i];
        }
        printf("Case #%d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}

