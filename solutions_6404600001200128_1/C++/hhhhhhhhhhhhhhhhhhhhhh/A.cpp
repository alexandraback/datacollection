#include<bits/stdc++.h>
using namespace std;

int a[2010];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ret1=0,ret2=0,mx=0;
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i])ret1+=(a[i-1]-a[i]);
            mx=max(mx,(a[i-1]-a[i]));
        }
        for(int i=1;i<n;i++){
            ret2+=min(mx,a[i-1]);
        }
        printf("Case #%d: %d %d\n",_,ret1,ret2);
    }
    return 0;
}
