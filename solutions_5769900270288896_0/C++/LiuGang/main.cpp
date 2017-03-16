#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int R , C , N, ans ;

bool vis[20][20];

int cal() {
    int ret = 0 ;
    for(int i=0; i<R; i++) {
        for(int  j=0; j<C; j++) {
            if(vis[i][j] && vis[i][j+1]) ret ++ ;
            if(vis[i][j] && vis[i+1][j]) ret ++ ;
        }
    }
    return ret ;
}

void dfs(int u , int res) {
    if(res == 0) {
        ans = min(ans , cal()) ;
        return ;
    }
    if(u >= R*C) return ;
    for(int i=u; i<R*C; i++) {
        int x = i/C , y = i%C ;
        vis[x][y] = true ;
        dfs(i+1, res-1) ;
        vis[x][y] = false ;
    }
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout) ;

    int T, cas = 1;
    scanf("%d", &T) ;
    while(T--) {
        memset(vis , 0 , sizeof(vis)) ;
        scanf("%d%d%d", &R, &C, &N) ;
        ans = R * C * 4 ;
        dfs(0 , N) ;
        printf("Case #%d: %d\n", cas++ , ans) ;
    }
    return 0;
}
