#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> VI;

int ans[2];
int grid[2][4][4];

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_out.txt","w",stdout);

    int T=INT;
    REP(t,1,T){
        FOR(k,2){
            ans[k]=INT-1;
            FOR(r,4)FOR(c,4)grid[k][r][c]=INT;
        }
        bool in[2][20]; CLR(in, 0);
        FOR(i,2)FOR(c,4) in[i][grid[i][ans[i]][c]] = 1;

        int common=0, res;
        REP(i,1,16)if(in[0][i] && in[1][i]){++common; res = i; }

        printf("Case #%d: ",t);

        if(common == 1) printf("%d\n",res);
        else if(common == 0) puts("Volunteer cheated!");
        else puts("Bad magician!");
    }
    return 0;
}
