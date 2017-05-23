//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define randin srand((unsigned int)time(NULL))
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define MAXN 100010
#define N
#define M 17
int dp[M][MAXN][M];
int stanum[MAXN],stat[MAXN];
int main(){
    //input;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    for(int i=0;i<1<<16;i++){
        int last=0;
        for(int j=0;j<16;j++){
            int t=(1<<j)&i?1:0;
            if(t) stanum[i]+=1;
            if(t==1&&last==1) stat[i]+=1;
            last=t;
        }
        //printf("i=%d num=%d t=%d\n",i,stanum[i],stat[i]);
    }
    int T;
    scanf("%d",&T);
    int r,c,n;
    for(int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        scanf("%d%d%d",&r,&c,&n);
        if(r<c) swap(r,c);
        for(int i=0;i<r;i++){
            for(int s=0;s<1<<c;s++){
                for(int j=0;j<=n;j++){
                    dp[i][s][j]=INT;
                }
            }
        }
        //printf("r=%d c=%d n=%d\n",r,c,n);
        for(int s=0;s<1<<c;s++){
            if(stanum[s]>n) continue;
            dp[0][s][stanum[s]]=stat[s];
        }
        for(int i=1;i<r;i++){
            for(int j=0;j<=n;j++){
                for(int s1=0;s1<1<<c;s1++){
                    if(dp[i-1][s1][j]==INT) continue;
                    for(int s2=0;s2<1<<c;s2++){
                        if(j+stanum[s2]>n) continue;
                        int num1=stat[s2];
                        for(int k=0;k<c;k++){
                            if((1<<k)&s1 && (1<<k)&s2) num1+=1;
                        }
                        dp[i][s2][j+stanum[s2]]=min(dp[i][s2][j+stanum[s2]],dp[i-1][s1][j]+num1);
                    }
                }
            }
        }
        int ans=INT;
        for(int s=0;s<1<<c;s++){
            ans=min(ans,dp[r-1][s][n]);
        }
        printf("%d\n",ans);
    }
    
    
    return 0;
}


























