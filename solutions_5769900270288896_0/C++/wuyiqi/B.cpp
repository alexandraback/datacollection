#include <bits/stdc++.h>
using namespace std;
int mat[20][20];
int ret;
void dfs(int x,int y,int r,int c,int n,int cost)
{
 //   printf("cost=%d\n", cost);
    if(n == 0) {
        /*
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                printf("%d ", mat[i][j]);
            }
            puts("");
        }*/
        if(ret == -1 || cost < ret) {
            ret = cost;
        }
        return ;
    }
    if(y == c + 1) {
        y = 1;
        x++;
    }
    if(x == r + 1) {
        if(n == 0) {
        if(ret == -1 || cost < ret) {
            ret = cost;
        }
        }
        return ;
    }
    mat[x][y] = 1; 
    dfs(x, y + 1, r, c, n - 1, cost+mat[x-1][y]+mat[x][y-1]);
    mat[x][y] = 0;
    dfs(x, y + 1, r, c, n , cost);
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int R, C, N;
    int ca = 1;
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(mat,0,sizeof(mat));
        scanf("%d%d%d", &R, &C, &N);
        ret = -1;
        dfs(1, 1, R, C, N, 0);
        printf("Case #%d: %d\n",ca++,ret);
    }
    return 0;
}
