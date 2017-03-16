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

const int N = 10005;
const int INF = 1000000000;

int a[N];

int main()
{
#ifdef PKWV
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out","w",stdout);
#endif // PKWV
    int T, cas(1);
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans(0);
        for(int i = 1; i < n; i++)
        {
            if(a[i] < a[i - 1]) ans += a[i - 1] - a[i];
        }
        int res(0), dt(-INF);
        for(int i = 1; i < n; i++)
        {
            dt = max(dt, a[i - 1] - a[i]);
        }
        if(dt <= 0) res = 0;
        else
        {
            int rate = (dt + 9) / 10;
            for(int i = 0; i < n - 1; i++)
            {
                if(a[i] < rate * 10) res += a[i];
                else res += rate * 10;
            }
        }
        printf("Case #%d: %d %d\n", cas++, ans, res);
    }
    return 0;
}
