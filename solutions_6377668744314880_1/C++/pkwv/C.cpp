//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 6005;
const db eps = 1e-8;
const db PI = acos(-1.0);
const int INF = 1000000000;

int sgn(db t)
{
    return t < -eps ? -1 : t > eps;
}

struct P
{
    db x, y;
    P(db _x = 0, db _y = 0): x(_x), y(_y) {}
    void input()
    {
        int _x, _y;
        scanf("%d%d", &_x, &_y);
        x = _x, y = _y;
    }
} p[N];

int ans[N];
db a[N], b[N];

int main()
{
#ifdef PKWV
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out","w",stdout);
#endif // PKWV
//    freopen("in.in","r",stdin);
    int T, cas(1);
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            p[i].input();
        for(int i = 0; i < n; i++)
        {
            int la(0), lb(0);
            for(int j = 0; j < n; j++)
            {
                if(i == j)continue ;
                a[la] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
//                printf("%d %f\n",j,a[la]);
                la++;
            }
            int cnt(0), cnt1(0);
            for(int j = 0; j < la; j++)
            {
                if(sgn(a[j] + PI) == 0) cnt++;
                if(sgn(a[j] - PI) == 0) cnt1++;
            }
            for(int j = 0; j < cnt; j++) a[la++] = PI;
            for(int j = 0; j < cnt1; j++) a[la++] = -PI;
            sort(a, a + la);
            lb = la;
            for(int j = 0; j < la; j++)
            {
                if(a[j] < 0) b[j] = a[j] + PI;
                else b[j] = a[j];
            }
            sort(b, b + lb);
//            for(int j = 0; j < la; j++) printf("%f ", a[j]);
//            printf("\n");
            int l(0), r(0), af(0), br(0);
            int res(INF);
            for(int j = 0; j < lb; j++)
            {
                while(l < la && a[l] + PI < b[j] - eps) l++;
                while(r < la && a[r] < b[j] + eps) r++;
                while(af < la && a[af] + PI < b[j] + eps) af++;
                while(br < la && a[br] < b[j] - eps) br++;
                res = min(res, n - (r - l) - 1);
                res = min(res, max(0,br - af));
            }
            if(n==1) ans[i]=0;
            else ans[i] = res;
        }
        printf("Case #%d:\n", cas++);
        for(int i = 0; i < n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
