#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int n,m,l;
int vis[20];
int c[20][20];
int ans;

void put(int p){
    int x=p/m,y=p%m;
    c[x][y]=1;
}

void calc(){
    int i,j;
    memset(c,0,sizeof(c));
    for(i=0;i<n*m;i++){
        if(vis[i]){
            put(i);
        }
    }
    int cnt=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<m;j++){
            if(c[i][j]&&c[i][j+1]) cnt++;
            if(c[i][j]&&c[i+1][j]) cnt++;
        }
    }
    for(i=0;i<m;i++){
        if(c[n-1][i]&&c[n-1][i+1]) cnt++;
    }
    ans=min(ans,cnt);
}

int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int T,ca=0;
    int i,j;
    scanf("%d",&T);
    while(T--){
        ca++;
        scanf("%d%d%d",&n,&m,&l);
        memset(vis,0,sizeof(vis));
        ans=n*m*4;
        int w=n*m;
        for(int s=0;s<(1<<w);s++){
            int cnt=0;
            memset(vis,0,sizeof(vis));
            for(i=0;i<w;i++){
                if(s&(1<<i)){
                    cnt++;
                    vis[i]=1;
                }
            }
            if(cnt==l){
                calc();
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
