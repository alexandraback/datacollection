#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n;
pair<int, int> cnt[26];
int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            cnt[i].second = i;
            scanf("%d", &cnt[i].first);
        }
        sort(cnt, cnt+n);
        reverse(cnt, cnt+n);
        while (cnt[0].first > cnt[1].first) {
            printf(" %c", cnt[0].second + 'A');
            cnt[0].first--;
        }
        for (i = 2; i < n; i++) {
            while (cnt[i].first > 0) {
                printf(" %c", cnt[i].second + 'A');
                cnt[i].first--;
            }
        }
        while (cnt[0].first > 0) {
            printf(" %c%c", cnt[0].second + 'A', cnt[1].second + 'A');

            cnt[0].first--;
            cnt[1].first--;
        }
        printf("\n");

    }
    return 0;
}
