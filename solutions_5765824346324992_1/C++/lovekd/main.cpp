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
#define INF 150000000000000LL
#define maxn 210000
#define mod  1000000007LL
#define HASHMOD 3894229
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int iCase, b , n;
int a[1010];
int re[1010];
LL cal(LL t) {
    LL ans = 0;
    for(int i = 1;i <= b;i ++) {
        LL temp = t / a[i];
        if(t % a[i] != 0) temp ++;
        ans += temp;
    }
    return ans;
}
void solve(void) {
    scanf("%d%d", &b, &n);
    for(int i = 1;i <= b;i ++) scanf("%d",a+i);
    if(n <= b) {
        printf("Case #%d: %d\n",++iCase, n);
        return;
    }
    LL l = 1, r = INF;
    LL t = l;
    while(l <= r) {
        LL mid = (l + r) / 2;
        LL num = cal(mid);
        if(num >= n) {
            r = mid - 1;
        }else {
            l = mid + 1;
            t = mid;
        }
    }
    LL havedone = 0;
    for(int i = 1;i <= b;i ++) {
        havedone += t / a[i];
        if(t % a[i] != 0) havedone ++;
        re[i] = t % a[i];
    }
    int ans = -1;
    //printf("t is %I64d\n",t);
    while(true) {

        for(int i = 1;i <= b;i ++) {
            if(re[i] == 0) {
                re[i] = -1;
                havedone ++;
                //printf("i is %d done is %d\n",i,havedone);
                if(havedone == n) {
                    ans = i;
                    break;
                }
            }
        }
        if(havedone == n) break;
        LL minr = INF, id = -1;
        for(int i = 1;i <= b;i ++) {
            if(re[i] <= 0) continue;
            int temp = a[i] - re[i];
            if(temp < minr) {
                minr = temp;
                id = i;
            }
        }
        if(id != -1) {
            havedone ++;
            if(havedone == n) {
                ans = id;
                break;
            }
            re[id] = -1;
        }
    }
    printf("Case #%d: %d\n",++iCase, ans);
}

int main(void) {
    //freopen("B-large.in", "r", stdin);
    //freopen("out.out", "w",  stdout);
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum --) solve();
}
