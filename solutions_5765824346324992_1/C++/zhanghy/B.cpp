#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 1010;
LL INF = 1000000000;

int T;
int B,N;
int a[maxn];


int main() {
    freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.in","r",stdin);
    freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.out","w",stdout);
    scanf("%d",&T);
    INF *= INF;
    for (int kase = 1;kase <= T; kase++) {
        scanf("%d%d",&B,&N);
        for (int i = 1;i <= B; i++) scanf("%d",&a[i]);
        LL l = 0,r = INF;
        while (l < r) {
            LL mid = (l+r)>>1;
            LL sum = 0;
            for (int i = 1;i <= B; i++) {
                sum += (mid+1) / a[i];
                if ((mid+1) % a[i]) sum++;
            }
            if (sum < N) l = mid+1;
            else r = mid;
        }
        LL k = 0;
        for (int i = 1;i <= B; i++) {
                k += l/a[i];
                if (l%a[i]) k++;
        }
        k = N-k;
        int ans = 0;
        for (int i = 1;i <= B; i++) {
            if (l % a[i] == 0) k--;
            if (k == 0) { ans = i; break; }
        }
        printf ("Case #%d: %d\n",kase,ans);
    }
    return 0;
}

