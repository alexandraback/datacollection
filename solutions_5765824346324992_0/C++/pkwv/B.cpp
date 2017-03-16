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

const int N = 1005;

int a[N], n, m;

ll calc(ll k)
{
    ll cnt(0LL);
    for(int i = 1; i <= m; i++)
        cnt += (k + a[i] - 1) / a[i];
    return cnt;
}

struct node
{
    ll h;
    int id;
} b[N];

bool cmp_h(const node &c, const node &d)
{
    return c.h < d.h || c.h == d.h && c.id < d.id;
}

int main()
{
#ifdef PKWV
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
#endif // PKWV
//    freopen("in.in","r",stdin);
    int T, cas(1);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &m, &n);
        int mval(0);
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &a[i]);
            mval = max(mval, a[i]);
        }
        ll l = 0, r = (ll)mval * (ll)n;
        int res(-1);
        ll ans(-1),num(-1);
        while(l <= r)
        {
            ll mid = (l + r) >> 1;
            ll cnt = calc(mid);
            if(cnt < n) l = mid + 1;
            else
            {
                ans = mid,num=cnt;
                r = mid - 1;
//                if(n > cnt - m)
//                {
//                    printf("%d %I64d %d\n",n,cnt,m);
//                    printf("mid: %I64d\n",mid);
//                    for(int i = 1; i <= m; i++)
//                    {
//                        b[i].h = ((mid-1LL) / a[i]) * a[i];
//                        b[i].id = i;
//                    }
//                    sort(b + 1, b + m + 1, cmp_h);
//                    ll id = n - (cnt - m);
//                    res = b[id].id;
//                    break;
//                }
//                else r = mid - 1;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            b[i].h = ((ans - 1LL) / a[i]) * a[i];
            b[i].id = i;
        }
        sort(b + 1, b + m + 1, cmp_h);
        ll id = n - (num - m);
        res = b[id].id;

        printf("Case #%d: %d\n", cas++, res);
    }
    return 0;
}
