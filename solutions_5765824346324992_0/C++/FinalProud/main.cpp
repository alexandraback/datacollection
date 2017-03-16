#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <vector>

#define lson l,mid,u << 1
#define rson mid + 1,r,u << 1 | 1
#define ls u << 1
#define rs u << 1 | 1

using namespace std;
typedef long long ll;
const double eps = 1e-9;
const ll INF = 1LL << 50;
int a[1100],b,n;

int solve (ll t) {
    ll all = 0, cnt = 0;
    for (int i = 1; i <= b; i++) {
        if (t) all += (t - 1) / a[i] + 1;
        cnt += (t % a[i] == 0);
    }
    if (cnt && all < n && n <= all + cnt) {
        n -= all;
        for (int i = 1; i <= b; i++) if (t % a[i] == 0) {
            n--;
            if (n == 0) {
                printf ("%d", i);
                break;
            }
        }
        return 0;
    }
    if (n <= all) return -1;
    return 1;
}


int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T,cnt = 0;
    cin>>T;
    while(T--)
    {
        scanf("%d %d",&b,&n);
        for(int i = 1; i <= b; i++)
            scanf("%d",a + i);
        printf("Case #%d: ",++cnt);
        ll l = -1,r = INF;
        while(l + 1 < r)
        {
            ll mid = (l + r) >> 1;
            int tmp = solve(mid);
            if(tmp == 0) break;
            if(tmp == -1) r = mid;
            else l = mid;
        }
        puts("");
    }
    return 0;
}
