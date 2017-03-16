#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

#define REP(i, n) for(int i=0;i<(n);++i)
#define FOR(i, j, k) for(int i=(j);i<=(k);++i)
#define mst(x, y) memset(x, y, sizeof(x))
#define pii pair<int, int>
#define fr first
#define sc second
#define seed 13331
#define ll long long
#define ull unsigned long long

template <typename OutputIterator>
void input(OutputIterator first, OutputIterator last){
    while(first != last) cin >> *(first++);
}

template <typename InputIterator>
void output(InputIterator first, InputIterator last, string fs=" ", bool newline=0){
    while(first != last) cout << *(first++) << fs;
    if(newline) cout<<endl;
}

static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}

const int maxn=1010;
const double pi=atan(1.0)*4;
struct node{
    int x,y, id;
}e[maxn], nd[maxn],res[maxn];
int cmp(node a,node b)
{
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int cross(node a,node b,node c)//向量积
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
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int T,n,l;
    scanf("%d",&T);
    FOR(cas, 1, T){
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d%d",&nd[i].x,&nd[i].y);
        REP(i, n) nd[i].id=i;
        int ans[1010];
        REP(i, n) ans[i] = 2e8;
        REP(i, 1<<n){
            int len = 0;
            REP(j, n) if((1<<j)&i)
                e[len ++] = nd[j];
            int ttt = convex(len);
            REP(j, ttt)  ans[res[j].id] = min(ans[res[j].id], n - len);
        }
        printf("Case #%d:\n", cas);
        REP(i, n) cout<<ans[i]<<endl;
    }
    return 0;
}
