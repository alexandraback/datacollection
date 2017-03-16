#include<bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
int ans,r,c,n;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
bool board[20][20]={};
void dfs(int x,int y,int cnt){
    if(cnt==n){
        int tot=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(!board[i][j])continue;
                for(int k=0;k<4;k++){
                    int xx=i+dx[k],yy=j+dy[k];
                    if(board[xx][yy])tot++;
                }
            }
        }
        if(tot<ans)ans=tot;
    }
    if(x==r+1)return;

    if(y==c){
        dfs(x+1,1,cnt);

        board[x][y]=1;
        dfs(x+1,1,cnt+1);
        board[x][y]=0;
    }
    else{
        dfs(x,y+1,cnt);

        board[x][y]=1;
        dfs(x,y+1,cnt+1);
        board[x][y]=0;
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&r,&c,&n);
        ans=INF;
        dfs(1,1,0);

        printf("Case #%d: %d\n",++Case,ans/2);
    }
    return 0;
}
