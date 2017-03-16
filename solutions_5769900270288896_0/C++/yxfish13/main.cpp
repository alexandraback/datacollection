//
//  main.cpp
//  prob_2
//
//  Created by yxfish13 on 15/5/3.
//  Copyright (c) 2015年 x-yu13. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int R,C,ans,N;
bool vis[100][100];
void dfs(int x,int y,int N){
    if (x==R+1){
        if (N) return;
        int anst=0;
        for (int i=1;i<=R;i++)
            for (int j=1;j<=C;j++)
            if (vis[i][j]){
                if (i>1&&vis[i-1][j]) anst++;
                if (j>1&&vis[i][j-1]) anst++;
            }
        ans=min(ans,anst);
        return;
    }
    if (y==C+1) dfs(x+1,1,N);
    else{
        vis[x][y]=true;dfs(x,y+1,N-1);
        vis[x][y]=false;dfs(x,y+1,N);
    }
}
int main(int argc, const char * argv[]) {
    freopen("a.txt","r",stdin);
    freopen("b1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int datanum=1;datanum<=T;datanum++){
        cin>>R>>C>>N;
        printf("Case #%d: ",datanum);
        ans=1000;
        dfs(1,1,N);
        printf("%d\n",ans);
    }
    return 0;
}
