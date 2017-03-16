//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>   //我是沙茶....今天又写搓了。。
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <utility>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-9
#define INF 15000
#define maxn 20
#define mod  1000000007LL
#define HASHMOD 3894229
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int iCase, n;
struct node{
    LL x,y;
}e[maxn],res[maxn],fuck[maxn];
LL cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
LL cross(node a,node b,node c)//向量积
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int convex(int n)//求凸包上的点
{
    sort(e,e+n,cmp);
    int m=0,i,j,k;
    //求得下凸包，逆时针
    //已知凸包点m个，如果新加入点为i，则向量(m-2,i)必定要在(m-2,m-1)的逆时针方向才符合凸包的性质
    //若不成立，则m-1点不在凸包上。
    for(i=0;i<n;i++)
    {
        while(m>1&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    k=m;
    //求得上凸包
    for(i=n-2;i>=0;i--)
    {
        while(m>k&&cross(res[m-1],e[i],res[m-2])<0)m--;
        res[m++]=e[i];
    }
    if(n>1)m--;//起始点重复。
    return m;
}
int calbin(int x) {
    int ans = 0;
    while(x) {
        ans += (x & 1);
        x >>= 1;
    }return ans;
}
void solve(void) {
    scanf("%d",&n);
    for(int i = 0;i < n;i ++) {
        scanf("%I64d%I64d",&fuck[i].x, &fuck[i].y);
    }
    printf("Case #%d:\n", ++iCase);
    int cap = (1 << n);
    for(int i = 0;i < n;i ++) {
        int ans = INF;
        for(int st = 0;st < cap;st ++) {
            //printf("st is %d\n",st);
            int temp = n - calbin(st);
            if(temp >= ans) continue;
            if((st & (1 << i)) == 0) continue;
            int tot = 0;
            for(int j = 0;j < n;j ++) {
                if((st & (1 << j))) {
                    e[tot].x = fuck[j].x;
                    e[tot].y = fuck[j].y;
                    tot++;
                }
            }
            //printf("bef test\n");
            int m = convex(tot);
            for(int j = 0;j < m;j ++) {
                //printf("con x %d y %d\n",res[j].x, res[j].y);
                if(res[j].x == fuck[i].x && res[j].y == fuck[i].y) {
                    if(ans > temp) {
                        ans = temp;
                    }
                }
            }
            //system("pause");
        }
        printf("%d\n",ans);
    }
}

int main(void) {
    //freopen("C-small-attempt1.in", "r", stdin);
    //freopen("out.out", "w",  stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum --) solve();
}
