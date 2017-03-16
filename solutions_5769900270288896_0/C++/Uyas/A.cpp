#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c, n;
int ans;

int a[20][20];

void work(int i, int j, int k, int cnt) {
    if (j == c) { j = 0; i += 1; }
    if (i == r) { 
        //printf("%d, %d\n", k, cnt);
        if (k != 0) return;
        if (cnt < ans) ans = cnt;
        return ;
    }
    a[i][j] = 0; work(i, j + 1, k, cnt);
    if (k == 0) return;
    a[i][j] = 1; int add = 0;
    if (i - 1 >= 0 && a[i - 1][j] == 1) ++add;
    if (j - 1 >= 0 && a[i][j - 1] == 1) ++add;
    work(i, j + 1, k - 1, cnt + add);
}

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        scanf("%d%d%d", &r, &c, &n);
        ans = 12345678;
        work(0, 0, n, 0);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

