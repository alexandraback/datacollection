#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> ans;
int s1[4][4],s2[4][4];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,i,j,x,y,c=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&x);
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&s1[i][j]);
        scanf("%d",&y);
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                scanf("%d",&s2[i][j]);
        ans.clear();
        x--,y--;
        for(i=0;i<4;i++){
            int flag=0;
            for(j=0;j<4;j++)
                if(s1[x][i]==s2[y][j])
                    flag=1;
            if(flag) ans.push_back(s1[x][i]);
        }
        printf("Case #%d: ",++c);
        if(ans.size()==1) printf("%d\n",ans[0]);
        else if(ans.size()>1) puts("Bad magician!");
        else puts("Volunteer cheated!");
    }
}
