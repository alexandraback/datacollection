#include <stdio.h>
#include <string>

int main()
{
    int t;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases++) {
        int n;
        scanf("%d", &n);
        int total = 0;
        int p[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            total += p[i];
        }
        printf("Case #%d:", cases);
        while (total > 0) {
            std::string ans;
            for (int j = 0; j < 2; j++) {
                int max_p = 0;
                for (int i = 0; i < n; i++) {
                    if (p[i] > max_p) max_p = p[i];
                }
                if (max_p == 0 || (j == 1 && total == 2)) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    if (p[i] == max_p) {
                        p[i]--;
                        total--;
                        ans += ('A' + i);
                        break;
                    }
                }
            }
            printf(" %s", ans.c_str());
        }
        printf("\n");
    }
    return 0;
}
