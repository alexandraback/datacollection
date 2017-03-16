#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

const int MAXN = 1010;

int a[MAXN];
int T, n, b;

bool check(LL k) {
    LL sum = 0, cnt = 0;
    for(int i = 0; i < b; ++i) {
        cnt += (k % a[i] == 0);
        sum += (k - 1) / a[i] + 1;
    }
    return sum + cnt >= n;
}

int solve() {
    LL l = 0, r = LL(n) * *max_element(a, a + b);//1000000;//
    while(l < r) {
        LL mid = (l + r) >> 1;
        if(!check(mid)) l = mid + 1;
        else r = mid;
    }
    LL sum = 0, p = 0;
    for(int i = 0; i < b; ++i)
        sum += (l - 1) / a[i] + 1;
    for(int i = 0; i < b; ++i)
        if(l % a[i] == 0 && sum + ++p == n) return i + 1;
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &b, &n);
        for(int i = 0; i < b; ++i)
            scanf("%d", &a[i]);
        printf("Case #%d: %d\n", t, solve());
    }
}
