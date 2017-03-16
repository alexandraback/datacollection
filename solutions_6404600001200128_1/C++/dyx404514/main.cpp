#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define maxn 100010
using namespace std;
int a[maxn];
int main(){
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

        int ans1=0,ans2=0;
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i])
            ans1+=a[i-1]-a[i];
        }
        int eat=0;
        for(int i=1;i<n;i++){
            eat=max(eat,a[i-1]-a[i]);
        }
        for(int i=1;i<n;i++){

            ans2+=min(eat,a[i-1]);
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
