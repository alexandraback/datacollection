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
int n;
int bx[1100];

int main() {
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    scanf("%d", &T);

    int cas = 1;

    while(T--) {
        int sum1 = 0; int sum2 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &bx[i]);
        }
        int mx = 0;
        for(int i = 1; i < n; i++) {
            if(bx[i] > bx[i + 1]) sum1 += bx[i] - bx[i + 1], mx = max(mx, bx[i] - bx[i + 1]);
        }

        for(int i = 1; i < n; i++) {
            sum2 += min(bx[i], mx);
        }

        printf("Case #%d: %d %d\n", cas++, sum1, sum2);
    }
    return 0;
} 

