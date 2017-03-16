#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int n, m;
int a[10000];
typedef long long LL;

int check(LL x) {
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (x + a[i] - 1) / a[i];
        if (ans >= m) return 0;
    }
    return 1;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, tcase = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        printf("Case #%d: ", ++tcase);
        if (n >= m) {
            printf("%d\n", m);
            continue;
        }
        LL head = 0, tail = 1LL << 50;
        while (head < tail - 1) {
            LL mid = (head + tail) >> 1;
            if (check(mid)) head = mid;
            else tail = mid;
        }
        int num = 0, ans = 0;
        for (int i = 1; i <= n; ++i)
            num += (a[i] + head - 1) / a[i];
        //cout << num << endl;
        for (int i = 1; i <= n; ++i) {
            if (head % a[i] == 0) ++num;
            if (num == m) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
