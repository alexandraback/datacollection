#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<set>
#define clr(x,y) memset(x,y,sizeof(x))
#define ll unsigned long long
using namespace std;

int n,m;
int vis[20],a[20],b[20];

int main(){
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        clr(vis,0);
        scanf("%d",&n);
        for(int i=0;i<16;i++) scanf("%d",&a[i]);
        n--;
        scanf("%d",&m);
        m--;
        for(int i=0;i<16;i++) scanf("%d",&b[i]);
        for(int i=n*4;i<n*4+4;i++) vis[a[i]]++;
        for(int i=m*4;i<m*4+4;i++) vis[b[i]]++;
        int res=0;
        int number=-1;
        for(int i=1;i<=16;i++){
            if(vis[i]==2){
                res++;
                number=i;
            }
        }
        printf("Case #%d: ",++cas);
        if(res==0) puts("Volunteer cheated!");
        else if(res==1) printf("%d\n",number);
        else puts("Bad magician!");
    }
    return 0;
}
