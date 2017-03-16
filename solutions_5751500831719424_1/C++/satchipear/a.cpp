#include <stdio.h>
#include <string.h>
char c[111][111];
int l[111][111];
int ln[111];

int abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        printf("Case #%d: ", cn);
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            char s[111];
            scanf("%s", s);
            ln[i] = 1;
            l[i][1] = 1;
            c[i][1] = s[0];
            for (int j = 1; s[j]; j++) {
                if (s[j] == s[j - 1]) {
                    l[i][ln[i]]++;
                } else {
                    ln[i]++;
                    c[i][ln[i]] = s[j];
                    l[i][ln[i]] = 1;
                }
            }
        }

        
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (ln[i] != ln[0]) {
                ok = false;
                break;
            }
            for (int j = 1; j <= ln[i]; j++) {
                if (c[i][j] != c[0][j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (!ok) {
            printf("Fegla Won\n");
            continue;
        } 

        int ans = 0;
        for (int i = 1; i <= ln[0]; i++) {
            int min = 1111111111;
            for (int j = 0; j < n; j++) {
                int now = 0;
                for (int k = 0; k < n; k++) {
                    now += abs(l[k][i] - l[j][i]);
                }
                if (now < min) {
                    min = now;
                }
            }
            ans += min;
        }
        printf("%d\n", ans);
    }
    return 0;
}

