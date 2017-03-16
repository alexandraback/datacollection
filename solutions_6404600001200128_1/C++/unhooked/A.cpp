#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2222;

int T, n, a[N];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int x = 0;
        int y = 0;
        int num = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; i++) {
            x += max(0, a[i - 1] - a[i]);
        }
        for (int i = 1; i < n; i++) {
            num = max(num, a[i - 1] - a[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            y += min(a[i], num);
        }
        printf("Case #%d: %d %d\n", t, x, y);
    }

    return 0;

}
