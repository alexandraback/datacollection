#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
const int N = 1100;
int a[N];

int main() {
    int o, n, cas = 0;
    scanf("%d", &o);
    while (o--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int res1 = 0, res2 = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] < a[i - 1])
                res1 += - a[i] + a[i - 1];
        }
        int mm = 0;
        for (int i = 2; i <= n; i++)
            mm = max(mm, - a[i] + a[i-1]);
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] >= mm)
                res2 += mm;
            else
                res2 += a[i - 1];
            
        }
        printf("Case #%d: %d %d\n", ++cas, res1, res2);
    }
    return 0;
}