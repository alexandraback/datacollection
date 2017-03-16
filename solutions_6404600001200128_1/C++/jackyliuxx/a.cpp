#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int n,a[1024];
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int ans1=0,ans2=0,mx2=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                ans1+=a[i-1]-a[i];
                mx2=max(mx2,a[i-1]-a[i]);
            }
        }
        for(int i=0;i<n-1;i++){
            if(a[i]<mx2)
                ans2+=a[i];
            else
                ans2+=mx2;
        }
        printf("Case #%d: %d %d\n",tk++,ans1,ans2);
    }
}

