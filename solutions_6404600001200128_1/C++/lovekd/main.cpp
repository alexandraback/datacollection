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
#define INF 150000000000LL
#define maxn 210000
#define mod  1000000007LL
#define HASHMOD 3894229
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int iCase;
int a[101000], n;
void solve(void) {
    scanf("%d",&n);
    for(int i = 1;i <= n; i ++) {
        scanf("%d",a+i);
    }
    int ans1 = 0, ans2 = 0, delta = 0;
    for(int i = 2;i <= n;i ++) {
        int temp = a[i-1] - a[i];
        if(temp > 0) ans1 += temp;
        if(temp > delta) delta = temp;
    }
    for(int i = 1;i < n;i ++) {
        if(a[i] >= delta) ans2 += delta;
        else ans2 += a[i];
    }
    printf("Case #%d: %d %d\n",++iCase, ans1, ans2);
}
int main(void) {
    //freopen("A-large.in", "r", stdin);
    //freopen("out.out", "w",  stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum --) solve();
}
