#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int t,n,m;
int a[5][5],b[5][5];
int vis[20];
vector<int>ans;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&t);
    int ca=1;
    while(t--){
        memset(vis,0,sizeof(vis));
        ans.clear();
        scanf("%d",&n);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&a[i][j]);
                if(i==n-1){
                    vis[a[i][j]]++;
                }
            }
        }
        scanf("%d",&m);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d",&b[i][j]);
                if(i==m-1){
                    vis[b[i][j]]++;
                }
            }
        }
        for(int i=1;i<=16;i++){
            if(vis[i] == 2) ans.push_back(i);
        }
        printf("Case #%d: ",ca++);
        if(ans.size()==0) puts("Volunteer cheated!");
        else if(ans.size()>1) puts("Bad magician!");
        else printf("%d\n",ans[0]);
    }
    return 0;
}
