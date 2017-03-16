#include <stdio.h>
#include <string.h>
#include <algorithm>
char inp[110][110];
inline int abs(int a) {
    return a>0?a:-a;
}
int main() {
    int cas, n, len[110], ans, cur[110], sum, srt[110];
    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        sum = 0;
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            scanf("%s", inp[i]);
            len[i] = strlen(inp[i]);
            sum += len[i];
        }
        ans = 0;
        memset(cur, 0, sizeof(cur));
        while (sum > 0) {
            if (cur[0] == len[0]) {
                ans = -1;
                break;
            }
            int cha = inp[0][cur[0]];
            memset(srt, 0, sizeof(srt));
            for (int i=0; i<n; i++) {
                while (inp[i][cur[i]] == cha) {
                    srt[i] ++;
                    cur[i] ++;
                    sum --;
                }
                if (srt[i] == 0) {
                    ans = -1;
                    break;
                }
            }
            if (ans == -1) break;

            std::sort(srt, srt+n);
            for (int i=0; i<n; i++) {
                ans += abs(srt[i] - srt[n/2]);
            }
        }
        if (ans != -1)
            printf("Case #%d: %d\n", ii+1, ans);
        else
            printf("Case #%d: Fegla Won\n", ii+1);
    }
    return 0;
}