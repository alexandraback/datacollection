#include<stdio.h>
int x[20][20],r,c,n,placed,bestans = 999999999;
void dfs(int curr,int curc){
    if(placed==n){
        //printf("%d %d %d %d\n",curr,curc,placed,bestans);
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j>0){
                    if(x[i][j] && x[i][j-1]) count++;
                }
                if(i>0){
                    if(x[i][j] && x[i-1][j]) count++;
                }
            }
        }
        if(count < bestans) bestans = count;
        return;
    }
    if(curr>=r) return;
    for(int i=curr;i<r;i++){
        int j = 0;
        if(i==curr) j = curc;
        for(;j<c;j++){
            int remains = (r-i-1)*c + c-j;
            if(remains < n-placed) return;
            x[i][j] = 1;
            placed ++;
            int nexti = i, nextj = j+1;
            if(nextj == c){
                nextj = 0;
                nexti++;
            }
            dfs(nexti,nextj);
            x[i][j] = 0;
            placed--;
            dfs(nexti,nextj);
        }
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt = 1 ; tt <= T; tt++){
        scanf("%d%d%d",&r,&c,&n);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                x[i][j] = 0;
            }
        }
        placed = 0;
        bestans = 999999999;
        dfs(0,0);
        printf("Case #%d: %d\n",tt,bestans);
    }
}
