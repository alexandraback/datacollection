#include<cstdio>
#include<cstring>

int cnt[50];

int T, N;

int main() {
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        cnt[0] = 0;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &cnt[i]);
        }
        int left = N;
        
        printf("Case #%d:", cas);
        int mx1 = 0, mx2 = 0;
        while (true) {
            mx1 = 0, mx2 = 0;
            for(int i = 1; i <= N; i++) {
                if(cnt[i] > cnt[mx1]) {
                    mx2 = mx1;
                    mx1 = i;
                }
                else if(cnt[i] > cnt[mx2]) {
                    mx2 = i;
                }
            }
            if(cnt[mx1] == 0) {
                puts("");
                break;
            }
            if(cnt[mx1] > cnt[mx2] || left > 2) {
                printf(" %c", mx1 - 1 + 'A');
                cnt[mx1]--;
                if(cnt[mx1] == 0) left--;
            }
            else {
                printf(" %c%c", mx1 - 1 + 'A', mx2 - 1 + 'A');
                cnt[mx1]--;
                cnt[mx2]--;
                left -= (cnt[mx1] == 0) + (cnt[mx2] == 0);
            }
        }
    }
    return 0;
}