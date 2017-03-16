#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

int r,c,n;
int ans[20][20][20];
int f[20][20];

void dfs(int x,int y){
    //printf("%d,%d\n",x,y);
    if(y>c){
        dfs(x+1,1);
        return;
    }
    if(x>r){
        static int tmp,n,i,j;
        tmp=0,n=0;
        for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            if(!f[i][j])continue;
            n++;
            tmp+=f[i-1][j]+f[i+1][j]+f[i][j-1]+f[i][j+1];
        }
        ans[r][c][n]=min(ans[r][c][n],tmp);
        return;
    }
    f[x][y]=1;
    dfs(x,y+1);
    f[x][y]=0;
    dfs(x,y+1);
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.ans","w",stdout);
    for(r=1;r<=16;r++)
    for(c=1;c*r<=16;c++){
        for(n=0;n<=r*c;n++)
            ans[r][c][n]=100000;
        dfs(1,1);
    }
    static int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        static int r,c,n;
        scanf("%d%d%d",&r,&c,&n);
        printf("Case #%d: %d\n",Cas,ans[r][c][n]/2);
    }
    return 0;
}
