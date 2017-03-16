#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, char> p[26];

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int s;
            scanf("%d", &s);
            p[i] = {s, 'A' + i};
            sum += s;
        }
        printf("Case #%d:", cs);
        for (int i = 0; i < sum;) {
            sort(p, p + n, greater<pair<int, char>>());
            if (2 * p[0].first > sum - i)
                printf(" %c=%d/%d ", p[0].second, p[0].first, sum - i);
            if (p[0].first == p[1].first and (n == 2 || p[2].first == 0)) {
                printf(" %c%c", p[0].second, p[1].second);
                p[0].first--; p[1].first--;
                i += 2;
            } else {
                printf(" %c", p[0].second);
                p[0].first--;
                i++;
            }
        }
        printf("\n");
    }
}
