#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
char s[110][110];
int len[110];
char seq[110];
int top[110];
int a[110][110];
int main() {
    int T,ca=1;
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n ;i++) {
            scanf("%s",s[i]);
            len[i] = strlen(s[i]);
        }
        int tot = 0;
        for(int i = 0; i < len[0]; ) {
            int j = i;
            seq[tot++] = s[0][i];
            while(j < len[0] && s[0][i] == s[0][j]) {
                j++;
            }
            a[0][tot - 1] = j - i;
            i = j;
        }
        bool flag = false;
        for(int i = 1; i < n; i++) {
            char tmp[110];
            int cnt = 0;
            for(int j = 0; j < len[i];) {
                int k = j;
                tmp[cnt++] = s[i][j];
                while(k < len[i] && s[i][j] == s[i][k]) {
                    k++;
                }
                a[i][cnt - 1] = k - j;
                j = k;
            }
            if(cnt != tot) {
                flag = true;
                break;
            }
            for(int j = 0; j < cnt; j++) {
                if(seq[j] != tmp[j]) {
                    flag = true;
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) {
            printf("Case #%d: Fegla Won\n", ca++);
            continue;
        }
        int ret = 0;
        for(int i = 0; i < tot; i++){
            int mi = -1;
            for(int ter = 1; ter <= 100; ter++) {
                int tmp = 0;
                for(int j = 0; j < n; j++) {
                    tmp += abs(ter - a[j][i]);
                }
                if(mi == -1 || tmp < mi) {
                    mi = tmp;
                }
            }
            ret += mi;
        }
        printf("Case #%d: %d\n", ca++, ret);
    }
    return 0;
}
