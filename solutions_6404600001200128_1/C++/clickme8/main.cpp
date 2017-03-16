#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
int a[1005];
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int t,tt=0;
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        tt++;
        int n,p,maxx=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&p);
            a[p]++;
            maxx=max(maxx,p);
        }
        int ans=maxx;
        int num,cut=0;
        for(int i=1000;i>0;i--){
            if(i==1){
                ans=min(ans,cut+1);break;
            }
            if(a[i]){
                ans=min(ans,i+cut);
                cut+=a[i];
                if(i%2){
                    a[i/2]+=a[i];
                    a[(i+1)/2]+=a[i];
                }
                else
                    a[i/2]+=2*a[i];
            }
        }

        printf("Case #%d: %d \n",tt,ans);
    }
    return 0;
}
