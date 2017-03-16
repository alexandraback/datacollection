#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

bool a[100][100];

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        int R,C,N; scanf("%d%d%d",&R,&C,&N);

        int ans = INF;
        int lim = 1<<(R*C);
        FOR(x,0,lim){
            //CHECK
            int tmp = x;
            int ct = 0;
            while (tmp > 0){
                if (tmp%2 == 1) ++ct;
                tmp/=2;
            }
            if (ct != N) continue;

            //FILL
            tmp = x;
            ct = 0;
            FOR(i,0,R){
                FOR(j,0,C){
                    a[i][j] = tmp%2;
                    tmp /= 2;
                    if ((j != 0) && (a[i][j] && a[i][j-1])){
                        ++ct;
                    }
                    if ((i!=0) && (a[i][j] && a[i-1][j])){
                        ++ct;
                    }
                }
            }
            ans = min(ans,ct);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
