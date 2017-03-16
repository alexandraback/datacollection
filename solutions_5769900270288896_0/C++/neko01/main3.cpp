/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define clr(a) memset(a,0,sizeof a)
#define clr1(a) memset(a,-1,sizeof a)
#define dbg(a) printf("%d\n",a)
typedef pair<int,int> pp;
const double eps=1e-9;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const LL inf=(((LL)1)<<61)+5;
int a[20][20];
int r,c;
int dir[4][2]={1,0,0,1};
bool inmap(int x,int y){
    return x>=0&&y>=0&&x<r&&y<c;
}
int gao()
{
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]==1)
            {
                for(int k=0;k<2;k++){
                    int xx=i+dir[k][0];
                    int yy=j+dir[k][1];
                    if(a[xx][yy]==1)
                        ans++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int t,n,cnt=0;
        freopen("B-small-attempt3.in" , "r" , stdin);
    freopen("B-small-attempt3.out" , "w" , stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r,&c,&n);
        int m=r*c;
        int ans=INF;
        for(int i=0;i<(1<<m);i++){
            int sum=0;
            for(int j=0;j<m;j++){
                if(i&(1<<j))
                    sum++;
            }
            if(sum==n){
                clr(a);
                for(int j=0;j<m;j++){
                    if(i&(1<<j)){
                        int x=j/c;
                        int y=j%c;
                        a[x][y]=1;
                    }
                }
                ans=min(ans,gao());
            }
        }
        printf("Case #%d: %d\n",++cnt,ans);
    }
    return 0;
}
