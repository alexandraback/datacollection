#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long LL;

#define MAXN 100100
#define INF 20000000
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)
#define mod 100007

int T;

int n, N;
int bx[1010];

struct Barber {
    int tim, id;
}ax[1010];

int cmp(const Barber & a, const Barber & b) {
    if(a.tim < b.tim) return 1;
    else if(a.tim == b.tim) {
        if(a.id < b.id) return 1;
        else return 0;
    } else return 0;
}

int main() {
    //freopen("pro.in","r",stdin);
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        scanf("%d%d", &n, &N);
        for(int i = 1; i <= n; i++) scanf("%d", &bx[i]);

        if(N <= n) {
            for(int i = 1; i <= n; i++) ax[i].id = i, ax[i].tim = bx[i];
            sort(ax + 1, ax + 1 + n, cmp);
            printf("Case #%d: %d\n", cas++, ax[N].id);
            continue;
        }

        long long l = 0, r = 100000000200000, mid, ans, sum = 0;
        int lef = 0;
        while(l <= r) {
            mid = l + r >> 1;
            sum = 0;
            for(int i = 1; i <= n; i++) {
                sum += (mid + bx[i] - 1) / bx[i];
            }
            if(sum < N) {
                ans = mid;
                lef = N - sum;
                l = mid + 1;
            } else r = mid - 1;
        }
        for(int i = 1; i <= n; i++) {
            ax[i].id = i;
            ax[i].tim = ans % bx[i];
        }
        sort(ax + 1, ax + 1 + n, cmp);
        printf("Case #%d: %d\n", cas++, ax[lef].id);
    }

    return 0;
} 

