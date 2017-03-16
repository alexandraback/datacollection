#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
const int INF=(int)1e9+7;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int m,n,p;
bool inside(int x,int y) {
    if (x<0 || x>=m || y<0 || y>=n) return (false);
    return (true);
}
int countAdj(int mask) {
    int res=0;
    REP(i,m) REP(j,n) if (BIT(mask,i*n+j)) REP(k,4) {
        int x=i+dx[k];
        int y=j+dy[k];
        if (inside(x,y) && BIT(mask,x*n+y)) res++;
    }
    return (res/2);
}
int process(void) {
    scanf("%d%d%d",&m,&n,&p);
    int res=INF;
    REP(i,MASK(m*n)) if (__builtin_popcount(i)==p)
        res=min(res,countAdj(i));
    return (res);
}
int main(void) {
    int t;
    scanf("%d",&t);
    FOR(i,1,t) printf("Case #%d: %d\n",i,process());
    return 0;
}
